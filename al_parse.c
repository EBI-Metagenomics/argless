#include "al_parse.h"
#include "al_argvec.h"
#include "al_basename.h"
#include "al_help.h"

void al_parse(int argc, char *argv[], int nopts, struct al_opt const *opts)
{
    if (!argvec_check_valid(argc, argv, nopts, opts, true)) return;
    argvec_sort(argc, argv, nopts, opts);
    if (argvec_has(argc, argv, nopts, opts, "usage"))
        help_usage(al_basename(argv[0]), nopts, opts, true);
}
