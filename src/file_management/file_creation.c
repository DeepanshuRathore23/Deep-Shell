#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "file_ops.h"

void create_file(const char *filename) {
    int fd = open(filename, O_CREAT | O_WRONLY, 0644);
    if (fd == -1) {
        perror("File creation failed");
        return;
    }
    write(fd, "File created from CLI\n", 23);
    close(fd);
    printf("File %s created successfully.\n", filename);
}
