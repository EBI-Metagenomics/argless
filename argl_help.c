#include "argl_help.h"
#include "argl_echo.h"
#include "argl_option.h"
/* meld-cut-here */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void display_try_info(char const *progam_name);

void help_usage(char const *prog, struct argl_option const *opts, bool die)
{
    echo_start(11);
    echof("Usage: %s", prog);

    echos(" [-");
    for (int i = 0; i < opt_count(opts); ++i)
    {
        if (isprint(opts[i].short_name)) echoc(opts[i].short_name);
    }
    echos("]");

    for (int i = 0; i < opt_count(opts); ++i)
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

void help_help(char const *prog, char const *doc,
               struct argl_option const *opts, bool die)
{
    echo_start(0);
    echof("Usage: %s [OPTION...] ARG1 ARG2", prog);
    echoc('\n');
    echo_end();

    echo_start(2);
    echoc(' ');
    char const *start = doc;
    char const *end = strchr(doc, ' ');
    while (end)
    {
        echof(" %.*s", (end - start), start);
        start = end + 1;
        end = strchr(start, ' ');
    }
    echo_end();

    echo_start(0);
    echoc('\n');
    echos("Options:");
    echo_end();

    echo_start(28);
    for (int i = 0; i < opt_count(opts); ++i)
    {
        if (isprint(opts[i].short_name))
        {
            echof("  -%c, --%s", opts[i].short_name, opts[i].long_name);
            echor(opts[i].arg_doc);
        }
        else
        {
            echof("      --%s", opts[i].long_name);
            echor(opts[i].arg_doc);
        }
        echo_flush();
    }
    echo_end();
    if (die) exit(0);
}

void help_version(char const *prog, char const *version, bool die)
{
    echo_start(0);
    echof("%s, version %s", prog, version);
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
/* meld-cut-here */
