#ifndef ARGL_ARGVEC_H
#define ARGL_ARGVEC_H

#include <stdbool.h>

struct argl_option;

/* meld-cut-proto */
bool argvec_check_valid(int argc, char *argv[], struct argl_option const *opts,
                        bool die);
void argvec_sort(int argc, char *argv[], struct argl_option const *opts);
bool argvec_has(int argc, char *argv[], struct argl_option const *opts,
                char const *long_name);
char const *argvec_get(int argc, char *argv[], struct argl_option const *opts,
                       char const *long_name);
int argvec_nargs(int argc, char *argv[], struct argl_option const *opts);
char **argvec_args(int argc, char *argv[], struct argl_option const *opts);
/* meld-cut-proto */

#endif
