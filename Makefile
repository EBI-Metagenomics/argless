.POSIX:

CC ?= gcc
CFLAGS := $(CFLAGS) -std=c99 -Wall -Wextra

SRC := al_arg.c
OBJ := $(SRC:.c=.o)
HDR := al_arg.h

all: check

al_arg.o: al_arg.h

%.o: %.c $(HDR)
	$(CC) $(CFLAGS) -c $<

test_arg.o: test_utils.h

test_arg: test_arg.o $(OBJ)
	$(CC) $^ $(CFLAGS) -o $@
	./test_arg

check: test_arg

test: check

clean:
	rm -f *.o test_arg 

.PHONY: check test clean
