// Including the header file of MFQ to implement a multilevel feedback queue
#include "MFQ.h"
#include "Job.h"
#include "ObjectQueue.h"

MFQ::MFQ() {
  // Setting to the initial values of the MFQ attributes
  numJobs = 0;
  totalJobTime = 0;
  avrgRspnsTime = 0;
  totalWtTime = 0;
  CPUIdle = 0;
  clock = 0;
  CPU = new CPU();
  inputQ = new ObjectQueue();
  q1 = new ObjectQueue();
  q2 = new ObjectQueue();
  q3 = new ObjectQueue();
  q4 = new ObjectQueue();
  cout << "(To file)" << endl; FIX ME
}

/*
 *  Purpose: This method will find mfq.txt
 *  and inserts the jobs into the input
 *  queue.
 *
 *
 */
void MFQ::readInput() {
  try {

  }
  catch {

  }

}

/**
 * Proccesses the arrival of a job from the queuing system.
 *
 * @param  arrJob   the arriving job.
 * @return     the sum of x and y
 */

  void MFQ::processArrival(Job arrJob)
  {

  }

  /**
   * Proccesses the departure of a job from the queuing system.
   *
   * @param  depJob   the departing job.
   * @return     the sum of x and y
   */

  void MFQ::processDeparture(Job depJob)
  {

  }

  /**
   * Processes the input from mfq.txt.
   *
   */

  void MFQ::processInput()
  {

  }

  /**
   * Submits a job from the appropriate queue to the cpu.
   *
   */

  void MFQ::submitCorrect()
  {
    if (!q1.isEmpty()){
        Job q1Job = q1.remove();
        cpu.submitJob(q1Job);
        q1Job.leaveQ(clock);
        avrgRspnsTime += q1Job.getResponseTime(clock);
        cpu.setClock(2);
        cpu.setFlag(true);
    }
    else if (!q2.isEmpty()){
        Job q2Job = q2.remove();
        cpu.submitJob(q2Job);
        q2Job.leaveQ(clock);
        cpu.setClock(4);
        cpu.setFlag(true);
    }
    else if (!q3.isEmpty()){
        Job q3Job = q3.remove();
        cpu.submitJob(q3Job);
        q3Job.leaveQ(clock);
        cpu.setClock(8);
        cpu.setFlag(true);
    }
    else if (!q4.isEmpty()){
        Job q4Job = q4.remove();
        cpu.submitJob(q4Job);
        q4Job.leaveQ(clock);
        cpu.setClock(16);
        cpu.setFlag(true);
    }
  }

  /**
   * Places a job in the correct queue according to it's current lowest level queue assignment.
   *
   * @param  inJob   the job to be sorted to the correct queue.
   */

  void MFQ::placeInQ(Job inJob)
  {
    if (inJob.getLLQ() == 1){
        q1.insert(inJob);
        inJob.enterQ(clock);
    }
    else if (inJob.getLLQ() == 2){
        q2.insert(inJob);
        inJob.enterQ(clock);
    }
    else if (inJob.getLLQ() == 3){
        q3.insert(inJob);
        inJob.enterQ(clock);
    }
    else if (inJob.getLLQ() == 4){
        q4.insert(inJob);
        inJob.enterQ(clock);
    }
  }

  /**
   * Checks the condition for whether or not all jobs have been processed.
   *
   * @return     true, if all jobs have been processed. Otherwise, false.
   */

  bool MFQ::isFinished()
  {
      return q1.isEmpty() && q2.isEmpty() && q3.isEmpty() && q4.isEmpty() && inputQ.isEmpty() && !cpu.isBusy();
  }
