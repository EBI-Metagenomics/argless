#ifndef AL_ARG_H
#define AL_ARG_H

#include <stdbool.h>

bool arg_is_opt(char const *arg);
bool arg_is_short_opt(char const *arg);
bool arg_is_short_opt_compact(char const *arg);
bool arg_is_long_opt(char const *arg);
bool arg_is_long_opt_compact(char const *arg);
char const *arg_opt_compact_value(char const *arg);
bool arg_short_opt_eq(char const *arg, char short_name);
bool arg_long_opt_eq(char const *arg, char const *long_name);

#endif
