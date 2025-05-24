#include <stdio.h>
#include "../../includes/file_management.h"
#include "../../syscalls/syscall_wrappers.h"

int create_folder(const char *foldername) {
    return syscall_create_folder(foldername);
}
