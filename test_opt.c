#include "al_opt.h"
#include "test_utils.h"

static struct al_opt const options[] = {
    {"output", 'o', "OUTPUT", "Output doc", false},
};

int main(void)
{
    ASSERT(opt_get(opt_count(options), options, "--output"));
    ASSERT(opt_get(opt_count(options), options, "--output=output.txt"));
    ASSERT(opt_get(opt_count(options), options, "-o"));
    ASSERT(opt_get(opt_count(options), options, "-ooutput.txt"));

    ASSERT(!opt_get(opt_count(options), options, "--outpuu"));
    ASSERT(!opt_get(opt_count(options), options, "--outpuu=output.txt"));
    ASSERT(!opt_get(opt_count(options), options, "-u"));
    ASSERT(!opt_get(opt_count(options), options, "-uoutput.txt"));
    return 0;
}
