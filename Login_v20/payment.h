#ifndef PAYMENT_H
#define PAYMENT_H

#include <QMainWindow>
#include <QtSql>
namespace Ui {
class payment;
}

class payment : public QMainWindow
{
    Q_OBJECT

public:
    explicit payment(QWidget *parent = 0);
    ~payment();


private slots:
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

private:
    Ui::payment *ui;
    payment *p;

};

#endif // PAYMENT_H
