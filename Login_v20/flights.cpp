#include "flights.h"
#include "ui_flights.h"
#include <QStandardItemModel>
Flights::Flights(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Flights)
{
    ui->setupUi(this);


     QSqlQuery qry;
     QString a;
     if(qry.exec("select source from flight")){

         while(qry.next()){

             a=qry.value(0).toString();
             ui->comboBox->addItem(a);
             int row = ui->comboBox->findText( "Select" );
             qobject_cast<QStandardItemModel *>(ui->comboBox->model())->item( row )->setEnabled( false );
         }

     }
     QSqlQuery qry2;
     QString a2;
     if(qry2.exec("select destination from flight")){

         while(qry2.next()){

             a2=qry2.value(0).toString();
             ui->comboBox_2->addItem(a2);
             int row = ui->comboBox_2->findText( "Select" );
             qobject_cast<QStandardItemModel *>(ui->comboBox_2->model())->item( row )->setEnabled( false );
         }

     }

     QSqlQuery qry3;
     QString a3;
     if(qry3.exec("select departure from flight")){

         while(qry3.next()){

             a3=qry3.value(0).toString();
             ui->comboBox_3->addItem(a3);
             int row = ui->comboBox_3->findText( "Select" );
             qobject_cast<QStandardItemModel *>(ui->comboBox_3->model())->item( row )->setEnabled( false );
         }

     }
     QSqlQuery qry4;
     QString a4;
     if(qry4.exec("select departure_date from flight")){

         while(qry4.next()){

             a4=qry4.value(0).toString();
             ui->comboBox_4->addItem(a4);
             int row = ui->comboBox_4->findText( "Select" );
             qobject_cast<QStandardItemModel *>(ui->comboBox_4->model())->item( row )->setEnabled( false );
         }

     }

}

Flights::~Flights()
{
    delete ui;
}

void Flights::on_pushButton_3_clicked()
{
    QSqlQuery qry;
    QString a,b,c,d,e;
    a=ui->comboBox->currentText();
    b=ui->comboBox_2->currentText();
    c=ui->comboBox_3->currentText();
    d=ui->comboBox_4->currentText();

    if(qry.exec("select flight_id,airport_name,arrival,duration,total_seats from flight where source='"+a+"' and destination='"+b+"' and departure='"+c+"' and departure_date='"+d+"'")){
        if(qry.next()==true){

            e=qry.value(0).toString();
            ui->label_flight_ID->setText(e);

            e=qry.value(1).toString();
            ui->label_airport_name->setText(e);

            e=qry.value(2).toString();
            ui->label_arrivalTime->setText(e);

            e=qry.value(3).toString();
            ui->label_duration->setText(e);

            e=qry.value(4).toString();
            ui->label_totalSeats->setText(e);

        }//end second if
        else
        {
        ui->label_flight_ID->setText("No data");
        ui->label_airport_name->setText("No data");
        ui->label_arrivalTime->setText("No data");
        ui->label_duration->setText("No data");
        ui->label_totalSeats->setText("No data");
        }//end else
        }
    }

void Flights::on_pushButton_2_clicked()
{
    //close();
    add = new adminAddFlight(this);

    add->show();

}


void Flights::on_pushButton_5_clicked()
{
    //close();
    edit = new adminEditFlight(this);

    edit->show();
}

void Flights::on_pushButton_4_clicked()
{
    edit = new adminEditFlight(this);

    edit->show();
}
