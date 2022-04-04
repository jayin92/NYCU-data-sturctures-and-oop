#include "../include/Monster.h"

Monster::Monster(): GameCharacter("", "Monster", 0, 0, 0) {}

Monster::Monster(string name, int hp, int atk, int def):
    GameCharacter(name, "Monster", hp, atk, def) {}

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
    cout << player -> getName() << ". You just encouter a monster." << endl;
    printStatus();
    char choice;
    do {
        if(choice == 'C' || choice == 'c'){
            player -> triggerEvent(player);
        }
        cout << "What do you want to do? (A: RETREAT, B: ATTACK, C: STATUS): ";  
    } while(cin >> choice && choice != 'a' && choice != 'A' && choice != 'B' && choice != 'b');
    
    if(choice == 'A' || choice == 'a'){
        Room* tmp = player -> getCurrentRoom();
        player -> setCurrentRoom(player -> getPreviousRoom());
        player -> setPreviousRoom(tmp);
    } else {
        int player_dmg = calculateDamage(player->getAttack(), getDefense());
        int monster_dmg = calculateDamage(getAttack(), player->getDefense());
        while(getCurrentHealth() > 0 && player -> getCurrentHealth()){
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