
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigcont_handler(int sig) {
    printf("Received SIGCONT signal. Process resumed.\n");
}

int main() {
    // Set up handler for SIGCONT signal
    signal(SIGCONT, sigcont_handler);

    printf("Waiting for signals. My PID: %d\n", getpid());

    // Infinite loop to keep the process running
    while (1) {
        pause();  // Wait for any signal
    }

    return 0;
}

