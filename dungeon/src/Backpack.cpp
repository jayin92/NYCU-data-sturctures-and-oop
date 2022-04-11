#include "../include/Backpack.h"

Backpack::Backpack(): 
    Object("backpack", "Backpack"), head(nullptr), left(nullptr), right(nullptr), body(nullptr) {}
    
bool Backpack::triggerEvent(Object* obj){
    Player* player = dynamic_cast<Player*>(obj);
    auto head = player -> getBackpack() -> getHead();
    auto body = player -> getBackpack() -> getBody();
    auto left = player -> getBackpack() -> getLeft();
    auto right = player -> getBackpack() -> getRight();

    cout << "Equipment: " << endl;
    cout << "> Head     : " << (head == nullptr ? "(empty)" : head->getName());
    cout << "> Body     : " << (body == nullptr ? "(empty)" : body->getName());
    cout << "> Left Arm : " << (left == nullptr ? "(empty)" : left->getName());
    cout << "> Right Arm: " << (right == nullptr ? "(empty)" : right->getName());
    cout << "----" << endl;
    cout << "Keys: " << endl;
    int idx = 1;
    for(Item* i: player->getBackpack() -> getKeys()){
        cout << idx ++ << ":" << i->getName() << endl;
    }
    cout << "----" << endl;
    cout << "Potions: " << endl;
    idx = 1;
    for(auto i: player->getBackpack() -> getPoitions()){
        cout << idx ++ << ":" << i->getName() << endl;
    }

    return true;
}


Item* Backpack::getHead(){
    return head;
}
Item* Backpack::getLeft(){
    return left;
}
Item* Backpack::getRight(){
    return right;
}
Item* Backpack::getBody(){
    return body;
}

vector<Item*> Backpack::getPoitions(){
    return potions;
}

vector<Item*> Backpack::getKeys(){
    return keys;
}

void Backpack::setHead(Object* obj, Item* newHead){
    Player* player = dynamic_cast<Player*>(obj);
    vector<Item> inventory = player -> getInventory();
    player -> increaseStates(newHead->getHealth(), newHead->getAttack(), newHead->getDefense());
    for(auto it=inventory.begin();it!=inventory.end();it++){
        if(it->getName() == newHead->getName()){
            inventory.erase(it);
            break;
        }
    }
    if(head != nullptr){
        player -> increaseStates(-head->getHealth(), -head->getAttack(), -head->getDefense());
        inventory.push_back(*head);
    }
    head = newHead;
    player -> setInventory(inventory);
}

void Backpack::setLeft(Object* obj, Item* newLeft){
    Player* player = dynamic_cast<Player*>(obj);
    vector<Item> inventory = player -> getInventory();
    player -> increaseStates(newLeft->getHealth(), newLeft->getAttack(), newLeft->getDefense());
    for(auto it=inventory.begin();it!=inventory.end();it++){
        if(it->getName() == newLeft->getName()){
            inventory.erase(it);
            break;
        }
    }
    if(left != nullptr){
        player -> increaseStates(-left->getHealth(), -left->getAttack(), -left->getDefense());
        inventory.push_back(*left);
    }
    left = newLeft;
    player -> setInventory(inventory);
}

void Backpack::setRight(Object* obj, Item* newRight){
    Player* player = dynamic_cast<Player*>(obj);
    vector<Item> inventory = player -> getInventory();
    player -> increaseStates(newRight->getHealth(), newRight->getAttack(), newRight->getDefense());
    for(auto it=inventory.begin();it!=inventory.end();it++){
        if(it->getName() == newRight->getName()){
            inventory.erase(it);
            break;
        }
    }
    if(right != nullptr){
        player -> increaseStates(-right->getHealth(), -right->getAttack(), -right->getDefense());
        inventory.push_back(*right);
    }
    right = newRight;
    player -> setInventory(inventory);
}

void Backpack::setBody(Object* obj, Item* newBody){
    Player* player = dynamic_cast<Player*>(obj);
    vector<Item> inventory = player -> getInventory();
    player -> increaseStates(newBody->getHealth(), newBody->getAttack(), newBody->getDefense());
    for(auto it=inventory.begin();it!=inventory.end();it++){
        if(it->getName() == newBody->getName()){
            inventory.erase(it);
            break;
        }
    }
    if(body != nullptr){
        player -> increaseStates(-body->getHealth(), -body->getAttack(), -body->getDefense());
        inventory.push_back(*body);
    }
    body = newBody;
    player -> setInventory(inventory);
}

void Backpack::addKey(Item* key){
    keys.push_back(key);
}

void Backpack::addPotions(Item* potion){
    potions.push_back(potion);
}
