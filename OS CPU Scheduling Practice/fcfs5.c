#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int p[n]; // process id
    int ArrivalTime[n];
    int BurstTime[n];
    int CompletionTime[n];
    int WaitingTime[n];
    int TurnaroundTime[n];

    float avgWaitingTime = 0, avgTurnaroundTime = 0; // initializing to zero

    for (int i = 0; i < n; i++) {
        printf("Enter arrival time for process %d: ", i + 1); // 'i+1' is process no
        scanf("%d", &ArrivalTime[i]);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &BurstTime[i]);
        p[i] = i + 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - (i + 1); j++) {
            if (ArrivalTime[j] > ArrivalTime[j + 1]) {
                int temp = ArrivalTime[j];
                ArrivalTime[j] = ArrivalTime[j + 1];
                ArrivalTime[j + 1] = temp;

                temp = BurstTime[j];
                BurstTime[j] = BurstTime[j + 1];
                BurstTime[j + 1] = temp;

                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            CompletionTime[i] = ArrivalTime[i] + BurstTime[i];
        } else {
            if (ArrivalTime[i] > CompletionTime[i - 1]) {
                CompletionTime[i] = ArrivalTime[i] + BurstTime[i];
            } else {
                CompletionTime[i] = CompletionTime[i - 1] + BurstTime[i];
            }
        }
        TurnaroundTime[i] = CompletionTime[i] - ArrivalTime[i];
        WaitingTime[i] = TurnaroundTime[i] - BurstTime[i];
        avgWaitingTime += (float)WaitingTime[i]; // converting int WaitingTime into float
        avgTurnaroundTime += (float)TurnaroundTime[i];
    }

    printf("\npid  arrivalT  burstT  completeT turnT waitingT\n");
    for (int i = 0; i < n; i++) {
        printf("%d  \t %d\t%d\t%d\t%d\t%d\n", p[i], ArrivalTime[i], BurstTime[i], CompletionTime[i], TurnaroundTime[i], WaitingTime[i]);
    }

    printf("\naverage waiting time: %.2f\n", avgWaitingTime / n);
    printf("average turnaround time: %.2f\n", avgTurnaroundTime / n);

    return 0;
}
