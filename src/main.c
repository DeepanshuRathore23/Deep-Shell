#include <stdio.h>
#include <string.h>
#include "../includes/auth.h"
#include "../includes/file_ops.h"
#include "../includes/folder_ops.h"

int main() {
    if (!authenticate()) return 1;

    char command[64], arg[64];
    while (1) {
        printf("CLI > ");
        scanf("%s %s", command, arg);

        if (strcmp(command, "createf") == 0) create_file(arg);
        else if (strcmp(command, "deletef") == 0) delete_file(arg);
        else if (strcmp(command, "created") == 0) create_folder(arg);
        else if (strcmp(command, "deleted") == 0) delete_folder(arg);
        else if (strcmp(command, "exit") == 0) break;
        else printf("Unknown command.\n");
    }

    return 0;
}
