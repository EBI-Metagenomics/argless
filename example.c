#include "argless.h"

static struct argl_option const options[] = {
    {"output", 'o', "OUTPUT", "Output file", false},
    {"fast", 'f', 0, "Enable fast processing", true},
    {"threshold", 't', "THRESHOLD", "Threshold on e-value", false},
    {"nthreads", 'n', "NTHREADS", "Set the number of threads", false},
    ARGL_DEFAULT_OPTS,
    ARGL_NULL_OPT,
};

static struct argl al = {
    .options = options,
    .args_doc = "ARG1 ARG2",
    .doc = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do "
           "eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut "
           "enim ad minim veniam, quis nostrud exercitation ullamco laboris "
           "nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor "
           "in reprehenderit in voluptate velit esse cillum dolore eu fugiat "
           "nulla pariatur. Excepteur sint occaecat cupidatat non proident, "
           "sunt in culpa qui officia deserunt mollit anim id est laborum.",
    .version = "1.0.0"};

int main(int argc, char *argv[])
{
    argl_parse(&al, argc, argv);
    return 0;
}
