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

void argl_parse(struct argl *al, int argc, char *argv[]);
bool argl_has(struct argl const *al, char const *long_name);
char const *argl_get(struct argl const *al, char const *long_name);
int argl_nargs(struct argl const *al);
char **argl_args(struct argl const *al);
void argl_usage(struct argl const *al);
/* meld-cut-here */

#endif
