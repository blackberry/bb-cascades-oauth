/**
 * KQOAuth - An OAuth authentication library for Qt.
 *
 * Author: Johan Paul (johan.paul@d-pointer.com)
 *         http://www.d-pointer.com
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  KQOAuth is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  In addition, as a special exception, KQOauth provides you certain additional
 *  rights. These rights are described in the Nokia Qt LGPL Exception
 *  version 1.1, included in the file LGPL_EXCEPTION.txt in this package. 
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with KQOAuth.  If not, see <http://www.gnu.org/licenses/>
 */
#ifndef KQOAUTHGLOBALS_H
#define KQOAUTHGLOBALS_H

#include <QtCore/qglobal.h>

#if defined(KQOAUTH)
#  define KQOAUTH_EXPORT Q_DECL_EXPORT
#else
#  define KQOAUTH_EXPORT Q_DECL_IMPORT
#endif

//////////// Static constant definitions ///////////
const QString OAUTH_KEY_CONSUMER("oauth_consumer");
const QString OAUTH_KEY_CONSUMER_KEY("oauth_consumer_key");
const QString OAUTH_KEY_TOKEN("oauth_token");
const QString OAUTH_KEY_TOKEN_SECRET("oauth_token_secret");
const QString OAUTH_KEY_SIGNATURE_METHOD("oauth_signature_method");
const QString OAUTH_KEY_TIMESTAMP("oauth_timestamp");
const QString OAUTH_KEY_NONCE("oauth_nonce");
const QString OAUTH_KEY_SIGNATURE("oauth_signature");
const QString OAUTH_KEY_CALLBACK("oauth_callback");
const QString OAUTH_KEY_VERIFIER("oauth_verifier");
const QString OAUTH_KEY_VERSION("oauth_version");
const QString OAUTH2_KEY_CLIENT_ID("client_id");
const QString OAUTH2_KEY_CLIENT_SECRET("client_secret");
const QString OAUTH2_KEY_REDIRECT_URI("redirect_uri");
const QString OAUTH2_KEY_RESPONSE_TYPE("response_type");

#endif // KQOAUTHGLOBALS_H
