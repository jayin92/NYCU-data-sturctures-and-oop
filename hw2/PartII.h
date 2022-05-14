#ifndef PARTII_H
#include "SolverBase.h"

class PartII : public SolverBase
{
public:
    void read(std::string);
    void solve();
    void write(std::string);
};

#define PARTII_H
#endif