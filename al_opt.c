#include "al_opt.h"
#include "al_arg.h"
#include <stddef.h>
#include <string.h>

struct al_opt const *opt_get(struct al_opt const *opts, char const *arg)
{
    for (int i = 0; i < opt_count(opts); ++i)
    {
        if (arg_is_short_opt(arg) && arg_short_opt_eq(arg, opts[i].short_name))
            return &opts[i];
        if (arg_is_long_opt(arg) && arg_long_opt_eq(arg, opts[i].long_name))
            return &opts[i];
    }
    return NULL;
}

int opt_count(struct al_opt const *opts)
{
    struct al_opt const *opt = opts;
    int size = 0;
    while (opt->long_name)
    {
        size++;
        opt++;
    }
    return size;
}
