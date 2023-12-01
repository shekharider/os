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
    int TempBurst[totalProcesses];
    int executedTime = 0;
    int executedProcesses = 0;
    float averageWaitingTime = 0;
    float averageTurnaroundTime = 0;

    for (int i = 0; i < totalProcesses; i++) {
        pid[i] = i + 1;
        printf("Enter process %d arrival time: ", i + 1);
        scanf("%d", &arrivalTime[i]);
        printf("Enter process %d burst time: ", i + 1);
        scanf("%d", &burstTime[i]);
        TempBurst[i] = burstTime[i];
        flag[i] = 0;
    }

    while (1) {
        int min = 99, c = totalProcesses;
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
            burstTime[c]--;
            executedTime++;
            if (burstTime[c] == 0) {
                completionTime[c] = executedTime;
                flag[c] = 1;
                executedProcesses++;
            }
        }
    }

    for (int i = 0; i < totalProcesses; i++) {
        turnaroundTime[i] = completionTime[i] - arrivalTime[i];
        waitingTime[i] = turnaroundTime[i] - TempBurst[i];
        averageWaitingTime += waitingTime[i];
        averageTurnaroundTime += turnaroundTime[i];
    }

    printf("pid  arrival  burst  complete turn waiting\n");
    for (int i = 0; i < totalProcesses; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], arrivalTime[i], TempBurst[i], completionTime[i], turnaroundTime[i], waitingTime[i]);
    }

    printf("\nAverage Turnaround Time is %.2f\n", (averageTurnaroundTime / totalProcesses));
    printf("Average Waiting Time is %.2f\n", (averageWaitingTime / totalProcesses));

    return 0;
}
