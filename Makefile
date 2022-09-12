.POSIX:

CC ?= gcc
CFLAGS := $(CFLAGS) -std=c99 -Wall -Wextra

SRC := al_arg.c al_opt.c
OBJ := $(SRC:.c=.o)

all: check

al_arg.o: al_arg.h
al_opt.o: al_opt.h

%.o: %.c $(HDR)
	$(CC) $(CFLAGS) -c $<

test_arg.o: test_utils.h
test_opt.o: test_utils.h

test_arg: test_arg.o $(OBJ)
	$(CC) $^ $(CFLAGS) -o $@
	./test_arg

test_opt: test_opt.o $(OBJ)
	$(CC) $^ $(CFLAGS) -o $@
	./test_opt

check: test_arg test_opt

test: check

clean:
	rm -f *.o test_arg test_opt

.PHONY: check test clean
