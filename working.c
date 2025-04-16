#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Function to get current time in seconds
time_t getCurrentTime() {
    return time(NULL);
}

// Function to format seconds into hh:mm:ss
void printDuration(time_t seconds) {
    int hrs = seconds / 3600;
    int mins = (seconds % 3600) / 60;
    int secs = seconds % 60;
    printf("Total working duration: %02d:%02d:%02d\n", hrs, mins, secs);
}

int main() {
    char option;
    time_t startTime, endTime;

    printf("==== Work Hours Tracker ====\n");

    printf("Press 's' to start working: ");
    scanf(" %c", &option);

    if (option != 's') {
        printf("Invalid input. Exiting.\n");
        return 0;
    }

    startTime = getCurrentTime();
    printf("Work started at: %s", ctime(&startTime));

    printf("\nPress 'e' to end work: ");
    scanf(" %c", &option);

    if (option != 'e') {
        printf("Invalid input. Exiting.\n");
        return 0;
    }

    endTime = getCurrentTime();
    printf("Work ended at: %s", ctime(&endTime));

    time_t totalSeconds = endTime - startTime;

    printDuration(totalSeconds);

    return 0;
}
