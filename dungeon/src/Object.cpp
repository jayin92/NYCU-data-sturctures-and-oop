#include "Object.h"

Object::Object(): name(""), tag("") {}
Object::Object(string _name, string _tag): name(_name), tag(_tag) {}

void Object::setName(string name){
    this -> name = name;
}

void Object::setTag(string tag){
    this -> tag = tag;
}

string Object::getName(){
    return this -> name;
}

string Object::getTag(){
    return this -> tag;
}
