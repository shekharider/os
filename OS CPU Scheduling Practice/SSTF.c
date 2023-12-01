#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 100

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortRequests(int requests[], int n, int head) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (abs(head - requests[i]) > abs(head - requests[j])) {
                swap(&requests[i], &requests[j]);
            }
        }
    }
}

void calculateSeekTime(int requests[], int n, int head) {
    int seekTime = 0;
    printf("Order of Service\n");
    printf("Head -> ");
    for (int i = 0; i < n; i++) {
        printf("%d -> ", requests[i]);
        seekTime += abs(head - requests[i]);
        head = requests[i];
    }
    printf("End\n");
    printf("Total Seek Time: %d\n", seekTime);
}

int main() {
    int requests[MAX_REQUESTS];
    int n, head;

    // Input number of requests
    printf("Enter the number of requests: ");
    scanf("%d", &n);

    // Input disk requests
    printf("Enter the disk requests:\n");
    for (int i = 0; i < n; i++) {
        printf("Request %d: ", i + 1);
        scanf("%d", &requests[i]);
    }

    // Input initial head position
    printf("Enter the initial head position: ");
    scanf("%d", &head);

    // Sort requests based on seek time
    sortRequests(requests, n, head);

    // Display the order of service and total seek time
    calculateSeekTime(requests, n, head);

    return 0;
}
