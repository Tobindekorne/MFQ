/**
 * This class has the methods for job objects to be created.
 *
 * @author Tobin deKorne'
 * @version 5/9/2017
 */
  private:
    int arrTime;
    int pid;
    int cpuTime;
    int llq;
    int jobClock;
    int enterQueue;
    int leaveQueue;
    int waitTime;
    int response;

    /**
     * Constructor for objects of class Job
     */
    public Job(String s)
    {
        st = new StringTokenizer(s);
        arrTime = Integer.parseInt(st.nextToken());
        pid = Integer.parseInt(st.nextToken());
        cpuTime = Integer.parseInt(st.nextToken());
        jobClock = cpuTime;
        llq = 1;
        waitTime = 0;
    }

    /**
     * Decrements the job clock
     *
     */
    public void decClock()
    {
        jobClock--;
    }

    /**
     * Returns the arrival time of the job to the system.
     *
     * @return     the arrival time of the job to the system.
     */
    public int getArrTime()
    {
        return arrTime;
    }

    /**
     * Returns the process identifier of the job.
     *
     * @return     the process identifier.
     */
    public int getPid()
    {
        return pid;
    }

    /**
     * Checks whether or not the job has completed.
     *
     * @return     true if the job has completed. Otherwise, false.
     */
    public boolean isFinished()
    {
        return jobClock == 0;
    }

    /**
     * Increments the job to a lower level queue.
     *
     */
    public void incLLQ()
    {
        llq++;
    }

    /**
     * Returns the lowest level queue that the job entered.
     *
     * @return     the lowest level queue that the job entered.
     */
    public int getLLQ()
    {
        return llq;
    }

    /**
     * Returns the current value of the jobClock.
     *
     * @return     the current value of the jobClock.
     */
    public int getClock()
    {
        return jobClock;
    }

    /**
     * Returns the time required for the cpu to process the job.
     *
     * @return     the time required for the cpu to process the job.
     */
    public int getCpuTime()
    {
        return cpuTime;
    }

    /**
     * Sets the time that the job has entered into a queue.
     *
     */
    public void enterQ(int time)
    {
        enterQueue = time;
    }

    /**
     * Sets the time that the job leaves a queue.
     *
     */
    public void leaveQ(int time)
    {
        leaveQueue = time;
        waitTime += leaveQueue - enterQueue;
    }

    /**
     * Returns the time the job waited in queues through its lifetime.
     *
     * @return     the time the job waited in queues through its lifetime.
     */
    public int getWaitTime()
    {
        return waitTime;
    }

    /**
     * Sets the time that it took for the job to start running after entering the system.
     *
     * @param     the time the job started running.
     */
    public int getResponseTime(int time)
    {
        return time - arrTime;
    }
}
