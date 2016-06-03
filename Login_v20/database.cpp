#include "database.h"

database::database()
{

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/Bekir/Desktop/Login_v20/DATABASE/airport");
    if (!db.open())
    {
       qDebug() << "Error: connection with database fail";
    }
    else
    {
       qDebug() << "Database: connection ok";
    }
}


bool database::checkCustomer1(QString a, QString b){
    db.open();
    QSqlQuery qry(db);
    qry.exec("SELECT * FROM customer WHERE username ='" + a + "'AND password ='" + b + "'");
    qry.first();
    bool ok = qry.value(0).toInt()==a.toInt();
    return ok;
}

