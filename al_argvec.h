#ifndef AL_ARGVEC_H
#define AL_ARGVEC_H

/* meld-cut-here */
#include <stdbool.h>

struct al_opt;

bool argvec_check_valid(int argc, char *argv[],
                               struct al_opt const *opts, bool die);
void argvec_sort(int argc, char *argv[], struct al_opt const *opts);
bool argvec_has(int argc, char *argv[], struct al_opt const *opts,
                       char const *long_name);
char const *argvec_get(int argc, char *argv[], struct al_opt const *opts,
                              char const *long_name);
int argvec_nargs(int argc, char *argv[], struct al_opt const *opts);
char **argvec_args(int argc, char *argv[], struct al_opt const *opts);
/* meld-cut-here */

#endif
