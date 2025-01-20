/* QupZillKa (2023-2025) https://github.com/dualword/QupZillKa License:GNU GPL v3*/
#include "NetworkTraffic.h"

#include "NetworkTrafficSidebar.h"
#include "browserwindow.h"
#include "webview.h"
#include "pluginproxy.h"
#include "mainapplication.h"
#include "sidebar.h"
#include "webhittestresult.h"

#include <QTranslator>

NetworkTraffic::NetworkTraffic() : QObject() {

}

//NetworkTraffic::~NetworkTraffic() {

//}

PluginSpec NetworkTraffic::pluginSpec()
{
    PluginSpec spec;
    spec.name = "Network Traffic Plugin";
    spec.info = "Network Traffic plugin";
    spec.description = "Shows network traffic in side panel";
    spec.version = "0.1.0";
    spec.author = "";
    spec.icon = QPixmap(":qupzilla.png");
    spec.hasSettings = false;
    return spec;
}

void NetworkTraffic::init(InitState state, const QString &settingsPath) {
    Q_UNUSED(state); Q_UNUSED(settingsPath);
    mApp->plugins()->registerAppEventHandler(PluginProxy::MousePressHandler, this);
    m_sideBar = new NetworkTrafficSidebar(this);
    SideBarManager::addSidebar("networktraffic-sidebar", m_sideBar);
}

void NetworkTraffic::unload() {
    SideBarManager::removeSidebar(m_sideBar);
    delete m_sideBar;
}

bool NetworkTraffic::testPlugin() {
    return (Qz::VERSION == QLatin1String(QUPZILLA_VERSION));
}

QTranslator* NetworkTraffic::getTranslator(const QString &locale) {
    QTranslator* translator = new QTranslator(this);
    translator->load(locale, ":/networrktrafficplugin/locale/");
    return translator;
}
