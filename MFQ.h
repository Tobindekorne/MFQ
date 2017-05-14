#ifndef MFQ_H
#define MFQ_H

// Including Queue Header File`
#include "ObjectQueue.h"
// Including CPU Header File
#include "CPU.h"


class MFQ {
private:
  int clock;
  ObjectQueue inputQ;
  ObjectQueue q1;
  ObjectQueue q2;
  ObjectQueue q3;
  ObjectQueue q4;
  centralProcessingUnit = new CPU();
public:
  MFQ();
  void readInput();
  processArrival(Job arrJob);
  void processDeparture(Job depJob);
  void processInput();
  void submitCorrect();
  void placeInQ(Job inJob);
  bool isFinished();
};

#endif
