#include "dialog2.h"
#include "ui_dialog2.h"
#include<QString>

Dialog2::Dialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);

    course1="Room 1: ";
    course2="Room 2: ";
    course3="Room 3: ";
    ui->lineEdit->setStyleSheet("QLineEdit {color: rgb(255,255,255); }");
ui->lineEdit_2->setStyleSheet("QLineEdit {color: rgb(255,255,255); }");
ui->lineEdit_3->setStyleSheet("QLineEdit {color: rgb(255,255,255); }");

}

Dialog2::~Dialog2()
{
    delete ui;
}
void Dialog2::printTimeTable(){

    ui->lineEdit->setText(course1);
    ui->lineEdit_2->setText(course2);
    ui->lineEdit_3->setText(course3);


    if(course1.contains("10-",Qt::CaseInsensitive))
    {
ui->lineEdit->setStyleSheet("QLineEdit { background: rgb(255, 40, 40); color: rgb(255,255,255); }");
    }
     if(course2.contains("10-",Qt::CaseInsensitive))
    {
ui->lineEdit_2->setStyleSheet("QLineEdit { background: rgb(255,40,40); color: rgb(255,255,255); }");
    }
     if(course3.contains("10-",Qt::CaseInsensitive))
    {
ui->lineEdit_3->setStyleSheet("QLineEdit { background: rgb(255,40,40); color: rgb(255,255,255); }");
    }

    if(course1.contains("11-",Qt::CaseInsensitive))
    {
ui->lineEdit->setStyleSheet("QLineEdit { background: rgb(55,3,228); color: rgb(255,255,255); }");
    }
     if(course2.contains("11-",Qt::CaseInsensitive))
    {
ui->lineEdit_2->setStyleSheet("QLineEdit { background: rgb(55,3,228); color: rgb(255,255,255); }");
    }
     if(course3.contains("11-",Qt::CaseInsensitive))
    {
ui->lineEdit_3->setStyleSheet("QLineEdit { background: rgb(55,3,228); color: rgb(255,255,255); }");
    }


    if(course1.contains("12-",Qt::CaseInsensitive))
    {
ui->lineEdit->setStyleSheet("QLineEdit { background: rgb(7,104,101); color: rgb(255,255,255); }");
    }
     if(course2.contains("12-",Qt::CaseInsensitive))
    {
ui->lineEdit_2->setStyleSheet("QLineEdit { background: rgb(7,104,101); color: rgb(255,255,255); }");
    }
    if(course3.contains("12-",Qt::CaseInsensitive))
    {
ui->lineEdit_3->setStyleSheet("QLineEdit { background: rgb(7,104,101); color: rgb(255,255,255); }");
    }


    if(course1.contains("13-",Qt::CaseInsensitive))
    {
ui->lineEdit->setStyleSheet("QLineEdit { background: rgb(101,102,98); color: rgb(255,255,255); }");
    }
     if(course2.contains("13-",Qt::CaseInsensitive))
    {
ui->lineEdit_2->setStyleSheet("QLineEdit { background: rgb(101,102,98); color: rgb(255,255,255); }");
    }
     if(course3.contains("13-",Qt::CaseInsensitive))
    {
ui->lineEdit_3->setStyleSheet("QLineEdit { background: rgb(101,102,98); color: rgb(255,255,255); }");
    }





}
