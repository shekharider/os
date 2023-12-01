#include <stdio.h>

void calculateNeed(int need[][4], int max[][4], int alloc[][4], int n, int m) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
}

int isSafe(int processes[], int avail[], int max[][4], int alloc[][4], int n, int m) {
    int need[n][m];
    calculateNeed(need, max, alloc, n, m);

    int finish[n];
    for (int i = 0; i < n; i++)
        finish[i] = 0;

    int work[m];
    for (int i = 0; i < m; i++)
        work[i] = avail[i];

    int safeSeq[n];
    int count = 0;

    while (count < n) {
        int found = 0;
        for (int p = 0; p < n; p++) {
            if (finish[p] == 0) {
                int j;
                for (j = 0; j < m; j++) {
                    if (need[p][j] > work[j])
                        break;
                }

                if (j == m) {
                    for (int k = 0; k < m; k++)
                        work[k] += alloc[p][k];

                    safeSeq[count++] = p;
                    finish[p] = 1;
                    found = 1;
                }
            }
        }

        if (found == 0) {
            printf("System is not in safe state");
            return 0;
        }
    }

    printf("System is in safe state.\nSafe sequence is: ");
    for (int i = 0; i < n; i++)
        printf("%d ", safeSeq[i]);

    return 1;
}

int main() {
    int processes[] = {0, 1, 2, 3};
    int n = sizeof(processes) / sizeof(processes[0]);

    int available[] = {3, 3, 2};

    int max[][4] = {{7, 5, 3},
                    {3, 2, 2},
                    {9, 0, 2},
                    {2, 2, 2}};

    int alloc[][4] = {{0, 1, 0},
                      {2, 0, 0},
                      {3, 0, 2},
                      {2, 1, 1}};

    isSafe(processes, available, max, alloc, n, 3);

    return 0;
}
