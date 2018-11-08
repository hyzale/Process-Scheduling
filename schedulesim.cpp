#include "Scheduler.hpp"
#include "Process.hpp"
#include "ArrayList.hpp"
#include "simulate.hpp"

#include <iostream>
#include <chrono>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    // std::cout << argc;
    if (argc != (1 + 3)) {
        return -1;
    }
    int nCPUBoundProcess = stoi(argv[1]);
    int nIOBoundProcess = stoi(argv[2]);
    int nCycles = stoi(argv[3]);

    RoundRobin* RR = new RoundRobin();
    FastRoundRobin* FRR = new FastRoundRobin();
    CompletelyFair* CF = new CompletelyFair();
    FastCompletelyFair* FCF = new FastCompletelyFair();

    Scheduler** sche = new Scheduler*[4];
    sche[0] = RR;
    sche[1] = FRR;
    sche[2] = CF;
    sche[3] = FCF;

    string label[4];
    label[0] = "RoundRobin";
    label[1] = "FastRoundRobin";
    label[2] = "CompletelyFair";
    label[3] = "FastCompletelyFair";

    for (int i = 0; i <= 3; i++) {
        double* res = simulate(sche[i], nCPUBoundProcess, nIOBoundProcess, nCycles);

        for(int i = 0; i <= 3; i++)
            cout << res[i] << ' ';

        cout << label[i] << endl;  
    }

    delete[] sche;
    delete RR; delete FRR; delete CF; delete FCF;
    return 0;
}

