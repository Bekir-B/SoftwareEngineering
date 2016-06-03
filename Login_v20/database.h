#ifndef DATABASE_H
#define DATABASE_H
#include <QString>
#include <QtSql>
#include <QDebug>
#include <QMessageBox>
class database
{
public:
    database();
     bool checkCustomer1(QString a, QString b);
     QSqlDatabase db;
private:
   // QSqlDatabase db;
};

#endif // DATABASE_H
