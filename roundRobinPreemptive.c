#include <stdio.h>

int main()
{
    int numberOfProcesses;
    int totalWait = 0, totalTAT = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &numberOfProcesses);
    int remainingProcesses = numberOfProcesses;
    int arrival[numberOfProcesses], burst[numberOfProcesses], remainingTime[numberOfProcesses];

    printf("Enter the process details:\n");
    for (int i = 0; i < numberOfProcesses; i++)
    {
        printf("Process [%d]:\n", i + 1);
        printf("  Arrival time: ");
        scanf("%d", &arrival[i]);
        printf("  Burst time: ");
        scanf("%d", &burst[i]);
        remainingTime[i] = burst[i];
    }

    int timeQuantum;
    printf("Enter the Time Quantum for the process: ");
    scanf("%d", &timeQuantum);

    printf("\nProcess No\tBurst Time\tTAT\tWaiting Time\n");
    for (int currTime = 0, i = 0; remainingProcesses != 0;)
    {
        int isComplete = 0;
        if (remainingTime[i] <= timeQuantum && remainingTime[i] > 0)
        {
            currTime += remainingTime[i];
            remainingTime[i] = 0;
            isComplete = 1;
        }
        else if (remainingTime[i] > 0)
        {
            remainingTime[i] -= timeQuantum;
            currTime += timeQuantum;
        }
        if (remainingTime[i] == 0 && isComplete == 1)
        {
            remainingProcesses--;
            printf("P%d\t\t%d\t\t%d\t\t%d\n", i + 1, burst[i], currTime - arrival[i], currTime - arrival[i] - burst[i]);
            totalWait += currTime - arrival[i] - burst[i];
            totalTAT += currTime - arrival[i];
            isComplete = 0;
        }
        if (i == numberOfProcesses - 1)
        {
            i = 0;
        }
        else if (arrival[i + 1] <= currTime)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }

    printf("\nAverage Turnaround Time: %.2f", (float)totalTAT / numberOfProcesses);
    printf("\nAverage Waiting Time: %.2f\n", (float)totalWait / numberOfProcesses);
    return 0;
}

