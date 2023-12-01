#include <stdio.h>
#include <limits.h>

void lruPageReplacement(int pages[], int n, int capacity) {
    int frame[capacity];
    int recentlyUsed[capacity];
    int pageFaults = 0;

    for (int i = 0; i < capacity; i++) {
        frame[i] = -1;
        recentlyUsed[i] = INT_MAX;
    }

    for (int i = 0; i < n; i++) {
        int pageExists = 0;

        for (int j = 0; j < capacity; j++) {
            if (frame[j] == pages[i]) {
                pageExists = 1;
                recentlyUsed[j] = i;
                break;
            }
        }

        if (!pageExists) {
            int leastRecentlyUsedIndex = 0;
            for (int j = 1; j < capacity; j++) {
                if (recentlyUsed[j] < recentlyUsed[leastRecentlyUsedIndex]) {
                    leastRecentlyUsedIndex = j;
                }
            }

            frame[leastRecentlyUsedIndex] = pages[i];
            recentlyUsed[leastRecentlyUsedIndex] = i;
            pageFaults++;
        }

        printf("Page %d: ", pages[i]);
        for (int j = 0; j < capacity; j++) {
            if (frame[j] == -1) {
                printf("[ ] ");
            } else {
                printf("[%d] ", frame[j]);
            }
        }
        printf("\n");
    }

    printf("Total Page Faults: %d\n", pageFaults);
}

int main() {
    int pages[] = {2, 3, 1, 4, 6, 2, 9, 8, 5, 4};
    int n = sizeof(pages) / sizeof(pages[0]);
    int capacity = 3;

    lruPageReplacement(pages, n, capacity);

    return 0;
}
