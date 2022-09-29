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
