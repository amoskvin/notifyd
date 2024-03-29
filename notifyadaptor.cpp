/*
 * This file was generated by qdbusxml2cpp version 0.7
 * Command line was: qdbusxml2cpp -v -c NotifyAdaptor -a notifyadaptor.h:notifyadaptor.cpp -l Notifyd -i notifyd.h notifications.xml
 *
 * qdbusxml2cpp is Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#include "notifyadaptor.h"
#include <QtCore/QMetaObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QStringList>
#include <QtCore/QVariant>

/*
 * Implementation of adaptor class NotifyAdaptor
 */

NotifyAdaptor::NotifyAdaptor(Notifyd *parent)
    : QDBusAbstractAdaptor(parent)
{
    // constructor
    setAutoRelaySignals(true);
}

NotifyAdaptor::~NotifyAdaptor()
{
    // destructor
}

void NotifyAdaptor::CloseNotification(uint id)
{
    // handle method call org.freedesktop.Notifications.CloseNotification
    parent()->CloseNotification(id);
}

QStringList NotifyAdaptor::GetCapabilities()
{
    // handle method call org.freedesktop.Notifications.GetCapabilities
    return parent()->GetCapabilities();
}

QString NotifyAdaptor::GetServerInformation(QString &vendor, QString &version, QString &spec_version)
{
    // handle method call org.freedesktop.Notifications.GetServerInformation
    return parent()->GetServerInformation(vendor, version, spec_version);
}

uint NotifyAdaptor::Notify(const QString &app_name, uint replaces_id, const QString &app_icon, const QString &summary, const QString &body, const QStringList &actions, const QVariantMap &hints, int expire_timeout)
{
    // handle method call org.freedesktop.Notifications.Notify
    return parent()->Notify(app_name, replaces_id, app_icon, summary, body, actions, hints, expire_timeout);
}

