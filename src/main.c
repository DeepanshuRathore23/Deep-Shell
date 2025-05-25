#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../includes/auth.h"
#include "../includes/file_ops.h"
#include "../includes/folder_ops.h"
#include "../includes/process_management.h"

int main() {
    if (!authenticate()) return 1;

    char input[128], command[64], arg[64];

    while (1) {
        printf("CLI > ");
        fgets(input, sizeof(input), stdin);
        sscanf(input, "%s %s", command, arg);

        if (strcmp(command, "run") == 0) {
            char buffer[64];
            printf("Enter command to run: ");
            scanf("%s", buffer);
            getchar(); // to consume newline left by scanf
            create_process(buffer);
        }
        else if (strcmp(command, "ps") == 0) {
            list_processes();
        }
        else if (strcmp(command, "kill") == 0) {
            pid_t pid;
            printf("Enter PID to kill: ");
            scanf("%d", &pid);
            getchar(); // consume newline
            kill_process(pid);
        }
        else if (strcmp(command, "createf") == 0) {
            create_file(arg);
        }
        else if (strcmp(command, "deletef") == 0) {
            delete_file(arg);
        }
        else if (strcmp(command, "created") == 0) {
            create_folder(arg);
        }
        else if (strcmp(command, "deleted") == 0) {
            delete_folder(arg);
        }
        else if (strcmp(command, "exit") == 0) {
            printf("Exiting CLI.\n");
            break;
        }
        else {
            printf("Unknown command.\n");
        }
    }

    return 0;
}
