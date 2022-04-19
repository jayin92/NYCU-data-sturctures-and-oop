#include "../include/NPC.h"
#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"

NPC::NPC(){}

NPC::NPC(string name, string script, vector<Item> com):
    GameCharacter(name, "NPC", 0, 0, 0), script(script), commodity(com) {}

void NPC::listCommodity(){
    int idx = 0;
    for(auto i: this->commodity){
        cout << idx++ << ": " << CYN+(i.getType())+NC << " " << i.getName() << " HP: " << i.getHealth() << ", ATK: " << i.getAttack() 
            << ", DEF: " << i.getDefense() << endl;
    }
}

bool NPC::triggerEvent(Object* object){
    Player* player = dynamic_cast<Player*>(object);
    cout << getScript() << endl;
    
    int idx = -1;
    do{
        if(0 <= idx && idx < (int)commodity.size()){
            commodity[idx].triggerEvent(player);
            commodity.erase(commodity.begin()+idx);
        }
        cout << "I have these items. Do you want to buy anything?" << endl;
        cout << "------------------- ITEM -------------------" << endl;
        listCommodity();
        cout << "--------------------------------------------" << endl;

        cout << "Enter the index of wanted item (Enter -1 for quitting): ";
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
