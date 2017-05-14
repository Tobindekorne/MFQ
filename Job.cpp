/**
 * This class has the methods for job objects to be created.
 *
 * @author Tobin deKorne'
 * @version 5/9/2017
 */
  private:
    //Holds the the time a job arrives as an integer
    int arrTime;
    //Process identifier of a job as an integer
    int pid;
    //Time it takes for a cpu to finish a job
    int cpuTime;
    //The lowest level queue the job entered
    int llq;

    int jobClock;
    //Time job entered queue
    int enterQueue;
    //Time job left queue
    int leaveQueue;
    //Time waiting in queue
    int waitTime;
    int response;

    /**
     * Constructor for objects of class Job
     */
  public:
     Job::Job(String s)
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
    void Job::decClock()
    {
        jobClock--;
    }

    /**
     * Returns the arrival time of the job to the system.
     *
     * @return     the arrival time of the job to the system.
     */
    int Job::getArrTime()
    {
        return arrTime;
    }

    /**
     * Returns the process identifier of the job.
     *
     * @return     the process identifier.
     */
    int Job::getPid()
    {
        return pid;
    }

    /**
     * Checks whether or not the job has completed.
     *
     * @return     true if the job has completed. Otherwise, false.
     */
    bool Job::isFinished()
    {
        return jobClock == 0;
    }

    /**
     * Increments the job to a lower level queue.
     *
     */
    void Job::incLLQ()
    {
        llq++;
    }

    /**
     * Returns the lowest level queue that the job entered.
     *
     * @return     the lowest level queue that the job entered.
     */
    int Job::getLLQ()
    {
        return llq;
    }

    /**
     * Returns the current value of the jobClock.
     *
     * @return     the current value of the jobClock.
     */
    int Job::getClock()
    {
        return jobClock;
    }

    /**
     * Returns the time required for the cpu to process the job.
     *
     * @return     the time required for the cpu to process the job.
     */
    int Job::getCpuTime()
    {
        return cpuTime;
    }

    /**
     * Sets the time that the job has entered into a queue.
     *
     */
    void Job::enterQ(int time)
    {
        enterQueue = time;
    }

    /**
     * Sets the time that the job leaves a queue.
     *
     */
    void Job::leaveQ(int time)
    {
        leaveQueue = time;
        //Increase the total wait time by the total time in queue
        waitTime += leaveQueue - enterQueue;
    }

    /**
     * Returns the time the job waited in queues through its lifetime.
     *
     * @return     the time the job waited in queues through its lifetime.
     */
    int Job::getWaitTime()
    {
        return waitTime;
    }

    /**
     * Sets the time that it took for the job to start running after entering the system.
     *
     * @param     the time the job started running.
     */
    int Job::getResponseTime(int time)
    {
        return time - arrTime;
    }
}
