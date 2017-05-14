#ifndef JOB_H
#define JOB_H

#include <fstream>
class Job
{
    private:
      int arrTime;
      int pid;
      int cpuTime;
      int llq;
      int jobClock;
      StringTokenizer st;
      int enterQueue;
      int leaveQueue;
      int waitTime;
      int response;

    public:
      Job(String s);

    /**
     * Decrements the job clock
     *
     */
      void decClock();

    /**
     * Returns the arrival time of the job to the system.
     *
     * @return     the arrival time of the job to the system.
     */
      int getArrTime();

    /**
     * Returns the process identifier of the job.
     *
     * @return     the process identifier.
     */
      int getPid()

    /**
     * Checks whether or not the job has completed.
     *
     * @return     true if the job has completed. Otherwise, false.
     */
    bool isFinished();

    /**
     * Increments the job to a lower level queue.
     *
     */
    void incLLQ();

    /**
     * Returns the lowest level queue that the job entered.
     *
     * @return     the lowest level queue that the job entered.
     */
    int getLLQ();

    /**
     * Returns the current value of the jobClock.
     *
     * @return     the current value of the jobClock.
     */
    int getClock();

    /**
     * Returns the time required for the cpu to process the job.
     *
     * @return     the time required for the cpu to process the job.
     */
    int getCpuTime();

    /**
     * Sets the time that the job has entered into a queue.
     *
     */
    void enterQ(int time);

    /**
     * Sets the time that the job leaves a queue.
     *
     */
    void leaveQ(int time);

    /**
     * Returns the time the job waited in queues through its lifetime.
     *
     * @return     the time the job waited in queues through its lifetime.
     */
    int getWaitTime();

    /**
     * Sets the time that it took for the job to start running after entering the system.
     *
     * @param     the time the job started running.
     */
    int getResponseTime(int time);
  };

  #endif
