import java.io.File;
import java.util.Scanner;
import java.io.FileNotFoundException;
/**
 * Write a description of class MFQ here.
 *
 * @author Tobin deKorne'
 * @version 7/14/2011
 */
public class MFQ
{
    private int clock;
    private ObjectQueue inputQ;
    private ObjectQueue q1;
    private ObjectQueue q2;
    private ObjectQueue q3;
    private ObjectQueue q4;
    private CPU cpu;
    private Job job;
    private LineWriter lw;
    private int numJobs;
    private int totalJobTime;
    private int avrgRspnsTime;
    private int totalWtTime;
    private int CpuIdle;

    /**
     * Constructor for objects of class MFQ
     */
    public MFQ()
    {
        System.out.printf("\f");
        System.out.printf("%-15s%-15s%-10s%-15s%-20s%-15s\n", "Event", "System Time", "PID", "CPU Time", "Time In System", "Lowest Level Queue");
        numJobs = 0;
        totalJobTime = 0;
        avrgRspnsTime = 0;
        totalWtTime = 0;
        CpuIdle= 0;
        clock = 0;
        cpu = new CPU();
        inputQ = new ObjectQueue();
        q1 = new ObjectQueue();
        q2 = new ObjectQueue();
        q3 = new ObjectQueue();
        q4 = new ObjectQueue();
        lw = new LineWriter("csis.txt", "w");
        lw.println(String.format("%-15s%-15s%-10s%-15s%-20s%-15s\n", "Event", "System Time", "PID", "CPU Time", "Time In System", "Lowest Level Queue"));
    }

    /**
     * Reads the "mfq.txt" file and inserts the jobs into the input queue
     *
     */
    public void readInput()
    {
        try{
            File inputFile = new File("mfq.txt");
            Scanner input = new Scanner(inputFile);

            while (input.hasNextLine()) {
                String line = input.nextLine();
                job = new Job(line);
                inputQ.insert(job);
            }
        } catch (FileNotFoundException e) {
            System.out.println("mfq.txt not found!");
        }
    }

    /**
     * Proccesses the arrival of a job from the queuing system.
     *
     * @param  arrJob   the arriving job.
     * @return     the sum of x and y
     */
    public void processArrival(Job arrJob)
    {
        System.out.printf("%-15s%-15d%-10d%-15d\n", "Arrival", clock, arrJob.getPid(), arrJob.getCpuTime());
        lw.println(String.format("%-15s%-15d%-10d%-15d\n", "Arrival", clock, arrJob.getPid(), arrJob.getCpuTime()));
        numJobs++;
    }

    /**
     * Proccesses the departure of a job from the queuing system.
     *
     * @param  depJob   the departing job.
     * @return     the sum of x and y
     */
    public void processDeparture(Job depJob)
    {
        totalJobTime += clock - depJob.getArrTime();
        totalWtTime += depJob.getWaitTime();
        System.out.printf("%-15s%-15d%-10d%-15s%-20d%-15d\n", "Departure", clock, depJob.getPid(), " ", clock - depJob.getArrTime(), depJob.getLLQ());
        lw.println(String.format("%-15s%-15d%-10d%-15s%-20d%-15d\n", "Departure", clock, depJob.getPid(), " ", clock - depJob.getArrTime(), depJob.getLLQ()));
    }

    /**
     * Processes the input from mfq.txt.
     *
     */
    public void processInput()
    {
        clock++;
        Job tempJob = new Job("-1 -1 -1");
        if (!inputQ.isEmpty())
            tempJob = (Job)inputQ.query();
        Job newJob = new Job(" 1 2 3");;
        if (tempJob.getArrTime() == clock){
            newJob = (Job)inputQ.remove();
            processArrival(newJob);
            placeInQ(newJob);
        }
        if (!cpu.isBusy()){
            CpuIdle++;
            submitCorrect();
        }
        else if (cpu.isBusy()){
            cpu.decClock();
            if (cpu.currentJob().isFinished()){
                processDeparture(cpu.currentJob());
                cpu.setFlag(false);
                submitCorrect();
            }
            else{
                if (cpu.complete() && cpu.isBusy()){
                    if (cpu.currentJob().getLLQ() < 4)
                        cpu.currentJob().incLLQ();
                    placeInQ(cpu.currentJob());
                    cpu.setFlag(false);
                    submitCorrect();
                }
                else if (newJob.getArrTime() > cpu.currentJob().getArrTime() && cpu.isBusy()){
                    if (cpu.currentJob().getLLQ() < 4)
                        cpu.currentJob().incLLQ();
                    placeInQ(cpu.currentJob());
                    cpu.setFlag(false);
                    submitCorrect();
                }
            }
        }
        if (isFinished()){
            System.out.println("Total number of jobs: " + numJobs);
            System.out.println("Total time all jobs were in the system: " + totalJobTime);
            System.out.println("Average response time: " + (double)avrgRspnsTime / (double)numJobs);
            System.out.println("Average turnaround time for the jobs: " + (double) totalJobTime / (double) numJobs);
            System.out.println("Average waiting time for the jobs: " + (double) totalWtTime / (double) numJobs);
            System.out.println("Average throughput for the system: " + (double) numJobs / (double) totalJobTime);
            System.out.println("Total CPU idle time: " + CpuIdle);
            lw.println("Total number of jobs: " + numJobs);
            lw.println("Total time all jobs were in the system: " + totalJobTime);
            lw.println("Average response time: " + (double)avrgRspnsTime / (double)numJobs);
            lw.println("Average turnaround time for the jobs: " + (double) totalJobTime / (double) numJobs);
            lw.println("Average waiting time for the jobs: " + (double) totalWtTime / (double) numJobs);
            lw.println("Average throughput for the system: " + (double) numJobs / (double) totalJobTime);
            lw.println("Total CPU idle time: " + CpuIdle);
            lw.close();
        }
    }

    /**
     * Submits a job from the appropriate queue to the cpu.
     *
     */
    public void submitCorrect()
    {
        if (!q1.isEmpty()){
            Job q1Job = (Job)q1.remove();
            cpu.submitJob(q1Job);
            q1Job.leaveQ(clock);
            avrgRspnsTime += q1Job.getResponseTime(clock);
            cpu.setClock(2);
            cpu.setFlag(true);
        }
        else if (!q2.isEmpty()){
            Job q2Job = (Job)q2.remove();
            cpu.submitJob(q2Job);
            q2Job.leaveQ(clock);
            cpu.setClock(4);
            cpu.setFlag(true);
        }
        else if (!q3.isEmpty()){
            Job q3Job = (Job)q3.remove();
            cpu.submitJob(q3Job);
            q3Job.leaveQ(clock);
            cpu.setClock(8);
            cpu.setFlag(true);
        }
        else if (!q4.isEmpty()){
            Job q4Job = (Job)q4.remove();
            cpu.submitJob(q4Job);
            q4Job.leaveQ(clock);
            cpu.setClock(16);
            cpu.setFlag(true);
        }
    }

    /**
     * Places a job in the correct queue according to it's current lowest level queue assignment.
     *
     * @param  inJob   the job to be sorted to the correct queue.
     */
    public void placeInQ(Job inJob)
    {
        if (inJob.getLLQ() == 1){
            q1.insert(inJob);
            inJob.enterQ(clock);
        }
        else if (inJob.getLLQ() == 2){
            q2.insert(inJob);
            inJob.enterQ(clock);
        }
        else if (inJob.getLLQ() == 3){
            q3.insert(inJob);
            inJob.enterQ(clock);
        }
        else if (inJob.getLLQ() == 4){
            q4.insert(inJob);
            inJob.enterQ(clock);
        }
    }

    /**
     * Checks the condition for whether or not all jobs have been processed.
     *
     * @return     true, if all jobs have been processed. Otherwise, false.
     */
    public boolean isFinished()
    {
        return q1.isEmpty() && q2.isEmpty() && q3.isEmpty() && q4.isEmpty() && inputQ.isEmpty() && !cpu.isBusy();
    }
}
