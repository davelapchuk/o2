#ifndef O0GLOBALS_H
#define O0GLOBALS_H

// Common constants
const QLatin1String O2_ENCRYPTION_KEY("12345678");
const QLatin1String O2_CALLBACK_URL("http://127.0.0.1:%1/");
const char O2_MIME_TYPE_XFORM[] = "application/x-www-form-urlencoded";
const char O2_MIME_TYPE_JSON[] = "application/json";

// QSettings key names
const QString O2_KEY_TOKEN(QString::fromLatin1("token.%1"));
const QString O2_KEY_TOKEN_SECRET(QString::fromLatin1("tokensecret.%1"));
const QString O2_KEY_CODE(QString::fromLatin1("code.%1"));
const QString O2_KEY_EXPIRES(QString::fromLatin1("expires.%1"));
const QString O2_KEY_REFRESH_TOKEN(QString::fromLatin1("refreshtoken.%1"));
const QString O2_KEY_LINKED(QString::fromLatin1("linked.%1"));
const QString O2_KEY_EXTRA_TOKENS(QString::fromLatin1("extratokens.%1"));

// OAuth 1/1.1 Request Parameters
const QLatin1String O2_OAUTH_CALLBACK("oauth_callback");
const QLatin1String O2_OAUTH_CONSUMER_KEY("oauth_consumer_key");
const QLatin1String O2_OAUTH_NONCE("oauth_nonce");
const QLatin1String O2_OAUTH_SIGNATURE("oauth_signature");
const QLatin1String O2_OAUTH_SIGNATURE_METHOD("oauth_signature_method");
const QLatin1String O2_OAUTH_TIMESTAMP("oauth_timestamp");
const QLatin1String O2_OAUTH_VERSION("oauth_version");
// OAuth 1/1.1 Response Parameters
const QLatin1String O2_OAUTH_TOKEN("oauth_token");
const QLatin1String O2_OAUTH_TOKEN_SECRET("oauth_token_secret");
const QLatin1String O2_OAUTH_CALLBACK_CONFIRMED("oauth_callback_confirmed");
const QLatin1String O2_OAUTH_VERFIER("oauth_verifier");

// OAuth 2 Request Parameters
const QLatin1String O2_OAUTH2_RESPONSE_TYPE("response_type");
const QLatin1String O2_OAUTH2_CLIENT_ID("client_id");
const QLatin1String O2_OAUTH2_CLIENT_SECRET("client_secret");
const QLatin1String O2_OAUTH2_USERNAME("username");
const QLatin1String O2_OAUTH2_PASSWORD("password");
const QLatin1String O2_OAUTH2_REDIRECT_URI("redirect_uri");
const QLatin1String O2_OAUTH2_SCOPE("scope");
const QLatin1String O2_OAUTH2_GRANT_TYPE_CODE("code");
const QLatin1String O2_OAUTH2_GRANT_TYPE_TOKEN("token");
const char O2_OAUTH2_GRANT_TYPE_PASSWORD[] = "password";
const QLatin1String O2_OAUTH2_GRANT_TYPE("grant_type");
const QLatin1String O2_OAUTH2_API_KEY("api_key");

// OAuth 2 Response Parameters
const QLatin1String O2_OAUTH2_ACCESS_TOKEN("access_token");
const QLatin1String O2_OAUTH2_REFRESH_TOKEN("refresh_token");
const QLatin1String O2_OAUTH2_EXPIRES_IN("expires_in");

// OAuth signature types
const QString O2_SIGNATURE_TYPE_HMAC_SHA1 = QString::fromLatin1("HMAC-SHA1");
const QString O2_SIGNATURE_TYPE_PLAINTEXT = QString::fromLatin1("PLAINTEXT");

// Parameter values
const QLatin1String O2_AUTHORIZATION_CODE("authorization_code");

// Standard HTTP headers
const char O2_HTTP_AUTHORIZATION_HEADER[] = "Authorization";

#endif // O0GLOBALS_H
