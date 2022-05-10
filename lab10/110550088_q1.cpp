#include <bits/stdc++.h>

using namespace std;

vector<bool> vis;
vector<vector<int>> adj;
set<int> cc;

void dfs(int src){
    cc.insert(src);
    vis[src] = true;
    for(auto i: adj[src]){
        if(!vis[i]){
            dfs(i);
        }
    }
}

int main(){
    int n;
    cin >> n;
    adj.resize(n);
    vis.resize(n, false);
    int t;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> t;
            if(t){
                adj[i].push_back(j);
            }
        }
    }
    for(int i=0;i<n;i++){
        if(!vis[i]){
            cc.clear();
            dfs(i);
            for(auto j: cc){
                cout << j << " ";
            }
            cout << endl;
        }
    }
}