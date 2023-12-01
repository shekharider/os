#include <stdio.h>

int main() {
    printf("Enter no of process: ");
    int totalProcesses;
    scanf("%d", &totalProcesses);

    int pid[totalProcesses];
    int arrivalTime[totalProcesses];
    int burstTime[totalProcesses];
    int completionTime[totalProcesses];
    int turnaroundTime[totalProcesses];
    int waitingTime[totalProcesses];
    int flag[totalProcesses];
    for (int i = 0; i < totalProcesses; i++) {
        printf("Enter process %d arrival time: ", i + 1);
        scanf("%d", &arrivalTime[i]);
        printf("Enter process %d burst time: ", i + 1);
        scanf("%d", &burstTime[i]);
        pid[i] = i + 1;
        flag[i] = 0;
    }

    int executedTime = 0;
    int executedProcesses = 0;
    float averageWaitingTime = 0;
    float averageTurnaroundTime = 0;

    while (1) {
        int c = totalProcesses;
        int min = 999;

        if (executedProcesses == totalProcesses)
            break;

        for (int i = 0; i < totalProcesses; i++) {
            if ((arrivalTime[i] <= executedTime) && (flag[i] == 0) && (burstTime[i] < min)) {
                min = burstTime[i];
                c = i;
            }
        }

        if (c == totalProcesses)
            executedTime++;
        else {
            completionTime[c] = executedTime + burstTime[c];
            executedTime += burstTime[c];
            turnaroundTime[c] = completionTime[c] - arrivalTime[c];
            waitingTime[c] = turnaroundTime[c] - burstTime[c];
            flag[c] = 1;
            executedProcesses++;
        }
    }

    printf("\npid  arrival burst  complete turn waiting\n");
    for (int i = 0; i < totalProcesses; i++) {
        averageWaitingTime += waitingTime[i];
        averageTurnaroundTime += turnaroundTime[i];
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], arrivalTime[i], burstTime[i], completionTime[i], turnaroundTime[i], waitingTime[i]);
    }

    printf("\nAverage Turnaround Time is %.2f\n", (averageTurnaroundTime / totalProcesses));
    printf("Average Waiting Time is %.2f\n", (averageWaitingTime / totalProcesses));

    return 0;
}
