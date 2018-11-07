#include "Scheduler.hpp"
#include "ArrayList.hpp"

RoundRobin::RoundRobin() {
    procQueue = new ArrayList<Process *>();
}

RoundRobin::~RoundRobin() {
    delete procQueue;
}

void RoundRobin::addProcess(Process* proc) {
    procQueue->pushBack(proc);
}

Process* RoundRobin::popNext(int curCycle) {
    Process* result = procQueue->getFront(), *first = result;
    procQueue->popFront();
    while (result != NULL && result->isBlocked(curCycle)) {
        procQueue->pushBack(result);
        result = procQueue->getFront();
        procQueue->popFront();
        if (result == first) {
            return NULL;
        }
    }
    return result;
}
