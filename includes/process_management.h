#ifndef PROCESS_MANAGEMENT_H
#define PROCESS_MANAGEMENT_H

void create_process(const char *command);
void list_processes();
void kill_process(pid_t pid);

#endif
