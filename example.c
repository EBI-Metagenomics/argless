#include "al_opt.h"
#include "al_parse.h"

static struct al_opt const opts[] = {
    {"output", 'o', "OUTPUT", "Output doc", false},
    AL_HELP_OPT,
    AL_USAGE_OPT,
};

int main(int argc, char *argv[])
{
    al_parse(argc, argv, opt_count(opts), opts);
    return 0;
}
