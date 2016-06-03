#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include "register.h"
#include <QDebug>
#include <database.h>

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);


}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    QString username, password;
        bool login = false;

        username = ui->lineEdit_username->text();
        password = ui->lineEdit_password->text();
        login = db.checkCustomer1(username,password);
        if(username=="admin"&&password=="12345678"){
            this->close();
            ui->label->setText("Correct");
            m = new MainWindow(this);
            m->show();
        }
        if(!login){
            QSqlQuery qry;
                        if(qry.exec("update customer set isLoggedIn=1 where username='"+username+"'")){
                            qDebug()<<"Succes";
                        }
            this->close();
            ui->label->setText("Correct");
            mc = new MainWindow_Customer(this);
            mc->show();

        }
        if(login){

            ui->label->setText("Incorrect");
        }

}


void Login::on_pushButton_2_clicked()
{
    close();
    r = new Register(this);
    r ->show();
}
