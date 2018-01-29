#ifndef ROOM_H
#define ROOM_H

#pragma once
#include <iostream>
#include <string.h>
#include "Course.h"
using namespace std;

class Room
{

private:
    Course course;

public:

    Room()
    {
        course.setID("");
        course.setName("");
    }
    Room(Course c)
    {
    course = c;
    }

    void setCource(string s)
    {
        course.parse(s);
    }
    Course getCource() { return course; }
    void print()
    {

        cout << endl<<"Room contains following course :- "<<endl;
        course.print();

    }

    bool isEmpty()
    {
        if (course.getName() == "") return true;
        return false;
    }

};


#endif // ROOM_H
