#include "ticket_cancellation.h"
#include "ui_ticket_cancellation.h"
#include "database.h"

Ticket_Cancellation::Ticket_Cancellation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Ticket_Cancellation)
{
    ui->setupUi(this);
}

Ticket_Cancellation::~Ticket_Cancellation()
{
    delete ui;
}

void Ticket_Cancellation::on_tableView_activated(const QModelIndex &index)
{
    QString val = ui->tableView->model()->data(index).toString();


    QSqlQuery qry;
    qry.prepare("select * from ticket where ticket_no='"+val+"'");
    if(qry.exec( ))
        {

        while(qry.next())
        {

            ui->label_5->setText(qry.value(0).toString());
        }

    /*QSqlQuery qry;
    qry.prepare("select customer_id from customer where isLoggedIn=1");

    QString user_id;
    user_id=qry.value(0).toString();

    QSqlQuery qry2;
    qry2.prepare("select * from ticket where customer_id='"+user_id+"'");

*/
   }
}

void Ticket_Cancellation::on_pushButton_2_clicked()
{


    database conn;
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery *qry = new QSqlQuery(conn.db);
    qry->prepare("select * from ticket");
    qry->exec();
    model->setQuery(*qry);
    ui->tableView->setModel(model);

}


void Ticket_Cancellation::on_pushButton_clicked()
{
    QString ticket_no;
    ticket_no = ui->label_5->text();
    QSqlQuery qry;
    if(qry.exec("delete from ticket where ticket_no='"+ticket_no+"'")){
        ui->label_8->setText("Removed successfully");

    }
    else
        ui->label_8->setText("Not Removed");
}
