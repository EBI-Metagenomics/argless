#include "argless.h"
#include <stdio.h>

static struct argl_option const options[] = {
    {"input", 'i', "INPUT", "Input file", false},
    {"output", 'o', "OUTPUT", "Output file", false},
    {"fast", 'f', 0, "Enable fast processing", true},
    {"quiet", 'q', 0, "Disable output to stdout", true},
    {"ncores", 'n', "NCORES", "Set the number of cores to use", false},
    ARGL_DEFAULT_OPTS,
    ARGL_NULL_OPT,
};

static struct argl argl = {
    .options = options,
    .args_doc = "ARG1 ARG2",
    .doc = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do "
           "eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut "
           "enim ad minim veniam, quis nostrud exercitation ullamco laboris "
           "nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor "
           "in reprehenderit in voluptate velit esse cillum dolore eu fugiat "
           "nulla pariatur. Excepteur sint occaecat cupidatat non proident, "
           "sunt in culpa qui officia deserunt mollit anim id est laborum.",
    .version = "1.0.0"};

int main(int argc, char *argv[])
{
    argl_parse(&argl, argc, argv);

    if (argc == 1) argl_usage(&argl);

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
