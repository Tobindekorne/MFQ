// Including the header file of MFQ to implement a multilevel feedback queue
#include "MFQ.h"

MFQ::MFQ() {
  // Opening writing to file log
  ofstream fout;
  // Finding mfq.txt
  fout.open("mfq.txt");
  if(fout) {
    // Setting to the initial values of the MFQ attributes
    numJobs = 0;
    totalJobTime = 0;
    avrgRspnsTime = 0;
    totalWtTime = 0;
    CPUIdle = 0;
    clock = 0;
    CPU = new CPU();
    inputQ = new ObjectQueue();
    fout << "MFQ 1:"; // Actual Input for Log.
    System.out.printf("\f");
    System.out.printf("%-15s%-15s%-10s%-15s%-20s%-15s\n", "Event", "System Time", "PID", "CPU Time", "Time In System", "Lowest Level Queue");
  }
  else {
    cout << "mfq.txt does not exist. MFQ not created." << endl;
  }
}

/*
 *  Purpose: This method will find mfq.txt
 *  and inserts the jobs into the input
 *  queue.
 */
void MFQ::readInput() {
  try {

  }
  catch {

  }
}
