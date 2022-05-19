#include "PartII.h"

#define INF 1e9

using namespace std;

void PartII::read(string file) {
    cout << "Part II reading..." << endl;
    ifstream ifs(file);
    ifs >> n >> m;
    d.resize(n);
    adj.resize(n);
    abs_adj.resize(n);
    int u, v, w;
    for(int i=0;i<m;i++){
        ifs >> u >> v >> w;
        adj[u].push_back({v, w});
        abs_adj[u].push_back({v, abs(w)});
    }
     
    ifs.close();
}
void PartII::solve() {
    cout << "Part II solving..." << endl;
    dijkstra(0);
    hasNegCyc = !bellmanFord(0);
}

void PartII::write(string file) {
    cout << "Part II writing..." << endl;
    ofstream ofs(file);
    ofs << "Dijkstra Cost: " << d[n-1] << endl;
    if(hasNegCyc){
        ofs << "Negative loop detected!" << endl;
    } else {
        ofs << "Bellman Ford Cost: " << d[n-1] << endl;
    }
    ofs.close();
}


void PartII::dijkstra(int src){
    fill(d.begin(), d.end(), INF);
    d[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(int i=0;i<n;i++){
        pq.push({INF, i});
    }
    while(!pq.empty()){
        auto edge = pq.top();
        pq.pop();
        int u = edge.second;
        for(auto i: abs_adj[u]){
            int w = i.first;
            int v = i.second;
            int alt = d[u] + i.first;
            if(alt < d[v]){
                d[v] = alt;
                pq.push({alt, v});
            }
        }
    }
}

bool PartII::bellmanFord(int src){
    fill(d.begin(), d.end(), INF);
    d[src] = 0;
    for(int i=0;i<n-1;i++){
        for(int u=0;u<n;u++){
            for(auto k: adj[u]){
                int v = k.first;
                int w = k.second;
                int alt = d[u] + w;
                if(alt < d[v]){
                    d[v] = alt;
                }
            }
        }
    }
    for(int u=0;u<n;u++){
        for(auto k: adj[u]){
            int v = k.first;
            int w = k.second;
            int alt = d[u] + w;
            if(alt < d[v]){
                return false;
            }
        }
    }

    return true;
}
