#ifndef BACKPACK_H_INCLUDED
#define BACKPACK_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Object.h"
#include "Item.h"

using namespace std;

class Item;

class Backpack: public Object
{
private:
    Item* head;
    Item* left;
    Item* right;
    Item* body;
    vector<Item*> potions;
    vector<Item*> keys;
public:
    Backpack();
    
    bool triggerEvent(Object*);

    /* Set & Get function*/
    Item* getHead();
    Item* getLeft();
    Item* getRight();
    Item* getBody();
    vector<Item*> getPoitions();
    vector<Item*> getKeys();

    void setHead(Object*, Item*);
    void setLeft(Object*, Item*);
    void setRight(Object*, Item*);
    void setBody(Object*, Item*);
    void addKey(Item*);
    void addPotions(Item*);
};

#endif // BACKPACK_H_INCLUDED
