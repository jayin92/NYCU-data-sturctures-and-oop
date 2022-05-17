#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> a(n+1);
    for(int i=0;i<m;i++){
        int u, v, w;
        cin >> u >> v >> w;
        a[u].push_back({v, w});
        a[v].push_back({u, w});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> vis(n+1, false);
    vector<pair<int, int>> parent(n+1, {-1, -1});
    vector<int> key(n+1, 1e9);
    pq.push({0, 1});
    key[1] = 0;
    while(!pq.empty()){
        auto v = pq.top().second;
        pq.pop();
        if(vis[v]) continue;

        vis[v] = true;
        for(auto i: a[v]){
            if(!vis[i.first] && key[i.first] > i.second){
                key[i.first] = i.second;
                pq.push({i.second, i.first});
                parent[i.first] = {v, i.second};
            }
        }
    }
    vector<tuple<int, int, int>> ans;
    for(int i=2;i<=n;i++){
        int u = parent[i].first;
        int v = i;
        if(u > v) swap(u, v);
        ans.emplace_back(u, v, parent[i].second);
    }
    sort(ans.begin(), ans.end());
    for(auto i: ans){
        cout << get<0>(i) << " " << get<1>(i) << " " << get<2>(i) << endl;
    }
     
}