#ifndef ARGD_HELP_H
#define ARGD_HELP_H

#include <stdbool.h>

struct argd;

// void argd_help(struct argd const *);
// void argd_help_try(struct argd const *);
// void argd_help_usage(struct argd const *);
void help_requires_arg(char const *program_name, char const *arg, bool die);
void help_unrecognized_arg(char const *program_name, char const *arg, bool die);
// void argd_help_requires(struct argd const *, char const *opt);

#endif
