#ifndef ARGL_HELP_H
#define ARGL_HELP_H

#include <stdbool.h>

struct argl_option;

/* meld-cut-proto */
void help_usage(char const *progname, struct argl_option const *opts, bool die);
void help_help(char const *progname, char const *doc,
               struct argl_option const *opts, bool die);
void help_version(char const *prog, char const *version, bool die);
void help_requires_arg(char const *progname, char const *arg, bool die);
void help_unrecognized_arg(char const *progname, char const *arg, bool die);
/* meld-cut-proto */

#endif
