#include <stdio.h>
#include "../../includes/authentication.h"
#include "../../syscalls/syscall_wrappers.h"

int authenticate_user(const char *username, const char *password) {
    return syscall_authenticate(username, password);
}
