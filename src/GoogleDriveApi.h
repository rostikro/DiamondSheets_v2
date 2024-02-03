//
// Created by Rostik on 1/18/2024.
//

#ifndef DIAMONDSHEETS_GOOGLEDRIVEAPI_H
#define DIAMONDSHEETS_GOOGLEDRIVEAPI_H


#include <QObject>

class QNetworkAccessManager;
class QHttpMultiPart;

class GoogleDriveApi : public QObject
{
Q_OBJECT

public:
    GoogleDriveApi(QObject *parent = nullptr);

    void uploadFile(const QString &name, const QString &buff);

    void updateFile(const QString &id, const QString &name, const QString &buff);

    void openFile(const QString &id);

    void getFiles();

    bool IsAuthenticated();

private:
    bool tryLoadTokens();

    QHttpMultiPart* prepareMultiPartBody(const QString &name, const QString &buff);

Q_SIGNALS:
    void setGoogleDriveFileId(const QString &id);

    void fileDownloaded(const QString &fileName, QString content);

    void filesListReceived(const QStringList &fileNames, const QStringList &fileIds);

private:
    QNetworkAccessManager* networkAccessManager;

    bool isAuthenticated = false;
    QString accessToken;
};


#endif //DIAMONDSHEETS_GOOGLEDRIVEAPI_H
