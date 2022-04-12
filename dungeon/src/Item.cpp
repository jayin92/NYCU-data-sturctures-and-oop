#include "../include/Item.h"

// TODO: triggerEvent

Item::Item(): Object("", "Item"), health(0), attack(0), defense(0){}

Item::Item(string name, string ty, int hp, int atk, int def):
    Object(name, "Item"), type(ty), health(hp), attack(atk), defense(def)
{}

bool Item::triggerEvent(Object* object){
    Player* player = dynamic_cast<Player*>(object);
    cout << "You get " << getName() << endl;
    player -> addItem(*this);
    return true;
}

int Item::getHealth(){
    return this -> health;
}

int Item::getAttack(){
    return this -> attack;
}

int Item::getDefense(){
    return this -> defense;
}

string Item::getType(){
    return type;
}

void Item::setHealth(int hp){
    this -> health = hp;
}

void Item::setAttack(int atk){
    this -> attack = atk;
}

void Item::setDefense(int def){
    this -> defense = def;
}
