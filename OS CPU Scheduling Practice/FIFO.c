#include <stdio.h>

void fifoPageReplacement(int pages[], int n, int capacity) {
    int frame[capacity];
    int frameIndex = 0;
    int pageFaults = 0;

    for (int i = 0; i < n; i++) {
        int pageExists = 0;

        for (int j = 0; j < capacity; j++) {
            if (frame[j] == pages[i]) {
                pageExists = 1;
                break;
            }
        }

        if (!pageExists) {
            frame[frameIndex] = pages[i];
            frameIndex = (frameIndex + 1) % capacity;
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

    fifoPageReplacement(pages, n, capacity);

    return 0;
}
