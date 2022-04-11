#include <iostream>
#include <string>
#include <vector>
#include "../include/Dungeon.h"
#include "../include/Item.h"
#include "../include/Backpack.h"
#include "../include/Monster.h"
#include "../include/NPC.h"
#include "../include/Player.h"


using namespace std;

int main(){
    Dungeon dungeon = Dungeon();
    dungeon.runDungeon();
    return 0;
}
