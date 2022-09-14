#include "argl_option.h"
#include "argl_arg.h"
/* meld-cut-here */
#include <stddef.h>
#include <string.h>

struct argl_option const *opt_get(struct argl_option const *opts,
                                  char const *arg)
{
    for (int i = 0; i < opt_count(opts); ++i)
    {
        if (arg_is_key_opt(arg) && arg_key_opt_eq(arg, opts[i].key))
            return &opts[i];
        if (arg_is_name_opt(arg) && arg_name_opt_eq(arg, opts[i].name))
            return &opts[i];
    }
    return 0;
}

int opt_count(struct argl_option const *opts)
{
    struct argl_option const *opt = opts;
    int size = 0;
    while (opt->name)
    {
        size++;
        opt++;
    }
    return size;
}
/* meld-cut-here */
