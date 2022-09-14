#include "argl_arg.h"
#include "test_utils.h"

int main(void)
{
    ASSERT(!arg_is_opt("-"));
    ASSERT(!arg_is_opt("--"));

    ASSERT(arg_is_opt("-o"));
    ASSERT(arg_is_opt("-ooutput.txt"));
    ASSERT(arg_is_opt("--output"));
    ASSERT(arg_is_opt("--output=output.txt"));

    ASSERT(arg_is_key_opt("-o"));
    ASSERT(arg_is_key_opt("-ooutput.txt"));
    ASSERT(!arg_is_key_opt_compact("-o"));
    ASSERT(arg_is_key_opt_compact("-ooutput.txt"));

    ASSERT(arg_is_name_opt("--output"));
    ASSERT(arg_is_name_opt("--output=output.txt"));
    ASSERT(!arg_is_name_opt_compact("--output"));
    ASSERT(arg_is_name_opt_compact("--output=output.txt"));

    ASSERT(arg_key_opt_eq("-o", 'o'));
    ASSERT(!arg_key_opt_eq("-u", 'o'));

    ASSERT(arg_key_opt_eq("-ooutput.txt", 'o'));
    ASSERT(!arg_key_opt_eq("-uoutput.txt", 'o'));

    ASSERT(arg_name_opt_eq("--output", "output"));
    ASSERT(!arg_name_opt_eq("--output", "outpuu"));

    ASSERT(arg_name_opt_eq("--output=output.txt", "output"));
    ASSERT(!arg_name_opt_eq("--outpuu=output.txt", "output"));

    return 0;
}
