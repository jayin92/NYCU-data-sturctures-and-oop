#ifndef PARTI_H
#include "SolverBase.h"
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

class PartI : public SolverBase
{
int n, m, cnt;
vector<vector<pair<int, int>>> graph;
vector<vector<pair<int, int>>> rev_graph;
map<pair<int, int>, int> scc_graph;
vector<pair<int, vector<int>>> scc_vertex;
vector<int> order;
vector<int> scc;

map<int, int> finish;
bool isAyclic = true;

public:
    void read(std::string);
    void solve();
    void write(std::string);
    void dfs(int);
    void scc_dfs(int, int);
    void scc_revdfs(int);
    void kosaraju();
    void buildGraph();
    void buildGraphDFS(int);
};

#define PARTI_H
#endif