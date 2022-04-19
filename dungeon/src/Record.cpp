#include "../include/Record.h"

Record::Record(){}

void Record::savePlayer(Player* player, ofstream& out){
    out << player -> getName() << endl;
    out << player -> getMaxHealth() << endl;
    out << player -> getCurrentHealth() << endl;
    out << player -> getAttack() << endl;
    out << player -> getDefense() << endl;
    out << player -> getCurrentRoom() -> getIndex() << endl;
    out << (player -> getPreviousRoom() != nullptr ? player -> getPreviousRoom() -> getIndex() : -1) << endl;
    out << player->getInventory().size() << endl;
    for(auto i: player->getInventory()){
        saveItem(&i, out, true);
    }
    if(player->getHead() != nullptr){
        out << "head" << endl;
        saveItem(player->getHead(), out, true);
    } else {
        out << "null" << endl;
    }
    if(player->getBody() != nullptr){
        out << "body" << endl;
        saveItem(player->getBody(), out, true);
    } else {
        out << "null" << endl;
    }
    if(player->getLeft() != nullptr){
        out << "left" << endl;
        saveItem(player->getLeft(), out, true);
    } else {
        out << "null" << endl;
    }
    if(player->getRight() != nullptr){
        out << "right" << endl;
        saveItem(player->getRight(), out, true);
    } else {
        out << "null" << endl;
    }
    out << player->getPotions().size() << endl;
    for(auto i: player->getPotions()){
        saveItem(&i, out, true);
    }
    out << player->getKeys().size() << endl;
    for(auto i: player->getKeys()){
        saveItem(&i, out, true);
    }
}

void Record::saveRooms(vector<Room*>& rooms, ofstream& out){
    out << rooms.size() << endl;
    for(auto i: rooms){
        out << i->getIndex() << endl;
        out << i->getIsExit() << endl;
        out << (i->getRoomKey()==nullptr ? "null" : i->getRoomKey()->getName()) << endl;
        if(i->getUpRoom() != nullptr){
            out << i->getUpRoom() -> getIndex() << endl;
        } else{
            out << "null" << endl;
        }
        if(i->getDownRoom() != nullptr){
            out << i->getDownRoom() -> getIndex() << endl;
        } else{
            out << "null" << endl;
        }
        if(i->getLeftRoom() != nullptr){
            out << i->getLeftRoom() -> getIndex() << endl;
        } else{
            out << "null" << endl;
        }
        if(i->getRightRoom() != nullptr){
            out << i->getRightRoom() -> getIndex() << endl;
        } else{
            out << "null" << endl;
        }
        out << i->getObjects().size() << endl;
        for(auto j: i->getObjects()){
            if(j->getTag() == "Item"){
                saveItem(dynamic_cast<Item*>(j), out, false);
            } else if(j->getTag() == "Monster"){
                saveMonster(dynamic_cast<Monster*>(j), out);
            } else if(j->getTag() == "NPC"){
                saveNPC(dynamic_cast<NPC*>(j), out);
            }
        }
    }
}

void Record::saveItem(Item* item, ofstream& out, bool isNPC){
    if(isNPC == false) out << "item" << endl;
    out << item->getName() << endl;
    out << item->getType() << endl;
    out << item->getHealth() << endl;
    out << item->getAttack() << endl;
    out << item->getDefense() << endl;
}

void Record::saveMonster(Monster* monster, ofstream& out){
    out << "monster" << endl;
    out << monster->getName() << endl;
    out << monster->getMaxHealth() << endl;
    out << monster->getCurrentHealth() << endl;
    out << monster->getAttack() << endl;
    out << monster->getDefense() << endl;
}
void Record::saveNPC(NPC* npc, ofstream& out){
    out << "npc" << endl;
    out << npc->getName() << endl;
    out << npc->getScript() << endl;
    out << "-" << endl;
    out << npc->getCommodity().size() << endl;
    for(auto i: npc->getCommodity()){
        saveItem(&i, out, true);
    }
}

void Record::loadItem(Item* item, ifstream& in){
    string name;
    in.ignore();
    getline(in, name);
    item->setName(name);
    string type;
    in >> type;
    item->setType(type);
    int health;
    in >> health;
    item->setHealth(health);
    int attack;
    in >> attack;
    item->setAttack(attack);
    int defense;
    in >> defense;
    item->setDefense(defense);
}

void Record::loadMonster(Monster* monster, ifstream& in){
    string name;
    in.ignore();
    getline(in, name);
    monster->setName(name);
    int maxHealth;
    in >> maxHealth;
    monster->setMaxHealth(maxHealth);
    int currentHealth;
    in >> currentHealth;
    monster->setCurrentHealth(currentHealth);
    int attack;
    in >> attack;
    monster->setAttack(attack);
    int defense;
    in >> defense;
    monster->setDefense(defense);
}

void Record::loadNPC(NPC* npc, ifstream& in){
    string name;
    in.ignore();
    getline(in, name);
    npc->setName(name);
    string script = "";
    while(true){
        string line;
        getline(in, line);
        if(line == "-"){
            break;
        }
        script += line + "\n";
    }
    // cout << script << endl;
    npc->setScript(script);
    vector<Item> commodity;
    int size;
    in >> size;
    for(int i = 0; i < size; i++){
        Item item;
        loadItem(&item, in);
        commodity.push_back(item);
    }
    npc->setCommodity(commodity);
}

void Record::loadPlayer(Player* player, vector<Room*> &rooms, ifstream& in){
    *player = Player();
    player -> setTag("player");
    string name;
    in.ignore();
    getline(in, name);
    player->setName(name);
    int maxHealth;
    in >> maxHealth;
    player->setMaxHealth(maxHealth);
    int currentHealth;
    in >> currentHealth;
    player->setCurrentHealth(currentHealth);
    int attack;
    in >> attack;
    player->setAttack(attack);
    int defense;
    in >> defense;
    player->setDefense(defense);
    int currentRoom;
    in >> currentRoom;
    player->setCurrentRoom(rooms[currentRoom]);
    int previousRoom;
    in >> previousRoom;
    if(previousRoom != -1){
        player->setPreviousRoom(rooms[previousRoom]);
    } else {
        player->setPreviousRoom(nullptr);
    }
    int inventorySize;
    in >> inventorySize;
    for(int i = 0; i < inventorySize; i++){
        Item* item = new Item;
        loadItem(item, in);
        player->addItem(*item);
    }
    string head;
    in >> head;
    if(head != "null"){
        Item* item = new Item;
        loadItem(item, in);
        player->increaseStates(-item->getHealth(), -item->getAttack(), -item->getDefense());
        player->setHead(item);
    }
    string body;
    in >> body;
    if(body != "null"){
        Item* item = new Item;
        loadItem(item, in);
        player->increaseStates(-item->getHealth(), -item->getAttack(), -item->getDefense());
        player->setBody(item);
    }
    string left;
    in >> left;
    if(left != "null"){
        Item* item = new Item;
        loadItem(item, in);
        player->increaseStates(-item->getHealth(), -item->getAttack(), -item->getDefense());
        player->setLeft(item);
    }
    string right;
    in >> right;
    if(right != "null"){
        Item* item = new Item;
        loadItem(item, in);
        player->increaseStates(-item->getHealth(), -item->getAttack(), -item->getDefense());
        player->setRight(item);
    }
    int potionSize;
    in >> potionSize;
    for(int i = 0; i < potionSize; i++){
        Item* item = new Item;
        loadItem(item, in);
        player->addItem(*item);
    }
    int keySize;
    in >> keySize;
    for(int i = 0; i < keySize; i++){
        Item* item = new Item;
        loadItem(item, in);
        player->addItem(*item);
    }
}

void Record::loadRooms(vector<Room*>& rooms, ifstream& in){
    rooms.clear();
    int sz;
    in >> sz;
    // cout << sz << endl;
    vector<int> up_idx(sz, -1);
    vector<int> down_idx(sz, -1);
    vector<int> left_idx(sz, -1);
    vector<int> right_idx(sz, -1);

    for(int i=0;i<sz;i++){
        Room* room = new Room;
        int idx;
        in >> idx;
        // cout << "-" << endl;
        // cout << idx << endl;
        room->setIndex(idx);
        bool isExit;
        in >> isExit;
        room->setIsExit(isExit);
        string temp;
        in.ignore();
        getline(in, temp);
        if(temp != "null"){
            room->setRoomKey(new Item(temp, "key", 0, 0, 0));
        }
        in >> temp;
        // cout << temp << endl;
        if(temp != "null"){
            up_idx[i] = stoi(temp);
        }
        in >> temp;
        // cout << temp << endl;
        if(temp != "null"){
            down_idx[i] = stoi(temp);
        }
        in >> temp;
        // cout << temp << endl;
        if(temp != "null"){
            left_idx[i] = stoi(temp);
        }
        in >> temp;
        // cout << temp << endl;
        if(temp != "null"){
            right_idx[i] = stoi(temp);
        }
        int objSz;
        in >> objSz;
        // cout << "obj" << endl;
        // cout << objSz << endl;
        for(int j=0;j<objSz;j++){
            string tag;
            in >> tag;
            // cout << tag << endl;
            if(tag == "item"){
                Item* item = new Item;
                loadItem(item, in);
                room->addObject(item);
            } else if(tag == "monster"){
                Monster* monster = new Monster;
                loadMonster(monster, in);
                room->addObject(monster);
            } else if(tag == "npc"){
                NPC* npc = new NPC;
                npc->setTag("NPC");
                loadNPC(npc, in);
                room->addObject(npc);
            }
        }
        rooms.push_back(room);
    }
    for(int i=0;i<sz;i++){
        if(up_idx[i] != -1){
            rooms[i]->setUpRoom(rooms[up_idx[i]]);
        }
        if(down_idx[i] != -1){
            rooms[i]->setDownRoom(rooms[down_idx[i]]);
        }
        if(left_idx[i] != -1){
            rooms[i]->setLeftRoom(rooms[left_idx[i]]);
        }
        if(right_idx[i] != -1){
            rooms[i]->setRightRoom(rooms[right_idx[i]]);
        }
    }
}

void Record::saveToFile(Player* player, vector<Room*>& rooms){
    string filename = "record.txt";
    // cout << "Enter record filename: ";
    // cin >> filename;
    ofstream out;
    out.open(filename);
    saveRooms(rooms, out);
    savePlayer(player, out);
    out.close();
}

void Record::loadFromFile(Player* player, vector<Room*>& rooms){
    string filename = "record.txt";
    // cout << "Enter record filename: ";
    // cin >> filename;
    ifstream in;
    in.open(filename);
    if(in.fail()){
        cout << "Record file not found." << endl;
        return;
    }
    loadRooms(rooms, in);
    loadPlayer(player, rooms, in);
}