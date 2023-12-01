#include <stdio.h>

void findWaitingTime(int processes[], int n, int bt[], int wt[], int priority[]) {
    int temp[n];
    for (int i = 0; i < n; i++)
        temp[i] = priority[i];

    wt[0] = 0;

    for (int i = 1; i < n; i++) {
        int index = i;
        for (int j = i + 1; j < n; j++) {
            if (temp[j] < temp[index])
                index = j;
        }

        int tempValue = temp[index];
        temp[index] = temp[i];
        temp[i] = tempValue;

        int tempProcess = processes[index];
        processes[index] = processes[i];
        processes[i] = tempProcess;
    }

    for (int i = 1; i < n; i++)
        wt[i] = bt[i - 1] + wt[i - 1];
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

void findAverageTime(int processes[], int n, int bt[], int priority[]) {
    int wt[n], tat[n];

    findWaitingTime(processes, n, bt, wt, priority);

    findTurnAroundTime(processes, n, bt, wt, tat);

    float total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }

    float avg_wt = total_wt / n;
    float avg_tat = total_tat / n;

    printf("Average Waiting Time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tat);
}

int main() {
    int processes[] = {1, 2, 3};
    int n = sizeof(processes) / sizeof(processes[0]);

    int burst_time[] = {6, 8, 7};
    int priority[] = {2, 1, 3};

    findAverageTime(processes, n, burst_time, priority);

    return 0;
}
