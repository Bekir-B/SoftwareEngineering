#ifndef DBMANAGER_H
#define DBMANAGER_H
#include <QSqlDatabase>

class DbManager
{
public:
    DbManager(const QString &path);
    bool isOpen() const;
    bool personExists(const QString& name) const;
    //void printAllPersons() const;
   //bool addPerson(const QString& name);
private:
    QSqlDatabase m_db;
};

#endif // DBMANAGER_H
