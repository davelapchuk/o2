#include <QDebug>
#include <QDateTime>
#include <QMap>
#include <QString>
#include <QStringList>
#if QT_VERSION >= 0x050000
#include <QUrlQuery>
#endif

#include "o2skydrive.h"
#include "o0globals.h"

O2Skydrive::O2Skydrive(QObject *parent): O2(parent) {
    setRequestUrl(QLatin1String("https://login.live.com/oauth20_authorize.srf"));
    setTokenUrl(QLatin1String("https://login.live.com/oauth20_token.srf"));
    setRefreshTokenUrl(QLatin1String("https://login.live.com/oauth20_token.srf"));
}

void O2Skydrive::link() {
    qDebug() << "O2Skydrive::link";
    if (linked()) {
        qDebug() << "O2kydrive::link: Linked already";
        return;
    }

    setLinked(false);
    setToken(QLatin1String(""));
    setTokenSecret(QLatin1String(""));
    setExtraTokens(QVariantMap());
    setRefreshToken(QString());
    setExpires(0);

    redirectUri_ = QString::fromLatin1("https://login.live.com/oauth20_desktop.srf");

    // Assemble intial authentication URL
    QList<QPair<QString, QString> > parameters;
    parameters.append(qMakePair(O2_OAUTH2_RESPONSE_TYPE, (grantFlow_ == GrantFlowAuthorizationCode) ? O2_OAUTH2_GRANT_TYPE_CODE : O2_OAUTH2_GRANT_TYPE_TOKEN));
    parameters.append(qMakePair(O2_OAUTH2_CLIENT_ID, clientId_));
    parameters.append(qMakePair(O2_OAUTH2_REDIRECT_URI, redirectUri_));
    parameters.append(qMakePair(O2_OAUTH2_SCOPE, scope_));

    // Show authentication URL with a web browser
    QUrl url(requestUrl_);
#if QT_VERSION < 0x050000
    url.setQueryItems(parameters);
#else
    QUrlQuery query(url);
    query.setQueryItems(parameters);
    url.setQuery(query);
#endif
    Q_EMIT openBrowser(url);
}

void O2Skydrive::redirected(const QUrl &url) {
    qDebug() << "O2Skydrive::redirected" << url;

    Q_EMIT closeBrowser();

    if (grantFlow_ == GrantFlowAuthorizationCode) {
        // Get access code
        QString urlCode;
#if QT_VERSION < 0x050000
        urlCode = url.queryItemValue(O2_OAUTH2_GRANT_TYPE_CODE);
#else
        QUrlQuery query(url);
        urlCode = query.queryItemValue(O2_OAUTH2_GRANT_TYPE_CODE);
#endif
        if (urlCode.isEmpty()) {
            qDebug() << "O2Skydrive::redirected: Code not received";
            Q_EMIT linkingFailed();
            return;
        }
        setCode(urlCode);

        // Exchange access code for access/refresh tokens
        QNetworkRequest tokenRequest(tokenUrl_);
        tokenRequest.setHeader(QNetworkRequest::ContentTypeHeader, QByteArray("application/x-www-form-urlencoded"));
        QMap<QString, QString> parameters;
        parameters.insert(O2_OAUTH2_GRANT_TYPE_CODE, code());
        parameters.insert(O2_OAUTH2_CLIENT_ID, clientId_);
        parameters.insert(O2_OAUTH2_CLIENT_SECRET, clientSecret_);
        parameters.insert(O2_OAUTH2_REDIRECT_URI, redirectUri_);
        parameters.insert(O2_OAUTH2_GRANT_TYPE, O2_AUTHORIZATION_CODE);
        QByteArray data = buildRequestBody(parameters);
        QNetworkReply *tokenReply = manager_->post(tokenRequest, data);
        timedReplies_.add(tokenReply);
        connect(tokenReply, SIGNAL(finished()), this, SLOT(onTokenReplyFinished()), Qt::QueuedConnection);
        connect(tokenReply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(onTokenReplyError(QNetworkReply::NetworkError)), Qt::QueuedConnection);
    } else {
        // Get access token
        QString urlToken = QLatin1String("");
        QString urlRefreshToken = QLatin1String("");
        int urlExpiresIn = 0;

        QStringList parts = url.toString().split(QLatin1Char('#'));
        if (parts.length() > 1) {
            foreach (QString item, parts[1].split(QLatin1Char('&'))) {
                int index = item.indexOf(QLatin1Char('='));
                if (index == -1) {
                    continue;
                }
                QString key = item.left(index);
                QString value = item.mid(index + 1);
                qDebug() << "O2Skydrive::redirected: Got" << key;
                if (key == O2_OAUTH2_ACCESS_TOKEN) {
                    urlToken = value;
                } else if (key == O2_OAUTH2_EXPIRES_IN) {
                    urlExpiresIn = value.toInt();
                } else if (key == O2_OAUTH2_REFRESH_TOKEN) {
                    urlRefreshToken = value;
                }
            }
        }

        setToken(urlToken);
        setRefreshToken(urlRefreshToken);
        setExpires(QDateTime::currentMSecsSinceEpoch() / 1000 + urlExpiresIn);
        if (urlToken.isEmpty()) {
            Q_EMIT linkingFailed();
        } else {
            setLinked(true);
            Q_EMIT linkingSucceeded();
        }
    }
}
