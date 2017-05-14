/*
 * Purpose: This is the client file which handles the order of task operations.
 * Authors Tobin deKorne', Teddy Williams, Rajak Jamel, Shrey Patel
 * May 9, 2017
 */

// Including the MFQ header file that implements a Multilevel Feedback Queue class
#include "MFQ.h"

// Using the standard namespace of input/output
using namespace std;

/*
 *  Purpose: The main driver function handling
 *  Input: int argc - The number of arguments in the excution command
 *  Output: Positive integers if the program run without errors and
 *  negitive integers with errors.
 */
int main(int argc, char const *argv[]) {
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
