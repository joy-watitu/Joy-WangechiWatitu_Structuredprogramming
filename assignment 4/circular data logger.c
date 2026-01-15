#include <stdio.h>
#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int start = 0;  // Points to the oldest element
int count = 0;  // Number of elements currently in buffer

// Insert a new sample into the buffer
void insert_sample(int value) {
    int index = (start + count) % BUFFER_SIZE;
    if (count < BUFFER_SIZE) {
        buffer[index] = value;
        count++;
    } else {
        buffer[start] = value;
        start = (start + 1) % BUFFER_SIZE;
    }
}

// Print all samples in chronological order
void print_samples()
{
    printf("Stored samples (oldest → newest): ");
    for (int i = 0; i < count; i++)
        {
        int index = (start + i) % BUFFER_SIZE;
        printf("%d ", buffer[index]);
    }
    printf("\n");
}

int main() {
    int value;
    char command;

    printf("Enter sensor values (type 'p' to print, 'q' to quit):\n");
    while (1) {
        if (scanf(" %c", &command) != 1) break;

        if (command == 'p') {
            print_samples();
        } else if (command == 'q') {
            break;
        } else {
            ungetc(command, stdin);
            if (scanf("%d", &value) == 1) {
                insert_sample(value);
            }
        }
    }

    return 0;
}
