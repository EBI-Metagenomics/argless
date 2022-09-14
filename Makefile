.POSIX:

CC ?= gcc
CFLAGS := $(CFLAGS) -std=c99 -Wall -Wextra

SRC := argl_basename.c argl_arg.c argl_option.c argl_argvec.c argl_echo.c argl_help.c argl.c
HDR := argl.h argl_arg.h argl_argvec.h argl_basename.h argl_echo.h argl_help.h argl_option.h argl_os.h
OBJ := $(SRC:.c=.o)

all: check example

argless.h: $(HDR)
	./meld.sh hdr $^ > $@

argless.c: $(SRC) | $(HDR) argless.h
	./meld.sh proto $(HDR) > $@
	./meld.sh src $^ >> $@

argless.o: argless.c | argless.h
	$(CC) $(CFLAGS) -c $<

%.o: %.c $(HDR)
	$(CC) $(CFLAGS) -c $<

test_argl.o: test_utils.h
test_arg.o: test_utils.h
test_argvec.o: test_utils.h
test_option.o: test_utils.h
test_parse.o: test_utils.h

test_argl: test_argl.o $(OBJ)
	$(CC) $^ $(CFLAGS) -o $@
	./test_argl

test_arg: test_arg.o $(OBJ)
	$(CC) $^ $(CFLAGS) -o $@
	./test_arg

test_argvec: test_argvec.o $(OBJ)
	$(CC) $^ $(CFLAGS) -o $@
	./test_argvec

test_option: test_option.o $(OBJ)
	$(CC) $^ $(CFLAGS) -o $@
	./test_option

example.o: argless.h

example: example.o argless.o
	$(CC) $^ $(CFLAGS) -o $@
	./example --version
	./example --help
	./example --usage

check: test_argl test_arg test_argvec test_option example

test: check

clean:
	rm -f *.o test_argl test_arg test_argvec test_option example argless.c argless.h

.PHONY: all check test clean
