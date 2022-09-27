#include "argl_argvec.h"
#include "argl_arg.h"
#include "argl_basename.h"
#include "argl_help.h"
#include "argl_option.h"
/* meld-cut-here */
#include <stdlib.h>
#include <string.h>

bool argvec_check_valid(int argc, char *argv[], struct argl_option const *opts,
                        bool die)
{
    char const *prg = al_basename(argv[0]);
    for (int i = 1; i < argc; ++i)
    {
        if (!arg_is_opt(argv[i])) continue;

        struct argl_option const *opt = opt_get(opts, argv[i]);
        if (!opt)
        {
            if (die) help_unrecognized_arg(prg, argv[i], EXIT_FAILURE);
            return false;
        }

        if (opt->has_value)
        {
            if (arg_is_opt_compact(argv[i])) continue;
            if (i + 1 == argc || arg_is_opt(argv[i + 1]))
            {
                if (die) help_requires_arg(prg, argv[i], EXIT_FAILURE);
                return false;
            }
            ++i;
        }
        else
        {
            if (arg_is_opt_compact(argv[i]))
            {
                if (die) help_unrecognized_arg(prg, argv[i], EXIT_FAILURE);
                return false;
            }
        }
    }
    return true;
}

void argvec_sort(int argc, char *argv[], struct argl_option const *opts)
{
    char *first_arg = 0;
    for (int i = 1; i < argc && first_arg != argv[i]; ++i)
    {
        if (!arg_is_opt(argv[i]))
        {
            char *curr = argv[i];
            size_t size = argc - 1 - i;
            memmove(argv + i, argv + i + 1, sizeof(argv[0]) * size);
            argv[argc - 1] = curr;
            if (!first_arg) first_arg = curr;
            --i;
        }
        else
        {
            struct argl_option const *opt = opt_get(opts, argv[i]);
            i += opt->has_value && !arg_is_opt_compact(argv[i]);
        }
    }
}

static int option_index(int argc, char *argv[], struct argl_option const *opts,
                        char const *name);

bool argvec_has(int argc, char *argv[], struct argl_option const *opts,
                char const *name)
{
    return option_index(argc, argv, opts, name) != -1;
}

char const *argvec_get(int argc, char *argv[], struct argl_option const *opts,
                       char const *name)
{
    int i = option_index(argc, argv, opts, name);
    if (i == -1) return 0;

    return arg_is_opt_compact(argv[i]) ? arg_opt_compact_value(argv[i])
                                       : argv[i + 1];
}

int argvec_nargs(int argc, char *argv[], struct argl_option const *opts)
{
    char **p = argvec_args(argc, argv, opts);
    return &argv[argc] - p;
}

char **argvec_args(int argc, char *argv[], struct argl_option const *opts)
{
    int i = 1;
    for (; i < argc; ++i)
    {
        if (arg_is_opt(argv[i]))
        {
            struct argl_option const *opt = opt_get(opts, argv[i]);
            if (opt) i += opt->has_value && !arg_is_opt_compact(argv[i]);
        }
        else
            break;
    }
    return argv + i;
}

static int option_index(int argc, char *argv[], struct argl_option const *opts,
                        char const *name)
{
    for (int i = 1; i < argc; ++i)
    {
        if (arg_is_opt(argv[i]))
        {
            struct argl_option const *opt = opt_get(opts, argv[i]);
            if (opt)
            {
                if (!strcmp(opt->name, name)) return i;
                i += opt->has_value && !arg_is_opt_compact(argv[i]);
            }
        }
    }
    return -1;
}
/* meld-cut-here */
