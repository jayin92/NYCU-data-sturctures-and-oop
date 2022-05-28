#ifndef PARTI_H
#include "SolverBase.h"
#include <algorithm>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>

using namespace std;

class PartI : public SolverBase
{
int n, m, cnt;
vector<vector<pair<int, int>>> graph; // Declare an adjacency list to save the graph (pair fisrt: vertex second: weight)
vector<vector<pair<int, int>>> rev_graph; // Declare an adjacency list to save the "reverse" graph (pair fisrt: vertex second: weight)
map<pair<int, int>, int> scc_graph;  // Use map to save edges and theirs weights
vector<pair<int, vector<int>>> scc_vertex; // Save the id of each vertices in every SCC
vector<int> order; // Save topological order
vector<int> scc; // Save the id of corresponding SCC of each vertex

map<int, int> finish; // Store the status of vertex when traversing
bool isAyclic = true; // To store that this graph is acyclic or not

public:
    void read(std::string); // Read input from file
    void solve(); // Main solve function
    void write(std::string); // Write output to file
    void dfs(int); // DFS
    void scc_dfs(int, int); // Run dfs to get SCC
    void scc_revdfs(int); // Run reverse dfs to get SCC
    void kosaraju(); // The main part of Kosaraju's Algorithm
    void buildGraph(); // Build coarse graph
    void buildGraphDFS(int); // Use dfs to build the coarse graph
};

#define PARTI_H
#endif