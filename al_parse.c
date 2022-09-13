#include "al_parse.h"
#include "al_argvec.h"
#include "al_basename.h"
#include "al_help.h"

void al_parse(int argc, char *argv[], struct al_opt const *opts)
{
    if (!argvec_check_valid(argc, argv, opts, true)) return;
    argvec_sort(argc, argv, opts);

    char const *progname = al_basename(argv[0]);
    if (argvec_has(argc, argv, opts, "usage")) help_usage(progname, opts, true);

    if (argvec_has(argc, argv, opts, "help")) help_help(progname, opts, true);
}
