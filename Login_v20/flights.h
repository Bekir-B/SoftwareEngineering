#ifndef FLIGHTS_H
#define FLIGHTS_H

#include <QMainWindow>
#include <QtSql>
#include <adminaddflight.h>
#include <admineditflight.h>

namespace Ui {
class Flights;
}

class Flights : public QMainWindow
{
    Q_OBJECT

public:
    explicit Flights(QWidget *parent = 0);
    ~Flights();

private slots:
    void on_pushButton_3_clicked();


    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Flights *ui;
    Flights *f;
    adminAddFlight *add;
    adminEditFlight *edit;

};

#endif // FLIGHTS_H
