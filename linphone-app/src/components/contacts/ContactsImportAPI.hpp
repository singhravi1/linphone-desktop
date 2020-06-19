#ifndef CONTACTSIMPORTAPI_HPP
#define CONTACTSIMPORTAPI_HPP

#include <QObject>
#include <QtNetwork>
#include "ContactsImportDataAPI.hpp"

class ContactsImportAPI : public QObject
{
Q_OBJECT
public:
	ContactsImportAPI(ContactsImportDataAPI * pData);
	virtual ~ContactsImportAPI();
	QString prepareRequest()const;

	void request();

	QPointer<QNetworkReply> mNetworkReply;
	QNetworkAccessManager mManager;
	
private:
	void handleReadyData();
	void handleFinished ();
	void handleError (QNetworkReply::NetworkError code);
	void handleSslErrors (const QList<QSslError> &errors);

	ContactsImportDataAPI * mData;
	QByteArray mBuffer;
};

#endif // CONTACTSIMPORTAPI_HPP
