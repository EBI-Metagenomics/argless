#include "al_parse.h"
#include "al_argvec.h"
#include "al_basename.h"
#include "al_help.h"

void al_parse(int argc, char *argv[], int nopts, struct al_opt const *opts)
{
    if (!argvec_check_valid(argc, argv, nopts, opts, true)) return;
    argvec_sort(argc, argv, nopts, opts);

    char const *progname = al_basename(argv[0]);
    if (argvec_has(argc, argv, nopts, opts, "usage"))
        help_usage(progname, nopts, opts, true);

    if (argvec_has(argc, argv, nopts, opts, "help"))
        help_help(progname, nopts, opts, true);
}
