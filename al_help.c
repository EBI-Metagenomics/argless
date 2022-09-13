#include "al_help.h"
#include <stdio.h>
#include <stdlib.h>

static void display_try_info(char const *progam_name);

void help_requires_arg(char const *prog, char const *arg, bool die)
{
    printf("%s: option `%s' requires an argument\n", prog, arg);
    display_try_info(prog);
    if (die) exit(1);
}

void help_unrecognized_arg(char const *prog, char const *arg, bool die)
{
    printf("%s: unrecognized option `%s'\n", prog, arg);
    display_try_info(prog);
    if (die) exit(1);
}

static void display_try_info(char const *prg)
{
    printf("Try `%s --help' or `%s --usage' for more information.\n", prg, prg);
}
