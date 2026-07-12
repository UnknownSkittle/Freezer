#include "FreezerWindow.h"
#include <QWebEngineSettings>
#include <QIcon>
#include <QStandardPaths>
#include <QDir>

FreezerWindow::FreezerWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Persistent profile for login
    QString dataPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir().mkpath(dataPath);

    profile = new QWebEngineProfile(dataPath, this);
    profile->setPersistentCookiesPolicy(QWebEngineProfile::AllowPersistentCookies);

    view = new QWebEngineView(this);
    view->setPage(new QWebEnginePage(profile, view));

    setCentralWidget(view);
    setWindowTitle("Freezer");
    setWindowIcon(QIcon(":/icons/freezer.png")); // or system icon path

    // Basic settings
    auto settings = view->settings();
    settings->setAttribute(QWebEngineSettings::PluginsEnabled, true);
    settings->setAttribute(QWebEngineSettings::JavascriptEnabled, true);

    // Load Deezer
    view->load(QUrl("https://www.deezer.com/"));

    resize(1024, 640);
}
