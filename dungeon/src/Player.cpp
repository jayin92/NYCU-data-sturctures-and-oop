#include "../include/Player.h"

Player::Player(){}

Player::Player(string name, int hp, int atk, int def):
    GameCharacter(name, "Player", hp, atk, def) {}


void Player::addItem(Item new_item){
    string type = new_item.getType();
    if(type == "key"){
        addKey(new_item);
    } else if(type == "potion") {
        addPotions(new_item);
    } else {
        inventory.push_back(new_item);
    }
}

void Player::increaseStates(int hp, int atk, int def){
    setCurrentHealth(min(getCurrentHealth() + hp, getMaxHealth()));
    setAttack(getAttack() + atk);
    setDefense(getDefense() + def);
}

void Player::changeRoom(Room* new_room){
    if(new_room->getRoomKey() != nullptr){
        bool flag = true;
        for(auto it=keys.begin(); it!=keys.end(); it++){
            if(it -> getName() == new_room->getRoomKey()->getName()){
                cout << "You have the key to enter this room." << endl;
                flag = false;
                break;
            }
        }
        if(flag){
            cout << "You need key " + new_room->getRoomKey()->getName() + " to enter this room." << endl;
            return;
        }
    }
    previousRoom = currentRoom;
    currentRoom = new_room;
}

bool Player::triggerEvent(Object*){
    cout << "------------------ STATUS ------------------" << endl;

    cout << getName() << endl;
    cout << "HP: "  << getCurrentHealth() << "/" << getMaxHealth() << endl;
    cout << "ATK: "  << getAttack() << endl;
    cout << "DEF: " << getDefense() << endl;
    auto inve = getInventory();
    if(inve.size() != 0){
        cout << "Item: ";
        for(auto i: inve){
            cout << i.getName() << ", ";
        }
        cout << endl;
    }
    cout << "Equipment: " << endl;
    cout << "> Head     : " << (head == nullptr ? "(empty)" : head->getName()) << endl;
    cout << "> Body     : " << (body == nullptr ? "(empty)" : body->getName()) << endl;
    cout << "> Left Arm : " << (left == nullptr ? "(empty)" : left->getName()) << endl;
    cout << "> Right Arm: " << (right == nullptr ? "(empty)" : right->getName()) << endl;
    cout << "----" << endl;
    cout << "Keys: " << endl;
    int idx = 0;
    for(Item i: keys){
        cout << idx ++ << ": " << i.getName() << endl;
    }
    cout << "----" << endl;
    cout << "Potions: " << endl;
    idx = 0;
    for(Item i: potions){
        cout << idx ++ << ": " << i.getName() << " ATK: " << i.getAttack() << " HP: " << i.getHealth() << endl;
    }
    cout << "--------------------------------------------" << endl;
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


Item* Player::getHead(){
    return head;
}
Item* Player::getLeft(){
    return left;
}
Item* Player::getRight(){
    return right;
}
Item* Player::getBody(){
    return body;
}

vector<Item> Player::getPotions(){
    return potions;
}

vector<Item> Player::getKeys(){
    return keys;
}

void Player::setHead(Item* newHead){
    increaseStates(newHead->getHealth(), newHead->getAttack(), newHead->getDefense());
    for(auto it=inventory.begin();it!=inventory.end();it++){
        if(it->getName() == newHead->getName()){
            inventory.erase(it);
            break;
        }
    }
    if(head != nullptr){
        increaseStates(-head->getHealth(), -head->getAttack(), -head->getDefense());
        inventory.push_back(*head);
    }
    head = newHead;
}

void Player::setLeft(Item* newLeft){
    increaseStates(newLeft->getHealth(), newLeft->getAttack(), newLeft->getDefense());
    for(auto it=inventory.begin();it!=inventory.end();it++){
        if(it->getName() == newLeft->getName()){
            inventory.erase(it);
            break;
        }
    }
    if(left != nullptr){
        increaseStates(-left->getHealth(), -left->getAttack(), -left->getDefense());
        inventory.push_back(*left);
    }
    left = newLeft;
}

void Player::setRight(Item* newRight){
    increaseStates(newRight->getHealth(), newRight->getAttack(), newRight->getDefense());
    for(auto it=inventory.begin();it!=inventory.end();it++){
        if(it->getName() == newRight->getName()){
            inventory.erase(it);
            break;
        }
    }
    if(right != nullptr){
        increaseStates(-right->getHealth(), -right->getAttack(), -right->getDefense());
        inventory.push_back(*right);
    }
    right = newRight;
}

void Player::setBody(Item* newBody){
    increaseStates(newBody->getHealth(), newBody->getAttack(), newBody->getDefense());
    for(auto it=inventory.begin();it!=inventory.end();it++){
        if(it->getName() == newBody->getName()){
            inventory.erase(it);
            break;
        }
    }
    if(body != nullptr){
        increaseStates(-body->getHealth(), -body->getAttack(), -body->getDefense());
        inventory.push_back(*body);
    }
    body = newBody;
}

void Player::addKey(Item key){
    keys.push_back(key);
}

void Player::addPotions(Item potion){
    potions.push_back(potion);
}

void Player::equip(){
    while(true){
        cout << "Equipment: " << endl;
        cout << "> Head     : " << (head == nullptr ? "(empty)" : (head->getName() + " ATK: " + to_string(head->getAttack()) + " DEF: " + to_string(head->getDefense()))) << endl;
        cout << "> Body     : " << (body == nullptr ? "(empty)" : (body->getName() + " ATK: " + to_string(body->getAttack()) + " DEF: " + to_string(body->getDefense()))) << endl;
        cout << "> Left Arm : " << (left == nullptr ? "(empty)" : (left->getName() + " ATK: " + to_string(left->getAttack()) + " DEF: " + to_string(left->getDefense()))) << endl;
        cout << "> Right Arm: " << (right == nullptr ? "(empty)" : (right->getName() + " ATK: " + to_string(right->getAttack()) + " DEF: " + to_string(right->getDefense()))) << endl;
        char c;
        do{
            cout << "(H)ead" << endl;
            cout << "(B)ody" << endl;
            cout << "(L)eft Arm" << endl;
            cout << "(R)ight Arm" << endl;
            cout << "(E)xit" << endl;
            cout << "Which part do you want to put equipments on > ";
        } while(cin >> c && (c != 'h' && c != 'H' && c != 'b' && c != 'B' && c != 'l' && c != 'L' && c != 'r' && c != 'R' && c != 'e' && c != 'E'));

        if(c == 'e' || c == 'E') return;

        if(c == 'h' || c == 'H'){
            cout << "> Head     : " << (head == nullptr ? "(empty)" : (head->getName() + " ATK: " + to_string(head->getAttack()) + " DEF: " + to_string(head->getDefense()))) << endl;
            cout << "Invetory: " << endl;
            int idx = 0;
            vector<Item> rep;
            for(Item i: inventory){
                if(i.getType() == "head"){
                    cout << "> " << idx ++ << ": "<< i.getName() + " ATK: " + to_string(i.getAttack()) + " DEF: " + to_string(i.getDefense()) << endl;
                    rep.push_back(i);
                }
            }
            idx = -1;
            do{
                if(idx >= 0 && idx < (int)rep.size()){
                    Item* newed = new Item(rep[idx]);
                    setHead(newed);
                    break;
                }
                cout << "Which equipment does you want to put on (Enter -1 to leave) > ";
            } while(cin >> idx && idx != -1);
            
        } else if(c == 'b' || c == 'B'){
            cout << "> Body: " << (body == nullptr ? "(empty)" : (body->getName() + " ATK: " + to_string(body->getAttack()) + " DEF: " + to_string(body->getDefense()))) << endl;
            cout << "Invetory: " << endl;
            int idx = 0;
            vector<Item> rep;
            for(Item i: inventory){
                if(i.getType() == "body"){
                    cout << "> " << idx ++ << ": "<< i.getName() + " ATK: " + to_string(i.getAttack()) + " DEF: " + to_string(i.getDefense()) << endl;
                    rep.push_back(i);
                }
            }
            idx = -1;
            do{
                if(idx >= 0 && idx < (int)rep.size()){
                    Item* newed = new Item(rep[idx]);
                    setBody(newed);
                    break;
                }
                cout << "Which equipment does you want to put on (Enter -1 to leave) > ";
            } while(cin >> idx && idx != -1);

        } else if(c == 'l' || c == 'L'){
            cout << "> Left Arm: " << (left == nullptr ? "(empty)" : (left->getName() + " ATK: " + to_string(left->getAttack()) + " DEF: " + to_string(left->getDefense()))) << endl;
            cout << "Invetory: " << endl;
            int idx = 0;
            vector<Item> rep;
            for(Item i: inventory){
                if(i.getType() == "left"){
                    cout << "> " << idx ++ << ": "<< i.getName() + " ATK: " + to_string(i.getAttack()) + " DEF: " + to_string(i.getDefense()) << endl;
                    rep.push_back(i);
                }
            }
            idx = -1;
            do{
                if(idx >= 0 && idx < (int)rep.size()){
                    Item* newed = new Item(rep[idx]);
                    setLeft(newed);
                    break;
                }
                cout << "Which equipment does you want to put on (Enter -1 to leave) > ";
            } while(cin >> idx && idx != -1);

        } else if(c == 'r' || c == 'R'){
            cout << "> Right Arm: " << (right == nullptr ? "(empty)" : (right->getName() + " ATK: " + to_string(right->getAttack()) + " DEF: " + to_string(right->getDefense()))) << endl;
            cout << "Invetory: " << endl;
            int idx = 0;
            vector<Item> rep;
            for(Item i: inventory){
                if(i.getType() == "right"){
                    cout << "> " << idx ++ << ": "<< i.getName() + " ATK: " + to_string(i.getAttack()) + " DEF: " + to_string(i.getDefense()) << endl;
                    rep.push_back(i);
                }
            }
            idx = -1;
            do{
                if(idx >= 0 && idx < (int)rep.size()){
                    Item* newed = new Item(rep[idx]);
                    setRight(newed);
                    break;
                }
                cout << "Which equipment does you want to put on (Enter -1 to leave) > ";
            } while(cin >> idx && idx != -1);

        }
    
    }
}

void Player::popKey(Item key){
    for(auto it=keys.begin(); it!=keys.end(); ++it){
        if(key.getName() == it->getName()){
            keys.erase(it);
            break;
        }
    }
}

void Player::popPotions(Item potion){
    for(auto it=potions.begin(); it!=potions.end(); ++it){
        if(potion.getName() == it->getName()){
            potions.erase(it);
            break;
        }
    }
}

void Player::useHealPotion(Item potion){
    increaseStates(potion.getHealth(), 0, 0);
}