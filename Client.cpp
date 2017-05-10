
/**
 * Purpose: This is the client file which handles the order of task operations.
 *
 * Authors Tobin deKorne', Teddy Williams, Rajak Jamel, Shrey Patel
 * May 9, 2017

public class Driver
{
    public static void main(String[] args){
        MFQ mfq = new MFQ();
        mfq.readInput();
        while (!mfq.isFinished())
            mfq.processInput();
    }
}
 */

// Including the CPU header file that implements a CPU class
#include "CPU.h"

// Including the MFQ header file that implements a Multilevel Feedback Queue class
#include "MFQ.h"

// Using the standard namespace of input/output
using namespace std;

/*
 *  Purpose: The main driver function handling
 *
 */
int main(int argc, char const *argv[]) {
  // Creating an CPU object to handle the MFQ
  CPU centralProcessingUnit;
  // Creating an MFQ object to interpret the elements in mfq.txt
  MFQ multFeedBackQueue;
  // Reading input from mfq.txt using the method readInput()
  multFeedBackQueue.readInput();
  // While the MFQ is still processing (is not finished) it will process input.
  while(!multFeedBackQueue.isFinished()) {
    // Process input
    multFeedBackQueue.processInput();
  }
  // Return with no errors (0)
  return 0;
}
