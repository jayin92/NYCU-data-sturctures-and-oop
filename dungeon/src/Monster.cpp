#include "Monster.h"

Monster::Monster(): GameCharacter("", "Monster", 0, 0, 0) {}

Monster::Monster(string name, int hp, int atk, int def):
    GameCharacter(name, "Monster", hp, atk, def) {}

