#include <stdio.h>
#include <unistd.h>
#include "file_ops.h"

void delete_file(const char *filename) {
    if (unlink(filename) == -1) {
        perror("File deletion failed");
        return;
    }
    printf("File %s deleted successfully.\n", filename);
}
