#include <stdio.h>
#include "../../includes/file_management.h"
#include "../../syscalls/syscall_wrappers.h"

int create_file(const char *filename) {
    return syscall_create_file(filename);
}
