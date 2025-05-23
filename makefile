# Define variables
CC = gcc
CFLAGS = -Wall -Wextra
SRC_DIR = syscalls
OBJ_DIR = obj

# Source files
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/file_ops.c
OBJS = $(SRCS:.c=.o)
TARGET = cli_app

# Default target
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $(SRCS)

# Clean up object files and binary
clean:
	rm -f $(TARGET) $(SRC_DIR)/*.o
