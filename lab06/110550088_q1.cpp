#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
/* Add whatever you want. */

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    stack<long long> s;
    long long t, op, x;
    cin >> t;
    while(t--){
        cin >> op;
        if(op == 0){
            cin >> x;
            s.push(x);
        } else {
            if(op == 1){
                if(s.empty()){
                    cout << "Not legal" << endl;
                } else {
                    s.pop();
                }
            } else if(op == 2){
                if(s.empty()) cout << "Not legal" << endl;
                else cout << s.top() << endl;
            } else if(op == 3){
                cout << s.size() << endl;
            }
        }
    }
    vector<long long> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    if(ans.size() == 0){
        cout << "No data" << endl;
    } else {
        reverse(ans.begin(), ans.end());
        for(auto i: ans){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}