/**
 * Contains the methods necessary to simulate the job of the cpu to process jobs.
 * 
 * @author Tobin deKorne'
 * @revised by Shrey Patel
 * @version 5/9/17
 */

    #include "CPU.h"

    /**
    * Constructor for objects of class CPU
    */

    CPU::CPU()
    {
        qClock = 0;
        flag = false;
    }

    /**
     * Sets the flag to determine whether or not the cpu is busy.
     * 
     * @param  value    the boolean value to set the flag to.
     */
    void CPU::setFlag(bool value)
    {
            flag = value;
    }
    
    /**
     * Returns whether or not the cpu is busy.
     * 
     * @return     Whether or not the cpu is busy.
     */
    bool CPU::isBusy()
    {
        return (flag == true);
    }
    
    /**
     * Decrements the quantum clock
     * 
     */
    void CPU::decClock()
    {
        qClock--;
        job.decClock();
    }
    
    /**
     * Sets the quantum clock.
     * 
     * @param  quantum   the time quantum allowed for the current job process.
     */
    void CPU::setClock(int quantum)
    {
        qClock = quantum;
    }
    
    /**
     * Submits a new job to the CPU
     * 
     * @param  newJob   The job being submitted.
     */
    void CPU::submitJob(Job newJob)
    {
        job = newJob;
    }
    
    /**
     * Returns whether or not the quantum clock has reached zero.
     * 
     * @return     true if the quantum clock equals 0. Otherwise, false.
     */
    bool  CPU::complete()
    {
        return qClock == 0;
    }
    
    /**
     * Returns the current job in the CPU.
     * 
     * @return     the current job in the CPU.
     */
    Job CPU::currentJob()
    {
        return job;
    }
    
    /**
     * Returns the current value of the quantum clock.
     * 
     * @return  the current value of the quantum clock.
     */
    int CPU::getClock()
    {
        return qClock;
    }
