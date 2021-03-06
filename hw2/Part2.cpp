#include "Part2.h"

#define INF 1e9

using namespace std;

void PartII::read(string file) {
    cout << "Part II reading..." << endl;
    ifstream ifs(file); // Decalre a input filestream to get input from file
    ifs >> n >> m; // input # of vertices and edges
    // Resize the vectors
    d.resize(n);
    abs_d.resize(n);
    adj.resize(n); 
    abs_adj.resize(n);
    
    // Build graph from input
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
    dijkstra(0); // Run from Dijkstra's algorithm from node 0

    // Run Bellman-Ford algorithm from node 0.
    // And if function return false, it means there is negative cycle in the graph
    hasNegCyc = !bellmanFord(0); 
}

void PartII::write(string file) {
    cout << "Part II writing..." << endl;
    ofstream ofs(file);
    ofs << abs_d[n-1] << endl; // Output the Dijkstra algorithm's output

    if(hasNegCyc){
        ofs << "Negative loop detected!" << endl; // If has negative cycle, then output "Negative loop detected!"
    } else {
        ofs << d[n-1] << endl; // Otherwise, output the Bellman-Ford algorithm's output
    }

    ofs.close(); // Close output file stream
}


void PartII::dijkstra(int src){
    fill(abs_d.begin(), abs_d.end(), INF); // Fill the distance vector w/ INF value
    abs_d[src] = 0; // The distance from node 0 to node 0 is 0

    // Use priority_queue to get the vertex with the smallest distance from node 0 in every step
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // first: weight, second: vertex

    // Push the initial node 0 to pq
    pq.push({0, 0});

    // If pq is not empty, keep running the relax process
    while(!pq.empty()){
        auto edge = pq.top();
        pq.pop();
        int u = edge.second;
        for(auto i: abs_adj[u]){
            int v = i.first;
            int w = i.second;
            int alt = abs_d[u] + w; // Alternate path's distance

            // If alternate distance less than current distance save in distance vector
            if(alt < abs_d[v]){
                abs_d[v] = alt;    // Update the distance in distance vector
                pq.push({alt, v}); // Update the new distance to pq
            }
        }
    }
}

bool PartII::bellmanFord(int src){
    fill(d.begin(), d.end(), INF); // Fill the distance vector w/ INF value
    d[src] = 0; // The distance from node 0 to node 0 is 0

    // Run n-1 times of relaxation process
    for(int i=0;i<n-1;i++){
        for(int u=0;u<n;u++){
            for(auto k: adj[u]){
                int v = k.first;
                int w = k.second;
                int alt = d[u] + w;

                // If alternate distance less than current distance save in distance vector
                if(d[u] != INF && alt < d[v]){
                    d[v] = alt; // Update the distance in distance vector
                }
            }
        }
    }


    for(int u=0;u<n;u++){
        for(auto k: adj[u]){
            int v = k.first;
            int w = k.second;
            int alt = d[u] + w;
            if(d[u] != INF && alt < d[v]){
                // If there still have edge that can be relaxed in nth times of relaxation process.
                // Then there exists a negative cycle
                return false;
            }
        }
    }

    return true;
}
