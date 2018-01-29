#ifndef COURSE_H
#define COURSE_H


#pragma once


#include <iostream>
#include <string.h>
using namespace std;

class Course
{
private:
    string Batch_Id;
    string Course_Name;
public:

    void print()
    {
        cout << "Batch_ID : ";
        for(int i=0;i<Batch_Id.length();i++)
        {
            cout << Batch_Id[i];
        }

        cout << endl << "Cource_Name : ";

        for (int i = 0; i<Course_Name.length(); i++)
        {
            cout << Course_Name[i];
        }
        cout << endl;
    }

    Course()
    {
    }

    Course(string id,string name)
    {
        Batch_Id = id;
        Course_Name = name;
    }

    //str== 13-CN
    void parse(string str)
    {
        if (str == "NULL" || str=="")
        {
            Batch_Id = "";
            Course_Name = "";
        }
        else {

            int i = 0;
            while (str[i] != '-')
            {
                Batch_Id += str[i];
                i++;
            }
            i++;
            while (i < str.length())
            {
                Course_Name += str[i];
                i++;
            }

        }
    }
    void setID(string d)
    {
        Batch_Id = d;
    }
    void setName(string n)
    {
        Course_Name = n;
    }

    string getID() { return Batch_Id; }
    string getName() { return Course_Name; }
    string getWhole()
    {

        if (Batch_Id == "") return "";

        string temp = Batch_Id;
        temp += "-";
        temp += Course_Name;

        return temp;
    }
};



#endif // COURSE_H
