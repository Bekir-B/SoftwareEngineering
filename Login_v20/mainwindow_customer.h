#ifndef MAINWINDOW_CUSTOMER_H
#define MAINWINDOW_CUSTOMER_H

#include <QMainWindow>
#include <ticket.h>
namespace Ui {
class MainWindow_Customer;
}

class MainWindow_Customer : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow_Customer(QWidget *parent = 0);
    ~MainWindow_Customer();

private slots:
    void on_actionTicket_triggered();

    void on_pushButton_clicked();

private:
    Ui::MainWindow_Customer *ui;
    Ticket *t;
};

#endif // MAINWINDOW_CUSTOMER_H
