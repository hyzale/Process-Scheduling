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

    Scheduler** sche = new Scheduler*[2];
    sche[0] = new RoundRobin();
    sche[1] = new FastRoundRobin();
    string label[2];
    label[0] = "RoundRobin";
    label[1] = "FastRoundRobin";

    for (int i = 0; i <= 1; i++) {
        double* res = simulate(sche[i], nCPUBoundProcess, nIOBoundProcess, nCycles);

        for(int i = 0; i <= 4; i++)
            cout << res[i] << ' ';

        cout << label[i] << endl;  
    }

    delete[] sche;

    return 0;
}

