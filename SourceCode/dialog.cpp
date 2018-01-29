#include "dialog.h"
#include "ui_dialog.h"
#include<QFileSystemModel>
#include<QHBoxLayout>
#include<QHeaderView>
#include <QDebug>
#include<QString>
#include"dialog2.h"
#include<QTimer>
#include<QFont>
#include<QGraphicsOpacityEffect>
#include<QPropertyAnimation>
#include <iostream>
#include "course.h"
#include "room.h"
#include "state.h"
#include "population.h"
#include "geneticai.h"
#include <time.h>
#ifdef Q_OS_WIN
#include <windows.h> // for Sleep
#endif
#include <QTime>

using namespace std;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
//    this->setProperty("windowOpacity", 0.5);
//    QTimer::singleShot(200, this, SLOT(updateCaption()));

    // now implement a slot called hideThisWidget() to do
    // things like hide any background dimmer, etc.
stop=9;

    int nRows = 3;
    int nCols = 5;
    ui->tableWidget->setRowCount(nRows);
    ui->tableWidget->setColumnCount(nCols);
    ui->tableWidget->setHorizontalHeaderLabels(QString("TimeSlot 1;TimeSlot 2;TimeSlot 3;TimeSlot 4;TimeSlot 5").split(";"));
    ui->tableWidget->setVerticalHeaderLabels(QString("Day 1;Day 2;Day 3").split(";"));

    for(int row = 0; row < nRows; row++)
    {
        for (int col = 0; col < nCols; col++)
        {
            Dialog2* item = new Dialog2();
            ui->tableWidget->setCellWidget(row, col, item );
        }
    }


    ui->tableWidget->setColumnWidth(0,200);
    ui->tableWidget->setColumnWidth(1,200);
    ui->tableWidget->setColumnWidth(2,200);
    ui->tableWidget->setColumnWidth(3,200);
    ui->tableWidget->setColumnWidth(4,200);
    ui->tableWidget->setRowHeight(0,145);
    ui->tableWidget->setRowHeight(1,145);
    ui->tableWidget->setRowHeight(2,145);

    ui->tableWidget->horizontalHeader()->setStyleSheet("color: blue");
    ui->tableWidget->verticalHeader()->setStyleSheet("color: blue");
    QFont f( "BatmanForeverAlternate", 12, QFont::Bold);
    ui->tableWidget->horizontalHeader()->setFont(f);

    QFont f1( "Arial", 8, QFont::Bold);
    ui->tableWidget->verticalHeader()->setFont(f1);

    QString pop,gen,mut,fit;

    pop = "100";
    gen = "0";
    mut = "0.01";
    fit = "0";

    ui->lineEdit->setText("Enter Total Generation");
    ui->lineEdit_2->setText(pop);
    ui->lineEdit_3->setText(fit);
    ui->lineEdit_4->setText(mut);



}

Dialog::~Dialog()
{
    delete ui;
}
void Dialog::runGA()
{

    // #Batch : 4
        // Per Batch : 5 courses
        //Batch 10 : {"10-TBW","10-DB","10-OS","10-ATO","10-Prob"}
        //Batch 11: {"11-DS","11-LA","11-ASL","11-PHL","11-NUM"}
        //Batch 12: {"12-Eng2","12-Cal2","12-CLD","12-CP","12-BE"}
        //Batch 13: {"13-ITC","13-Cal","13-PK","13-ISL","13-Eng1"}

        //#Population: 100
        //Mutation_Rate: 0.01

        //For Mating pool
        //0-20 -1
        //21-40 -2
        //41-60 -3
        //61-80 -4
        //81-100 -5 , at worst case when all of population has fitness in 81-100 range then we will need an array of size 500



        TimeTable bestTT; //Top TimeTable in our generation range
        int BestGen=0; //The Generation Where we got our Top TimeTable

        int mating_pool[500];
        int index_pool = 0;
        string hhh[20] = { "10-TBW","10-DB","10-OS","10-ATO","10-Prob","11-DS","11-LA","11-ASL","11-PHL","11-NUM",
        "12-Eng2","12-Cal2","12-CLD","12-CP","12-BE","13-ITC","13-Cal","13-PK","13-ISL","13-Eng1"
        };
        string temp[20];

        for (int i = 0; i < 20; i++)
        {
            temp[i] = hhh[i];
        }
        TimeTable _population[100];
        GeneticAI ai;
int user_Gen=0;
        QString user_generation=ui->lineEdit->text();
         user_Gen=user_generation.toInt();

        //Generating Population

        int generation = 1;

        for (int i = 0; i < 100; i++)
        {
            _population[i].Initialize_TT(temp);
            for (int i = 0; i < 20; i++)
            {
                temp[i] = hhh[i];
            }
        }
        while (generation != user_Gen)
        {
            //Calculating fitness of population

            for (int i = 0; i < 100; i++)
            {
                ai.CalculateFitness(_population[i]);
            }

                 int max = 0;
                int index = 0;

                for (int i = 0; i < 100; i++)
                {
                    int fitnes = _population[i].getFitness();
                    if (fitnes > max)
                    {
                        max = fitnes;
                        index = i;
                    }
                }

        if(generation%5==0)
        {
            printTT(_population[index],generation);
            qsleep();
        }


                if(bestTT.getFitness()<max)
                {

                    bestTT.makeEqual(_population[index]);
                    ai.CalculateFitness(bestTT);
                      BestGen=generation;
                }



            //Building Mating Pool based on the fitness of population

            int fitness = 0;
            for (int i = 0; i < 100; i++)
            {
                fitness = _population[i].getFitness();

                if (fitness >= 0 && fitness <= 20)
                {
                    mating_pool[index_pool++] = i;
                }
                else if (fitness >= 21 && fitness <= 40)
                {
                    mating_pool[index_pool++] = i;
                    mating_pool[index_pool++] = i;
                }
                else if (fitness >= 41 && fitness <= 60)
                {
                    mating_pool[index_pool++] = i;
                    mating_pool[index_pool++] = i;
                    mating_pool[index_pool++] = i;
                }
                else if (fitness >= 61 && fitness <= 80)
                {
                    mating_pool[index_pool++] = i;
                    mating_pool[index_pool++] = i;
                    mating_pool[index_pool++] = i;
                    mating_pool[index_pool++] = i;
                }
                else if (fitness >= 81 && fitness <= 100)
                {
                    mating_pool[index_pool++] = i;
                    mating_pool[index_pool++] = i;
                    mating_pool[index_pool++] = i;
                    mating_pool[index_pool++] = i;
                    mating_pool[index_pool++] = i;
                }
            }

            //Making New Population
            //Picking 2 Random parents from Mating Pool and performing Crossover + Mutation(according to mutation_rate)
            //Crossover generate two childs
            //Mutation is done at the end of Crossover , (inside CrossOver function)

            //Make a Temp Population that will hold  newly generated children

                    TimeTable _population_temp[100];

            for (int i = 0; i < 100; i++) //50 cuz 2 parents generate 2 Children
            {

                //srand(time(NULL));
                int random_parent_index = rand() % index_pool;

                //srand(time(NULL));
                int random_parent_index2 = rand() % index_pool;

                int Parent_index_pop = mating_pool[random_parent_index];
                int Parent_index_pop2 = mating_pool[random_parent_index2];

                TimeTable* Childrens = ai.Crossover(_population[Parent_index_pop], _population[Parent_index_pop2]);

                _population_temp[i++].makeEqual(Childrens[1]);

                _population_temp[i].makeEqual(Childrens[0]);

            }


            for (int i = 0; i < 100; i++)
                    {

                        _population[i].makeEqual(_population_temp[i]);
                    }




            index_pool = 0;
            QString gen=QString::number(generation);

            ui->lineEdit->setText(gen);


                generation++;

        }
        QString gen=QString::number(generation);

        ui->lineEdit->setText(gen);
        for (int i = 0; i < 100; i++)
            {
                ai.CalculateFitness(_population[i]);

            }

        int max = 0;
       int index = 0;

       for (int i = 0; i < 100; i++)
       {
           int fitnes = _population[i].getFitness();
           if (fitnes > max)
           {
               max = fitnes;
               index = i;
           }
       }

       if(bestTT.getFitness()<max)
       {

           bestTT.makeEqual(_population[index]);
           ai.CalculateFitness(bestTT);
             BestGen=generation;
       }



        printTT(bestTT,BestGen);

}

void Dialog::qsleep()
{
        QTime dieTime= QTime::currentTime().addSecs(6); //Can change time from here
        while (QTime::currentTime() < dieTime)
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

}
void Dialog::printTT(TimeTable pop, int bestgen)
{

//    int max = 0;
//        int index = 0;

//        for (int i = 0; i < 100; i++)
//        {
//            int fitnes = pop[i].getFitness();
//            if (fitnes > max)
//            {
//                max = fitnes;
//                index = i;
//            }
//        }

        //TimeTable tem = pop;

        for(int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 5; col++)
            {
                Dialog2* item = new Dialog2();

                Room* temp=pop.getState(row,col);

                string c1=temp[0].getCource().getWhole();

                QString course1 = QString::fromStdString(c1);

               string c2= temp[1].getCource().getWhole();

                QString course2 = QString::fromStdString(c2);

             string c3=   temp[2].getCource().getWhole();
              QString course3 = QString::fromStdString(c3);

             item->course1.append(course1);

             item->course2.append(course2);

             item->course3.append(course3);


             item->printTimeTable();
                ui->tableWidget->setCellWidget(row, col, item );
            }
        }

        QString fit=QString::number(pop.getFitness());

        ui->lineEdit_3->setText(fit);

        QString gen=QString::number(bestgen);

        ui->lineEdit_5->setText(gen);

        QString clash=QString::number(pop.number_clashes+pop.number_clashes2+pop.number_clashes3);

        ui->lineEdit_6->setText(clash);

        QString con=QString::number(((pop.number_consecutive/3)+(pop.number_consecutive2/3)+(pop.number_consecutive3/3)));

        ui->lineEdit_7->setText(con);

        QString gap=QString::number(pop.number_gap+pop.number_gap2+pop.number_gap3);

        ui->lineEdit_8->setText(gap);




}

void Dialog::on_pushButton_clicked()
{

runGA();
}
