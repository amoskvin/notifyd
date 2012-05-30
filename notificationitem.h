#ifndef NOTIFICATIONITEM_H
#define NOTIFICATIONITEM_H

#include <QWidget>

namespace Ui {
class NotificationItem;
}

class NotificationItem : public QWidget
{
    Q_OBJECT
    
public:
    explicit NotificationItem(QWidget* parent = 0);
    ~NotificationItem();

    void setSummary(const QString& summary);
    void setBody(const QString& body);

    
private:
    Ui::NotificationItem* ui;
};

#endif // NOTIFICATIONITEM_H
