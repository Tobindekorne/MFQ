
/**
 * Contains the methods necessary to simulate the job of the cpu to process jobs.
 *
 * @author Tobin deKorne'
 * @revised by Shrey Patel
 * @version 5/9/17
 */

#ifndef CPU_H
#define CPU_H
#include 'Job.h'

class CPU
{
    private:
        Job job;
        int qClock;
        bool flag;

    public: 
        /**
         * Constructor for objects of class CPU
         */
        CPU();

        /**
         * Sets the flag to determine whether or not the cpu is busy.
         *
         * @param  value    the boolean value to set the flag to.
         */
        void setFlag(boolean value);

        /**
         * Returns whether or not the cpu is busy.
         *
         * @return     Whether or not the cpu is busy.
         */
        bool isBusy();

        /**
         * Decrements the quantum clock
         *
         */
        void decClock();

        /**
         * Sets the quantum clock.
         *
         * @param  quantum   the time quantum allowed for the current job process.
         */
        void setClock(int quantum);

        /**
         * Submits a new job to the CPU
         *
         * @param  newJob   The job being submitted.
         */
        void submitJob(Job newJob);
        /**
         * Returns whether or not the quantum clock has reached zero.
         *
         * @return     true if the quantum clock equals 0. Otherwise, false.
         */
        bool complete();

        /**
         * Returns the current job in the CPU.
         *
         * @return     the current job in the CPU.
         */
        Job currentJob();

        /**
         * Returns the current value of the quantum clock.
         *
         * @return  the current value of the quantum clock.
         */
        int getClock();
};

#endif
