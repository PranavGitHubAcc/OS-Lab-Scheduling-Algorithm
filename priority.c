#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int BT[10], AT[10], P[10], WT[10], TAT[10];
    float avgTAT = 0, avgWT = 0;

    int sum_burst_time = 0;

    for (int i = 0; i < n; i++)
    {
        printf("Enter the arrival time for process P%d: ", i + 1);
        scanf("%d", &AT[i]);
        printf("Enter the burst time for process P%d: ", i + 1);
        scanf("%d", &BT[i]);
        printf("Enter the priority for process P%d: ", i + 1);
        scanf("%d", &P[i]);
        sum_burst_time += BT[i];
    }

    printf("\nProcess\tArrival\tBurst\tPriority\tTAT\tWaiting\n");

    int time = 0;

    for (int i = 0; i < n; i++)
    {
        int highest_priority = 10, selected_process = -1;
        for (int j = 0; j < n; j++)
        {
            if (AT[j] <= time && BT[j] > 0 && P[j] < highest_priority)
            {
                highest_priority = P[j];
                selected_process = j;
            }
        }
        time += BT[selected_process];
        TAT[selected_process] = time - AT[selected_process];
        WT[selected_process] = TAT[selected_process] - BT[selected_process];
        avgTAT += TAT[selected_process];
        avgWT += WT[selected_process];
        printf("%d\t%d\t%d\t%d\t\t%d\t%d\n", selected_process + 1, AT[selected_process], BT[selected_process], P[selected_process], TAT[selected_process], WT[selected_process]);
        BT[selected_process] = 0; // Marking process as completed
    }

    printf("\nAverage TAT: %.1f\n", avgTAT / n);
    printf("Average WT: %.1f\n", avgWT / n);

    return 0;
}
