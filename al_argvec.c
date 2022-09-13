#include "al_argvec.h"
#include "al_arg.h"
#include "al_opt.h"
#include <string.h>

bool argvec_check_integrity(int argc, char *argv[], int nopts,
                            struct al_opt const *opts)
{
    for (int i = 1; i < argc; ++i)
    {
        if (!arg_is_opt(argv[i])) continue;

        struct al_opt const *opt = opt_get(nopts, opts, argv[i]);
        if (!opt) return false;

        if (opt->is_flag)
        {
            if (arg_is_opt_compact(argv[i])) return false;
        }
        else
        {
            if (arg_is_opt_compact(argv[i])) continue;
            if (i + 1 == argc || arg_is_opt(argv[i + 1])) return false;
            ++i;
        }
    }
    return true;
}

void argvec_sort(int argc, char *argv[], int nopts, struct al_opt const *opts)
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
            struct al_opt const *opt = opt_get(nopts, opts, argv[i]);
            i += !opt->is_flag && !arg_is_opt_compact(argv[i]);
        }
    }
}
