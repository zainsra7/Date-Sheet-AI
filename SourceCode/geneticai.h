#ifndef GENETICAI_H
#define GENETICAI_H



#include<iostream>
#include "Population.h"
#include <map>
#include <time.h>
using namespace std;

class GeneticAI
{
private:

public:
    void CalculateFitness(TimeTable &t)
    {
        //1. Clash (Same Batch ke course aik time slot par ni hona chahiye) : High Priority , -30%
        //2. 2 consectives slot par same abtch ke paper nahi hone chahhiye :Medium //		,-20% : per consecutive :-3%
        //3. Max 1 gap time slot , not more than that						: Low //		,-10% : per gap :-1%


        int current_score = 100;

        int clash_count = 0;

        int arr[15];

        int index = 0;

        //Denote 10==1 , 11==2, 12==3, 13==4


        for (int x = 0; x < 3; x++)
        {

            index = 0;
            for (int y = 0; y < 5; y++)
            {
                //1.
                Room * temp = t.getState(x, y);

                string ID = temp[0].getCource().getID();
                string ID2 = temp[1].getCource().getID();
                string ID3 = temp[2].getCource().getID();

                if ((ID==ID2 && ID!="" && ID2!="")
                    || (ID == ID3 && ID != "" && ID3 != "")
                    || (ID3 == ID2 && ID3 != "" && ID2 != ""))
                {

                    if (current_score - 30 <= 0) { current_score = 0; }
                    else current_score -= 30;
                    clash_count++;
                }

                if (ID == "10")
                {
                    arr[index++] = 1;
                }
                else if (ID == "11")
                {
                    arr[index++] = 2;
                }
                else if (ID == "12")
                {
                    arr[index++] = 3;
                }
                else if (ID == "13")
                {
                    arr[index++] = 4;
                }
                else
                {
                    arr[index++] = -1;
                }

                if (ID2 == "10") {
                    arr[index++] = 1;

                }
                else if (ID2 == "11")
                {
                    arr[index++] = 2;
                }
                else if (ID2 == "12")
                {
                    arr[index++] = 3;
                }
                else if (ID2 == "13")
                {
                    arr[index++] = 4;
                }
                else
                {
                    arr[index++] = -1;
                }

                if (ID3 == "10")
                {
                    arr[index++] = 1;
                }
                else if (ID3 == "11")
                {
                    arr[index++] = 2;
                }
                else if (ID3 == "12")
                {
                    arr[index++] = 3;
                }
                else if (ID3 == "13")
                {
                    arr[index++] = 4;
                }
                else
                {
                    arr[index++] = -1;
                }

            }
            int consective_score = Consecutive(arr);
            int gap_score = MeasureGap(arr);

            if (x == 0)
            {
                for(int i=0;i<15;i++)
                t.Day1_arr[i] = arr[i];

                t.number_consecutive = consective_score;
                t.number_gap = gap_score;
                t.number_clashes = clash_count;
            }
            else if (x == 1)
            {
                for (int i = 0; i<15; i++)
                    t.Day2_arr[i] = arr[i];

                t.number_consecutive2 = consective_score;
                t.number_gap2 = gap_score;
                t.number_clashes2 = clash_count;
            }
            else
            {
                for (int i = 0; i<15; i++)
                    t.Day3_arr[i] = arr[i];


                t.number_consecutive3 = consective_score;
                t.number_gap3 = gap_score;
                t.number_clashes3 = clash_count;
            }
            clash_count = 0;

            if (current_score - consective_score <= 0) { current_score = 0;  }
            else current_score -= consective_score;
            if (current_score - gap_score <= 0) { current_score = 0;  }
            else current_score -= gap_score;
        }

        t.setFitness(current_score);
    }
    TimeTable* Crossover(TimeTable a, TimeTable b)
    {


        TimeTable * children_TT = new TimeTable[2];
        //00 ,01 ,10 , 11 , 20 , 21 (D1-D3 , T1-T2 of TT-a)

        TimeTable child1;
        TimeTable child2;

        //Take Batch 10 , 11 courses from Parent a

        for (int i = 0; i < 3; i++) {

            for (int y = 0; y < 5; y++)
            {
                Room * temp = a.getState(i, y);

                if (temp[0].getCource().getID() == "10" || temp[0].getCource().getID() == "11")
                {
                    Room* temp_child = child1.getState(i, y);
                    temp_child[0].setCource(temp[0].getCource().getWhole());
                }
                    if (temp[1].getCource().getID() == "10" || temp[1].getCource().getID() == "11")
                {
                        Room* temp_child = child1.getState(i, y);
                        temp_child[1].setCource(temp[1].getCource().getWhole());

                }
                    if (temp[2].getCource().getID() == "10" || temp[2].getCource().getID() == "11")
                {
                        Room* temp_child = child1.getState(i, y);
                        temp_child[2].setCource(temp[2].getCource().getWhole());

                }

            }
        }

        //10,11 of Parent B
        for (int i = 0; i < 3; i++) {

            for (int y = 0; y < 5; y++)
            {
                Room * temp = b.getState(i, y);

                if (temp[0].getCource().getID() == "10" || temp[0].getCource().getID() == "11")
                {
                    Room* temp_child = child2.getState(i, y);
                    temp_child[0].setCource(temp[0].getCource().getWhole());
                }
                if (temp[1].getCource().getID() == "10" || temp[1].getCource().getID() == "11")
                {
                    Room* temp_child = child2.getState(i, y);
                    temp_child[1].setCource(temp[1].getCource().getWhole());

                }
                if (temp[2].getCource().getID() == "10" || temp[2].getCource().getID() == "11")
                {
                    Room* temp_child = child2.getState(i, y);
                    temp_child[2].setCource(temp[2].getCource().getWhole());

                }

            }
        }

        //Take Batch 12,13 from Parent b to put in Child1

        Course c;

        //12,13 portion of Parent B
        for (int i = 0; i < 3; i++)
        {

            for (int y = 0; y < 5; y++)
            {
                Room * temp = b.getState(i, y);

                if (temp[0].getCource().getID() == "12" || temp[0].getCource().getID() == "13")
                {

                    Room* temp_child = child1.getState(i, y);

                    if (temp_child[0].getCource().getName() == "")
                    {
                        temp_child[0].setCource(temp[0].getCource().getWhole());

                    }
                    else
                    {
                        c = temp[0].getCource();
                        InsertAtRandom(child1, c);
                    }
                }
                if (temp[1].getCource().getID() == "12" || temp[1].getCource().getID() == "13")
                {

                    Room* temp_child = child1.getState(i, y);

                    if (temp_child[1].getCource().getName() == "")
                    {
                        temp_child[1].setCource(temp[1].getCource().getWhole());

                    }
                    else
                    {
                        c = temp[1].getCource();
                        InsertAtRandom(child1, c);
                    }

                }
                if (temp[2].getCource().getID() == "12" || temp[2].getCource().getID() == "13" )
                {

                    Room* temp_child = child1.getState(i, y);
                    if (temp_child[2].getCource().getName() == "")
                    {
                        temp_child[2].setCource(temp[2].getCource().getWhole());

                    }
                    else
                    {
                        c = temp[2].getCource();
                        InsertAtRandom(child1, c);
                    }

                }


            }
        }

        //12,13 portion of Parent A
        for (int i = 0; i < 3; i++)
        {

            for (int y = 0; y < 5; y++)
            {
                Room * temp = a.getState(i, y);

                if (temp[0].getCource().getID() == "12" || temp[0].getCource().getID() == "13")
                {

                    Room* temp_child = child2.getState(i, y);

                    if (temp_child[0].getCource().getName() == "")
                    {
                        temp_child[0].setCource(temp[0].getCource().getWhole());

                    }
                    else
                    {
                        c = temp[0].getCource();
                        InsertAtRandom(child2, c);
                    }
                }
                if (temp[1].getCource().getID() == "12" || temp[1].getCource().getID() == "13")
                {

                    Room* temp_child = child2.getState(i, y);

                    if (temp_child[1].getCource().getName() == "")
                    {
                        temp_child[1].setCource(temp[1].getCource().getWhole());

                    }
                    else
                    {
                        c = temp[1].getCource();
                        InsertAtRandom(child2, c);
                    }

                }
                if (temp[2].getCource().getID() == "12" || temp[2].getCource().getID() == "13")
                {

                    Room* temp_child = child2.getState(i, y);
                    if (temp_child[2].getCource().getName() == "")
                    {
                        temp_child[2].setCource(temp[2].getCource().getWhole());

                    }
                    else
                    {
                        c = temp[2].getCource();
                        InsertAtRandom(child2, c);
                    }

                }


            }
        }


        children_TT[0] = child1;
        children_TT[1] = child2;

        Mutation(children_TT[0]);
        Mutation(children_TT[1]);

        return children_TT;
    }
    void Mutation(TimeTable &c)
    {
        double mutation_rate = 0.01;

        if (rand_md() < mutation_rate)
            {
                //perform Mutation
                int day1 = rand() % 3;
                int slot1 = rand() % 5;
                int room1 = rand ()%3;
                int day2 = rand() % 3;
                int slot2 = rand() % 5;
                int room2 = rand() % 3;

                Room * temp=c.getState(day1, slot1);
                Room * temp2=c.getState(day2, slot2);
                Course s=temp[room1].getCource();
                temp[room1].setCource("");
                temp[room1].setCource(temp2[room2].getCource().getWhole());
                temp2[room2].setCource("");
                temp2[room2].setCource(s.getWhole());
            }

    }

    int Consecutive(int arr[15])
    {

        bool consective = false;
        int count_consectuive = 0;
        for (int i = 0; i < 12; i += 3)
        {

            for (int j = i; j < i + 3; j++)
            {
                for (int x = i + 3; x < i + 6; x++)
                {

                    if (arr[j] == arr[x] && arr[j]!=-1 && arr[x]!=-1)
                    {
                        consective = true;
                        count_consectuive++;
                    }
                }
            }
        }
        return count_consectuive*3;
    }

    int MeasureGap(int arr[15])
    {
        int count_gap = 0;
            for (int j = 0; j < 3; j++)
            {
                for (int x = 9; x < 15; x++)
                {
                    if (arr[j] == arr[x] && arr[j] != -1 && arr[x] != -1)
                    {
                        count_gap++;
                    }
                }
        }

            for (int y = 3; y < 6; y++)
            {
                for (int x = 12; x < 15; x++)
                {
                    if (arr[y] == arr[x] && arr[y] != -1 && arr[x] != -1)
                    {
                        count_gap++;
                    }
                }
            }

        return count_gap*1;

    }

    void InsertAtRandom(TimeTable& temp,Course c)
    {
        bool inserted = false;
        int day = 0;
        int slot = 0;
        int room = 0;
        while (inserted != true)
        {
            day = rand() % 3;
            slot = rand() % 5;
            room = rand() % 3;

            Room* temp_child = temp.getState(day, slot);


            if (room == 0 && temp_child[0].getCource().getName() == "")
            {

                temp_child[0].setCource(c.getWhole());

                inserted = true;
            }
            else if (room == 1 && temp_child[1].getCource().getName() == "")
            {
                temp_child[1].setCource(c.getWhole());
                inserted = true;
            }

            else if (room == 2 && temp_child[2].getCource().getName() == "")
            {
                temp_child[2].setCource(c.getWhole());
                inserted = true;
            }

        }




    }
    double rand_md()
    {
        return (double)rand() / (RAND_MAX + 1.0);
    }


};


#endif // GENETICAI_H
