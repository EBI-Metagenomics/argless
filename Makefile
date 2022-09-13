.POSIX:

CC ?= gcc
CFLAGS := $(CFLAGS) -std=c99 -Wall -Wextra

SRC := al_arg.c al_argvec.c al_basename.c al_echo.c al_help.c al_opt.c al_parse.c
HDR := al_arg.h al_argvec.h al_basename.h al_echo.h al_help.h al_opt.h al_os.h al_parse.h
OBJ := $(SRC:.c=.o)

all: example

%.o: %.c $(HDR)
	$(CC) $(CFLAGS) -c $<

test_arg.o: test_utils.h
test_argvec.o: test_utils.h
test_opt.o: test_utils.h
test_parse.o: test_utils.h

test_arg: test_arg.o $(OBJ)
	$(CC) $^ $(CFLAGS) -o $@
	./test_arg

test_argvec: test_argvec.o $(OBJ)
	$(CC) $^ $(CFLAGS) -o $@
	./test_argvec

test_opt: test_opt.o $(OBJ)
	$(CC) $^ $(CFLAGS) -o $@
	./test_opt

example: example.o $(OBJ)

check: test_arg test_argvec test_opt example

test: check

clean:
	rm -f *.o test_arg test_argvec test_opt example

.PHONY: all check test clean
