#ifndef CUSTOMER_DETAILS_H
#define CUSTOMER_DETAILS_H

#include <QMainWindow>
#include <QtSql>
#include "database.h"
namespace Ui {
class Customer_Details;
}

class Customer_Details : public QMainWindow
{
    Q_OBJECT

public:
    explicit Customer_Details(QWidget *parent = 0);
    ~Customer_Details();

private slots:
    void on_pushButton_clicked();

    void on_tableView_activated(const QModelIndex &index);

private:
    Ui::Customer_Details *ui;
    Customer_Details *c;

};

#endif // CUSTOMER_DETAILS_H
