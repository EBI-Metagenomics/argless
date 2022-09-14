#include "argl_arg.h"
/* meld-cut-here */
#include <stddef.h>
#include <string.h>

static size_t arg_long_compact_opt_size(char const *arg);

bool arg_is_opt(char const *arg)
{
    return arg_is_key_opt(arg) || arg_is_name_opt(arg);
}

bool arg_is_opt_compact(char const *arg)
{
    return arg_is_key_opt(arg) ? arg_is_key_opt_compact(arg)
                               : arg_is_name_opt_compact(arg);
}

bool arg_is_key_opt(char const *arg)
{
    return strlen(arg) > 1 && arg[0] == '-' && arg[1] != '-';
}

bool arg_is_key_opt_compact(char const *arg)
{
    return strlen(arg) > 2 && arg[0] == '-' && arg[1] != '-';
}

bool arg_is_name_opt(char const *arg)
{
    return strlen(arg) > 2 && arg[0] == '-' && arg[1] == '-';
}

bool arg_is_name_opt_compact(char const *arg) { return strchr(arg, '='); }

char const *arg_opt_compact_value(char const *arg)
{
    return arg_is_name_opt_compact(arg) ? strchr(arg, '=') + 1 : arg + 2;
}

bool arg_key_opt_eq(char const *arg, char key) { return arg[1] == key; }

bool arg_name_opt_eq(char const *arg, char const *name)
{
    size_t size = 0;
    if (arg_is_name_opt_compact(arg))
        size = arg_long_compact_opt_size(arg);
    else
        size = strlen(arg + 2);

    return size == strlen(name) && !strncmp(arg + 2, name, size);
}

static size_t arg_long_compact_opt_size(char const *arg)
{
    char const *p = strchr(arg, '=');
    return p - &arg[2];
}
/* meld-cut-here */
