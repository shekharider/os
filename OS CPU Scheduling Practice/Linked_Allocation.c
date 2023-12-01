#include <stdio.h>

struct Node {
    int data;
    struct Node* next;
};

void linkedAllocation(int block_size[], int m, int file_size[], int n) {
    struct Node* head = NULL;

    for (int i = 0; i < m; i++) {
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = block_size[i];
        temp->next = head;
        head = temp;
    }

    int allocation[n];

    for (int i = 0; i < n; i++) {
        struct Node* current = head;
        struct Node* prev = NULL;

        while (current != NULL && current->data < file_size[i]) {
            prev = current;
            current = current->next;
        }

        if (current != NULL) {
            allocation[i] = current->data;
            prev->next = current->next;
            free(current);
        } else {
            allocation[i] = -1;
        }
    }

    printf("\nFile No.\tFile Size\tBlock No.\n");
    for (int i = 0; i < n; i++) {
        printf(" %d \t\t %d \t\t", i + 1, file_size[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i]);
        else
            printf("Not Allocated\n");
    }
}

int main() {
    int block_size[] = {100, 500, 200, 300, 600};
    int m = sizeof(block_size) / sizeof(block_size[0]);

    int file_size[] = {212, 417, 112, 426};
    int n = sizeof(file_size) / sizeof(file_size[0]);

    linkedAllocation(block_size, m, file_size, n);

    return 0;
}
