#include "Room.h"

Room::Room(bool isExit, int idx, vector<Object*> objs){
    this -> isExit = isExit;
    this -> index = idx;
    this -> objects = objs;
}

bool Room::popObject(Object* obj){
    for(auto it=objects.begin();it!=objects.end(); it++){
        if(*it == obj){
            objects.erase(it);
            return true;
        }
    }
    return false;

}

void Room::setUpRoom(Room* r){
    this -> upRoom = r;
}

void Room::setDownRoom(Room* r){
    this -> downRoom = r;
}

void Room::setLeftRoom(Room* r){
    this -> leftRoom = r;
}

void Room::setRightRoom(Room* r){
    this -> rightRoom = r;
}

void Room::setIsExit(bool isExit){
    this -> isExit = isExit;
}

void Room::setIndex(int idx){
    this -> index = idx;
}

vector<Object*> Room::getObjects(){
    return this -> objects;
}

Room* Room::getUpRoom(){
    return this -> upRoom;
}

Room* Room::getDownRoom(){
    return this -> downRoom;
}

Room* Room::getLeftRoom(){
    return this -> leftRoom;
}

Room* Room::getRightRoom(){
    return this -> rightRoom;
}
