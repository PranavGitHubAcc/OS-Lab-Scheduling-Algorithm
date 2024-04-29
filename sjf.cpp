#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int BT[10], AT[10];
    float avgTAT = 0, avgWT = 0;

    int sum_burst_time = 0;

    for (int i = 0; i < n; i++)
    {
        printf("Enter the arrival time for process P%d: ", i + 1);
        scanf("%d", &AT[i]);
        printf("Enter the burst time for process P%d: ", i + 1);
        scanf("%d", &BT[i]);
        sum_burst_time += BT[i];
    }

    BT[9] = 9999;

    printf("\nProcess\tArrival\tBurst\tComplete\tTAT\tWaiting\n");

    int time = 0;

    while (time < sum_burst_time)
    {
        int smallest = 9;
        for (int i = 0; i < n; i++)
        {
            if (AT[i] <= time && BT[i] > 0 && BT[i] < BT[smallest])
                smallest = i;
        }
        int completionTime = time + BT[smallest];
        int tat = completionTime - AT[smallest];
        int wt = tat - BT[smallest];

        printf("%d\t%d\t%d\t%d\t\t%d\t%d\n", smallest + 1, AT[smallest], BT[smallest], completionTime, tat, wt);
        avgTAT += tat;
        avgWT += wt;
        time += BT[smallest];
        BT[smallest] = 0;
    }

    printf("\nAverage TAT: %.1f\n", avgTAT / n);
    printf("Average WT: %.1f\n", avgWT / n);

    return 0;
}
