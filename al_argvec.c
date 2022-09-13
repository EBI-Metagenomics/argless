#include "al_argvec.h"
#include "al_arg.h"
#include "al_opt.h"

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
