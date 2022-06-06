#include "Part1.h"

using namespace std;

bool operator<(const pair<int, int>& a, const pair<int, int>& b){
    return (a.first < b.first) || (a.first == b.first && a.second < b.second);
}

void PartI::read(string file) {
    cout << "Part I reading..." << endl;
    ifstream ifs(file); // Use input file stream to read input from file
    ifs >> n >> m; // Get # of vertices n and # of edges m
    // Resize the vector
    graph.resize(n);
    rev_graph.resize(n);
    scc.resize(n);
    int u, v, w;

    // Build graph 
    for(int i=0;i<m;i++){
        ifs >> u >> v >> w;
        graph[u].push_back({v, 1});
        rev_graph[v].push_back({u, 1});
    }
    // Close the ifstream
    ifs.close();

    // Because we need to traverse from smallest index to the largest, thus we need to sort the adj. list
    for(int i=0;i<n;i++){
        sort(graph[i].begin(), graph[i].end());
    }
}

void PartI::solve() {
    cout << "Part I solving..." << endl;
    for(int i=0;i<n;i++){
        // Run DFS for not yet traversed vertex
        if(finish[i] == 0){
            dfs(i);
        }
    }

    if(isAyclic){
        // If is acylic, then reverse the order to get real topological ordering
        reverse(order.begin(), order.end());
        return;
    }
    
}

void PartI::write(string file) {
    cout << "Part I writing..." << endl;
    ofstream ofs(file); // use output filestream to write output to file
    if(isAyclic){
        // Write the topological ordering to file
        for(auto i: order){
            ofs << i << " ";
        }
        ofs << endl;
        // After writing the to the file, directly exit the function
        return;
    }
    // If not ayclic, then run Kosaraju's algorithtm to find SCC
    kosaraju();
    // After running Kosaraju's algorithtm, vertex will have a label which indicates that which SCC it belongs to.
    // This information will save in vector<int> scc.
    // cnt is # of SCC in the given graph.
    scc_vertex.resize(cnt, {1e9, {}}); // scc_vertex will save the minimum index and every vertex in each SCC.
    // Iterate all vertices in the graph.
    for(int i=0;i<n;i++){
        int u = scc[i];
        scc_vertex[u].first = min(scc_vertex[u].first, i);
        scc_vertex[u].second.push_back(i); 
    }
    sort(scc_vertex.begin(), scc_vertex.end()); // Sort the SCCs based on the minimum index.

    // Relabel the vertices to match the new index value of every SCC
    for(int i=0;i<cnt;i++){
        for(auto j: scc_vertex[i].second){
            scc[j] = i;
        }
    }

    // Build coarse graph
    buildGraph();
    // After running the above function, we will get the coarse graph and save as map.

    ofs << cnt << " " << scc_graph.size() << endl; // Output the # of vertcies and edges

    // Because map will sort by key, we don't need to sort the map.
    for(auto i: scc_graph){
        ofs << i.first.first << " " << i.first.second << " " << i.second << endl;
    }

    // Close output filestream
    ofs.close();
    return;
}

void PartI::dfs(int v){
    // Back edge, cyclic
    if(finish[v] == 1){
        isAyclic = false;
        return;
    }

    // forward edge or cross edge
    if(finish[v] == 2){
        return;
    }

    // mark 1
    finish[v] = 1;
    for(auto i: graph[v]){
        dfs(i.first);
    }

    // mark 2
    finish[v] = 2;
    order.push_back(v);
}

void PartI::scc_revdfs(int v){
    // DFS runs on reverse graph
    finish[v] = 1;
    for(auto i: rev_graph[v]){
        if(finish[i.first] == 0){
            scc_revdfs(i.first);
        }
    }
    order.push_back(v);
}

void PartI::scc_dfs(int cur, int s){
    // DFS runs on graph and lable the vertices
    scc[cur] = s;
    for(auto i: graph[cur]){
        int u = i.first;
        if(scc[u] == -1){
            scc_dfs(u, s);
        }
    }
}

void PartI::kosaraju(){
    order.clear();  // Clear the original order
    finish.clear(); // Clear the vector
    scc.resize(n);  // Resize the vector that store vertex belongs to SCC
    fill(scc.begin(), scc.end(), -1); // Fill the vector with -1
    for(int i=0;i<n;i++){
        if(finish[i] == 0){ // If not yet traversed, then run DFS on reverse graph.
            scc_revdfs(i);
        }
    }
    cnt = 0; // Store the # of SCC
    reverse(order.begin(), order.end());
    // Use topological ordering of reverse graph to get SCC
    for(auto i: order){
        if(scc[i] == -1){    // Not in any SCC
            scc_dfs(i, cnt); // Run DFS
            cnt ++;
        }
    }
}

void PartI::buildGraphDFS(int v){
    finish[v] = 1;
    for(auto i: graph[v]){ // Iterate all edges that connect to vertex v
        int u = i.first;
        if(scc[v] != scc[u]){
            scc_graph[{scc[v], scc[u]}] ++; // If two vertices belongs to different SCC, then this edge will appear in coarse graph and weight will plus 1
        }
        if(finish[u] == 0){ // If not yet visited, then run DFS
            buildGraphDFS(u);
        }
    }
}

void PartI::buildGraph(){
    finish.clear(); // Clear the vector that records visited vertices
    for(int i=0;i<n;i++){
        if(finish[i] == 0){
            buildGraphDFS(i);
        }
    }
}