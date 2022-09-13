#include "al_help.h"
#include "al_echo.h"
#include "al_opt.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

static void display_try_info(char const *progam_name);

void help_usage(char const *prog, int nopts, struct al_opt const *opts,
                bool die)
{
    echo_start(11);
    echof("Usage: %s", prog);

    echos(" [-");
    for (int i = 0; i < nopts; ++i)
    {
        if (isprint(opts[i].short_name)) echoc(opts[i].short_name);
    }
    echos("]");

    for (int i = 0; i < nopts; ++i)
    {
        if (isprint(opts[i].short_name) && !opts[i].is_flag)
        {
            echof(" [-%c %s]", opts[i].short_name, opts[i].arg_name);
        }
        if (opts[i].is_flag)
            echof(" [--%s]", opts[i].long_name);
        else
            echof(" [--%s=%s]", opts[i].long_name, opts[i].arg_name);
    }

    echo_end();
    if (die) exit(0);
}

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
