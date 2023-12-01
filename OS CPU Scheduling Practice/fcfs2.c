#include <stdio.h>

struct Process {
    int pid;  // Process ID
    int bt;   // Burst Time
    int art;  // Arrival Time
    int ct;   // Completion Time
    int tat;  // Turnaround Time
    int wt;   // Waiting Time
};

void calculateTimes(struct Process proc[], int n) {
    // Completion time for the first process is its burst time
    proc[0].ct = proc[0].bt;
    proc[0].tat = proc[0].ct - proc[0].art;
    proc[0].wt = proc[0].tat - proc[0].bt;

    // Calculate completion time, turnaround time, and waiting time for the remaining processes
    for (int i = 1; i < n; i++) {
        proc[i].ct = proc[i - 1].ct + proc[i].bt;
        proc[i].tat = proc[i].ct - proc[i].art;
        proc[i].wt = proc[i].tat - proc[i].bt;
    }
}

void displayTable(struct Process proc[], int n) {
    printf(" P\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");

    for (int i = 0; i < n; i++) {
        printf(" %d\t%d\t%d\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].art, proc[i].bt, proc[i].ct, proc[i].tat, proc[i].wt);
    }

    // Calculate and display average waiting time and average turnaround time
    float avgWaitingTime = 0, avgTurnaroundTime = 0;
    for (int i = 0; i < n; i++) {
        avgWaitingTime += proc[i].wt;
        avgTurnaroundTime += proc[i].tat;
    }

    printf("\nAverage Waiting Time = %.2f\n", avgWaitingTime / n);
    printf("Average Turnaround Time = %.2f\n", avgTurnaroundTime / n);
}

int main() {
    struct Process proc[] = {{1, 10, 2}, {2, 5, 5}, {3, 8, 1}};
    int n = sizeof(proc) / sizeof(proc[0]);

    // Sort processes based on arrival time (not necessary for FCFS, but included for clarity)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - (i + 1); j++) {
            if (proc[j].art > proc[j + 1].art) {
                struct Process temp = proc[j];
                proc[j] = proc[j + 1];
                proc[j + 1] = temp;
            }
        }
    }

    // Calculate completion time, turnaround time, and waiting time
    calculateTimes(proc, n);

    // Display the table and average times
    displayTable(proc, n);

    return 0;
}
