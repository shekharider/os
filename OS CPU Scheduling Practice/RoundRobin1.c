#include <stdio.h>

int main() {
    int n, i, qt, count = 0, temp, sq = 0;
    int burstTime[10], waitingTime[10], turnaroundTime[10], remainingBurstTime[10];
    float averageWaitingTime = 0, averageTurnaroundTime = 0;

    printf("Enter the number of processes (maximum 10) = ");
    scanf("%d", &n);

    printf("Enter the burst time of the processes\n");
    for (i = 0; i < n; i++) {
        printf("P%d = ", i);
        scanf("%d", &burstTime[i]);
        remainingBurstTime[i] = burstTime[i];
    }

    printf("Enter the quantum time: ");
    scanf("%d", &qt);

    while (1) {
        for (i = 0, count = 0; i < n; i++) {
            temp = qt;
            if (remainingBurstTime[i] == 0) {
                count++;
                continue;
            }
            if (remainingBurstTime[i] > qt)
                remainingBurstTime[i] -= qt;
            else if (remainingBurstTime[i] >= 0) {
                temp = remainingBurstTime[i];
                remainingBurstTime[i] = 0;
            }
            sq += temp;
            turnaroundTime[i] = sq;
        }
        if (n == count)
            break;
    }

    printf("--------------------------------------------------------------------------------\n");
    printf("Process\t      Burst Time\t       Turnaround Time\t          Waiting Time\n");
    printf("--------------------------------------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        waitingTime[i] = turnaroundTime[i] - burstTime[i];
        averageWaitingTime += waitingTime[i];
        averageTurnaroundTime += turnaroundTime[i];
        printf(" %d\t\t %d\t\t\t %d\t\t\t\t %d\n", (i + 1), burstTime[i], turnaroundTime[i], waitingTime[i]);
    }

    averageWaitingTime /= n;
    averageTurnaroundTime /= n;
    printf("\nAverage waiting Time = %.2f\n", averageWaitingTime);
    printf("Average turnaround time = %.2f\n", averageTurnaroundTime);

    return 0;
}
