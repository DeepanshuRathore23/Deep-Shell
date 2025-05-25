#include <stdio.h>
#include <unistd.h>
#include "folder_ops.h"

void delete_folder(const char *dirname) {
    if (rmdir(dirname) == -1) {
        perror("Folder deletion failed");
        return;
    }
    printf("Folder %s deleted successfully.\n", dirname);
}
