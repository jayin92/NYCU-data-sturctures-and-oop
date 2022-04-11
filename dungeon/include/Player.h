#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "GameCharacter.h"
#include "Room.h"
#include "Item.h"
#include "Backpack.h"

using namespace std;

class Item;
class Backpack;

class Player: public GameCharacter
{
private:
    Room* currentRoom = nullptr;
    Room* previousRoom = nullptr;
    vector<Item> inventory;
    Backpack* backpack;
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
    Backpack* getBackpack();
};

#endif // PLAYER_H_INCLUDED
