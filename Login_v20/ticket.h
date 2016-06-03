#ifndef TICKET_H
#define TICKET_H

#include <QMainWindow>
#include <QtSql>
#include <payment.h>
#include "database.h"
namespace Ui {
class Ticket;
}

class Ticket : public QMainWindow
{
    Q_OBJECT

public:
    explicit Ticket(QWidget *parent = 0);
    ~Ticket();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_tableView_activated(const QModelIndex &index);

private:
    Ui::Ticket *ui;
    Ticket *t;
    payment *p;
};

#endif // TICKET_H
