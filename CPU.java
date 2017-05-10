
/**
 * Contains the methods necessary to simulate the job of the cpu to process jobs.
 * 
 * @author Tobin deKorne'
 * @version 7/14/2011
 */
public class CPU
{
    private Job job;
    private int qClock;
    private boolean flag;

    /**
     * Constructor for objects of class CPU
     */
    public CPU()
    {
        qClock = 0;
        flag = false;
    }

    /**
     * Sets the flag to determine whether or not the cpu is busy.
     * 
     * @param  value    the boolean value to set the flag to.
     */
    public void setFlag(boolean value)
    {
            flag = value;
    }
    
    /**
     * Returns whether or not the cpu is busy.
     * 
     * @return     Whether or not the cpu is busy.
     */
    public boolean isBusy()
    {
        return flag == true;
    }
    
    /**
     * Decrements the quantum clock
     * 
     */
    public void decClock()
    {
        qClock--;
        job.decClock();
    }
    
    /**
     * Sets the quantum clock.
     * 
     * @param  quantum   the time quantum allowed for the current job process.
     */
    public void setClock(int quantum)
    {
        qClock = quantum;
    }
    
    /**
     * Submits a new job to the CPU
     * 
     * @param  newJob   The job being submitted.
     */
    public void submitJob(Job newJob)
    {
        job = newJob;
    }
    
    /**
     * Returns whether or not the quantum clock has reached zero.
     * 
     * @return     true if the quantum clock equals 0. Otherwise, false.
     */
    public boolean complete()
    {
        return qClock == 0;
    }
    
    /**
     * Returns the current job in the CPU.
     * 
     * @return     the current job in the CPU.
     */
    public Job currentJob()
    {
        return job;
    }
    
    /**
     * Returns the current value of the quantum clock.
     * 
     * @return  the current value of the quantum clock.
     */
    public int getClock()
    {
        return qClock;
    }
}
