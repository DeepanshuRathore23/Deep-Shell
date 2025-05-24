#include <stdio.h>
#include "../../includes/file_management.h"
#include "../../syscalls/syscall_wrappers.h"

int delete_file(const char *filename) {
    return syscall_delete_file(filename);
}
