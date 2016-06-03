#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QSqlQuery qry1;
    if(qry1.exec("update customer set isLoggedIn=0 where isLoggedIn=1")){
        qDebug()<<"Success";
        qApp->quit();
        QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
    }
}


void MainWindow::on_actionFlights_triggered()
{
    f = new Flights(this);
    f ->show();
}

void MainWindow::on_actionTicket_2_triggered()
{
    t = new Ticket (this);
    t ->show();
}

void MainWindow::on_actionDetails_triggered()
{
    c = new Customer_Details (this);
    c ->show();
}

void MainWindow::on_actionCancel_Ticket_triggered()
{
    ct = new Ticket_Cancellation(this);
    ct -> show ();
}
