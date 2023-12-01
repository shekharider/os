#include <stdio.h>

struct Process {
    int pid;  // Process ID
    int bt;   // Burst Time
    int at;   // Arrival Time
    int ct;   // Completion Time
    int tat;  // Turnaround Time
    int wt;   // Waiting Time
};

void swap(struct Process* a, struct Process* b) {
    struct Process temp = *a;
    *a = *b;
    *b = temp;
}

void findWaitingTime(struct Process proc[], int n, int wt[]) {
    int rt[n];

    // Copy the burst time into rt[]
    for (int i = 0; i < n; i++)
        rt[i] = proc[i].bt;

    int complete = 0, t = 0, minm = 9999;
    int shortest = -1, finish_time;

    while (complete != n) {
        for (int j = 0; j < n; j++) {
            if (rt[j] > 0 && rt[j] < minm && t >= proc[j].at) {
                minm = rt[j];
                shortest = j;
            }
        }

        if (shortest == -1) {
            t++;
            continue;
        }

        wt[shortest] = t - proc[shortest].at;
        t += 1;
        rt[shortest]--;

        if (rt[shortest] == 0) {
            complete++;
            minm = 9999;
        }
    }
}

void findTurnAroundTime(struct Process proc[], int n, int wt[], int tat[]) {
    for (int i = 0; i < n; i++)
        tat[i] = proc[i].bt + wt[i];
}

void findAverageTime(struct Process proc[], int n) {
    int wt[n], tat[n];

    findWaitingTime(proc, n, wt);

    findTurnAroundTime(proc, n, wt, tat);

    // Display processes along with all details
    printf(" P\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");

    // Calculate total waiting time and total turnaround time
    float total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        proc[i].ct = proc[i].bt + wt[i] + proc[i].at;
        total_wt += wt[i];
        total_tat += tat[i];
        printf(" %d\t%d\t%d\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].at, proc[i].bt, proc[i].ct, tat[i], wt[i]);
    }

    // Display average waiting time and average turnaround time
    printf("\nAverage Waiting Time = %.2f\n", total_wt / n);
    printf("Average Turnaround Time = %.2f\n", total_tat / n);
}

int main() {
    struct Process proc[] = {{1, 6, 2}, {2, 8, 5}, {3, 7, 1}};
    int n = sizeof(proc) / sizeof(proc[0]);

    // Sort processes based on arrival time (not necessary for SRTF, but included for clarity)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - (i + 1); j++) {
            if (proc[j].at > proc[j + 1].at) {
                swap(&proc[j], &proc[j + 1]);
            }
        }
    }

    // Calculate completion time, turnaround time, and waiting time
    findAverageTime(proc, n);

    return 0;
}
