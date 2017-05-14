// Including the header file of MFQ to implement a multilevel feedback queue
#include "MFQ.h"

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
