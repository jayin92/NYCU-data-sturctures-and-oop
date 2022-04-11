#ifndef BACKPACK_H_INCLUDED
#define BACKPACK_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Object.h"
#include "Item.h"

using namespace std;

class Item;
class Player;

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

    void setHead(Player*, Item*);
    void setLeft(Player*, Item*);
    void setRight(Player*, Item*);
    void setBody(Player*, Item*);
    void addKey(Item*);
    void addPotions(Item*);
};

#endif // BACKPACK_H_INCLUDED
