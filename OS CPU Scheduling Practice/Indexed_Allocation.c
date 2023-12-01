#include <stdio.h>

struct IndexBlock {
    int blockNumbers[10];
};

void indexedAllocation(int block_size[], int m, int file_size[], int n) {
    struct IndexBlock indexTable[n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (block_size[j] >= file_size[i]) {
                indexTable[i].blockNumbers[0] = j;
                for (int k = 1; k < file_size[i]; k++) {
                    indexTable[i].blockNumbers[k] = -1;
                }
                break;
            }
        }
    }

    printf("\nFile No.\tFile Size\tBlock No.\n");
    for (int i = 0; i < n; i++) {
        printf(" %d \t\t %d \t\t", i + 1, file_size[i]);
        if (indexTable[i].blockNumbers[0] != -1) {
            for (int j = 0; j < file_size[i]; j++) {
                printf("%d ", indexTable[i].blockNumbers[j]);
            }
            printf("\n");
        } else {
            printf("Not Allocated\n");
        }
    }
}

int main() {
    int block_size[] = {100, 500, 200, 300, 600};
    int m = sizeof(block_size) / sizeof(block_size[0]);

    int file_size[] = {2, 4, 3, 5};
    int n = sizeof(file_size) / sizeof(file_size[0]);

    indexedAllocation(block_size, m, file_size, n);

    return 0;
}
