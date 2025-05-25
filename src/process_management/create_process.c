#include <stdlib.h>
#include <stdio.h>
#include "process_management.h"

void create_process(const char *command) {
    if (fork() == 0) {
        execlp(command, command, NULL);
        perror("Error executing process");
        exit(1);
    }
}
