# Argless

Cross-platform argument parser for C/C++.

## Usage

### Minimal example

```c
#include "argless.h"

static struct argl_option const options[] = {
    ARGL_DEFAULT_OPTS,
    ARGL_NULL_OPT,
};

static struct argl argl = {.options = options,
                           .args_doc = nullptr,
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

  Lorem ipsum dolor sit

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
    {"input", 'i', "INPUT", "Input file", false},
    {"output", 'o', "OUTPUT", "Output file", false},
    {"fast", 'f', nullptr, "Enable fast processing", true},
    {"quiet", 'q', nullptr, "Disable output to stdout", true},
    {"ncores", 'n', "NCORES", "Set the number of cores to use", false},
    ARGL_DEFAULT_OPTS,
    ARGL_NULL_OPT,
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

    if (argc == 2) argl_usage(&argl);

    printf("Arguments:");
    for (int k = 0; k < argl_nargs(&argl); ++k)
        printf(" %s", argl_args(&argl)[k]);
    puts("\n");

    char const *i = argl_has(&argl, "input") ? argl_get(&argl, "input") : "";
    char const *o = argl_has(&argl, "output") ? argl_get(&argl, "output") : "";
    char const *f = argl_has(&argl, "fast") ? "enabled" : "disabled";
    char const *q = argl_has(&argl, "quiet") ? "enabled" : "disabled";
    char const *n = argl_has(&argl, "ncores") ? argl_get(&argl, "ncores") : "";

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
  incididunt ut labore et dolore magna

Options:
  -i, --input                Input file
  -o, --output               Output file
  -f, --fast                 Enable fast processing
  -q, --quiet                Disable output to stdout
  -n, --ncores               Set the number of cores to use
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
  output =
  fast   = disabled
  quiet  = disabled
  ncores =
```

Notice that arguments can be passed in-between options.

```
$ ./example arg1 --input file.txt --output - --ncores 1 --fast arg2
Arguments: arg1 arg2

Options:
  input  = file.txt
  output = -
  fast   = enabled
  quiet  = disabled
  ncores = 1
```

## Acknowledgements

 - [Argp](https://www.gnu.org/software/libc/manual/html_node/Argp.html)
 - [Getopt](https://www.gnu.org/software/libc/manual/html_node/Getopt.html)

## Authors

- [Danilo Horta](https://www.github.com/horta)

## License

This project is licensed under the [MIT license](https://raw.githubusercontent.com/horta/argless/main/LICENSE).
