
#ifndef SCHEDULER
#define SCHEDULER

#include "Process.hpp"
#include "List.hpp"
#include "ArrayList.hpp"
#include "LinkedList.hpp"
#include "BSTMultimap.hpp"
#include "RBTMultimap.hpp"

class Scheduler 
{
  public:

   //adds the given process to the processes to be scheduled
   virtual void addProcess(Process* proc) {
    };

   //removes and returns the next process in the schedule.
   //(Returns 0 if there is no available process).
   virtual Process* popNext(int curCycle) {
    return 0;
   };

   virtual ~Scheduler() = default;

};

class RoundRobin : public Scheduler
{
  protected:
   List<Process*>* procQueue;

  public:
   RoundRobin();
   virtual ~RoundRobin();
   virtual void addProcess(Process* proc);
   virtual Process* popNext(int curCycle);

};

class FastRoundRobin : public RoundRobin
{
  public:
    FastRoundRobin();

};

class CompletelyFair : public Scheduler
{
 protected:
  BSTMultimap<int, Process*>* procTree;

 public:
  CompletelyFair();
  virtual ~CompletelyFair();

  virtual void addProcess(Process* proc);
  virtual Process* popNext(int curCycle);

};

class FastCompletelyFair : public CompletelyFair
{
 public:
  FastCompletelyFair();

};

#endif
