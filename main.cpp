#include "mainwindow.h"
#include <QApplication>
#include <QtSql/QSqlDatabase>
#include <QtDebug>
#include <QSqlError>
#include "dbmanager.h"

static const QString path = "C:/Users/korisnik/Desktop/sqlitestudio-3.0.7/SQLiteStudio/ime.db";

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    /*QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/korisnik/Desktop/sqlitestudio-3.0.7/SQLiteStudio/ime.db");

    if(!db.open())
    {
        qDebug() << db.lastError().text();
        qFatal("Failed to connect!");
    }

    else

    qDebug("Connected.");*/

    DbManager db(path);
    if (db.isOpen()) {
        db.personExists("Mehmed");
        //db.printAllPersons();
        //db.addPerson("Vildan");
        qDebug()<<"End";
    }
    else
       qDebug()<<"Njet end";
    return a.exec();
}
