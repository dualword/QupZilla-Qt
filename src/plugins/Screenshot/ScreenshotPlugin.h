/* QupZillKa (2021-2024) http://github.com/dualword/QupZillKa License:GNU GPL v3*/

#ifndef SRC_PLUGINS_SCREENSHOT_SCREENSHOTPLUGIN_H_
#define SRC_PLUGINS_SCREENSHOT_SCREENSHOTPLUGIN_H_

#include "plugininterface.h"

class ScreenshotPlugin : public QObject, public PluginInterface{
    Q_OBJECT
    Q_INTERFACES(PluginInterface)
    Q_PLUGIN_METADATA(IID "QupZilla.Browser.plugin.ScreenshotPlugin")

public:
	explicit ScreenshotPlugin();
    PluginSpec pluginSpec();
    void init(InitState state, const QString &settingsPath);
    void unload() {};
    bool testPlugin();
    void populateWebViewMenu(QMenu* menu, WebView* view, const WebHitTestResult &r);

private slots:
	void takeScreenshot();

private:
    WebView* m_view;


};

#endif /* SRC_PLUGINS_SCREENSHOT_SCREENSHOTPLUGIN_H_ */
