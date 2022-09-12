#include "al_opt.h"
#include "al_arg.h"
#include <stddef.h>

struct al_opt const *opt_get(int nopts, struct al_opt const *opts,
                             char const *arg)
{
    for (int i = 0; i < nopts; ++i)
    {
        if (arg_is_short_opt(arg) && arg_short_opt_eq(arg, opts[i].short_name))
            return &opts[i];
        if (arg_is_long_opt(arg) && arg_long_opt_eq(arg, opts[i].long_name))
            return &opts[i];
    }
    return NULL;
}
