#ifndef AL_H
#define AL_H

/* meld-cut-here */
#include <stdbool.h>

struct al_opt;

struct al
{
    struct al_opt const *options;
    char const *args_doc;
    char const *doc;
    char const *version;

    int argc;
    char **argv;
};

void al_parse(struct al *al, int argc, char *argv[]);
bool al_has(struct al const *al, char const *long_name);
char const *al_get(struct al const *al, char const *long_name);
int al_nargs(struct al const *al);
char **al_args(struct al const *al);
/* meld-cut-here */

#endif
