//
// Created by Rostik on 1/18/2024.
//

#include "GoogleDriveApi.h"

#include <QDesktopServices>
#include <QJsonObject>
#include <QJsonDocument>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QSettings>
#include <QHttpMultiPart>
#include <QJsonArray>

GoogleDriveApi::GoogleDriveApi(QObject *parent)
        : QObject(parent), networkAccessManager(new QNetworkAccessManager(this))
{
    isAuthenticated = tryLoadTokens();
}

bool GoogleDriveApi::tryLoadTokens()
{
    QSettings settings("Diamond Company", "Diamond Sheets", this);

    accessToken = settings.value("accessToken").toString();

    if (accessToken.isEmpty())
        return false;

    return true;
}

bool GoogleDriveApi::IsAuthenticated()
{
    if (!isAuthenticated)
        isAuthenticated = tryLoadTokens();
    return isAuthenticated;
}

QHttpMultiPart* GoogleDriveApi::prepareMultiPartBody(const QString &name, const QString &buff)
{
    QJsonObject obj;
    obj["name"] = name;
    QString json(QJsonDocument(obj).toJson(QJsonDocument::Compact));

    auto multipart = new QHttpMultiPart(QHttpMultiPart::RelatedType);

    QHttpPart metadata;
    metadata.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    metadata.setBody(json.toUtf8());

    QHttpPart file;
    file.setHeader(QNetworkRequest::ContentTypeHeader, "text/csv");
    file.setBody(buff.toUtf8());

    multipart->append(metadata);
    multipart->append(file);

    return multipart;
}

void GoogleDriveApi::uploadFile(const QString &name, const QString &buff)
{
    auto multipart = prepareMultiPartBody(name, buff);

    QNetworkRequest request;
    request.setUrl(QUrl("https://www.googleapis.com/upload/drive/v3/files?uploadType=multipart"));
    request.setRawHeader("Authorization", "Bearer " + accessToken.toUtf8());

    auto reply = networkAccessManager->post(request, multipart);

    multipart->setParent(reply);

    connect(reply, &QNetworkReply::finished, [=]()
    {
        QJsonObject response(QJsonDocument::fromJson(reply->readAll()).object());
        Q_EMIT setGoogleDriveFileId(response["id"].toString());
        reply->deleteLater();
    });
}

void GoogleDriveApi::updateFile(const QString &id, const QString &name, const QString &buff)
{
    auto multipart = prepareMultiPartBody(name, buff);

    QNetworkRequest request;
    request.setUrl(QUrl("https://www.googleapis.com/upload/drive/v3/files/" + id + "?uploadType=multipart"));
    request.setRawHeader("Authorization", "Bearer " + accessToken.toUtf8());

    auto reply = networkAccessManager->sendCustomRequest(request, "PATCH", multipart);

    multipart->setParent(reply);

    connect(reply, &QNetworkReply::finished, [=]()
    {
        reply->deleteLater();
    });
}

void GoogleDriveApi::openFile(const QString &id)
{
    QNetworkRequest request;
    request.setUrl(QUrl("https://www.googleapis.com/drive/v3/files/" + id));
    request.setRawHeader("Authorization", "Bearer " + accessToken.toUtf8());

    auto reply = networkAccessManager->get(request);

    connect(reply, &QNetworkReply::finished, [=]()
    {
        QJsonObject response(QJsonDocument::fromJson(reply->readAll()).object());

        auto fileName = response["name"].toString();

        Q_EMIT setGoogleDriveFileId(response["id"].toString());

        // Second request to get file content
        QNetworkRequest requestContent;
        requestContent.setUrl(QUrl("https://www.googleapis.com/drive/v3/files/" + id + "?alt=media"));
        requestContent.setRawHeader("Authorization", "Bearer " + accessToken.toUtf8());

        auto replyContent = networkAccessManager->get(requestContent);

        connect(replyContent, &QNetworkReply::finished, [=]()
        {
            Q_EMIT fileDownloaded(fileName, replyContent->readAll());
            replyContent->deleteLater();
        });

        reply->deleteLater();
    });
}

void GoogleDriveApi::getFiles()
{
    QNetworkRequest request;
    request.setUrl(QUrl("https://www.googleapis.com/drive/v3/files"));
    request.setRawHeader("Authorization", "Bearer " + accessToken.toUtf8());

    auto reply = networkAccessManager->get(request);

    connect(reply, &QNetworkReply::finished, [=]()
    {
        QStringList fileNames, fileIds;

        QJsonObject response(QJsonDocument::fromJson(reply->readAll()).object());
        for (auto file : response["files"].toArray())
        {
            auto objFile = file.toObject();
            fileNames.push_back(objFile["name"].toString());
            fileIds.push_back(objFile["id"].toString());
        }

        Q_EMIT filesListReceived(fileNames, fileIds);
    });
}
