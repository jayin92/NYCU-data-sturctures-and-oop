#include "Player.h"

Player::Player(string name, int hp, int atk, int def):
    GameCharacter(name, "Player", hp, atk, def) {}


void Player::addItem(Item new_item){
    inventory.push_back(new_item);
}

void Player::increaseStates(int hp, int atk, int def){
    setCurrentHealth(getCurrentHealth() + hp);
    setAttack(getAttack() + atk);
    setDefense(getDefense() + def);
}

void Player::changeRoom(Room* new_room){
    previousRoom = currentRoom;
    currentRoom = new_room;
}

bool Player::triggerEvent(Object*){
    cout << "Status:" << endl;

    cout << getName() << endl;
    cout << "HP: "  << getCurrentHealth() << "/" << getMaxHealth() << endl;
    cout << "ATK: "  << getAttack() << endl;
    cout << "DEF: " << getDefense() << endl;
    auto inve = getInventory();
    if(inve.size() != 0){
        cout << "Item: ";
        for(auto i: inve){
            cout << i.getName() << " ";
        }
        cout << endl;
    }

    return true;
}

void Player::setCurrentRoom(Room* room){
    currentRoom = room;
}

void Player::setPreviousRoom(Room* room){
    previousRoom = room;
}

void Player::setInventory(vector<Item> invent){
    inventory = invent;
}

Room* Player::getCurrentRoom(){
    return currentRoom;
}
Room* Player::getPreviousRoom(){
    return previousRoom;
}
vector<Item> Player::getInventory(){
    return inventory;
}

