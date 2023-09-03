/* QupZilla-Qt (2023) http://github.com/dualword/QupZilla-Qt License:GNU GPL*/

#ifndef SRC_PLUGINS_NETWORKTRAFFIC_SRC_NETWORKINTERCEPTOR_H_
#define SRC_PLUGINS_NETWORKTRAFFIC_SRC_NETWORKINTERCEPTOR_H_

#include "urlinterceptor.h"

#include <QWebEngineUrlRequestInterceptor>

class NetworkInterceptor : public UrlInterceptor {
    Q_OBJECT

public:
	explicit NetworkInterceptor(QObject *p = Q_NULLPTR);
	virtual ~NetworkInterceptor();

public:
    void interceptRequest(QWebEngineUrlRequestInfo &info) Q_DECL_OVERRIDE;

signals:
	void newRequest(const QString&, const QString&, const QString&);

};

#endif /* SRC_PLUGINS_NETWORKTRAFFIC_SRC_NETWORKINTERCEPTOR_H_ */
