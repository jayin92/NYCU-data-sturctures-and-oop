#include "../include/Dungeon.h"

bool Dungeon::not_finished = true;

Dungeon::Dungeon(){}

void clear() {
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    std::cout << "\x1B[2J\x1B[H";
}

void Dungeon::createPlayer(){
    string name;
    cout << "Enter Your Name: ";
    cin >> name;
    player = Player(name, 100, 10, 0);
    cout << "Hi, " << name << endl;
    player.triggerEvent(&player);
}


void Dungeon::createMap(){
    vector<Item> itemList;
    itemList.push_back(Item("INF", 0, 1e3, 1e3));
    NPC* jay = new NPC("jayinnn", "I'm jayinnn, the author of this game.", itemList);
    Monster* ethan = new Monster("Ethan", 300, 75, 80);
    ethan -> setIsBoss(false);
    vector<Object*> objList;
    objList.push_back(jay);
    Room* initRoom = new Room(false, 0, objList);
    objList.push_back(ethan);
    Room* Room1 = new Room(false, 1, objList);
    player.setCurrentRoom(initRoom);
    player.setCurrentRoom(initRoom);
    initRoom -> setRightRoom(Room1);
    Room1 -> setLeftRoom(initRoom);
    rooms.push_back(*initRoom);
    rooms.push_back(*Room1);
}

void Dungeon::handleMovement(){
    map<char, Room*> avaRoom;
    if(player.getCurrentRoom() -> getUpRoom() != nullptr
        || player.getCurrentRoom() -> getDownRoom() != nullptr
        || player.getCurrentRoom() -> getLeftRoom() != nullptr
        || player.getCurrentRoom() -> getRightRoom() != nullptr)
    {
        if(player.getCurrentRoom() -> getUpRoom() != nullptr){
            avaRoom['U'] = avaRoom['u'] = player.getCurrentRoom() -> getUpRoom();
            cout << "(U)p Room" << endl;
        }
        if(player.getCurrentRoom() -> getDownRoom() != nullptr){
            avaRoom['D'] = avaRoom['d'] = player.getCurrentRoom() -> getDownRoom();
            cout << "(D)own Room" << endl;
        }
        if(player.getCurrentRoom() -> getLeftRoom() != nullptr){
            avaRoom['L'] = avaRoom['l'] = player.getCurrentRoom() -> getLeftRoom();
            cout << "(L)eft Room" << endl;
        }
        if(player.getCurrentRoom() -> getRightRoom() != nullptr){
            avaRoom['R'] = avaRoom['r'] = player.getCurrentRoom() -> getRightRoom();
            cout << "(R)ight Room" << endl;
        }
        char c;
        do{
            cout << "Which room do you want to go? ";
        } while(cin >> c && (avaRoom.find(c) == avaRoom.end()));
        Room* cur = player.getCurrentRoom();
        cout << avaRoom[c]->getIndex() << endl;
        player.setCurrentRoom(avaRoom[c]);
        player.setPreviousRoom(cur);
    } else {
        cout << "Sorry, you can't go anywhere." << endl;
    }

    return;
}


void Dungeon::handleEvent(Object* object){
    if(object -> triggerEvent(&player)){
        return;
    } else {
        exit(0);
    }
}

void Dungeon::chooseAction(vector<Object*> objects){
    int idx = 0;
    for(int i=0;i<(int)objects.size();i++){
        if(objects[i]->getTag() == "Monster"){
            handleEvent(objects[i]);
            return;
        }
    }
    cout << "--------------------" << endl;
    for(int i=0;i<(int)objects.size();i++){
        cout << idx ++ << ": " << objects[i]->getTag()
            << ": " << objects[i]->getName() << endl;
    }
    cout << "--------------------" << endl;
    cout << "(M)ove" << endl;
    cout << "(S)how Status" << endl;
    char c;
    do{
        cout << "Enter the index of the charcter you want to interact: ";
    } while(cin >> c && !(('0' <= c && c <= '0'+(int)objects.size())
        || c == 'M' || c == 'm' || c == 'S' || c == 's'));

    if(c == 'M' || c == 'm'){
        handleMovement();
    } else if(c == 'S' || c == 's'){
        clear();
        player.triggerEvent(&player);
    } else {
        handleEvent(objects[c-'0']);
    }
}



void Dungeon::startGame(){
    createPlayer();
    createMap();
}

void Dungeon::runDungeon(){
    startGame();
    while(not_finished){
        chooseAction(player.getCurrentRoom() -> getObjects());
    }
}
