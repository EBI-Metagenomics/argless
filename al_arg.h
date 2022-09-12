#ifndef AL_ARG_H
#define AL_ARG_H

#include <stdbool.h>

bool arg_is_opt(char const *arg);
bool arg_is_short_opt(char const *arg);
bool arg_is_short_opt_compressed(char const *arg);
bool arg_is_long_opt(char const *arg);
bool arg_is_long_opt_compressed(char const *arg);
char const *arg_opt_compressed_value(char const *arg);
bool arg_long_opt_eq(char const *arg, char const *long_name);

#endif
