#include "argl.h"
#include "argl_option.h"
#include "test_utils.h"
#include <string.h>

static struct argl_option const options[] = {
    {"output", 'o', ARGL_TEXT("OUTPUT", ARGL_NULL), "Output file"},
    {"fast", 'f', ARGL_FLAG(), "Enable fast processing"},
    {"threshold", 't', ARGL_TEXT("THRESHOLD", ARGL_NULL),
     "Threshold on e-value"},
    {"nthreads", 'n', ARGL_TEXT("NTHREADS", "1"), "Set the number of threads"},
    ARGL_DEFAULT,
    ARGL_END,
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
static void test3(void);

int main(void)
{
    test1();
    test2();
    test3();
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
    ASSERT(!strcmp(argl_get(&al, "nthreads"), "1"));

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

static void test3(void)
{
    static char *argv[] = {"prg", "ARG1", "--", "--output=output.txt",
                           "-f",  "-t",   "1.2"};
    argl_parse(&al, countof(argv), argv);
    ASSERT(!argl_has(&al, "output"));
    ASSERT(!argl_has(&al, "fast"));
    ASSERT(!argl_has(&al, " output"));
    ASSERT(!argl_has(&al, "f"));
    ASSERT(!argl_has(&al, "nthreads"));

    ASSERT(argl_nargs(&al) == 6);
    char **v = argl_args(&al);
    ASSERT(!strcmp(v[0], "ARG1"));
    ASSERT(!strcmp(v[1], "--"));
    ASSERT(!strcmp(v[2], "--output=output.txt"));
    ASSERT(!strcmp(v[3], "-f"));
    ASSERT(!strcmp(v[4], "-t"));
    ASSERT(!strcmp(v[5], "1.2"));
}
