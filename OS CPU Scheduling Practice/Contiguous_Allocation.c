#include <stdio.h>

void contiguousAllocation(int block_size[], int m, int file_size[], int n) {
    int allocation[n];

    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (allocation[j] == -1 && block_size[j] >= file_size[i]) {
                allocation[i] = j;
                break;
            }
        }
    }

    printf("\nFile No.\tFile Size\tBlock No.\n");
    for (int i = 0; i < n; i++) {
        printf(" %d \t\t %d \t\t", i + 1, file_size[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

int main() {
    int block_size[] = {100, 500, 200, 300, 600};
    int m = sizeof(block_size) / sizeof(block_size[0]);

    int file_size[] = {212, 417, 112, 426};
    int n = sizeof(file_size) / sizeof(file_size[0]);

    contiguousAllocation(block_size, m, file_size, n);

    return 0;
}
