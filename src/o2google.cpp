//
// Created by michaelpollind on 3/13/17.
//

#include "o2google.h"

static const QLatin1String GftEndpoint("https://accounts.google.com/o/oauth2/auth");
static const QLatin1String GftTokenUrl("https://accounts.google.com/o/oauth2/token");
static const QLatin1String GftRefreshUrl("https://accounts.google.com/o/oauth2/token");

O2Google::O2Google(QObject *parent) : O2(parent){
    setRequestUrl(GftEndpoint);
    setTokenUrl(GftTokenUrl);
    setRefreshTokenUrl(GftRefreshUrl);
}
