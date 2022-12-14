#include "argl_help.h"
#include "argl_echo.h"
#include "argl_option.h"
/* meld-cut-here */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void display_try_info(char const *progam_name);

void help_usage(char const *prog, struct argl_option const *opts,
                int exit_status)
{
    echo_start(11);
    echof("Usage: %s", prog);

    echos(" [-");
    for (int i = 0; i < opts_count(opts); ++i)
    {
        if (isprint(opts[i].key)) echoc(opts[i].key);
    }
    echos("]");

    for (int i = 0; i < opts_count(opts); ++i)
    {
        if (isprint(opts[i].key) && !opt_is_flag(opts + i))
        {
            echof(" [-%c %s]", opts[i].key, opt_arg_name(opts + i));
        }
        if (!opt_is_flag(opts + i))
            echof(" [--%s=%s]", opts[i].name, opt_arg_name(opts + i));
        else
            echof(" [--%s]", opts[i].name);
    }

    echo_end();
    exit(exit_status);
}

void help_help(char const *prog, char const *args_doc, char const *doc,
               struct argl_option const *opts, int exit_status)
{
    echo_start(0);
    echof("Usage: %s [OPTION...]", prog);
    if (args_doc) echof(" %s", args_doc);
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
    if (strlen(start) > 0) echof(" %s", start);
    echo_end();

    echo_start(0);
    echoc('\n');
    echos("Options:");
    echo_end();

    echo_start(28);
    for (int i = 0; i < opts_count(opts); ++i)
    {
        if (isprint(opts[i].key))
            echof("  -%c, --%s", opts[i].key, opts[i].name);
        else
            echof("      --%s", opts[i].name);

        if (opt_has_user_default(opts + i))
            echor2(opts[i].arg_doc, opt_get_default(opts + i));
        else
            echor(opts[i].arg_doc);
        echo_flush();
    }
    echo_end();
    exit(exit_status);
}

void help_version(char const *prog, char const *version, int exit_status)
{
    echo_start(0);
    echof("%s, version %s", prog, version);
    echo_end();
    exit(exit_status);
}

void help_requires_arg(char const *prog, char const *arg, int exit_status)
{
    printf("%s: option `%s' requires an argument\n", prog, arg);
    display_try_info(prog);
    exit(exit_status);
}

void help_unrecognized_arg(char const *prog, char const *arg, int exit_status)
{
    printf("%s: unrecognized option `%s'\n", prog, arg);
    display_try_info(prog);
    exit(exit_status);
}

static void display_try_info(char const *prg)
{
    printf("Try `%s --help' or `%s --usage' for more information.\n", prg, prg);
}
/* meld-cut-here */
