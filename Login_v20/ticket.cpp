#include "ticket.h"
#include "ui_ticket.h"
#include <QStandardItemModel>
#include "database.h"
#include <QSql>
#include <QSqlQuery>

Ticket::Ticket(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Ticket)
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
             int row = ui->comboBox_2->findText( "Select" ); // SELECT
             qobject_cast<QStandardItemModel *>(ui->comboBox_2->model())->item( row )->setEnabled( false );
         }

     }





     QSqlQuery qry7;

          if(qry7.exec("select * from customer where isLoggedIn=1"))
              {
                 qry7.first();
                  ui->label_->setText(qry7.value(3).toString());
                  ui->label_3->setText(qry7.value(4).toString());
                  ui->label_15->setText(qry7.value(7).toString());
                  ui->label_16->setText(qry7.value(5).toString());
                  ui->label_17->setText(qry7.value(6).toString());
                  ui->label_18->setText("No Data");
                  ui->label_20->setText(qry7.value(0).toString());


          }



}

Ticket::~Ticket()
{
    delete ui;
}



void Ticket::on_pushButton_2_clicked()
{
    //QSqlQuery qry;
    QString a,b,c;
    a=ui->comboBox->currentText();
    b=ui->comboBox_2->currentText();


   // Table
        database conn;
        QSqlQueryModel* model = new QSqlQueryModel();
        QSqlQuery *qry = new QSqlQuery(conn.db);
        qry->prepare("select * from flight where source='"+a+"' and destination='"+b+"'");
        qry->exec();
        model->setQuery(*qry);
        ui->tableView->setModel(model);


}

void Ticket::on_pushButton_clicked()
{
    QString seat_no, customer_id, flight_id, source, destination, departure, departure_date,Cls,price;


    bool sn,ci,fi,s,d,depT,depD,cl,pr=false;

    //seat_no
        seat_no=ui->lineEdit->text();

        if(seat_no.length()>=1 && seat_no.length()<151){
            sn=true;
        }

        else
            sn=false;

      //customer_id

        customer_id=ui->label_20->text();
        if(customer_id.length()>=1 && customer_id.length()<101){
            ci=true;
        }

        else
            ci=false;

        //flight_id


        flight_id=ui->label_19->text();
        if(flight_id.length()>=1 && flight_id.length()<101){
            fi=true;
        }

        else
            fi=false;



        //source


        source=ui->comboBox->currentText();
        if(source.length()>=1 && source.length()<101){
            s=true;
        }

        else
            s=false;


        //destination


                destination=ui->comboBox_2->currentText();
                if(destination.length()>=1 && destination.length()<101){
                    d=true;
                }

                else
                    d=false;

        //departure


                departure=ui->label_24->text();
                if(departure.length()>=1 && departure.length()<101){
                    depT=true;
                }

                else
                    depT=false;


           //departure_date


                departure_date=ui->label_25->text();
                if(departure_date.length()>=1 && departure_date.length()<101){
                   depD=true;
                        }

                        else
                    depD=false;


                //Cls


                     Cls=ui->label_12->text();
                     if(Cls.length()>=1 && Cls.length()<101){
                       cl=true;
                             }

                             else
                        cl=false;


                     //price


                          price=ui->label_28->text();
                          if(price.length()>=1 && price.length()<10001){
                             pr=true;
                                  }

                                  else
                              pr=false;

  if(sn==true && ci==true && fi==true && s==true && d==true && depT==true && depD==true && cl==true && pr==true){

   QSqlQuery qry1;

if(qry1.exec("insert into ticket (seat_no, customer_id, flight_id, source, destination, departure, departure_date,class, price) values ('"+seat_no+"','"+customer_id+"','"+flight_id+"','"+source+"','"+destination+"','"+departure+"','"+departure_date+"','"+Cls+"', '"+price+"') ")){



        close();
        p=new payment(this);
        p->show();

}
  }
else
      ui->label_26->setText("Please enter all data correctly");
}



void Ticket::on_tableView_activated(const QModelIndex &index)
{
    QString val = ui->tableView->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select flight_id, class, departure, departure_date, price from flight where flight_id='"+val+"'");
    if(qry.exec( ))
        {

        while(qry.next())
        {
            qry.first();
            ui->label_19->setText(qry.value(0).toString());
            ui->label_12->setText(qry.value(1).toString());
            ui->label_24->setText(qry.value(2).toString());
            ui->label_25->setText(qry.value(3).toString());
            ui->label_28->setText(qry.value(4).toString());
        }
}
}
