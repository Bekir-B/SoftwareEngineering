#ifndef TICKET_CANCELLATION_H
#define TICKET_CANCELLATION_H

#include <QMainWindow>

namespace Ui {
class Ticket_Cancellation;
}

class Ticket_Cancellation : public QMainWindow
{
    Q_OBJECT

public:
    explicit Ticket_Cancellation(QWidget *parent = 0);
    ~Ticket_Cancellation();

private slots:
    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Ticket_Cancellation *ui;
};

#endif // TICKET_CANCELLATION_H
