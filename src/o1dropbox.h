#ifndef O1DROPBOX_H
#define O1DROPBOX_H

#include "o0export.h"
#include "o1.h"

/// Dropbox authenticator
class O0_EXPORT O1Dropbox: public O1 {
    Q_OBJECT

public:
    explicit O1Dropbox(QObject *parent = 0): O1(parent) {
        setRequestTokenUrl(QUrl(QLatin1String("https://api.dropbox.com/1/oauth/request_token")));
        setAuthorizeUrl(QUrl(QLatin1String("https://www.dropbox.com/1/oauth/authorize?display=mobile")));
        setAccessTokenUrl(QUrl(QLatin1String("https://api.dropbox.com/1/oauth/access_token")));
     }
};

#endif // O1DROPBOX_H
