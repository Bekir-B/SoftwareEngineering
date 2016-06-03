#include "payment.h"
#include "ui_payment.h"
#include <QStandardItemModel>

payment::payment(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::payment)
{
    ui->setupUi(this);


    QSqlQuery qry;
    QString a;

    if(qry.exec("select type from typeOfcc")){
    while(qry.next()){


        a=qry.value(0).toString();
        ui->comboBox->addItem(a);
        int row = ui->comboBox->findText( "Select" );
        qobject_cast<QStandardItemModel *>(ui->comboBox->model())->item( row )->setEnabled( false );
    }
}

    /*
    QString flight_id, customer_id, ticket_no, price, mode;

    bool fi, ci, tn, p, m = false;


    //flight_id

    flight_id=ui->label_13->text();
    if(flight_id.length()>=1 && flight_id.length()<101){
        fi=true;
    }

    else
        fi=false;

    //customer_id

    customer_id=ui->label_14->text();
    if(customer_id.length()>=1 && customer_id.length()<101){
        ci=true;
    }

    else
        ci=false;



    //ticket_no

    ticket_no=ui->label_15->text();
    if(ticket_no.length()>=1 && ticket_no.length()<101){
        tn=true;
    }

    else
        tn=false;


    //price

    price=ui->label_16->text();
    if(price.length()>=1 && price.length()<10001){
        p=true;
    }

    else
        p=false;
    */
}

payment::~payment()
{
    delete ui;
}


void payment::on_radioButton_clicked()
{
    ui->lineEdit->setEnabled(false);
        ui->lineEdit_2->setEnabled(false);
        ui->lineEdit_3->setEnabled(false);
        ui->lineEdit_4->setEnabled(false);
        ui->label_7->setEnabled(false);
        ui->label_8->setEnabled(false);
        ui->label_9->setEnabled(false);
        ui->label_10->setEnabled(false);
        ui->label_11->setEnabled(false);
        ui->label_12->setEnabled(false);
        ui->comboBox->setEnabled(false);
        ui->comboBox_2->setEnabled(false);
        ui->comboBox_3->setEnabled(false);

}

void payment::on_radioButton_2_clicked()
{
    ui->lineEdit->setEnabled(true);
        ui->lineEdit_2->setEnabled(true);
        ui->lineEdit_3->setEnabled(true);
        ui->lineEdit_4->setEnabled(true);
        ui->label_7->setEnabled(true);
        ui->label_8->setEnabled(true);
        ui->label_9->setEnabled(true);
        ui->label_10->setEnabled(true);
        ui->label_11->setEnabled(true);
        ui->label_12->setEnabled(true);
        ui->comboBox->setEnabled(true);
        ui->comboBox_2->setEnabled(true);
        ui->comboBox_3->setEnabled(true);
}
