#include "dbmanager.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
static const QString path = "C:/Users/korisnik/Desktop/sqlitestudio-3.0.7/SQLiteStudio/ime.db";
DbManager::DbManager(const QString &path)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
       m_db.setDatabaseName(path);

       if (!m_db.open())
       {
          qDebug() << "Error: connection with database fail";
       }
       else
       {
          qDebug() << "Database: connection ok";
       }
}



bool DbManager::isOpen() const
{
    return m_db.isOpen();
}

bool DbManager::personExists(const QString& name) const
{
    bool exists = false;

    QSqlQuery qry;
       if(qry.exec("SELECT name FROM people WHERE name=\'"+name+"'"))
        {
           qDebug() << "blah";
        exists = true;
        return exists;
        }
       else
       {
           qDebug() << "else";
           qDebug() << qry.lastError().text();
           exists = false;
           return exists;
       }
}


/*void DbManager::printAllPersons() const
{
    qDebug() << "Persons in db:";
    QSqlQuery query("SELECT * FROM people");
    int idName = query.record().indexOf("name");
    while (query.next())
    {
        qDebug() << "karac";
        QString name = query.value(idName).toString();
        qDebug() << "===" << name;
    }
}*/

/*bool DbManager::addPerson(const QString& name)
{
   bool success = false;
   // you should check if args are ok first...
   QSqlQuery query;
   query.prepare("INSERT INTO people (name) VALUES (:name)");
   query.bindValue(":name", name);
   if(query.exec())
   {
       success = true;
   }
   else
   {
        qDebug() << "addPerson error:  " << query.lastError();
   }

   return success;
}*/
