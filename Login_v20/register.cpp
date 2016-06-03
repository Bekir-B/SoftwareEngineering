#include "register.h"
#include "ui_register.h"


Register::Register(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
}

Register::~Register()
{
    delete ui;
}


void Register::on_pushButton_clicked()
{

    QString UName, FName, LName, Address, PhoneNo, Password;
    QString Age;
    bool u=false,f=false,l=false,a=false,ph=false,pw=false,age=false;

    //username check
    UName = ui->lineEdit_Username->text();
    if(UName.length()>=4&&UName.length()<17){
        u=true;
    }
    else
        u=false;

    //first name
    FName = ui->lineEdit_FName->text();
    if(FName.length()>=1&&FName.length()<26){
        f=true;
    }
    else
        f=false;

    //last name
    LName = ui->lineEdit_LName->text();
    if(LName.length()>=1&&LName.length()<26){
        l=true;
    }
    else
        l=false;

    //address
    Address = ui->lineEdit_Address->text();

    if(Address.length()>=1&&Address.length()<101){
        a=true;
    }
    else
        a=false;

    //phoneNo
    PhoneNo = ui->lineEdit_PhoneNo->text();

    if(PhoneNo.length()>=9&&PhoneNo.length()<26){
        ph=true;
    }
    else
        ph=false;

    //password
    Password = ui->lineEdit_Password->text();
    if(Password.length()>=8&&Password.length()<17){
        pw=true;
    }
    else
        pw=false;

    //age
    Age = ui->spinBox_Age->text();
    if(Age.length()>=1&&Age.length()<121){
        age=true;
    }
    else
        age=false;

    if(u==true && f==true && l==true && a==true && ph==true && pw==true && age==true){

        QSqlQuery qry,qry2;
                    if(qry2.exec("select username from customer where username ='"+UName+"' ")){
                        if(qry2.next()==1)
                        ui->label_8->setText("Username already exists!");
                        else{
                            if(qry.exec("insert into customer (username, name, last_name, address, phone, password, age) values ('"+UName+"','"+FName+"','"+LName+"','"+Address+"','"+PhoneNo+"','"+Password+"', '"+Age+"')")){

            ui->label_8->setText("Registered");

            qApp->quit();
            QProcess::startDetached(qApp->arguments()[0], qApp->arguments());

        }
        else

            ui->label_8->setText("Error");

     }}
    }//end if both true

    if(f==false||l==false||a==false||ph==false||pw==false||age==false){
        ui->label_8->setText("Please enter username and password correctly");
    }



}


