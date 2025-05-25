CC = gcc
CFLAGS = -Iincludes

SRC = $(wildcard src/*.c) \
      $(wildcard src/file_management/*.c)

OBJ = $(SRC:.c=.o)
TARGET = build/cli

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^

clean:
	rm -f $(OBJ) $(TARGET)
