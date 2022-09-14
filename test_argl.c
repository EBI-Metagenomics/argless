#include "argl.h"
#include "argl_option.h"
#include "test_utils.h"
#include <string.h>

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

static void test1(void);
static void test2(void);

int main(void)
{
    test1();
    test2();
    return 0;
}

static void test1(void)
{
    static char *argv[] = {"prg",  "ARG1", "--output", "output.txt",
                           "ARG2", "-f",   "-t1.2"};
    argl_parse(&al, countof(argv), argv);
    ASSERT(argl_has(&al, "output"));
    ASSERT(argl_has(&al, "fast"));
    ASSERT(!argl_has(&al, " output"));
    ASSERT(!argl_has(&al, "f"));
    ASSERT(!argl_has(&al, "nthreads"));

    ASSERT(!strcmp(argl_get(&al, "output"), "output.txt"));
    ASSERT(!strcmp(argl_get(&al, "threshold"), "1.2"));

    ASSERT(argl_nargs(&al) == 2);
    char **v = argl_args(&al);
    ASSERT(!strcmp(v[0], "ARG1"));
    ASSERT(!strcmp(v[1], "ARG2"));
}

static void test2(void)
{
    static char *argv[] = {"prg", "ARG1", "--output=output.txt",
                           "-f",  "-t",   "1.2"};
    argl_parse(&al, countof(argv), argv);
    ASSERT(argl_has(&al, "output"));
    ASSERT(argl_has(&al, "fast"));
    ASSERT(!argl_has(&al, " output"));
    ASSERT(!argl_has(&al, "f"));
    ASSERT(!argl_has(&al, "nthreads"));

    ASSERT(!strcmp(argl_get(&al, "output"), "output.txt"));
    ASSERT(!strcmp(argl_get(&al, "threshold"), "1.2"));

    ASSERT(argl_nargs(&al) == 1);
    char **v = argl_args(&al);
    ASSERT(!strcmp(v[0], "ARG1"));
}
