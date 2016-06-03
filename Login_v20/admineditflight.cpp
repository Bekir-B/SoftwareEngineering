#include "admineditflight.h"
#include "ui_admineditflight.h"

adminEditFlight::adminEditFlight(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::adminEditFlight)
{
    ui->setupUi(this);


}

adminEditFlight::~adminEditFlight()
{
    delete ui;
}

void adminEditFlight::on_pushButton_3_clicked()
{
    database conn;
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery *qry = new QSqlQuery(conn.db);
    qry->prepare("select * from flight");
    qry->exec();
    model->setQuery(*qry);
    ui->tableView->setModel(model);
}

void adminEditFlight::on_tableView_activated(const QModelIndex &index)
{
    QString val = ui->tableView->model()->data(index).toString();

    QSqlQuery qry;
    qry.prepare("select * from flight where flight_id='"+val+"'");
    if(qry.exec( ))
        {

        while(qry.next())
        {

            ui->lineEdit->setText(qry.value(2).toString());
            ui->lineEdit_2->setText(qry.value(3).toString());
            ui->lineEdit_3->setText(qry.value(4).toString());
            ui->lineEdit_4->setText(qry.value(5).toString());
            ui->lineEdit_5->setText(qry.value(6).toString());
            ui->lineEdit_6->setText(qry.value(7).toString());
            ui->lineEdit_7->setText(qry.value(8).toString());
            ui->label_id->setText(qry.value(0).toString());



        }

    }
}

void adminEditFlight::on_pushButton_clicked()
{
    QString Source, Destination, Departure, Arrival, Seats, Duration, Depart_Date, flight_ID;

    bool src=false,dst=false,dpt=false,arv=false,sts=false,drt=false, dpt_date=false;

    flight_ID = ui->label_id->text();

    //source check
    Source = ui->lineEdit->text();
    if(Source.length()>=1&&Source.length()<101){
        src=true;
    }
    else
        src=false;

    /*Airport_name=ui->comboBox->currentText();
    aptname=true;*/

    //destination check
    Destination = ui->lineEdit_2->text();
    if(Destination.length()>=1&&Destination.length()<101){
        dst=true;
    }
    else
        dst=false;

    //departure check
    Departure = ui->lineEdit_3->text();
    if(Departure.length()>=1&&Departure.length()<101){
        dpt=true;
    }
    else
        dpt=false;

    //arrival check
    Arrival = ui->lineEdit_4->text();

    if(Arrival.length()>=1&&Arrival.length()<101){
        arv=true;
    }
    else
        arv=false;

    //seats check
    Seats = ui->lineEdit_5->text();

    if(Seats.length()>=1&&Seats.length()<1001){
        sts=true;
    }
    else
        sts=false;

    //duration
    Duration = ui->lineEdit_6->text();
    if(Duration.length()>=1&&Duration.length()<101){
        drt=true;
    }
    else
        drt=false;

    //departure date check
    Depart_Date = ui->lineEdit_7->text();
    if(Depart_Date.length()>=1&&Depart_Date.length()<=101){
        dpt_date=true;
    }
    else
        dpt_date=false;

    if(src==true && dst==true && dpt==true && drt==true && arv==true && sts==true && dpt_date==true){

        QSqlQuery qry;

        //if(qry.exec("update flight set (airport_name, source, destination, departure, arrival, duration, total_seats, departure_date) values ('"+Airport_name+"','"+Source+"','"+Destination+"','"+Departure+"','"+Arrival+"','"+Duration+"','"+Seats+"', '"+Depart_Date+"')")){
        if(qry.exec("update flight set source='"+Source+"', destination='"+Destination+"', departure='"+Departure+"', arrival='"+Arrival+"', duration='"+Duration+"', total_seats='"+Seats+"', departure_date= '"+Depart_Date+"' where flight_id ='"+flight_ID+"'")){
            ui->label_status->setText("Updated successfully");

            //qApp->quit();
            //QProcess::startDetached(qApp->arguments()[0], qApp->arguments());

        }
        else

            ui->label_status->setText("Not successful");

            //ui->label_8->setText(age);
    }//end if both true

    if(src==false||dst==false||dpt==false||arv==false||drt==false||sts==false||dpt_date==false){
        ui->label_status->setText("Please enter all the values correctly");
    }
}

void adminEditFlight::on_pushButton_2_clicked()
{
    QString flight_id;
    flight_id = ui->label_id->text();
    QSqlQuery qry;
    if(qry.exec("delete from flight where flight_id='"+flight_id+"'")){
        ui->label_status->setText("Removed successfully");

    }
    else
        ui->label_status->setText("Not Removed");
}
