/* QupZillKa (2023) http://github.com/dualword/QupZillKa License:GNU GPL version 3*/

#include "NetworkInterceptor.h"
#include "networkurlinterceptor.h"
#include "networkmanager.h"
#include "mainapplication.h"

NetworkInterceptor::NetworkInterceptor(QObject* p) : UrlInterceptor(p) {
	mApp->networkManager()->installUrlInterceptor(this);
}

NetworkInterceptor::~NetworkInterceptor() {
    mApp->networkManager()->removeUrlInterceptor(this);
}

void NetworkInterceptor::interceptRequest(QWebEngineUrlRequestInfo &info) {
	if(info.firstPartyUrl().toString().length() <= 0) return;
	emit newRequest(QString(info.requestMethod()), info.firstPartyUrl().toString(), info.requestUrl().toString());
}
