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
#include <QTcpSocket>
#include <QStringList>
#include <QUrl>
#include <QFile>

#include "kqoauthauthreplyserver.h"
#include "kqoauthauthreplyserver_p.h"

KQOAuthAuthReplyServerPrivate::KQOAuthAuthReplyServerPrivate(KQOAuthAuthReplyServer *parent):
    q_ptr(parent)
{

}

KQOAuthAuthReplyServerPrivate::~KQOAuthAuthReplyServerPrivate()
{

}

void KQOAuthAuthReplyServerPrivate::onIncomingConnection() {
    Q_Q(KQOAuthAuthReplyServer);
    qDebug() << "Incoming Connection";
    socket = q->nextPendingConnection();
    connect(socket, SIGNAL(readyRead()),
            this, SLOT(onBytesReady()), Qt::UniqueConnection);
}

void KQOAuthAuthReplyServerPrivate::onBytesReady() {
    Q_Q(KQOAuthAuthReplyServer);
    qDebug() << "Socket peer host address: " << socket->peerAddress();
    QByteArray reply;
    QByteArray content;
    QFile file(localFile);
	 if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {

	 } else {
		 qDebug() << "first url worked";
		 QTextStream in(&file);
		 while (!in.atEnd()) {
			 QString line = in.readLine();
			 qDebug() << line;
		 }
	 }

	 QByteArray data = socket->readAll();
	 qDebug()<< "Query Data: " << data;
	 QMultiMap<QString, QString> queryParams = parseQueryParams(&data);
	 if(queryParams.size() == 0 && !handlingRedirect) { //assume theres a hash and do the redirect hack
		 handlingRedirect = true;
		 content.append("<HTML><head><script type=\"text/javascript\">var str='http://'+window.location.host + '?' + window.location.hash.substring(1); window.location=str;</script></head><h1>Account authorized, go ahead back to the tumblr app and start your experience!</h1></HTML>");
	 } else {
		 handlingRedirect = false;
		 //TODO then send down the local file if there is one
		 content.append("<HTML><h1>Account linked, go ahead back to the app and check the status!</h1></HTML>");
	 }

    reply.append("HTTP/1.0 200 OK \r\n");
    reply.append("Content-Type: text/html; charset=\"utf-8\"\r\n");
    reply.append(QString("Content-Length: %1\r\n").arg(content.size()));
    reply.append("\r\n");
    reply.append(content);
    socket->write(reply);

    if(!handlingRedirect) {
    	socket->disconnectFromHost();
    	q->close();
    	emit q->verificationReceived(queryParams);
    }
}

QMultiMap<QString, QString> KQOAuthAuthReplyServerPrivate::parseQueryParams(QByteArray *data) {
    QString splitGetLine = QString(*data).split("\r\n").first();   // Retrieve the first line with query params.
    splitGetLine.remove("GET ");                                   // Clean the line from GET
    splitGetLine.remove("HTTP/1.1");                               // From HTTP
    splitGetLine.remove("\r\n");                                   // And from rest.
    splitGetLine.prepend("http://localhost");                      // Now, make it a URL

    QUrl getTokenUrl(splitGetLine);
    QList< QPair<QString, QString> > tokens = getTokenUrl.queryItems();  // Ask QUrl to do our work.

    QMultiMap<QString, QString> queryParams;
    QPair<QString, QString> tokenPair;
    foreach (tokenPair, tokens) {
        queryParams.insert(tokenPair.first.trimmed(), tokenPair.second.trimmed());
    }

    return queryParams;
}



KQOAuthAuthReplyServer::KQOAuthAuthReplyServer(QObject *parent) :
    QTcpServer(parent),
    d_ptr( new KQOAuthAuthReplyServerPrivate(this) )
{
    Q_D(KQOAuthAuthReplyServer);

    connect(this, SIGNAL(newConnection()),
            d, SLOT(onIncomingConnection()));
}

KQOAuthAuthReplyServer::~KQOAuthAuthReplyServer()
{
    delete d_ptr;
}


void KQOAuthAuthReplyServer::setSuccessHtmlFile(QString filePath) {
	Q_D(KQOAuthAuthReplyServer);
	d->localFile = filePath;
}


