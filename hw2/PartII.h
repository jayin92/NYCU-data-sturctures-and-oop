#ifndef PARTII_H
#include "SolverBase.h"

class PartII : public SolverBase
{
    int n, m;
    bool hasNegCyc = false;
    vector<vector<pair<int, int>>> adj;
    vector<vector<pair<int, int>>> abs_adj;
    vector<int> d;
public:
    void read(std::string);
    void solve();
    void write(std::string);
    void dijkstra(int);
    bool bellmanFord(int);
};

#define PARTII_H
#endif