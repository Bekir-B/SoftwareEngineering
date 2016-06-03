#ifndef ADMINEDITFLIGHT_H
#define ADMINEDITFLIGHT_H

#include <QMainWindow>
#include <QSqlQuery>
#include "database.h"
namespace Ui {
class adminEditFlight;
}

class adminEditFlight : public QMainWindow
{
    Q_OBJECT

public:
    explicit adminEditFlight(QWidget *parent = 0);
    ~adminEditFlight();

private slots:
    void on_pushButton_3_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::adminEditFlight *ui;
      adminEditFlight *edit;
      database *db;
};

#endif // ADMINEDITFLIGHT_H
