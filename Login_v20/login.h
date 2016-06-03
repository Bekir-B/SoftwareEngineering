#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include "mainwindow.h"
#include "register.h"
#include "database.h"
#include "mainwindow_customer.h"
namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private slots:
    void on_pushButton_clicked();

    //void on_pushButton_released();

    void on_pushButton_2_clicked();

private:
    Ui::Login *ui;
    database db;
    MainWindow *m;
    MainWindow_Customer *mc;
    Login *l;
    Register *r;
};

#endif // LOGIN_H
