#include "argl_option.h"
#include "test_utils.h"

static struct argl_option const options[] = {
    {"output", 'o', "OUTPUT", "Output doc", false}, ARGL_NULL_OPT};

int main(void)
{
    ASSERT(opt_get(options, "--output"));
    ASSERT(opt_get(options, "--output=output.txt"));
    ASSERT(opt_get(options, "-o"));
    ASSERT(opt_get(options, "-ooutput.txt"));

    ASSERT(!opt_get(options, "--outpuu"));
    ASSERT(!opt_get(options, "--outpuu=output.txt"));
    ASSERT(!opt_get(options, "-u"));
    ASSERT(!opt_get(options, "-uoutput.txt"));
    return 0;
}
