#include <stdio.h>
#include <limits.h>

struct Process {
    int pid;  // Process ID
    int bt;   // Burst Time
    int art;  // Arrival Time
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

    int complete = 0, t = 0, minm = INT_MAX;
    int shortest = 0, finish_time;
    int check = 0;

    // Process until all processes get completed
    while (complete != n) {

        // Find process with minimum remaining time among the processes that arrive till the current time
        for (int j = 0; j < n; j++) {
            if ((proc[j].art <= t) && (rt[j] < minm) && rt[j] > 0) {
                minm = rt[j];
                shortest = j;
                check = 1;
            }
        }

        if (check == 0) {
            t++;
            continue;
        }

        // Reduce remaining time by one
        rt[shortest]--;

        // Update minimum
        minm = rt[shortest];
        if (minm == 0)
            minm = INT_MAX;

        // If a process gets completely executed
        if (rt[shortest] == 0) {
            complete++;
            check = 0;

            // Find finish time of the current process
            finish_time = t + 1;

            // Calculate waiting time
            wt[shortest] = finish_time - proc[shortest].bt - proc[shortest].art;

            if (wt[shortest] < 0)
                wt[shortest] = 0;
        }

        // Increment time
        t++;
    }
}

void findTurnAroundTime(struct Process proc[], int n, int wt[], int tat[]) {
    // calculating turnaround time by adding bt[i] + wt[i]
    for (int i = 0; i < n; i++)
        tat[i] = proc[i].bt + wt[i];
}

void findAverageTime(struct Process proc[], int n) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    // Function to find waiting time of all processes
    findWaitingTime(proc, n, wt);

    // Function to find turn around time for all processes
    findTurnAroundTime(proc, n, wt, tat);

    // Display processes along with all details
    printf(" P\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");

    // Calculate total waiting time and total turnaround time
    for (int i = 0; i < n; i++) {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf(" %d\t%d\t%d\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].art, proc[i].bt, proc[i].art + tat[i], tat[i], wt[i]);
    }

    printf("\nAverage waiting time = %.2f\n", (float)total_wt / (float)n);
    printf("Average turn around time = %.2f\n", (float)total_tat / (float)n);
}

int main() {
    struct Process proc[] = {{1, 10, 2}, {2, 5, 5}, {3, 8, 1}};
    int n = sizeof(proc) / sizeof(proc[0]);

    // Sort processes based on arrival time
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - (i + 1); j++) {
            if (proc[j].art > proc[j + 1].art) {
                swap(&proc[j], &proc[j + 1]);
            }
        }
    }

    findAverageTime(proc, n);
    return 0;
}
