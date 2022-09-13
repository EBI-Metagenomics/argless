.POSIX:

CC ?= gcc
CFLAGS := $(CFLAGS) -std=c99 -Wall -Wextra

SRC := al.c al_arg.c al_argvec.c al_basename.c al_echo.c al_help.c al_opt.c
HDR := al.h al_arg.h al_argvec.h al_basename.h al_echo.h al_help.h al_opt.h al_os.h
OBJ := $(SRC:.c=.o)

all: meld example

argless.h: $(HDR)
	./meld.sh hdr $^ > $@

argless.c: $(SRC) | argless.h
	./meld.sh src $^ > $@

%.o: %.c $(HDR)
	$(CC) $(CFLAGS) -c $<

meld: argless.h argless.c

test_al.o: test_utils.h
test_arg.o: test_utils.h
test_argvec.o: test_utils.h
test_opt.o: test_utils.h
test_parse.o: test_utils.h

test_al: test_al.o $(OBJ)
	$(CC) $^ $(CFLAGS) -o $@
	./test_al

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

check: test_al test_arg test_argvec test_opt example

test: check

clean:
	rm -f *.o test_al test_arg test_argvec test_opt example argless.c argless.h

.PHONY: all check test clean meld
