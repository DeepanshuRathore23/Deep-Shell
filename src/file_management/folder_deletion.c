#include <stdio.h>
#include "../../includes/file_management.h"
#include "../../syscalls/syscall_wrappers.h"

int delete_folder(const char *foldername) {
    return syscall_delete_folder(foldername);
}
