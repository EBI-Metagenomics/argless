#include "argl_option.h"
#include "test_utils.h"

static struct argl_option const options[] = {
    {"input", 'i', ARGL_TEXT("INPUT", ARGL_NULL), "Input doc"},
    {"output", 'o', ARGL_TEXT("OUTPUT", "/dev/null"), "Output doc"},
    {"fast", 'f', ARGL_FLAG(), "Fast doc"},
    {"verbose", 'v', ARGL_FLAG(), "Verbose doc"},
    ARGL_END};

int main(void)
{
    ASSERT(opts_search(options, "--output"));
    ASSERT(opts_search(options, "--output=output.txt"));
    ASSERT(opts_search(options, "-o"));
    ASSERT(opts_search(options, "-ooutput.txt"));

    ASSERT(!opts_search(options, "--outpuu"));
    ASSERT(!opts_search(options, "--outpuu=output.txt"));
    ASSERT(!opts_search(options, "-u"));
    ASSERT(!opts_search(options, "-uoutput.txt"));
    return 0;
}
