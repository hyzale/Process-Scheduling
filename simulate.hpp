#ifndef SIMULATE
#define SIMULATE

#include <iostream>
#include <chrono>
#include <string>
#include "Scheduler.hpp"
#include "Process.hpp"
#include "ArrayList.hpp"

double* simulate(Scheduler* sched, int numCPUBound, int numIOBound, int numCycles);


#endif
