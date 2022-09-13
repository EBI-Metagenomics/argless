#include "al.h"
#include "al_argvec.h"
#include "al_basename.h"
#include "al_help.h"

void al_parse(struct al *al, int argc, char *argv[])
{
    al->argc = argc;
    al->argv = argv;
    if (!argvec_check_valid(argc, argv, al->options, true)) return;
    argvec_sort(argc, argv, al->options);

    char const *progname = al_basename(argv[0]);

    if (argvec_has(argc, argv, al->options, "usage"))
        help_usage(progname, al->options, true);

    if (argvec_has(argc, argv, al->options, "help"))
        help_help(progname, al->options, true);
}

bool al_has(struct al const *al, char const *long_name)
{
    return argvec_has(al->argc, al->argv, al->options, long_name);
}

char const *al_get(struct al const *al, char const *long_name)
{
    return argvec_get(al->argc, al->argv, al->options, long_name);
}
