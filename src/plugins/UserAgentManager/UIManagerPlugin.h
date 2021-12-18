/* QupZilla-Qt (2021) http://github.com/dualword/QupZilla-Qt License:GNU GPL*/

#ifndef SRC_PLUGINS_USERAGENTMANAGER_UIMANAGERPLUGIN_H_
#define SRC_PLUGINS_USERAGENTMANAGER_UIMANAGERPLUGIN_H_

#include "plugininterface.h"

class AbstractButtonInterface;
class BrowserWindow;

class UIManagerPlugin : public QObject, public PluginInterface {
    Q_OBJECT
    Q_INTERFACES(PluginInterface)
    Q_PLUGIN_METADATA(IID "QupZilla.Browser.plugin.UAManagerPlugin")

public:
	explicit UIManagerPlugin();
    PluginSpec pluginSpec();
    void init(InitState state, const QString &settingsPath);
    void unload();
    bool testPlugin();
    QTranslator* getTranslator(const QString &locale);

public slots:
    void mainWindowCreated(BrowserWindow* window);
    void mainWindowDeleted(BrowserWindow* window);
    void updateSettings();

private slots:
	void showSettings();

private:
    AbstractButtonInterface* createStatusBarIcon(BrowserWindow* mainWindow);
    QHash<BrowserWindow*, AbstractButtonInterface*> m_SBIcons;
};

#endif /* SRC_PLUGINS_USERAGENTMANAGER_UIMANAGERPLUGIN_H_ */
