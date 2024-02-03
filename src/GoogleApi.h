//
// Created by Rostik on 1/18/2024.
//

#ifndef DIAMONDSHEETS_GOOGLEAPI_H
#define DIAMONDSHEETS_GOOGLEAPI_H


#include <QObject>

class QOAuth2AuthorizationCodeFlow;

class GoogleApi : public QObject
{
Q_OBJECT

public:
    GoogleApi(QObject *parent = nullptr);

    bool IsAuthenticated() { return isAuthenticated; }

private:
    void saveTokens();

    bool tryLoadTokens();

public Q_SLOT:
    void authenticate();

Q_SIGNALS:
    void authenticated();

private:
    QOAuth2AuthorizationCodeFlow* google = nullptr;

    // Specify here your client id and secret from Google Cloud Console
    const QString clientId = "";
    const QString secret = "";

    bool isAuthenticated = false;
    QString accessToken;
    QString refreshToken;
};


#endif //DIAMONDSHEETS_GOOGLEAPI_H
