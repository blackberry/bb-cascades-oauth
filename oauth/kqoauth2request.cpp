/**
 * KQOAuth - An OAuth authentication library for Qt.
 *
 * Author: Johan Paul (johan.paul@d-pointer.com)
 *         http://www.d-pointer.com
 *
 *  KQOAuth is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  KQOAuth is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with KQOAuth.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <QtDebug>

#include "kqoauth2request_p.h"
#include "kqoauth2request.h"

/**
 * Private d_ptr implementations.
 */
KQOAuth2Request_Private::KQOAuth2Request_Private()
{

}

KQOAuth2Request_Private::~KQOAuth2Request_Private()
{
}

/**
 * Public implementations.
 */
KQOAuth2Request::KQOAuth2Request(QObject *parent) :
        KQOAuthRequest(parent),
        d_ptr(new KQOAuth2Request_Private)
{
}

bool KQOAuth2Request::isValid() const {
    // Access token must always be retrieved using the POST HTTP method.
    // And then check the validity of the XAuth request.
    // Provided by the base class as a protected method for us.
    return validateOauth2Request();
}

void KQOAuth2Request::initRequest(KQOAuthRequest::RequestType type, const QUrl &requestEndpoint) {
	KQOAuthRequest::initRequest(type,requestEndpoint);
	setRequestOAuthMethod(KQOAuthRequest::OAUTH2);
}
