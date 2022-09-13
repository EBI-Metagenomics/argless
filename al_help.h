#ifndef ARGD_HELP_H
#define ARGD_HELP_H

#include <stdbool.h>

struct al_opt;

void help_usage(char const *progname, int nopts, struct al_opt const *opts,
                bool die);
void help_requires_arg(char const *progname, char const *arg, bool die);
void help_unrecognized_arg(char const *progname, char const *arg, bool die);

#endif
