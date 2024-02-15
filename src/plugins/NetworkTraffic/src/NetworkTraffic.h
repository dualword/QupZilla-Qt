/* QupZillKa (2023) http://github.com/dualword/QupZillKa License:GNU GPL version 3*/

#ifndef SRC_PLUGINS_NETWORKTRAFFIC_SRC_NETWORKTRAFFIC_H_
#define SRC_PLUGINS_NETWORKTRAFFIC_SRC_NETWORKTRAFFIC_H_

#include "plugininterface.h"
#include <QLabel>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QPointer>

class NetworkTrafficSidebar;

class NetworkTraffic : public QObject, public PluginInterface {
    Q_OBJECT
    Q_INTERFACES(PluginInterface)
    Q_PLUGIN_METADATA(IID "QupZilla.Browser.plugin.NetworkTraffic")

public:
	explicit NetworkTraffic();
	//virtual ~NetworkTraffic();
    PluginSpec pluginSpec();

    void init(InitState state, const QString &settingsPath);
    void unload();
    bool testPlugin();
    QTranslator* getTranslator(const QString &locale);

private:
    NetworkTrafficSidebar *m_sideBar = nullptr;
};

#endif /* SRC_PLUGINS_NETWORKTRAFFIC_SRC_NETWORKTRAFFIC_H_ */
