#ifndef DIALOG2_H
#define DIALOG2_H

#include <QDialog>
#include "population.h"
#include <string>

namespace Ui {
class Dialog2;
}

class Dialog2 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog2(QWidget *parent = 0);
    ~Dialog2();
    void printTimeTable();
    QString course1;
    QString course2;
    QString course3;
private:
    Ui::Dialog2 *ui;

};

#endif // DIALOG2_H
