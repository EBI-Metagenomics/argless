#include "al_argvec.h"
#include "al_arg.h"
#include "al_basename.h"
#include "al_help.h"
#include "al_opt.h"
#include <string.h>

bool argvec_check_valid(int argc, char *argv[], struct al_opt const *opts,
                        bool die)
{
    char const *prg = al_basename(argv[0]);
    for (int i = 1; i < argc; ++i)
    {
        if (!arg_is_opt(argv[i])) continue;

        struct al_opt const *opt = opt_get(opts, argv[i]);
        if (!opt)
        {
            if (die) help_unrecognized_arg(prg, argv[i], die);
            return false;
        }

        if (opt->is_flag)
        {
            if (arg_is_opt_compact(argv[i]))
            {
                if (die) help_unrecognized_arg(prg, argv[i], die);
                return false;
            }
        }
        else
        {
            if (arg_is_opt_compact(argv[i])) continue;
            if (i + 1 == argc || arg_is_opt(argv[i + 1]))
            {
                if (die) help_requires_arg(prg, argv[i], die);
                return false;
            }
            ++i;
        }
    }
    return true;
}

void argvec_sort(int argc, char *argv[], struct al_opt const *opts)
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
            struct al_opt const *opt = opt_get(opts, argv[i]);
            i += !opt->is_flag && !arg_is_opt_compact(argv[i]);
        }
    }
}

static int option_index(int argc, char *argv[], struct al_opt const *opts,
                        char const *long_name);

bool argvec_has(int argc, char *argv[], struct al_opt const *opts,
                char const *long_name)
{
    return option_index(argc, argv, opts, long_name) != -1;
}

char const *argvec_get(int argc, char *argv[], struct al_opt const *opts,
                       char const *long_name)
{
    int i = option_index(argc, argv, opts, long_name);
    if (i == -1) return 0;

    return arg_is_opt_compact(argv[i]) ? arg_opt_compact_value(argv[i])
                                       : argv[i + 1];
}

static int option_index(int argc, char *argv[], struct al_opt const *opts,
                        char const *long_name)
{
    for (int i = 1; i < argc; ++i)
    {
        if (arg_is_opt(argv[i]))
        {
            struct al_opt const *opt = opt_get(opts, argv[i]);
            if (opt)
            {
                if (!strcmp(opt->long_name, long_name)) return i;
                i += !opt->is_flag && !arg_is_opt_compact(argv[i]);
            }
        }
    }
    return -1;
}
