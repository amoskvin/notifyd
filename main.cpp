#include <QtGui/QApplication>
#include <QtDBus/QDBusConnection>

#include "notifyadaptor.h"
#include "notifyd.h"

int main(int argc, char** argv)
{
    QApplication a(argc, argv);
    a.setQuitOnLastWindowClosed(false);
    
    Notifyd* demo = new Notifyd();
    new NotifyAdaptor(demo);

    QDBusConnection connection = QDBusConnection::sessionBus();
    bool ret = connection.registerService("org.freedesktop.Notifications");
    if (!ret)
        qDebug() << "registerService failed :(";
    ret = connection.registerObject("/org/freedesktop/Notifications", demo);
    if (!ret)
        qDebug() << "registerObject failed :(";

    qDebug() << "exec!";
    return a.exec();
}
