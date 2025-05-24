//this is my main program#include <stdio.h>
#include <string.h>
#include "../includes/file_management.h"
#include "../includes/authentication.h"

#define MAX_INPUT 256

void prompt() {
    printf("myCLI> ");
}

int main() {
    char input[MAX_INPUT];
    char command[50], target[200];

    printf("Welcome to myCLI\n");

    // Authenticate once at startup
    char username[50], password[50];

    printf("Username: ");
    if (fgets(username, sizeof(username), stdin) == NULL) {
        printf("Failed to read username\n");
        return 1;
    }
    username[strcspn(username, "\n")] = 0;

    printf("Password: ");
    if (fgets(password, sizeof(password), stdin) == NULL) {
        printf("Failed to read password\n");
        return 1;
    }
    password[strcspn(password, "\n")] = 0;

    if (authenticate_user(username, password) != 0) {
        printf("Authentication failed. Exiting.\n");
        return 1;
    }

    printf("Authentication successful.\n\n");

    while (1) {
        prompt();

        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("\nExiting...\n");
            break;
        }

        int args = sscanf(input, "%49s %199s", command, target);

        if (args < 1) continue;

        if (strcmp(command, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        }
        else if (strcmp(command, "help") == 0) {
            printf("Commands:\n");
            printf(" create_file <filename>\n");
            printf(" delete_file <filename>\n");
            printf(" create_folder <foldername>\n");
            printf(" delete_folder <foldername>\n");
            printf(" exit\n");
        }
        else if (args == 2) {
            int ret = -1;
            if (strcmp(command, "create_file") == 0) {
                ret = create_file(target);
            }
            else if (strcmp(command, "delete_file") == 0) {
                ret = delete_file(target);
            }
            else if (strcmp(command, "create_folder") == 0) {
                ret = create_folder(target);
            }
            else if (strcmp(command, "delete_folder") == 0) {
                ret = delete_folder(target);
            }
            else {
                printf("Unknown command. Type 'help' for help.\n");
                continue;
            }

            if (ret == 0)
                printf("Command '%s' executed successfully.\n", command);
            else
                printf("Command '%s' failed.\n", command);
        }
        else {
            printf("Invalid input. Type 'help' for help.\n");
        }
    }

    return 0;
}
