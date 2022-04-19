#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Object.h"

using namespace std;

class Item;

class Room
{
private:
    Room* upRoom = nullptr;
    Room* downRoom = nullptr;
    Room* leftRoom = nullptr;
    Room* rightRoom = nullptr;
    Item* roomKey = nullptr;
    bool isExit;
    int index;
    vector<Object*> objects; /*contain 1 or multiple objects, including monster, npc, etc*/
public:
    Room();
    Room(bool, int, vector<Object*>);
    bool popObject(Object*); /*pop out the specific object, used when the interaction is done*/


    /* Set & Get function*/
    void setUpRoom(Room*);
    void setDownRoom(Room*);
    void setLeftRoom(Room*);
    void setRightRoom(Room*);
    void setRoomKey(Item*);
    void setIsExit(bool);
    void setIndex(int);
    void setObjects(vector<Object*>);
    void addObject(Object*);
    bool getIsExit();
    int getIndex();
    vector<Object*> getObjects();
    Room* getUpRoom();
    Room* getDownRoom();
    Room* getLeftRoom();
    Room* getRightRoom();
    Item* getRoomKey();
};

#endif // ROOM_H_INCLUDED
