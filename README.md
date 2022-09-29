# Argless

Cross-platform argument parser for C/C++.

## Usage

Download the latest [release](https://github.com/horta/argless/releases) and
include `argless.h` and `argless.c` in your project.

### Minimal example

```c
#include "argless.h"

static struct argl_option const options[] = {
    ARGL_DEFAULT,
    ARGL_END,
};

static struct argl argl = {.options = options,
                           .args_doc = ARGL_NULL,
                           .doc = "Lorem ipsum dolor sit amet.",
                           .version = "1.0.0"};

int main(int argc, char *argv[])
{
    argl_parse(&argl, argc, argv);
    return 0;
}
```

Help, version, and usage commmands come for free.

```
$ ./minimal --help
Usage: minimal [OPTION...]

  Lorem ipsum dolor sit amet.

Options:
  -?, --help                 Give this help list
      --usage                Give a short usage message
  -V, --version              Print program version
```

```
$ ./minimal --version
minimal, version 1.0.0
```

```
$ ./minimal --usage
Usage: minimal [-?V] [--help] [--usage] [--version]
```

### Comprehensive example

```c
#include "argless.h"
#include <stdio.h>

static struct argl_option const options[] = {
    {"input", 'i', ARGL_TEXT("INPUT", ARGL_NULL), "Input file"},
    {"output", 'o', ARGL_TEXT("OUTPUT", "/dev/null"), "Output file"},
    {"fast", 'f', ARGL_FLAG(), "Enable fast processing"},
    {"quiet", 'q', ARGL_FLAG(), "Disable output to stdout"},
    {"ncores", 'n', ARGL_TEXT("NCORES", "1"), "Set the number of cores"},
    ARGL_DEFAULT,
    ARGL_END,
};

static struct argl argl = {
    .options = options,
    .args_doc = "ARG1 ARG2",
    .doc = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do "
           "eiusmod tempor incididunt ut labore et dolore magna aliqua.",
    .version = "1.0.0"};

int main(int argc, char *argv[])
{
    argl_parse(&argl, argc, argv);
    if (argl_nargs(&argl) != 2) argl_usage(&argl);

    printf("Arguments:");
    for (int k = 0; k < argl_nargs(&argl); ++k)
        printf(" %s", argl_args(&argl)[k]);
    puts("\n");

    char const *i = argl_get(&argl, "input");
    char const *o = argl_get(&argl, "output");
    char const *f = argl_get(&argl, "fast");
    char const *q = argl_get(&argl, "quiet");
    char const *n = argl_get(&argl, "ncores");

    printf("Options:\n");
    printf("  input  = %s\n", i);
    printf("  output = %s\n", o);
    printf("  fast   = %s\n", f);
    printf("  quiet  = %s\n", q);
    printf("  ncores = %s\n", n);

    return 0;
}
```

The help format is based on the Argp one.

```
$ ./example --help
Usage: example [OPTION...] ARG1 ARG2

  Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor
  incididunt ut labore et dolore magna aliqua.

Options:
  -i, --input                Input file
  -o, --output               Output file [/dev/null]
  -f, --fast                 Enable fast processing
  -q, --quiet                Disable output to stdout
  -n, --ncores               Set the number of cores [1]
  -?, --help                 Give this help list
      --usage                Give a short usage message
  -V, --version              Print program version
```

Passing the two required arguments.

```
$ ./example arg1 arg2
Arguments: arg1 arg2

Options:
  input  =
  output = /dev/null
  fast   = false
  quiet  = false
  ncores = 1
```

Notice that arguments can be passed in-between options.

```
$ ./example arg1 --input file.txt --output - --ncores 1 --fast arg2
Arguments: arg1 arg2

Options:
  input  = file.txt
  output = -
  fast   = true
  quiet  = false
  ncores = 1
```

## Acknowledgements

 - [Argp](https://www.gnu.org/software/libc/manual/html_node/Argp.html)
 - [Getopt](https://www.gnu.org/software/libc/manual/html_node/Getopt.html)

## Authors

- [Danilo Horta](https://www.github.com/horta)

## License

This project is licensed under the [MIT license](https://raw.githubusercontent.com/horta/argless/main/LICENSE).
