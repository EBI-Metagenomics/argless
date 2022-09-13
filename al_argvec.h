#ifndef AL_ARGVEC_H
#define AL_ARGVEC_H

#include <stdbool.h>

struct al_opt;

bool argvec_check_valid(int argc, char *argv[], int nopts,
                        struct al_opt const *opts, bool die);
void argvec_sort(int argc, char *argv[], int nopts, struct al_opt const *opts);
bool argvec_has(int argc, char *argv[], int nopts, struct al_opt const *opts,
                char const *long_name);

#endif
