#include <stdio.h>
#include <limits.h>

int findOptimalIndex(int pages[], int n, int frame[], int start) {
    int index = -1, farthest = start;

    for (int i = 0; i < n; i++) {
        int j;
        for (j = start; j < n; j++) {
            if (frame[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    index = i;
                }
                break;
            }
        }

        if (j == n)
            return i;
    }

    return (index == -1) ? 0 : index;
}

void optimalPageReplacement(int pages[], int n, int capacity) {
    int frame[capacity];
    int pageFaults = 0;

    for (int i = 0; i < capacity; i++)
        frame[i] = -1;

    for (int i = 0; i < n; i++) {
        int pageExists = 0;

        for (int j = 0; j < capacity; j++) {
            if (frame[j] == pages[i]) {
                pageExists = 1;
                break;
            }
        }

        if (!pageExists) {
            int index = findOptimalIndex(pages, n, frame, i + 1);
            frame[index] = pages[i];
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

    optimalPageReplacement(pages, n, capacity);

    return 0;
}
