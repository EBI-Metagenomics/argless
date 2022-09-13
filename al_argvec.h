#ifndef AL_ARGVEC_H
#define AL_ARGVEC_H

#include <stdbool.h>

struct al_opt;

bool argvec_check_integrity(int argc, char *argv[], int nopts,
                            struct al_opt const *opts);
void argvec_sort(int argc, char *argv[], int nopts, struct al_opt const *opts);

#endif
