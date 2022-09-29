#include "argl_argvec.h"
#include "argl_option.h"
#include "test_utils.h"
#include <string.h>

static struct argl_option const opts[] = {
    {"output", 'o', ARGL_TEXT("OUTPUT", ARGL_NULL), "Output doc"},
    ARGL_END,
};

static void test_integrity(void);
static void test_sort(void);

int main(void)
{
    test_integrity();
    test_sort();
    return 0;
}

static void test_integrity(void)
{
    static char *c0[] = {"prg", "ARG1", "--output", "output.txt"};
    static char *c1[] = {"prg", "ARG1", "--output=output.txt"};
    static char *c2[] = {"prg", "ARG1", "-o", "output.txt"};
    static char *c3[] = {"prg", "ARG1", "-ooutput.txt"};
    static char *c4[] = {"prg", "ARG1"};

    ASSERT(argvec_check_valid(countof(c0), c0, opts, false));
    ASSERT(argvec_check_valid(countof(c1), c1, opts, false));
    ASSERT(argvec_check_valid(countof(c2), c2, opts, false));
    ASSERT(argvec_check_valid(countof(c3), c3, opts, false));
    ASSERT(argvec_check_valid(countof(c4), c4, opts, false));

    static char *w0[] = {"prg", "ARG1", "--output"};
    static char *w1[] = {"prg", "ARG1", "--outpuu=output.txt"};
    static char *w2[] = {"prg", "ARG1", "-o"};
    static char *w3[] = {"prg", "ARG1", "-uoutput.txt"};

    ASSERT(!argvec_check_valid(countof(w0), w0, opts, false));
    ASSERT(!argvec_check_valid(countof(w1), w1, opts, false));
    ASSERT(!argvec_check_valid(countof(w2), w2, opts, false));
    ASSERT(!argvec_check_valid(countof(w3), w3, opts, false));
}

static bool eqvec(int n, char *a[], char *b[]);

static void test_sort(void)
{
    static char *a0[] = {"prg", "ARG1", "--output", "output.txt"};
    static char *desired0[] = {"prg", "--output", "output.txt", "ARG1"};

    static char *a1[] = {"prg", "--output", "output.txt"};
    static char *desired1[] = {"prg", "--output", "output.txt"};

    static char *a2[] = {"prg"};
    static char *desired2[] = {"prg"};

    static char *a3[] = {"prg", "ARG1", "-ooutput.txt", "ARG2"};
    static char *desired3[] = {"prg", "-ooutput.txt", "ARG1", "ARG2"};

    static char *a4[] = {"prg", "ARG1", "-o", "output.txt", "ARG2"};
    static char *desired4[] = {"prg", "-o", "output.txt", "ARG1", "ARG2"};

    argvec_sort(countof(a0), a0, opts);
    ASSERT(eqvec(countof(a0), a0, desired0));

    argvec_sort(countof(a1), a1, opts);
    ASSERT(eqvec(countof(a1), a1, desired1));

    argvec_sort(countof(a2), a2, opts);
    ASSERT(eqvec(countof(a2), a2, desired2));

    argvec_sort(countof(a3), a3, opts);
    ASSERT(eqvec(countof(a3), a3, desired3));

    argvec_sort(countof(a4), a4, opts);
    ASSERT(eqvec(countof(a4), a4, desired4));
}

static bool eqvec(int n, char *a[], char *b[])
{
    bool equal = true;
    for (int i = 0; i < n; ++i)
    {
        equal = equal && !strcmp(a[i], b[i]);
    }
    return equal;
}
