#include "../include/NPC.h"

NPC::NPC(string name, string script, vector<Item> com):
    GameCharacter(name, "NPC", 0, 0, 0), script(script), commodity(com) {}

void NPC::listCommodity(){
    int idx = 0;
    for(auto i: this->commodity){
        cout << idx++ << ": " << i.getName() << " HP: " << i.getHealth() << ", ATK: " << i.getAttack() 
            << ", DEF: " << i.getDefense() << endl;
    }
}

bool NPC::triggerEvent(Object* object){
    Player* player = dynamic_cast<Player*>(object);
    cout << "Hi, I'm " << getName() << "." << endl;
    cout << getScript() << endl;
    
    int idx;
    do{
        cout << "I have these items. Do you want to buy anything?" << endl;
        listCommodity();
        cout << "Enter the index of wanted item (Enter -1 for quitting): ";
        if(0 <= idx && idx < commodity.size()){
            player -> addItem(commodity[idx]);
            commodity.erase(commodity.begin()+idx);
        }
    } while(cin >> idx && idx != -1);

    return true;
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
