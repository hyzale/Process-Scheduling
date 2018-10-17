#include "Process.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;

//Constructor with process id and set cpuTime and waitTime to 0
Process::Process(int id) : id(id)
{
   cpuTime = 0;
   waitTime = 0;
}

//return the ID of process.
int Process::getID() const
{
   return id;
}
//return the cpu time process used.
int Process::getCPUTime() const
{
   return cpuTime;
}
//return the wait time (ready to run but not).
int Process::getWaitTime(int curCycleNum) const
{
   int additionalWait = curCycleNum - lastTime;
   if(additionalWait < 0)
   {
      additionalWait = 0;
   }
   return waitTime + additionalWait;
}

//constructor of the CPU bound process with the last time process set as 0
CPUBoundProcess::CPUBoundProcess(int id) : Process(id)
{
   lastTime = 0;
}

//return false as process is never blocked
bool CPUBoundProcess::isBlocked(int curCycleNum) const
{
   return false;
}

//return sliceSize that process uses all the cpu time
int CPUBoundProcess::useCPU(int curCycleNum, int sliceSize)
{
   //The process uses all CPU time given to it
   cpuTime += sliceSize;
   
   waitTime += curCycleNum - lastTime;
   //When the process next uses the CPU, it will have been
   //waiting since the end of this window.
   lastTime = curCycleNum + sliceSize;

   return sliceSize;
}

//constructor, set with range of cpu burst time, i/o request time
IOBoundProcess::IOBoundProcess(int id) : Process(id), minBurst(5), maxBurst(15), minIO(50), maxIO(200)
{
   lastTime = 0;
   blockedUntil = 0;
   remainingBurst = 0;
}

//the process maybe blocked
//process blocked if the cycle number is smaller than 
//the time when the process will unblock, vice versa.
bool IOBoundProcess::isBlocked(int curCycleNum) const
{
   return curCycleNum < blockedUntil;
}



//The time using cpu...
//btw feel like the provided comment explain this very clearly.
//not sure why we need to comment again.
int IOBoundProcess::useCPU(int curCycleNum, int sliceSize)
{
   //If the process was blocked, and is now unblocked,
   //choose a length for the next CPU burst
   if(curCycleNum >= blockedUntil && remainingBurst == 0)
   {
      remainingBurst = random()%(maxBurst - minBurst + 1) + minBurst;
   }

   int timeUsed = 0;
   if(remainingBurst > 0) //If the process is not blocked...
   {
      waitTime += curCycleNum - lastTime;

      if(remainingBurst > sliceSize) //If the whole window will be used...
      {
	 remainingBurst -= sliceSize;
	 timeUsed = sliceSize;

	 //When the process next uses the CPU, it will have been
	 //waiting since the end of this window.
	 lastTime = curCycleNum + sliceSize;
      }
      else //Otherwise the process will block without using the whole window
      {
	 timeUsed = remainingBurst;
	 remainingBurst = 0;

	 //Choose a time for the IO request to complete
	 blockedUntil = curCycleNum + timeUsed + random()%(maxIO - minIO + 1) + minIO;
	 //When the process next uses the CPU, it will have been
	 //waiting since it unblocked (not since the end of this window).
	 lastTime = blockedUntil;
      }
   }

   cpuTime += timeUsed;
   return timeUsed;
}
