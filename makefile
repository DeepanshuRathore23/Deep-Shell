CC = gcc
CFLAGS = -Wall -Wextra -g -Iincludes
SRC = src/main.c \
      src/authentication.c \
      src/file_management/file_creation.c \
      src/file_management/file_deletion.c \
      src/file_management/folder_creation.c \
      src/file_management/folder_deletion.c \
      syscalls/syscall_wrappers.c
OBJ = $(SRC:.c=.o)
TARGET = build/mycli

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJ) $(TARGET)
