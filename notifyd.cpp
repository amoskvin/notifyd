#include "notifyd.h"

#include <QtCore/QDebug>

#include <QtGui/QMessageBox>

/*
 * Implementation of class Notifyd
 */

Notifyd::Notifyd(QObject* parent)
    : QObject(parent)
{
    mId = 0;
    qDebug() << "Notifyd created";
}

Notifyd::~Notifyd()
{
    qDebug() << "Notifyd deleted";
}

void Notifyd::CloseNotification(uint id)
{
    qDebug() << QString("CloseNotification(%1);").arg(id);
}

QStringList Notifyd::GetCapabilities()
{
    QStringList caps;
    caps << "actions"
         << "body"
      // << "body-hyperlinks"
      // << "body-images"
      // << "body-markup"
      // << "icon-multi"
      // << "icon-static"
      // << "sound"
      ;
    qDebug() << QString("GetCapabilities(); =>") << caps;
    return caps;
}

QString Notifyd::GetServerInformation(QString& vendor, QString& version, QString& spec_version)
{
    //qDebug() << QString("GetServerInformation(%1, %2, %3);").arg(vendor, version, spec_version);
    qDebug() << QString("GetServerInformation(...);");
    spec_version = QString("0.9");
    version = QString("0.1");
    vendor = QString("Alec");
    return QString("notifyd");
}

uint Notifyd::Notify(const QString& app_name,
                               uint replaces_id,
                     const QString& app_icon,
                     const QString& summary,
                     const QString& body,
                 const QStringList& actions,
                 const QVariantMap& hints,
                                int expire_timeout
                     )
{
    if (++mId == 0)
        mId++;
    qDebug() << QString("Notify(\n"
                        "  app_name = %1\n"
                        "  replaces_id = %2\n"
                        "  app_icon = %3\n"
                        "  summary = %4\n"
                        "  body = %5\n"
                        ).arg(app_name, QString::number(replaces_id), app_icon, summary, body)
                     << "  actions =" << actions << endl
                     << "  hints =" << hints << endl
             << QString("  expire_timeout = %1\n) => %2").arg(QString::number(expire_timeout), QString::number(mId));

    NotificationItem* item = new NotificationItem();
    itemMap.insert(mId, item);
    item->setSummary(summary);
    item->setBody(body);
    item->show();

    return mId;
}
