#ifndef ARGL_ARG_H
#define ARGL_ARG_H

#include <stdbool.h>

/* meld-cut-proto */
bool arg_is_opt(char const *arg);
bool arg_is_opt_compact(char const *arg);
bool arg_is_key_opt(char const *arg);
bool arg_is_key_opt_compact(char const *arg);
bool arg_is_name_opt(char const *arg);
bool arg_is_name_opt_compact(char const *arg);
char const *arg_opt_compact_value(char const *arg);
bool arg_key_opt_eq(char const *arg, char key);
bool arg_name_opt_eq(char const *arg, char const *name);
/* meld-cut-proto */

#endif
