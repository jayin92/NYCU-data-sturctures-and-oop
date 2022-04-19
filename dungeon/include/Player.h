#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "GameCharacter.h"
#include "Room.h"
#include "Item.h"

using namespace std;

class Item;

class Player: public GameCharacter
{
private:
    Room* currentRoom = nullptr;
    Room* previousRoom = nullptr;
    vector<Item> inventory;
    Item* head = nullptr;
    Item* left = nullptr;
    Item* right = nullptr;
    Item* body = nullptr;
    vector<Item> potions;
    vector<Item> keys;
public:
    Player();
    Player(string,int,int,int);
    void addItem(Item);
    void increaseStates(int,int,int);
    void changeRoom(Room*);

    /* Virtual function that you need to complete   */
    /* In Player, this function should show the     */
    /* status of player.                            */
    bool triggerEvent(Object*);

    /* Set & Get function*/
    void setCurrentRoom(Room*);
    void setPreviousRoom(Room*);
    void setInventory(vector<Item>);
    Room* getCurrentRoom();
    Room* getPreviousRoom();

    vector<Item> getInventory();
    Item* getHead();
    Item* getLeft();
    Item* getRight();
    Item* getBody();
    vector<Item> getPotions();
    vector<Item> getKeys();

    void setHead(Item*);
    void setLeft(Item*);
    void setRight(Item*);
    void setBody(Item*);
    void addKey(Item);
    void addPotions(Item);
    void popKey(Item);
    void useHealPotion(Item);
    void popPotions(Item);
    void equip();
};

#endif // PLAYER_H_INCLUDED
