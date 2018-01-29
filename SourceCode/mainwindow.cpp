#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"dialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    delete ui->mainToolBar;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Dialog *d = new Dialog;
    d->setModal(true);
    d->exec();

}

void MainWindow::on_pushButton_2_clicked()
{
    exit(1);
}
