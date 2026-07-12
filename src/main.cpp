#include <QApplication>
#include <QIcon>
#include "FreezerWindow.h"

int main(int argc, char *argv[])
{
    // Wayland-friendly
    qputenv("QT_QPA_PLATFORM", QByteArray("wayland"));

    QApplication app(argc, argv);
    app.setOrganizationName("Freezer");
    app.setApplicationName("Freezer");

    FreezerWindow w;
    w.show();

    return app.exec();
}
