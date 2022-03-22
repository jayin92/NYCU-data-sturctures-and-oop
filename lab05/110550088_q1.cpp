#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int _data, Node* _next, Node* _prev): data(_data), next(_next), prev(_prev) {}
};

class LinkedList
{
public:
    void push_front(int data)
    {
        if(head != nullptr){
            head = head -> prev = new Node(data, head, nullptr);
        } else {
            head = new Node(data, head, nullptr);
            tail = head;
        }
    }
  
    void push_back(int data)
    {  
        if(tail != nullptr){
            tail = tail -> next = new Node(data, nullptr, tail);
        } else {
            tail = new Node(data, nullptr, tail);
            head = tail;
        }
    }
  
    void pop_front()
    {
        Node* discard = head;
        if(discard == nullptr){
            head = tail = nullptr;
            return;
        }
        head = head -> next;
        if(head != nullptr)
            head -> prev = nullptr;
        delete discard;
    }
  
    void pop_back()
    {
        Node* discard = tail;
        if(discard == nullptr){
            head = tail = nullptr;
            return;
        }
        tail = tail -> prev;
        if(tail != nullptr)
            tail -> next = nullptr;

        delete discard;
    }
  
    void printList()
    {
        Node* cur = head;
        while(cur != nullptr){
            cout << cur -> data << " ";
            cur = cur -> next;
        }
        cout << endl;
    }
private:
    Node* head = nullptr;
    Node* tail = nullptr;
// Hint: maintain head and tail node pointing to begin and end of the list 
};
 
int main()
{
/* Hint: Read input from STDIN and perform the corresponding operation.*/
    LinkedList list;
    int t;
    cin >> t;
    int op, x;
    while(t--){
        cin >> op;
        if(op == 0){
            cin >> x;
            list.push_back(x);
        } else if(op == 1){
            cin >> x;
            list.push_front(x);
        } else if(op == 2){
            list.pop_back();
        } else if(op == 3){
            list.pop_front();
        }
    }
  	list.printList();
    return 0;
}