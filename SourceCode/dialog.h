#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<QStandardItemModel>
#include <QTableView>
#include "population.h"
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    void runGA();
    void qsleep();
    void printTT(TimeTable pop, int bestgen);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
    int stop;
    QStandardItemModel *model;
};

#endif // DIALOG_H
