#include <stdio.h>

void sort_by_priority(int n, int BT[], int AT[], int Priority[], int PID[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (Priority[j] > Priority[j + 1]) {
                int temp = BT[j];
                BT[j] = BT[j + 1];
                BT[j + 1] = temp;
                
                temp = AT[j];
                AT[j] = AT[j + 1];
                AT[j + 1] = temp;
                
                temp = Priority[j];
                Priority[j] = Priority[j + 1];
                Priority[j + 1] = temp;
                
                temp = PID[j];
                PID[j] = PID[j + 1];
                PID[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int BT[n], WT[n], TAT[n], AT[n], CT[n], Priority[n], PID[n];
    
    printf("Enter the arrival time, burst time, and priority of each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d %d", &AT[i], &BT[i], &Priority[i]);
        PID[i] = i + 1; // Process ID
    }

    sort_by_priority(n, BT, AT, Priority, PID);

    int time = 0;
    for (int i = 0; i < n; i++) {
        if (AT[i] > time) {
            time = AT[i];
        }
        CT[i] = time + BT[i];
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - BT[i]; 
        time = CT[i];
    }

    printf("\nProcess\tArrival Time\tBurst Time\tPriority\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", PID[i], AT[i], BT[i], Priority[i], CT[i], TAT[i], WT[i]);
    }

    double avgTAT = 0;
    double avgWT = 0;
    for (int i = 0; i < n; i++){
        avgTAT += TAT[i];
        avgWT += WT[i];
    }
    avgTAT /= n;
    avgWT /= n;

    printf("The average Turnaround Time: %f\n", avgTAT);
    printf("The average Wait Time: %f\n", avgWT);
    
    return 0;
}
