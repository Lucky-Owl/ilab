
CC = gcc

# Compiler options
CFLAGS = -Wall -fprofile-arcs -ftest-coverage \
	-Wpedantic -Werror -std=c99

RM = rm -rf
OUT = stack

# Default target (make without specified target)
all: build

# Rule for compiling target
build: test.o stack.o
	$(CC) $(CFLAGS) -o $(OUT) test.c stack.c
	$(RM) *.o

# Patterns for compiling object files (*.o)
test.o: test.c stack.h
	$(CC) $(CFLAGS) -c test.c

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c

# Delete all temprorary and binary files
clean:
	$(RM) *.o *~ *gcda *gcno $(OUT)
