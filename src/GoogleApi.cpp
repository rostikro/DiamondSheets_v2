//
// Created by Rostik on 1/18/2024.
//

#include "GoogleApi.h"

#include <QOAuth2AuthorizationCodeFlow>
#include <QDesktopServices>
#include <QOAuthHttpServerReplyHandler>
#include <QJsonObject>
#include <QJsonDocument>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QSettings>
#include <QHttpMultiPart>

void GoogleApi::authenticate()
{
    google->grant();
}

GoogleApi::GoogleApi(QObject *parent)
        : QObject(parent), google(new QOAuth2AuthorizationCodeFlow(this))
{
    google->setScope("https://www.googleapis.com/auth/drive.file");

    connect(google, &QOAuth2AuthorizationCodeFlow::authorizeWithBrowser, &QDesktopServices::openUrl);

    google->setAuthorizationUrl(QUrl("https://accounts.google.com/o/oauth2/auth"));
    google->setAccessTokenUrl(QUrl("https://oauth2.googleapis.com/token"));
    google->setClientIdentifier(clientId);
    google->setClientIdentifierSharedKey(secret);

    google->setReplyHandler(new QOAuthHttpServerReplyHandler(8080, this));

    connect(google, &QOAuth2AuthorizationCodeFlow::granted, [=]()
    {
        accessToken = google->token();
        refreshToken = google->refreshToken();
        saveTokens();
        Q_EMIT authenticated();
    });

    if (tryLoadTokens())
        isAuthenticated = true;
}

void GoogleApi::saveTokens()
{
    QSettings settings("Diamond Company", "Diamond Sheets", this);

    settings.setValue("accessToken", accessToken);
    settings.setValue("refreshToken", refreshToken);
}

bool GoogleApi::tryLoadTokens()
{
    QSettings settings("Diamond Company", "Diamond Sheets", this);

    accessToken = settings.value("accessToken").toString();
    refreshToken = settings.value("refreshToken").toString();

    google->setToken(accessToken);
    google->setRefreshToken(refreshToken);

    if (accessToken.isEmpty() || refreshToken.isEmpty())
        return false;

    return true;
}