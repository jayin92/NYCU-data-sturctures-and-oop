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
    int player_dmg = calculateDamage(player->getAttack(), getDefense());
    int monster_dmg = calculateDamage(getAttack(), player->getDefense());
    do {
        if(choice == 'S' || choice == 's'){
            player -> triggerEvent(player);
        } else if(choice == 'R' || choice == 'r'){
            Room* tmp = player -> getCurrentRoom();
            player -> setCurrentRoom(player -> getPreviousRoom());
            player -> setPreviousRoom(tmp);
            return true;
        } else if(choice == 'A' || choice == 'a') {
            cout << "Player " << player -> getName() << " deals " << player_dmg
                << " damages to Monster " << getName() << endl;
            setCurrentHealth(getCurrentHealth()-player_dmg);
            if(getCurrentHealth() <= 0){
                cout << "Monster " << getName() << " has been killed." << endl; 
                player -> getCurrentRoom() -> popObject(this);
                return true;
            }
            cout << "Monster " << getName() << " deals " << monster_dmg
                << " damages to Player " << player -> getName() << endl;
            player -> setCurrentHealth(player->getCurrentHealth() - monster_dmg);
            if(player -> getCurrentHealth() <= 0){
                cout << "Player " << player -> getName() << " is dead." << endl;
                return false;
            }            
        } else if(choice == 'P' || choice == 'p'){
            int idx = -2;
            do {
                if(0 <= idx && idx < player -> getPotions().size()){
                    auto potion = player->getPotions()[idx];
                    auto atk = potion.getAttack();
                    auto hp = potion.getHealth();
                    if(atk != 0){
                        cout << "Player " << player -> getName() << " using " << potion.getName()
                        << " to deal " << atk
                        << " damages to Monster " << getName() << endl;
                        setCurrentHealth(getCurrentHealth()-atk);
                        if(getCurrentHealth() <= 0){
                            cout << "Monster " << getName() << " has been killed." << endl; 
                            player -> getCurrentRoom() -> popObject(this);
                            return true;
                        }
                    } else if(hp != 0){
                        player -> setCurrentHealth(player -> getCurrentHealth() + hp);
                        if(player -> getCurrentHealth() > player -> getMaxHealth()){
                            player -> setCurrentHealth(player -> getMaxHealth());
                        }
                    }
                    player -> popPotions(potion);
                }
                int sz = player -> getPotions().size();
                for(int i=0;i<sz;i++){
                    auto potion = player -> getPotions()[i];
                    auto atk = potion.getAttack();
                    auto hp = potion.getHealth();
                    cout << i << ": " << (potion.getName()) << " ";
                    if(atk != 0){
                        cout << "ATK: " << atk << " ";
                    }
                    if(hp != 0){
                        cout << "HP: " << hp << " ";
                    }
                    cout << endl;
                }
                cout << "Which potions you want to use (-1 for quit) > ";
            } while(cin >> idx && idx != -1);
        } else {
            cout << "Invalid input." << endl;
        }
        cout << "(R)ETREAT" << endl;
        cout << "(A)TTACK" << endl;
        cout << "(S)TATUS" << endl;
        cout << "(P)otion" << endl;
        cout << "What do you want to do? > ";  
    } while(cin >> choice);
    
}