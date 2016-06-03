#include "mainwindow_customer.h"
#include "ui_mainwindow_customer.h"
#include <QSqlQuery>
MainWindow_Customer::MainWindow_Customer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow_Customer)
{
    ui->setupUi(this);
}

MainWindow_Customer::~MainWindow_Customer()
{
    delete ui;
}

void MainWindow_Customer::on_actionTicket_triggered()
{
    t = new Ticket(this);
    t->show();
}



void MainWindow_Customer::on_pushButton_clicked()
{
    QSqlQuery qry1;
    if(qry1.exec("update customer set isLoggedIn=0 where isLoggedIn=1")){
        qDebug()<<"Success";
        qApp->quit();
        QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
    }
}
