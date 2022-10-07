#ifndef ARGL_H
#define ARGL_H

/* meld-cut-here */
#include <stdbool.h>

struct argl_option;

struct argl
{
    struct argl_option const *options;
    char const *args_doc;
    char const *doc;
    char const *version;

    int argc;
    char **argv;
};

void argl_parse(struct argl *, int argc, char *argv[]);
bool argl_has(struct argl const *, char const *name);
char const *argl_get(struct argl const *, char const *name);
int argl_nargs(struct argl const *);
char **argl_args(struct argl const *);
void argl_usage(struct argl const *);
void argl_usage2(struct argl const *, int exit_status);
char const *argl_program(struct argl const *);
/* meld-cut-here */

#endif
