#include "../include/Monster.h"

Monster::Monster(): GameCharacter("", "Monster", 0, 0, 0), isBoss(false) {}

Monster::Monster(string name, int hp, int atk, int def):
    GameCharacter(name, "Monster", hp, atk, def), isBoss(false) {}

int calculateDamage(int atk, int def){
    return atk * atk / (atk + def);
}

bool Monster::getIsBoss(){
    return isBoss;
}

void Monster::setIsBoss(int _isBoss){
    isBoss = _isBoss;
}

void Monster::printStatus(){
    cout << "Monster: " << getName() << endl;
    cout << "HP: " << getMaxHealth() << endl;
    cout << "ATK: " << getAttack() << endl;
    cout << "DEF: " << getDefense() << endl;
}

bool Monster::triggerEvent(Object* object){
    Player* player = dynamic_cast<Player*>(object);
    player -> triggerEvent(player);
    cout << "Player " << player -> getName() << ", you just encouter a monster." << endl;
    printStatus();
    char choice = 'Z';
    do {
        if(choice == 'S' || choice == 's'){
            player -> triggerEvent(player);
        }
        cout << "(R)ETREAT" << endl;
        cout << "(A)TTACK" << endl;
        cout << "(S)TATUS" << endl;
        cout << "What do you want to do? ";  
    } while(cin >> choice && choice != 'r' && choice != 'R' && choice != 'a' && choice != 'A');
    
    if(choice == 'R' || choice == 'r'){
        Room* tmp = player -> getCurrentRoom();
        player -> setCurrentRoom(player -> getPreviousRoom());
        player -> setPreviousRoom(tmp);
    } else {
        int player_dmg = calculateDamage(player->getAttack(), getDefense());
        int monster_dmg = calculateDamage(getAttack(), player->getDefense());
        while(getCurrentHealth() > 0 && player -> getCurrentHealth() > 0){
            cout << "Player " << player -> getName() << " deals " << player_dmg
                << " damages to Monster " << getName() << endl;
            setCurrentHealth(getCurrentHealth()-player_dmg);
            if(getCurrentHealth() <= 0) break;
            cout << "Monster " << getName() << " deals " << monster_dmg
                << " damages to Player " << player -> getName() << endl;
            player -> setCurrentHealth(player->getCurrentHealth() - monster_dmg);
        }
        if(player -> getCurrentHealth() <= 0){
            cout << "Player " << player -> getName() << " is dead." << endl;
            return false;
        }
        cout << "Monster " << getName() << " has been killed." << endl; 
        player -> getCurrentRoom() -> popObject(this);
        return true;
    }

    return true;
}