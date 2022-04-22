#include "../include/Dungeon.h"
#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"


bool Dungeon::not_finished = true;

Dungeon::Dungeon(){}
Record record;


void clear() {
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    std::cout << "\x1B[2J\x1B[H";
}

void Dungeon::createPlayer(){
    string s = "    ____                                   \n"
               "   / __ \\__  ______  ____ ____  ____  ____ \n"
               "  / / / / / / / __ \\/ __ `/ _ \\/ __ \\/ __ \\\n"
               " / /_/ / /_/ / / / / /_/ /  __/ /_/ / / / /\n"
               "/_____/\\__,_/_/ /_/\\__, /\\___/\\____/_/ /_/ \n"
               "                  /____/                   \n";

    cout << s;
    string name;
    cout << "Enter Your Name: ";
    cin >> name;
    player = Player(name, 1000, 10000, 10000);
    cout << "Hi, " << name << endl;
    player.triggerEvent(&player);
}


void Dungeon::createMap(){
    Monster* calculus = new Monster("Calculus", 40, 20, 10);
    Monster* physics = new Monster("Physics", 20, 5, 5);
    Monster* differentialEquations = new Monster("Differential Equations", 50, 15, 15);
    
    Monster* linearAlgebra = new Monster("Linear Algebra", 25, 7, 7);
    Monster* dm = new Monster("Discrete Mathematics", 20, 5, 5);

    Monster* intro2com = new Monster("Introduction to Computers", 15, 5, 5);
    Monster* oop = new Monster("OOP", 25, 15, 15);
    Monster* dcd = new Monster("Digital Circuits Design", 25, 10, 10);
    Monster* dataStructures = new Monster("Data Structures", 30, 17, 17);
    Monster* intro2algo = new Monster("Introduction to Algorithms", 50, 40, 40);

    Monster* gpe = new Monster("GPE", 100, 50, 50);
    gpe->setIsBoss(true);

    NPC* thePf = new NPC("The Professor", "Hi, I'm the Professor from NYCU CS\nWelcome you to enter this dungeon.\nTo escape this dungeon, you need to beat a monster called GPE.\nHere is the student ID card, this card is really helpful.\nDon't forget to pick it up.", vector<Item>{Item("NYCU Student ID Card", "key", 0, 0, 0)});

    NPC* pfChung = new NPC("Professor Chung", "Hi, I'm Professor Chung.\nSeems like you have killed the Monster Calculus.\nMy OCW is really good, huh.\nHope you can run away from this dungeon.", vector<Item>());
    NPC* gilbertStrang = new NPC("Gilbert Strang", "Hi, I'm Gilbert Strang.\nThe author of a well-known textbook. To help you beat the Monster Linear Algebra, I have something to give you.", vector<Item>{Item("Gram-schmidt Method", "right", 0, 10, 10)});
    NPC* pfLee = new NPC("Professor Lee", "Hi, I'm Professor Lee.\nThe professor of General Physics. You said that you can't enter the room of physics.\nHere is the key to that room.\nGo and kill Monster Physics.", vector<Item>{Item("Ewant Account", "key", 0, 0, 0)});
    NPC* turing = new NPC("Alan Turing", "Hi, I'm Alan Turing.\nThe famous computer scientist. To help you beat the Monster Introduction to Algorithms, I have something to give you.", vector<Item>{Item("Turing Machine", "key", 0, 0, 0)});
    NPC* georgeBoole = new NPC("George Boole", "Hi, I'm George Boole.\nThe pioneer in Boolean Algebra. I have something to give you.", vector<Item>{Item("Boolean Algebra", "key", 0, 0, 0)});



    Room* initRoom = new Room(false, 0, vector<Object*>{thePf, new Item("Heal Potion", "potion", 10, 0, 0), new Item("Damage Potion", "potion", 0, 5, 0)});
    Room* calculusRoom = new Room(false, 1, vector<Object*>{calculus});
    Room* physicsRoom = new Room(false, 2, vector<Object*>{physics, new Item("Schrodinger Equation", "key", 0, 0, 0)});
    Room* LARoom = new Room(false, 3, vector<Object*>{linearAlgebra, new Item("SVD", "body", 0, 5, 10)});
    Room* intro2comRoom = new Room(false, 4, vector<Object*>{intro2com, new Item("Pointer", "right", 0, 20, 5)});
    Room* pfChungRoom = new Room(false, 5, vector<Object*>{pfChung});
    Room* gilbertStrangRoom = new Room(false, 6, vector<Object*>{gilbertStrang});
    Room* differentialEquationsRoom = new Room(false, 7, vector<Object*>{differentialEquations, new Item("Damage Potion", "potion", 0, 5, 0)});
    Room* pfLeeRoom = new Room(false, 8, vector<Object*>{pfLee});
    Room* intro2algoRoom = new Room(false, 9, vector<Object*>{intro2algo, new Item("DP", "head", 0, 5, 10)});
    Room* dataStructuresRoom = new Room(false, 10, vector<Object*>{dataStructures, new Item("Treap", "key", 0, 0, 0)});
    Room* oopRoom = new Room(false, 11, vector<Object*>{oop, new Item("STL", "left", 0, 5, 20), new Item("Heal Potion", "potion", 10, 0, 0)});
    Room* turingRoom = new Room(false, 12, vector<Object*>{turing, new Item("Heal Potion", "potion", 10, 0, 0)});
    Room* georgeBooleRoom = new Room(false, 13, vector<Object*>{georgeBoole});
    Room* dmRoom = new Room(false, 14, vector<Object*>{dm, new Item("Binary Tree", "body", 0, 0, 15)});
    Room* dcdRoom = new Room(false, 15, vector<Object*>{dcd, new Item("K-map", "key", 0, 0, 0)});
    Room* gpeRoom = new Room(true, 16, vector<Object*>{gpe});

    physicsRoom->setRoomKey(new Item("Ewant Account", "key", 0, 0, 0));
    intro2comRoom->setRoomKey(new Item("NYCU Student ID Card", "key", 0, 0, 0));
    differentialEquationsRoom->setRoomKey(new Item("Schrodinger Equation", "key", 0, 0, 0));
    intro2algoRoom->setRoomKey(new Item("Turing Machine", "key", 0, 0, 0));
    turingRoom->setRoomKey(new Item("K-map", "key", 0, 0, 0));
    dmRoom->setRoomKey(new Item("Boolean Algebra", "key", 0, 0, 0));
    gpeRoom->setRoomKey(new Item("Treap", "key", 0, 0, 0));
    
    initRoom->setUpRoom(calculusRoom);
    initRoom->setDownRoom(physicsRoom);
    initRoom->setLeftRoom(LARoom);
    initRoom->setRightRoom(intro2comRoom);

    calculusRoom->setDownRoom(initRoom);
    calculusRoom->setUpRoom(pfChungRoom);

    LARoom -> setRightRoom(initRoom);

    intro2comRoom->setLeftRoom(initRoom);

    physicsRoom->setUpRoom(initRoom);

    pfChungRoom->setUpRoom(pfLeeRoom);
    pfChungRoom->setDownRoom(calculusRoom);
    pfChungRoom->setLeftRoom(gilbertStrangRoom);
    pfChungRoom->setRightRoom(differentialEquationsRoom);

    differentialEquationsRoom->setLeftRoom(pfChungRoom);

    gilbertStrangRoom->setRightRoom(pfChungRoom);

    pfLeeRoom->setDownRoom(pfChungRoom);

    intro2comRoom->setUpRoom(dataStructuresRoom);
    intro2comRoom->setDownRoom(intro2algoRoom);
    intro2comRoom->setRightRoom(oopRoom);

    dataStructuresRoom->setDownRoom(intro2comRoom);

    oopRoom->setLeftRoom(intro2comRoom);

    intro2algoRoom->setUpRoom(intro2comRoom);

    oopRoom->setUpRoom(turingRoom);
    oopRoom->setDownRoom(georgeBooleRoom);
    oopRoom->setRightRoom(gpeRoom);

    turingRoom->setDownRoom(oopRoom);

    georgeBooleRoom->setUpRoom(oopRoom);

    gpeRoom->setLeftRoom(oopRoom);

    georgeBooleRoom->setDownRoom(dmRoom);
    georgeBooleRoom->setRightRoom(dcdRoom);

    dmRoom->setUpRoom(georgeBooleRoom);

    dcdRoom->setLeftRoom(georgeBooleRoom);

    rooms.push_back(initRoom);
    rooms.push_back(calculusRoom);
    rooms.push_back(physicsRoom);
    rooms.push_back(LARoom);
    rooms.push_back(intro2comRoom);
    rooms.push_back(pfChungRoom);
    rooms.push_back(gilbertStrangRoom);
    rooms.push_back(differentialEquationsRoom);
    rooms.push_back(pfLeeRoom);
    rooms.push_back(intro2algoRoom);
    rooms.push_back(dataStructuresRoom);
    rooms.push_back(oopRoom);
    rooms.push_back(turingRoom);
    rooms.push_back(georgeBooleRoom);
    rooms.push_back(dmRoom);
    rooms.push_back(dcdRoom);
    rooms.push_back(gpeRoom);

    player.setCurrentRoom(initRoom);
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
        if(player.getCurrentRoom() -> getIsExit() == true){
            avaRoom['E'] = avaRoom['e'] = nullptr;
            cout << "(E)xit" << endl;
        }
        char c;
        do{
            cout << "Which room do you want to go? ";
        } while(cin >> c && avaRoom.find(c) == avaRoom.end());
        if(c == 'E' || c == 'e'){
            cout << GRN << "Congratulations! Player " << player.getName() << ", you have exited the dungeon." << NC << endl;
            player.setCurrentRoom(nullptr);
        } else {
            player.changeRoom(avaRoom[c]);
        }
    } else {
        cout << "Sorry, you can't go anywhere." << endl;
    }

    return;
}


void Dungeon::handleEvent(Object* object){
    object -> triggerEvent(&player);
    return;
}

bool Dungeon::checkGameLogic(){
    if(player.getCurrentRoom() == nullptr || player.getCurrentHealth() <= 0) return false;
    else return true;
}

void Dungeon::chooseAction(vector<Object*> objects){
    int idx = 0;
    for(int i=0;i<(int)objects.size();i++){
        if(objects[i]->getTag() == "Monster"){
            handleEvent(objects[i]);
            return;
        }
    }
    cout << "------------------- ROOM -------------------" << endl;
    for(int i=0;i<(int)objects.size();i++){
        cout << idx ++ << ": " << CYN+(objects[i]->getTag() == "Item" ? dynamic_cast<Item*>(objects[i])->getType() : objects[i]->getTag())+NC << 
        " " << objects[i]->getName() << endl;
    }
    cout << "--------------------------------------------" << endl;
    cout << "(M)ove" << endl;
    cout << "(S)how Status" << endl;
    cout << "(E)quipment" << endl;
    cout << "(P)otions" << endl;
    cout << "(C)reate Record" << endl;
    cout << "(L)oad Record" << endl;
    cout << "(Q)uit" << endl;
    char c;
    do{
        cout << "Enter the index of the charcter you want to interact: ";
    } while(cin >> c && !(('0' <= c && c < '0'+(int)objects.size())
        || c == 'M' || c == 'm' || c == 'S' || c == 's' || c == 'E' || c == 'e' || c == 'P' || c == 'p' || c == 'C' || c == 'c' || c == 'L' || c == 'l' || c == 'Q' || c == 'q'));
    clear();
    if(c == 'M' || c == 'm'){
        handleMovement();
    } else if(c == 'S' || c == 's'){
        player.triggerEvent(&player);
    } else if(c == 'E' || c == 'e'){
        player.equip();
    } else if(c == 'P' || c == 'p') {
        int inp = -2;
        do {
            int sz = player.getPotions().size();
            if(0 <= inp && inp < sz){
                player.useHealPotion(player.getPotions()[inp]);
                player.popPotions(player.getPotions()[inp]);
            }
            int idx = 0;
            for(auto i: player.getPotions()){
                if(i.getHealth() != 0){
                    cout << idx << ": " << i.getName() << " HP: " << i.getHealth() << endl;
                }
                idx ++;
            }
            cout << "Which potions you want to use (-1 for quit) > ";
        } while(cin >> inp && inp != -1);
    } else if(c == 'C' || c == 'c'){
        record.saveToFile(&player, rooms);
    } else if(c == 'L' || c == 'l') {
        record.loadFromFile(&player, rooms);
    } else if(c == 'Q' || c == 'q'){
        exit(0);
    } else {
        handleEvent(objects[c-'0']);
        if(objects[c-'0']->getTag()=="Item"){
            player.getCurrentRoom()->popObject(objects[c-'0']);
        }
    }
}


void Dungeon::startGame(){
    createPlayer();
    createMap();
}

void Dungeon::runDungeon(){
    startGame();
    while(not_finished){
        if(checkGameLogic() == false){
            exit(0);
        }
        chooseAction(player.getCurrentRoom() -> getObjects());
    }
}
