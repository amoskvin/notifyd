#ifndef NOTIFYD_H
#define NOTIFYD_H

#include <QtCore/QString>
#include <QtCore/QObject>
#include <QtCore/QVariantMap>
#include <QtCore/QStringList>

#include "notificationitem.h"

/*
 * Class for interface org.freedesktop.Notifications
 */
class Notifyd: public QObject
{
    Q_OBJECT

public:
    explicit Notifyd(QObject* parent = 0);
    virtual ~Notifyd();

public slots:
    void CloseNotification(uint id);
    QStringList GetCapabilities();
    QString GetServerInformation(QString& vendor, QString& version, QString& spec_version);
    uint Notify(const QString& app_name,
                uint replaces_id,
                const QString& app_icon,
                const QString& summary,
                const QString& body,
                const QStringList& actions,
                const QVariantMap& hints,
                int expire_timeout);
signals:
    void ActionInvoked(uint in0, const QString& in1);
    void NotificationClosed(uint in0, uint in1);

private:
    uint mId;
    QMap<uint, NotificationItem*> itemMap;
};

#endif // NOTIFYD_H
