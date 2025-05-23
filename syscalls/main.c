#include<string.h>
#include<stdio.h>
#include"file_ops.h"

void show_help() {
    printf("Available commands \n");
    printf("(1) create <filename>\n");
    printf("(2) read <filename>");
    printf("(3) delete <filename>");
    printf("(4) quit : exits the CLI");
}

int main() {
    char command[100], filename[100];

    while(1) {
        scanf("%s", command);
        if(strcmp(command, "quit") == 0) break;

        scanf("%s", filename);

        if(strcmp(command, "create") == 0) create_file(filename);
        else if(strcmp(command, "read") == 0) read_file(filename);
        else if(strcmp(command, "delete") == 0) delete_file(filename);
    }

}