#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "flights.h"
#include "ticket.h"
#include "payment.h"
#include "customer_details.h"
#include "ticket_cancellation.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_actionFlights_triggered();

    void on_actionTicket_2_triggered();

    void on_actionDetails_triggered();

    void on_actionCancel_Ticket_triggered();

private:
    Ui::MainWindow *ui;
    Flights *f;
    Ticket *t;
    payment *p;
    Customer_Details *c;
    Ticket_Cancellation *ct;

};

#endif // MAINWINDOW_H
