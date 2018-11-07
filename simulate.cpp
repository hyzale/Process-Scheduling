#include "Scheduler.hpp"
#include "Process.hpp"
#include "ArrayList.hpp"
#include <iostream>
#include <chrono>
#include <string>

using namespace std;

double* simulate(Scheduler* sched, int numCPUBound, int numIOBound, int numCycles) {
    List<Process*>* procs = new ArrayList<Process *>();
    Process* p = NULL;
    int i;
    int popNextCalled = 0;

    for (i = 1; i <= numCPUBound; i++) {
        procs->pushBack((p = new CPUBoundProcess(i)));
        sched->addProcess(p);
    }
    for (; i <= numCPUBound + numIOBound; i++) {
        procs->pushBack((p = new IOBoundProcess(i)));
        sched->addProcess(p);
    }

    auto startTime = chrono::system_clock::now();
    for(int iter = 1; iter <= numCycles;) {
        // cout << iter << endl;
        Process* next = sched->popNext(iter);
        popNextCalled++;

        if (!next) {
            iter += 10;
        } else {
            int cyclePassed = next->useCPU(iter, 10);
            iter += cyclePassed;
            sched->addProcess(next);
        }
    }
    auto dur = chrono::system_clock::now() - startTime;

    double cput_cpubd = 0, wt_cpubd = 0, cput_iobd = 0, wt_iobd = 0;
    for (i = 1; i <= numCPUBound; i++) {
        Process* p = procs->getFront();
        cput_cpubd += p->getCPUTime();
        wt_cpubd += p->getWaitTime(numCycles);
        procs->popFront();
        delete p;
    }
    for (; i <= numCPUBound + numIOBound; i++) {
        Process* p = procs->getFront();
        cput_iobd += p->getCPUTime();
        wt_iobd += p->getWaitTime(numCycles);
        procs->popFront();
        delete p;
    }
    delete procs;

    double* res = new double[5];
    res[0] = chrono::duration_cast<chrono::nanoseconds>(dur).count() / popNextCalled; // ns simulation / popnext called
    res[1] = cput_cpubd / numCPUBound; // avg cpu time of al cpubound procs
    res[2] = wt_cpubd / numCPUBound; // avg wait time of al cpubound procs
    res[3] = cput_iobd / numIOBound; // avg cpu time of al iobound procs
    res[4] = wt_iobd / numIOBound; // avg wait time of al iobound procs
    return res;
}



