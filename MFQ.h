#ifndef MFQ_H
#define MFQ_H

#include <fstream>

#include "ObjectQueue.h"
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
};

#endif
