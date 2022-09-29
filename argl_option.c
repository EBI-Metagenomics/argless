#include "argl_option.h"
#include "argl_arg.h"
/* meld-cut-here */
#include <stddef.h>
#include <string.h>

struct argl_option const *opts_search(struct argl_option const *opts,
                                      char const *arg)
{
    for (int i = 0; i < opts_count(opts); ++i)
    {
        if (arg_is_key_opt(arg) && arg_key_opt_eq(arg, opts[i].key))
            return &opts[i];
        if (arg_is_name_opt(arg) && arg_name_opt_eq(arg, opts[i].name))
            return &opts[i];
    }
    return NULL;
}

struct argl_option const *opts_get(struct argl_option const *opts,
                                   char const *name)
{
    for (int i = 0; i < opts_count(opts); ++i)
    {
        if (!strcmp(name, opts[i].name)) return &opts[i];
    }
    return NULL;
}

int opts_count(struct argl_option const *opts)
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

bool opt_has_user_default(struct argl_option const *opt)
{
    return !opt_is_flag(opt) && opt->arg_def.s.default_value;
}

char const *opt_get_default(struct argl_option const *opt)
{
    if (opt_is_flag(opt)) return "false";
    return opt->arg_def.s.default_value;
}

bool opt_is_flag(struct argl_option const *opt)
{
    return opt->arg_def.type == ARGL_FLAG_TYPE;
}

char const *opt_arg_name(struct argl_option const *opt)
{
    return opt->arg_def.s.name;
}
/* meld-cut-here */
