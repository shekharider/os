#include <stdio.h>

void detectDeadlock(int allocation[5][3], int request[5][3], int available[3], int n, int m) {
    int finish[n], work[m], safeSeq[n];
    int count = 0;

    for (int i = 0; i < n; i++)
        finish[i] = 0;

    for (int i = 0; i < m; i++)
        work[i] = available[i];

    int need[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = allocation[i][j] - request[i][j];

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
                        work[k] += allocation[p][k];

                    safeSeq[count++] = p;
                    finish[p] = 1;
                    found = 1;
                }
            }
        }

        if (found == 0) {
            printf("System is in deadlock state.\n");
            printf("Processes involved in deadlock: ");
            for (int i = 0; i < n; i++) {
                if (finish[i] == 0) {
                    printf("%d ", i);
                }
            }
            return;
        }
    }

    printf("System is not in deadlock state.\n");
}

int main() {
    int allocation[5][3] = {{0, 1, 0},
                             {2, 0, 0},
                             {3, 0, 2},
                             {2, 1, 1},
                             {0, 0, 2}};

    int request[5][3] = {{0, 0, 0},
                         {2, 0, 2},
                         {0, 0, 0},
                         {1, 0, 0},
                         {0, 0, 2}};

    int available[3] = {3, 3, 2};

    int n = sizeof(allocation) / sizeof(allocation[0]);
    int m = sizeof(allocation[0]) / sizeof(allocation[0][0]);

    detectDeadlock(allocation, request, available, n, m);

    return 0;
}
