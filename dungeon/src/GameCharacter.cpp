#include "../include/GameCharacter.h"

GameCharacter::GameCharacter():
    Object("", "GameCharacter"), maxHealth(0), currentHealth(0), attack(0), defense(0) {}


GameCharacter::GameCharacter(string name, string tag, int hp, int atk, int def):
    Object(name, tag), maxHealth(hp), currentHealth(hp), attack(atk), defense(def) {}

bool GameCharacter::checkIsDead(){
    return this -> currentHealth <= 0;
}

int GameCharacter::takeDamage(int dmg){
    return this -> currentHealth -= dmg;
}

void GameCharacter::setMaxHealth(int hp){
    this -> maxHealth = hp;
}

void GameCharacter::setCurrentHealth(int hp){
    this -> currentHealth = hp;
}

void GameCharacter::setAttack(int atk){
    this -> attack = atk;
}

void GameCharacter::setDefense(int def){
    this -> defense = def;
}

int GameCharacter::getMaxHealth(){
    return this -> maxHealth;
}

int GameCharacter::getCurrentHealth(){
    return this -> currentHealth;
}

int GameCharacter::getAttack(){
    return this -> attack;
}

int GameCharacter::getDefense(){
    return this -> defense;
}

