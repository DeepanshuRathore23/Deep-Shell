#include <signal.h>
#include <stdio.h>
#include "process_management.h"

void kill_process(pid_t pid) {
    if (kill(pid, SIGTERM) == 0)
        printf("Process %d terminated.\n", pid);
    else
        perror("Error terminating process");
}
