#include <stdio.h>

// Function to swap two integers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int BT[n], WT[n], TAT[n], AT[n], CT[n];

    printf("Enter the arrival time of each process: \n");
    for (int i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &AT[i]);
    }

    printf("Enter the burst time of each process: \n");
    for (int i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &BT[i]);
    }

    // Bubble Sort to sort processes based on arrival time
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (AT[j] > AT[j + 1])
            {
                swap(&AT[j], &AT[j + 1]);
                swap(&BT[j], &BT[j + 1]);
            }
        }
    }

    int time = 0;
    for (int i = 0; i < n; i++)
    {
        if (AT[i] > time)
        {
            time = AT[i];
        }
        CT[i] = time + BT[i];
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - BT[i];
        time = CT[i];
    }

    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, AT[i], BT[i], CT[i], TAT[i], WT[i]);
    }

    double avgTAT = 0;
    double avgWT = 0;
    for (int i = 0; i < n; i++)
    {
        avgTAT += TAT[i];
        avgWT += WT[i];
    }
    avgTAT /= n;
    avgWT /= n;

    printf("The average Turnaround Time: %f", avgTAT);
    printf("\nThe average Wait Time: %f", avgWT);

    return 0;
}
