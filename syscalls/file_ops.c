#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include"file_ops.h"

void create_file(const char *filename) {
    int fd = open(filename, O_CREAT || O_WRONLY, 0644);

    if(fd == -1) {
        perror("Error creating file\n");
        return;
    }

    write(fd, "created file using system call", 32);
    close(fd);
    printf("%s file has been ceated\n", filename);
}

void delete_file(const char *filename) {
    if(unlink(filename) == -1) {
        printf("Error deleting the file\n");
        return;
    }
    printf("%s file has been deleted\n", filename);
}

void read_file(const char *filename) {
    char buffer[1024];
    int fd = open(filename, O_RDONLY);

    if(fd == -1) {
        perror("Error opening file\n");
        return;
    }

    int bytes_read = read(fd, buffer, sizeof(buffer));

    if(bytes_read>0) {
        write(STDOUT_FILENO, buffer, bytes_read);
    }

    close(fd);
}