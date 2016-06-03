#include "customer_details.h"
#include "ui_customer_details.h"

Customer_Details::Customer_Details(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Customer_Details)
{
    ui->setupUi(this);
}

Customer_Details::~Customer_Details()
{
    delete ui;
}

void Customer_Details::on_pushButton_clicked() // showing everything except password of customers
{
    database conn;
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery *qry = new QSqlQuery(conn.db);
    qry->prepare("select customer_id,username,name,last_name,address,phone,age,ccn_no,isLoggedIn from customer");
    qry->exec();
    model->setQuery(*qry);
    ui->tableView->setModel(model);
}

void Customer_Details::on_tableView_activated(const QModelIndex &index)
{
     QString val = ui->tableView->model()->data(index).toString();
}
