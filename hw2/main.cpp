#include <iostream>
#include <cassert>
#include <string>
#include "PartI.h"
#include "PartII.h"

using namespace std;

int main(int argc, char* argv[])
{
    assert(argc == 4);
    string inputFile = argv[1];
    string outputFileI = argv[2];
    string outputFileII = argv[3];

    SolverBase* solver_1 = new PartI();
    solver_1->read(inputFile);
    solver_1->solve();
    solver_1->write(outputFileI);
    delete solver_1;

    SolverBase* solver_2 = new PartII();
    solver_2->read(inputFile);
    solver_2->solve();
    solver_2->write(outputFileII);
    delete solver_2;
    
    cout << "Solved." << endl;
}
