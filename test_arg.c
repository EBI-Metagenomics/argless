#include "al_arg.h"
#include "test_utils.h"

int main(void)
{
    ASSERT(!arg_is_opt("-"));
    ASSERT(!arg_is_opt("--"));

    ASSERT(arg_is_opt("-o"));
    ASSERT(arg_is_opt("-ooutput.txt"));
    ASSERT(arg_is_opt("--output"));
    ASSERT(arg_is_opt("--output=output.txt"));

    ASSERT(arg_is_short_opt("-o"));
    ASSERT(arg_is_short_opt("-ooutput.txt"));
    ASSERT(!arg_is_short_opt_compressed("-o"));
    ASSERT(arg_is_short_opt_compressed("-ooutput.txt"));

    ASSERT(arg_is_long_opt("--output"));
    ASSERT(arg_is_long_opt("--output=output.txt"));
    ASSERT(!arg_is_long_opt_compressed("--output"));
    ASSERT(arg_is_long_opt_compressed("--output=output.txt"));
    return 0;
}
