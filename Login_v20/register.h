#ifndef REGISTER_H
#define REGISTER_H

#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <iostream>
#include <QApplication>
#include <QProcess>
#include <QThread>
#include <QChar>

using namespace std;
namespace Ui {
class Register;
}

class Register : public QMainWindow
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = 0);
    ~Register();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Register *ui;
    Register *r;
};

#endif // REGISTER_H
