#include <bits/stdc++.h>

using namespace std;

class AVL{
public:

    struct Node{
        Node* left;
        Node* right;
        int val;
        int height;
        Node(int _val){
            left = right = nullptr;
            val = _val;
            height = 1;
        }
    };
    Node* root;
    AVL(){
        root = nullptr;
    }
    int getHeight(Node* node){
        if(node == nullptr){
            return 0;
        } else {
            return node -> height;
        }
    }

    int getBalance(Node* node){
        if(node == nullptr) return 0;
        else return getHeight(node->left) - getHeight(node->right);
    }

    Node* leftRotation(Node* node){
        Node* tmp = node -> right;
        node -> right = tmp -> left;
        tmp -> left= node;

        node -> height = max(getHeight(node->left), getHeight(node->right)) + 1;
        tmp -> height  = max(getHeight(tmp->left), getHeight(tmp->right)) + 1;

        return tmp;
    }

    Node* rightRotation(Node* node){
        Node* tmp = node -> left;
        node -> left = tmp -> right;
        tmp -> right = node;
        node -> height = max(getHeight(node->left), getHeight(node->right)) + 1;
        tmp -> height  = max(getHeight(tmp->left), getHeight(tmp->right)) + 1;

        return tmp;
    }

    Node* insert(Node* node, int val){
        if(node == nullptr){
            return new Node(val);
        }
        if(node -> val > val){
            node -> left = insert(node -> left, val);
        } else if(node -> val < val){
            node -> right = insert(node -> right, val);
        }
        node -> height = max(getHeight(node->left), getHeight(node->right)) + 1;
        int balance = getBalance(node);
        if(balance > 1 && node -> left -> val > val){ // LL
            node = rightRotation(node);

            return node;
        }
        if(balance < -1 && node -> right -> val < val){ // RR
            node = leftRotation(node);

            return node;
        }
        if(balance > 1 && node -> left -> val < val){ // LR
            node -> left = leftRotation(node->left);
            node = rightRotation(node);

            return node;
        }
        if(balance < -1 && node -> right -> val > val){ // RL
            node -> right = rightRotation(node->right);
            node = leftRotation(node);

            return node;
        }

        return node;
    }
    void insert(int val){
        root = insert(root, val);
    }
};

int main(){
    int n;
    cin >> n;
    int tmp;
    AVL avl;
    while(n--){
        cin >> tmp;
        avl.insert(tmp);
    }

    cout << avl.root -> val << endl;
}