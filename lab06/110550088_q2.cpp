#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    int t, line;
    line = 1;
    while(cin >> t){
        if(t == 0) break;
        cout << "Scenario #" << line++ << endl; 
        vector<int> group(1000005, -1);
        vector<queue<int>> mem(t);
        deque<int> q;
        int n;
        int x;
        for(int i=0;i<t;i++){
            cin >> n;
            for(int j=0;j<n;j++){
                cin >> x;
                group[x] = i;
            }
        }
        string s;
        while(cin >> s){
            if(s == "STOP"){
                break;
            }
            if(s == "ENQUEUE"){
                cin >> x;
                int g = group[x];
                mem[g].push(x);
                bool flag = true;
                for(auto i: q){
                    if(i == g){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    q.push_back(g);
                }
            } else if(s == "DEQUEUE"){
                if(q.empty()) continue;
                int y = q.front();
                cout << mem[y].front() << endl;
                mem[y].pop();
                if(mem[y].empty()){
                    q.pop_front();
                }
            }
        }
        cout << endl;
    }
    
}