#ifndef STATE_H
#define STATE_H


#include <iostream>
#include "Room.h"
using namespace std;

class State
{
private:
    Room rooms[3];
public:

    State()
    {


    }

    void setRooms(string cr1,string cr2,string cr3)
    {
        rooms[0].setCource(cr1);
        rooms[1].setCource(cr2);
        rooms[2].setCource(cr3);
    }

    void printState()
    {
        rooms[0].print();
        rooms[1].print();
        rooms[2].print();
    }

    void setRoom1(string cr1)
    {
        rooms[0].setCource(cr1);
    }
    void setRoom2(string cr2)
    {
        rooms[1].setCource(cr2);
    }
    void setRoom3(string cr3)
    {
        rooms[2].setCource(cr3);
    }

    Room getRoom1() { return rooms[0]; }
    Room getRoom2() { return rooms[1]; }
    Room getRoom3() { return rooms[2]; }

    Room* getAllRooms() { return rooms; }

};


#endif // STATE_H
