#ifndef ARGL_HELP_H
#define ARGL_HELP_H

struct argl_option;

/* meld-cut-proto */
void help_usage(char const *progname, struct argl_option const *opts,
                int exit_status);
void help_help(char const *progname, char const *doc,
               struct argl_option const *opts, int exit_status);
void help_version(char const *prog, char const *version, int exit_status);
void help_requires_arg(char const *progname, char const *arg, int exit_status);
void help_unrecognized_arg(char const *progname, char const *arg,
                           int exit_status);
/* meld-cut-proto */

#endif
