/**
 * KQOAuth - An OAuth authentication library for Qt.
 *
 * Author: Johan Paul (johan.paul@d-pointer.com)
 *         http://www.d-pointer.com
 *         This file: Kyle Fowler
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
 *  along with KQOAuth.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef KQOAUTH2REQUEST_H
#define KQOAUTH2REQUEST_H

#include "kqoauthrequest.h"
#include "kqoauthrequest_1.h"

class KQOAuth2Request_Private;
class KQOAUTH_EXPORT KQOAuth2Request : public KQOAuthRequest
{
    Q_OBJECT
public:
    KQOAuth2Request(QObject *parent = 0);

    /**
     * These methods can be overridden in child classes which are different types of
     * OAuth requests.
     */
    // Validate the request of this type.
    bool isValid() const;
    void initRequest(KQOAuthRequest::RequestType type, const QUrl &requestEndpoint);

private:
    KQOAuth2Request_Private * const d_ptr;
};

#endif // KQOAUTHREQUEST_XAUTH_H
