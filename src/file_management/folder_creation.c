#include <stdio.h>
#include <sys/stat.h>
#include "folder_ops.h"

void create_folder(const char *dirname) {
    if (mkdir(dirname, 0755) == -1) {
        perror("Folder creation failed");
        return;
    }
    printf("Folder %s created successfully.\n", dirname);
}
