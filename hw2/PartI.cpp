#include "PartI.h"
#include <iostream>
#include <fstream>

using namespace std;

bool operator<(const pair<int, int>& a, const pair<int, int>& b){
    return (a.first < b.first) || (a.first == b.first && a.second < b.second);
}

void PartI::read(string file) {
    cout << "Part I reading..." << endl;
    ifstream ifs(file);
    ifs >> n >> m;
    graph.resize(n);
    rev_graph.resize(n);
    scc.resize(n);
    int u, v, w;
    for(int i=0;i<m;i++){
        ifs >> u >> v >> w;
        graph[u].push_back({v, w});
        rev_graph[v].push_back({u, w});
    }
    ifs.close();
}

void PartI::solve() {
    cout << "Part I solving..." << endl;
    for(int i=0;i<n;i++){
        if(finish[i] == 0){
            dfs(i);
        }
    }
    if(isAyclic){
        reverse(order.begin(), order.end());
        return;
    }
    
}

void PartI::write(string file) {
    cout << "Part I writing..." << endl;
    ofstream ofs(file);
    if(isAyclic){
        for(auto i: order){
            ofs << i << " ";
        }
        ofs << endl;
        return;
    }
    kosaraju();
    scc_vertex.resize(cnt, {1e9, {}});
    for(int i=0;i<n;i++){
        int u = scc[i];
        scc_vertex[u].first = min(scc_vertex[u].first, i);
        scc_vertex[u].second.push_back(i); 
    }
    sort(scc_vertex.begin(), scc_vertex.end());
    for(int i=0;i<cnt;i++){
        for(auto j: scc_vertex[i].second){
            scc[j] = i;
        }
    }

    buildGraph();

    ofs << cnt << " " << scc_graph.size() << endl;
    for(auto i: scc_graph){
        ofs << i.first.first << " " << i.first.second << " " << i.second << endl;
    }

    ofs.close();
    return;
}

void PartI::dfs(int v){
    if(finish[v] == 1){
        isAyclic = false;
        return;
    }
    if(finish[v] == 2){
        return;
    }

    finish[v] = 1;
    for(auto i: graph[v]){
        dfs(i.first);
    }
    finish[v] = 2;
    order.push_back(v);
}

void PartI::scc_revdfs(int v){
    finish[v] = 1;
    for(auto i: rev_graph[v]){
        if(finish[v] == 0){
            scc_revdfs(i.first);
        }
    }
    order.push_back(v);
}

void PartI::scc_dfs(int cur, int s){
    scc[cur] = s;
    for(auto i: graph[cur]){
        int u = i.first;
        if(scc[u] == -1){
            scc_dfs(u, s);
        }
    }
}

void PartI::kosaraju(){
    order.clear();
    finish.clear();
    scc.resize(n);
    fill(scc.begin(), scc.end(), -1);
    for(int i=0;i<n;i++){
        if(finish[i] == 0){
            scc_revdfs(i);
        }
    }
    cnt = 0;
    reverse(order.begin(), order.end());
    for(auto i: order){
        if(scc[i] == -1){
            scc_dfs(i, cnt);
            cnt ++;
        }
    }
}

void PartI::buildGraphDFS(int v){
    finish[v] = 1;
    for(auto i: graph[v]){
        int u = i.first;
        if(scc[v] != scc[u]){
            scc_graph[{scc[v], scc[u]}] ++;
        }
        if(finish[u] == 0){
            buildGraphDFS(u);
        }
    }
}

void PartI::buildGraph(){
    finish.clear();
    for(int i=0;i<n;i++){
        if(finish[i] == 0){
            buildGraphDFS(i);
        }
    }
}