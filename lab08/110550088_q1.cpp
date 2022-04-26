#include <iostream>

using namespace std;

struct Node{
    Node* left = nullptr;
    Node* right = nullptr;
    int val;
    Node(int _val){
        val = _val;
    }
};

void preOrder(Node* cur){
    cout << cur -> val << endl;
    if(cur -> left) preOrder(cur->left);
    if(cur -> right) preOrder(cur->right);
}

void inOrder(Node* cur){
    if(cur -> left) inOrder(cur->left);
    cout << cur -> val << endl;
    if(cur -> right) inOrder(cur->right);
}

void postOrder(Node* cur){
    if(cur -> left) postOrder(cur->left);
    if(cur -> right) postOrder(cur->right);
    cout << cur -> val << endl;
}

int main(){
    int n;
    cin >> n;
    Node* root = new Node(n);
    while(cin >> n){
        Node* cur = root;
        while(true){
            if(n > cur->val){
                if(cur -> right == nullptr){
                    cur -> right = new Node(n);
                    break;
                }
                cur = cur -> right;
            } else {
                if(cur -> left == nullptr){
                    cur -> left = new Node(n);
                    break;
                }
                cur = cur -> left;
            }
        }
    }
    cout << "PreOrder" << endl;
    preOrder(root);
    cout << "InOrder" << endl;
    inOrder(root);
    cout << "PostOrder" << endl;
    postOrder(root);

}