#include "NPC.h"

NPC::NPC(string name, string script, vector<Item> com):
    GameCharacter(name, "NPC", 0, 0, 0), script(script), commodity(com) {}

void NPC::listCommodity(){
    for(auto i: this->commodity){
        std::cout << i.getName() << " ";
    }
    std::cout << std::endl;
}


void NPC::setScript(string script){
    this -> script = script;
}

void NPC::setCommodity(vector<Item> com){
    this -> commodity = com;
}

string NPC::getScript(){
    return this -> script;
}

vector<Item> NPC::getCommodity(){
    return this -> commodity;
}
