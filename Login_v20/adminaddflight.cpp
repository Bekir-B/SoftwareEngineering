#include "adminaddflight.h"
#include "ui_adminaddflight.h"
#include <QStandardItemModel>

adminAddFlight::adminAddFlight(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::adminAddFlight)
{
    ui->setupUi(this);
    QSqlQuery qry;
    QString a;

     if(qry.exec("select airport_name from airport")){
     while(qry.next()){


         a=qry.value(0).toString();
         ui->comboBox->addItem(a);
         int row = ui->comboBox->findText( "Select" );
         qobject_cast<QStandardItemModel *>(ui->comboBox->model())->item( row )->setEnabled( false );
     }
}

}

adminAddFlight::~adminAddFlight()
{
    delete ui;
}



void adminAddFlight::on_pushButton_2_clicked()
{



    QString source, destination, departure_date, departure,  arrival, duration, seats, airport_name;


    bool s=false,d=false,depD=false,depT=false,a=false,dur=false,seat=false,an=false;


    //airport_name from comboBOX
    airport_name=ui->comboBox->currentText();
    an=true;

    //source check
    source = ui->lineEdit_source->text();
    if(source.length()>=1&&source.length()<101){
        s=true;
    }
    else
        s=false;


    //destination
    destination = ui->lineEdit_destination->text();
    if(destination.length()>=1&& destination.length()<101){
        d=true;
    }
    else
        d=false;

    //departure_date
    departure_date = ui->lineEdit_departureD->text();
    if(departure_date.length()>=1 && departure_date.length()<100){
        depD=true;
    }
    else
        depD=false;

    //departure
   departure = ui->lineEdit_departureT->text();
    if(departure.length()>=1 && departure.length()<100){
        depT=true;
    }
    else
        depT=false;


    //arrival
   arrival = ui->lineEdit_arrivalT->text();
    if(arrival.length()>=1 && arrival.length()<100){
        a=true;
    }
    else
        a=false;


    //duration
   duration = ui->lineEdit_duration->text();
    if(duration.length()>=1 && duration.length()<100){
        dur=true;
    }
    else
        dur=false;



        //seats
       seats = ui->lineEdit_totalSeats->text();
        if(seats.length()>=1 && seats.length()<1001){
            seat=true;
        }
        else
            seat=false;


    if(s==true && d==true && depD==true && depT==true && a==true && dur==true && seat==true && an==true){

    QSqlQuery qry1;

    if(qry1.exec("insert into flight (source, destination, departure_date, departure, arrival, duration, total_seats, airport_name) values ('"+source+"','"+destination+"','"+departure_date+"','"+departure+"','"+arrival+"','"+duration+"','"+seats+"', '"+airport_name+"')")){

ui->label->setText("Added");


    }

    else
         ui->label->setText("Error");
  }
    if(s==false||d==false||depD==false||depT==false||a==false||dur==false || seat==false){
        ui->label->setText("Please enter data correctly");
    }
}



void adminAddFlight::on_pushButton_3_clicked()
{
    database conn;
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery *qry = new QSqlQuery(conn.db);
    qry->prepare("select * from flight");
    qry->exec();
    model->setQuery(*qry);
    ui->tableView->setModel(model);

}



void adminAddFlight::on_tableView_activated(const QModelIndex &index)
{

    QString val = ui->tableView->model()->data(index).toString();

    QSqlQuery qry;
    qry.prepare("select * from flight where flight_id='"+val+"'");
    if(qry.exec( ))
        {

        while(qry.next())
        {


    ui->lineEdit_source->setText(qry.value(2).toString());
    ui->lineEdit_destination->setText(qry.value(3).toString());
    ui->lineEdit_departureD->setText(qry.value(4).toString());
    ui->lineEdit_departureT->setText(qry.value(5).toString());
    ui->lineEdit_arrivalT->setText(qry.value(6).toString());
    ui->lineEdit_duration->setText(qry.value(7).toString());
    ui->lineEdit_totalSeats->setText(qry.value(8).toString());
    ui->comboBox->setCurrentText(qry.value(0).toString());
}

    }
}
