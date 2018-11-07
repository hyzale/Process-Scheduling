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

    double* res = simulate(new RoundRobin(), nCPUBoundProcess, nIOBoundProcess, nCycles);

    for(int i = 0; i <= 4; i++)
        cout << res[i] << ' ';

    cout << endl;

    return 0;
}

