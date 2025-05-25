#include <stdio.h>
#include <string.h>
#include "auth.h"

int authenticate() {
    char username[32], password[32];
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    if (strcmp(username, "admin") == 0 && strcmp(password, "root") == 0) {
        printf("Login successful!\n");
        return 1;
    }

    printf("Authentication failed.\n");
    return 0;
}
