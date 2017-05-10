
/**
 * Runs a loop to process all jobs using the MFQ class.
 * 
 * @author Tobin deKorne' 
 * @version 7/14/2011
 */
public class Driver
{
    public static void main(String[] args){
        MFQ mfq = new MFQ();
        mfq.readInput();
        while (!mfq.isFinished())
            mfq.processInput();
    }
}
