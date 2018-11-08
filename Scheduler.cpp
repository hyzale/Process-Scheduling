#include "Scheduler.hpp"


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

FastRoundRobin::FastRoundRobin() {
    delete procQueue;
    procQueue = new LinkedList<Process *>();
}

CompletelyFair::CompletelyFair() {
    procTree = new BSTMultimap<int, Process*>();
}

CompletelyFair::~CompletelyFair() {
    delete procTree;
}

void CompletelyFair::addProcess(Process* proc) {
    procTree->insert(proc->getCPUTime(), proc);
}

Process* CompletelyFair::popNext(int curCycle) {
    BSTForwardIterator<int, Process*> processIter = procTree->getMin();
    while(processIter.getValue()->isBlocked(curCycle)) {
        processIter.next();
    }
    Process* result = processIter.getValue();
    procTree->remove(processIter);
    return result;
}

FastCompletelyFair::FastCompletelyFair() {
    delete procTree;
    procTree = new RBTMultimap<int, Process*>();  
}
