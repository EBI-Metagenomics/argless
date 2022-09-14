#include "argl.h"
#include "argl_argvec.h"
#include "argl_basename.h"
#include "argl_help.h"
#include <stdlib.h>

/* meld-cut-here */
void argl_parse(struct argl *al, int argc, char *argv[])
{
    al->argc = argc;
    al->argv = argv;
    if (!argvec_check_valid(argc, argv, al->options, true)) return;
    argvec_sort(argc, argv, al->options);

    char const *progname = al_basename(argv[0]);

    if (argvec_has(argc, argv, al->options, "usage"))
        help_usage(progname, al->options, EXIT_SUCCESS);

    if (argvec_has(argc, argv, al->options, "help"))
        help_help(progname, al->doc, al->options, EXIT_SUCCESS);

    if (argvec_has(argc, argv, al->options, "version"))
        help_version(progname, al->version, EXIT_SUCCESS);

    if (argc == 1) help_usage(progname, al->options, EXIT_FAILURE);
}

bool argl_has(struct argl const *al, char const *long_name)
{
    return argvec_has(al->argc, al->argv, al->options, long_name);
}

char const *argl_get(struct argl const *al, char const *long_name)
{
    return argvec_get(al->argc, al->argv, al->options, long_name);
}

int argl_nargs(struct argl const *al)
{
    return argvec_nargs(al->argc, al->argv, al->options);
}

char **argl_args(struct argl const *al)
{
    return argvec_args(al->argc, al->argv, al->options);
}
/* meld-cut-here */
