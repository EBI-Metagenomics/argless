#include "al_arg.h"
#include <stddef.h>
#include <string.h>

static size_t arg_long_compact_opt_size(char const *arg);

bool arg_is_opt(char const *arg)
{
    return arg_is_short_opt(arg) || arg_is_long_opt(arg);
}

bool arg_is_opt_compact(char const *arg)
{
    return arg_is_short_opt(arg) ? arg_is_short_opt_compact(arg)
                                 : arg_is_long_opt_compact(arg);
}

bool arg_is_short_opt(char const *arg)
{
    return strlen(arg) > 1 && arg[0] == '-' && arg[1] != '-';
}

bool arg_is_short_opt_compact(char const *arg)
{
    return strlen(arg) > 2 && arg[0] == '-' && arg[1] != '-';
}

bool arg_is_long_opt(char const *arg)
{
    return strlen(arg) > 2 && arg[0] == '-' && arg[1] == '-';
}

bool arg_is_long_opt_compact(char const *arg) { return strchr(arg, '='); }

char const *arg_opt_compact_value(char const *arg)
{
    return strchr(arg, '=') + 1;
}

bool arg_short_opt_eq(char const *arg, char short_name)
{
    return arg[1] == short_name;
}

bool arg_long_opt_eq(char const *arg, char const *long_name)
{
    size_t size = 0;
    if (arg_is_long_opt_compact(arg))
        size = arg_long_compact_opt_size(arg);
    else
        size = strlen(arg + 2);

    return size == strlen(long_name) && !strncmp(arg + 2, long_name, size);
}

static size_t arg_long_compact_opt_size(char const *arg)
{
    char const *p = strchr(arg, '=');
    return p - &arg[2];
}
