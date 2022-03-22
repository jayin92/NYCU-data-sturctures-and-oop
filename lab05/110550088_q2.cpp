#include <iostream>
using namespace std;

class Room{
public:
    Room *left_room;
    Room *right_room;
    int index;
    Room(Room* left, int idx): left_room(left), index(idx), right_room(nullptr){}
  //add constructor or functions if you need
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    Room* prev = nullptr;
    Room* head = nullptr;
    int x;
    while(n--){
        cin >> x;
        if(head == nullptr){
            head = new Room(prev, x);
            prev = head;
        } else {
            prev = prev -> right_room = new Room(prev, x);
        }
    }
    int t;
    cin >> t;
    Room* cur = head;
    char c;
    cout << cur -> index << " ";
    while(t--){
        cin >> c;
        if(c == 'r'){
            if(cur -> right_room == nullptr){
                cout << -1 << " ";    
            } else {
                cur = cur -> right_room;
                cout << cur -> index << " ";
            }
        } else {
            if(cur -> left_room == nullptr){
                cout << -1 << " ";    
            } else {
                cur = cur -> left_room;
                cout << cur -> index << " ";
            }
        }
    }
    cout << endl;
    return 0;
}