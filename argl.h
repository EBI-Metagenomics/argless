#ifndef ARGL_H
#define ARGL_H

/* meld-cut-here */
#include <stdbool.h>

struct argl_option;

struct al
{
    struct argl_option const *options;
    char const *args_doc;
    char const *doc;
    char const *version;

    int argc;
    char **argv;
};
/* meld-cut-here */

void al_parse(struct al *al, int argc, char *argv[]);
bool al_has(struct al const *al, char const *long_name);
char const *al_get(struct al const *al, char const *long_name);
int al_nargs(struct al const *al);
char **al_args(struct al const *al);

#endif
