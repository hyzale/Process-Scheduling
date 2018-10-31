#ifndef Scheduler
#define Scheduler

class Scheduler 
{
  public:

   //adds the given process to the processes to be scheduled
   virtual void addProcess(Process* proc);

   //removes and returns the next process in the schedule.
   //(Returns 0 if there is no available process).
   virtual Process* popNext(int curCycle);

   virtual ~Scheduler();

};

class RoundRobin : public Scheduler
{
  protected:
   List<Process*>* procQueue;

  public:
   virtual RoundRobin();
   virtual ~RoundRobin();
   virtual void addProcess(Process* proc);
   virtual Process* popNext(int curCycle);

};



#endif
