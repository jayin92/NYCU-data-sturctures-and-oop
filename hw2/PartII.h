#ifndef PARTII_H
#include "SolverBase.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

class PartII : public SolverBase
{
    int n, m; // # of vertices and edges
    bool hasNegCyc = false; // has negative cycle in the graph or not
    vector<vector<pair<int, int>>> adj; // Declare an adjacency list to save the graph (pair fisrt: vertex second: weight)
    vector<vector<pair<int, int>>> abs_adj; // Declare an adjacency list to save the graph (pair fisrt: vertex second: abs(weight))
    vector<int> d, abs_d; // The shortest distance from node 0 to every other vertices
public:
    void read(std::string); // Read input from file
    void solve(); // Main solve fucntion
    void write(std::string); // Write the output to file
    void dijkstra(int); // Dijkstra's Algorithm
    bool bellmanFord(int); // Bellman-Ford's Algorithm
};

#define PARTII_H
#endif