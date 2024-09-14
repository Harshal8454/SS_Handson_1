#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    pid_t pid;

    printf("Enter the PID of the process to send signals to: ");
    scanf("%d", &pid);

    // Sending SIGSTOP to stop the process
    kill(pid, SIGSTOP);
    printf("Sent SIGSTOP to process %d.\n", pid);

    // Sleep for a few seconds to demonstrate stopping
    sleep(5);

    // Sending SIGCONT to resume the process
    kill(pid, SIGCONT);
    printf("Sent SIGCONT to process %d.\n", pid);

    return 0;
}
