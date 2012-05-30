#include "notificationitem.h"
#include "ui_notificationitem.h"

NotificationItem::NotificationItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NotificationItem)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_X11NetWmWindowTypeNotification, true);

    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    ui->bodyLabel->setMaximumWidth(width());
}

NotificationItem::~NotificationItem()
{
    delete ui;
}

void NotificationItem::setSummary(const QString& summary)
{
    ui->summaryLabel->setVisible(!summary.isEmpty());
    ui->summaryLabel->setText(summary);
    adjustSize();
}

void NotificationItem::setBody(const QString& body)
{
    ui->bodyLabel->setVisible(!body.isEmpty());
    ui->bodyLabel->setText(body);
    adjustSize();
}
