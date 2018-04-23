#include "o2spotify.h"

static const QLatin1String SpotifyEndpoint("https://accounts.spotify.com/authorize");
static const QLatin1String SpotifyTokenUrl("https://accounts.spotify.com/api/token");

O2Spotify::O2Spotify(QObject *parent): O2(parent) {
    setRequestUrl(SpotifyEndpoint);
    setTokenUrl(SpotifyTokenUrl);
    setRefreshTokenUrl(SpotifyTokenUrl);
}

const QString O2Spotify::Scope::PLAYLIST_READ_PRIVATE = QLatin1String("playlist-read-private");
const QString O2Spotify::Scope::PLAYLIST_READ_COLLABORATIVE = QLatin1String("playlist-read-collaborative");
const QString O2Spotify::Scope::PLAYLIST_MODIFY_PUBLIC = QLatin1String("playlist-modify-public");
const QString O2Spotify::Scope::PLAYLIST_MODIFY_PRIVATE = QLatin1String("playlist-modify-private");
const QString O2Spotify::Scope::STREAMING = QLatin1String("streaming");
const QString O2Spotify::Scope::USER_FOLLOW_MODIFY = QLatin1String("user-follow-modify");
const QString O2Spotify::Scope::USER_FOLLOW_READ = QLatin1String("user-follow-read");
const QString O2Spotify::Scope::USER_LIBRARY_READ = QLatin1String("user-library-read");
const QString O2Spotify::Scope::USER_LIBRARY_MODIFY = QLatin1String("user-library-modify");
const QString O2Spotify::Scope::USER_READ_PRIVATE = QLatin1String("user-read-private");
const QString O2Spotify::Scope::USER_READ_BIRTHDATE = QLatin1String("user-read-birthdate");
const QString O2Spotify::Scope::USER_READ_EMAIL = QLatin1String("user-read-email");
const QString O2Spotify::Scope::USER_TOP_READ = QLatin1String("user-top-read");

QStringList O2Spotify::Scope::allScopesList() {
    QStringList result;
    return result
            << PLAYLIST_READ_PRIVATE
            << PLAYLIST_READ_COLLABORATIVE
            << PLAYLIST_MODIFY_PUBLIC
            << PLAYLIST_MODIFY_PRIVATE
            << STREAMING
            << USER_FOLLOW_MODIFY
            << USER_FOLLOW_READ
            << USER_LIBRARY_READ
            << USER_LIBRARY_MODIFY
            << USER_READ_PRIVATE
            << USER_READ_BIRTHDATE
            << USER_READ_EMAIL
            << USER_TOP_READ;
}
