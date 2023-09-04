/* QupZilla-Qt (2023) http://github.com/dualword/QupZilla-Qt License:GNU GPL*/

#include "networkurlinterceptor.h"
#include "NetworkInterceptor.h"
#include "networkmanager.h"
#include "NetworkTrafficSidebar.h"
#include "mainapplication.h"

#include <QtWidgets>

NetworkTrafficSidebar::NetworkTrafficSidebar(QObject* p) : SideBarInterface(p), w(0), net(0) {

}

NetworkTrafficSidebar::~NetworkTrafficSidebar() {

}

QString NetworkTrafficSidebar::title() const {
    return tr("Network Traffic");
}

QAction* NetworkTrafficSidebar::createMenuAction() {
    QAction* act = new QAction(tr("Network Traffic Sidebar"), this);
    act->setCheckable(true);
    return act;
}

QWidget* NetworkTrafficSidebar::createSideBarWidget(BrowserWindow* mainWindow) {
    Q_UNUSED(mainWindow)

	w = new QWidget();
	net = new NetworkInterceptor(w);
	QObject::connect(net, SIGNAL(newRequest(const QString&,const QString&,const QString&)),
			SLOT(newRequest(const QString&,const QString&,const QString&)));

    QPushButton* btn = new QPushButton("Clear", w);
    QObject::connect(btn, SIGNAL(clicked()), SLOT(clear()));
    tbl = new QTableWidget(0, 3, w);
	QStringList list;
	list.push_back("Method");
	list.push_back("From");
	list.push_back("To");
	tbl->setHorizontalHeaderLabels(list);
	tbl->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);

    QVBoxLayout* l = new QVBoxLayout(w);
    l->addWidget(btn);
    l->addWidget(tbl);
    w->setLayout(l);
    return w;
}

void NetworkTrafficSidebar::clear() {
	tbl->clearContents();
	tbl->setRowCount(0);
}

void NetworkTrafficSidebar::newRequest(const QString& s1, const QString& s2, const QString& s3){
	tbl->insertRow(tbl->rowCount());
	int row = tbl->rowCount()-1;
	QTableWidgetItem *item = new QTableWidgetItem(tr("%1").arg(s1));
	tbl->setItem(row, 0, item);
	item = new QTableWidgetItem(tr("%1").arg(s2));
	tbl->setItem(row, 1, item);
	item = new QTableWidgetItem(tr("%1").arg(s3));
	tbl->setItem(row, 2, item);
}
