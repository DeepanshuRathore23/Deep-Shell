#include <unistd.h>
#include <sys/syscall.h>
#include "../../includes/file_management.h"
#include "../../includes/authentication.h"

#define SYS_AUTHENTICATE 550
#define SYS_CREATE_FILE 551
#define SYS_DELETE_FILE 552
#define SYS_CREATE_FOLDER 553
#define SYS_DELETE_FOLDER 554

int syscall_authenticate(const char *username, const char *password) {
    return syscall(SYS_AUTHENTICATE, username, password);
}

int syscall_create_file(const char *filename) {
    return syscall(SYS_CREATE_FILE, filename);
}

int syscall_delete_file(const char *filename) {
    return syscall(SYS_DELETE_FILE, filename);
}

int syscall_create_folder(const char *foldername) {
    return syscall(SYS_CREATE_FOLDER, foldername);
}

int syscall_delete_folder(const char *foldername) {
    return syscall(SYS_DELETE_FOLDER, foldername);
}
