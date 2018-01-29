#ifndef POPULATION_H
#define POPULATION_H



#include <iostream>
#include "State.h"
#include <vector>
using namespace std;


class TimeTable
{


private:
    State state[3][5];
    int fitness;


public:

    TimeTable()
    {
        fitness = 0;
        number_clashes = 0;
        number_consecutive = 0;
        number_gap = 0;
        number_clashes2 = 0;
        number_consecutive2 = 0;
        number_gap2 = 0;
        number_clashes3 = 0;
        number_consecutive3 = 0;
        number_gap3 = 0;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                state[i][j].setRooms("", "", "");
            }
        }


    }


    void Initialize_TT(string s[20])
    {

        int day=0;
        int slot =0;
        int room = 0;
        int course = 0;
        bool inserted = false;

        while (checkValidCourses(s) != 20)
        {
             day = rand() % 3;
             slot = rand() % 5;
             room = rand() % 3;
             course = rand() % 20;

            while (s[course] == "-1") { course = rand() % 20; }

            if (room == 0 && state[day][slot].getRoom1().getCource().getName() == "")
            {
                state[day][slot].setRoom1(s[course]);
                inserted = true;
            }
            else if (room == 1 && state[day][slot].getRoom2().getCource().getName() == "")
            {
                state[day][slot].setRoom2(s[course]);
                inserted = true;
            }

            else if (room == 2 && state[day][slot].getRoom3().getCource().getName() == "")
            {
                state[day][slot].setRoom3(s[course]);
                inserted = true;
            }

            if (inserted == true) s[course] = "-1";

            inserted = false;
        }

    }


    int checkValidCourses(string s[20])
    {
        int count = 0;
        for (int i = 0; i < 20; i++)
        {
            if (s[i] == "-1") { count++; }
        }

        return count;
    }


    void printTT()
    {
        cout << endl << endl << endl << "DATE SHEET" << endl << endl;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (state[i][j].getRoom1().isEmpty() == false)
                {
                    string course = state[i][j].getRoom1().getCource().getName();
                    cout << endl;
                    cout << "Day [" << i << "] Slot [" << j << "] ->> Room {0} : Course = ";
                    for (int x = 0; x < course.length(); x++)
                        cout << course[x];
                }

                if (state[i][j].getRoom2().isEmpty() == false)
                {
                    string course = state[i][j].getRoom2().getCource().getName();
                    cout << endl;
                    cout << "Day [" << i << "] Slot [" << j << "] ->> Room {1} : Course = ";
                    for (int x = 0; x < course.length(); x++)
                        cout << course[x];
                }
                if (state[i][j].getRoom3().isEmpty() == false)
                {
                    string course = state[i][j].getRoom3().getCource().getName();
                    cout << endl;
                    cout << "Day [" << i << "] Slot [" << j << "] ->> Room {2} : Course = ";
                    for (int x = 0; x < course.length(); x++)
                        cout << course[x];
                }


                cout << endl << "--------------" << endl;
            }
        }
        cout << endl << "-------------------";
        cout << endl << endl << "Day " << 1 << endl;
        printArray(Day1_arr);
        cout << endl << "#Consecutive : " << number_consecutive / 3;
        cout << endl << "#Gap : " << number_gap;
        cout << endl << "#Clash : " << number_clashes;


        cout << endl << "-------------------";
        cout << endl << endl << "Day " << 2 << endl;
        printArray(Day2_arr);
        cout << endl << "#Consecutive : " << number_consecutive2 / 3;
        cout << endl << "#Gap : " << number_gap2;
        cout << endl << "#Clash : " << number_clashes2;


        cout << endl << "-------------------";
        cout << endl << endl << "Day " << 3 << endl;
        printArray(Day3_arr);
        cout << endl << "#Consecutive : " << number_consecutive3 / 3;
        cout << endl << "#Gap : " << number_gap3;
        cout << endl << "#Clash : " << number_clashes3;

        cout << endl << "Fitness Value : " << fitness << endl;
    }

    Room* getState(int row, int col)
    {
        return state[row][col].getAllRooms();
    }

    void Initialize_Crossover1(string s[18])
    {
        int index = 0;

        for (int i = 0; i < 3; i++) {

            for (int y = 0; y < 2; y++) {

                Room* temp=state[i][y].getAllRooms();
                temp[0].setCource(s[index++]);
                temp[1].setCource(s[index++]);
                temp[2].setCource(s[index++]);
            }
        }


    }
    void makeEqual(TimeTable &c)
    {

        fitness = 0;
        number_clashes = 0;
        number_consecutive = 0;
        number_gap = 0;
        number_clashes2 = 0;
        number_consecutive2 = 0;
        number_gap2 = 0;
        number_clashes3 = 0;
        number_consecutive3 = 0;
        number_gap3 = 0;


        for (int i = 0; i < 3; i++)
        {
            for(int y=0;y<5;y++)
            {
                /*this->state[i][y].setRoom1("");

                this->state[i][y].setRoom1(c.state[i][y].getRoom1().getCource().getWhole());

                this->state[i][y].setRoom2("");

                this->state[i][y].setRoom2(c.state[i][y].getRoom2().getCource().getWhole());

                this->state[i][y].setRoom3("");

                this->state[i][y].setRoom3(c.state[i][y].getRoom3().getCource().getWhole());*/
                this->state[i][y] = c.state[i][y];

            }
        }





        for (int i = 0; i < 15; i++)
        {

            this->Day1_arr[i] = -1;
            this->Day2_arr[i] = -1;
            this->Day3_arr[i] = -1;

        }

    }



    void Initialize_Crossover2(string s[27])
    {
        int index = 0;

        for (int i = 0; i < 3; i++) {

            for (int y = 2; y < 5; y++) {

                Room* temp = state[i][y].getAllRooms();
                temp[0].setCource(s[index++]);
                temp[1].setCource(s[index++]);
                temp[2].setCource(s[index++]);
            }
        }


    }
    void printArray(int arr[15])

    {
        cout << "[";
        for (int i = 0; i < 3; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "]" << " ";


        cout << "[";
        for (int i = 3; i < 6; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "]" << " ";



        cout << "[";
        for (int i = 6; i < 9; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "]" << " ";



        cout << "[";
        for (int i = 9; i < 12; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "]" << " ";


        cout << "[";
        for (int i = 12; i < 15; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "]" << " ";

    }
    void setFitness(int f) { fitness = f; }
    int getFitness() {return  fitness; }


    //For Day_1
    int number_clashes;
    int number_consecutive;
    int number_gap;
    int Day1_arr[15];

    //For Day_2
    int number_clashes2;
    int number_consecutive2;
    int number_gap2;
    int Day2_arr[15];

    //ForDay_3
    int number_clashes3;
    int number_consecutive3;
    int number_gap3;
    int Day3_arr[15];
};


#endif // POPULATION_H
