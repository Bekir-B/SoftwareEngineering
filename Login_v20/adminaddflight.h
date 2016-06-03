#ifndef ADMINADDFLIGHT_H
#define ADMINADDFLIGHT_H

#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <iostream>
#include <QApplication>
#include <QProcess>
#include <QThread>
#include <QChar>

#include "database.h"
#include <QSqlQuery>
namespace Ui {
class adminAddFlight;
}

class adminAddFlight : public QMainWindow
{
    Q_OBJECT

public:
    explicit adminAddFlight(QWidget *parent = 0);
    ~adminAddFlight();



private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_tableView_activated(const QModelIndex &index);

private:
    Ui::adminAddFlight *ui;
    adminAddFlight *add;

};

#endif // ADMINADDFLIGHT_H
