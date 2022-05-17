#include <bits/stdc++.h>

using namespace std;


vector<int> dsu;

int find(int x){
    if(dsu[x] == x) return x;
    return dsu[x] = find(dsu[x]);
}

bool merge(int a, int b){
    int fa = find(a);
    int fb = find(b);
    if(fa == fb) return false;
    dsu[fa] = fb;

    return true;
}


int main(){
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> edge;
    for(int i=0;i<m;i++){
        int u, v, w;
        cin >> u >> v >> w;
        edge.emplace_back(w, min(u, v), max(u, v));
    }
    dsu.resize(n+1);
    for(int i=1;i<=n;i++) dsu[i] = i;
    vector<tuple<int, int, int>> ans;
    sort(edge.begin(), edge.end());
    for(auto i: edge){
        int u = get<1>(i);
        int v = get<2>(i);
        int w = get<0>(i);
        if(merge(u, v)){
            ans.emplace_back(u, v, w);
        }
    }
    sort(ans.begin(), ans.end());
    for(auto i: ans){
        cout << get<0>(i) << " " << get<1>(i) << " " << get<2>(i) << endl;
    }     
}