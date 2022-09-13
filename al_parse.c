#include "al_parse.h"
#include "al_argvec.h"

void al_parse(int argc, char *argv[], int nopts, struct al_opt const *opts)
{
    if (!argvec_check_valid(argc, argv, nopts, opts, true)) return;
}
