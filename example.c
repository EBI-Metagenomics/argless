#include "al_opt.h"
#include "al_parse.h"

static struct al_opt const opts[] = {
    {"output", 'o', "OUTPUT", "Output file", false},
    {"fast", 'f', 0, "Enable fast processing", true},
    {"threshold", 't', "THRESHOLD", "Threshold on e-value", false},
    {"nthreads", 'n', "NTHREADS", "Set the number of threads", false},
    AL_DEFAULT_OPTS,
};

int main(int argc, char *argv[])
{
    al_parse(argc, argv, opt_count(opts), opts);
    return 0;
}
