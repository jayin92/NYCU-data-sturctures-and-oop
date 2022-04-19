#include "../include/Room.h"

Room::Room() {}
Room::Room(bool isExit, int idx, vector<Object*> objs): isExit(isExit), index(idx), objects(objs){}

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

void Room::setRoomKey(Item* key){
    this -> roomKey = key;
}

vector<Object*> Room::getObjects(){
    return objects;
}

void Room::addObject(Object* obj){
    objects.push_back(obj);
}

Room* Room::getUpRoom(){
    return upRoom;
}

Room* Room::getDownRoom(){
    return downRoom;
}

Room* Room::getLeftRoom(){
    return leftRoom;
}

Room* Room::getRightRoom(){
    return rightRoom;
}

bool Room::getIsExit(){
    return isExit;
}

int Room::getIndex(){
    return this->index;
}

Item* Room::getRoomKey(){
    return this -> roomKey;
}
