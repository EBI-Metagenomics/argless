#include "al_argvec.h"
#include "al_opt.h"
#include "test_utils.h"

static struct al_opt const opts[] = {
    {"output", 'o', "OUTPUT", "Output doc", false},
};

int main(void)
{
    static char *c0[] = {"prg", "ARG1", "--output", "output.txt"};
    static char *c1[] = {"prg", "ARG1", "--output=output.txt"};
    static char *c2[] = {"prg", "ARG1", "-o", "output.txt"};
    static char *c3[] = {"prg", "ARG1", "-ooutput.txt"};
    static char *c4[] = {"prg", "ARG1"};

    ASSERT(argvec_check_integrity(countof(c0), c0, opt_count(opts), opts));
    ASSERT(argvec_check_integrity(countof(c1), c1, opt_count(opts), opts));
    ASSERT(argvec_check_integrity(countof(c2), c2, opt_count(opts), opts));
    ASSERT(argvec_check_integrity(countof(c3), c3, opt_count(opts), opts));
    ASSERT(argvec_check_integrity(countof(c4), c4, opt_count(opts), opts));

    static char *w0[] = {"prg", "ARG1", "--output"};
    static char *w1[] = {"prg", "ARG1", "--outpuu=output.txt"};
    static char *w2[] = {"prg", "ARG1", "-o"};
    static char *w3[] = {"prg", "ARG1", "-uoutput.txt"};

    ASSERT(!argvec_check_integrity(countof(w0), w0, opt_count(opts), opts));
    ASSERT(!argvec_check_integrity(countof(w1), w1, opt_count(opts), opts));
    ASSERT(!argvec_check_integrity(countof(w2), w2, opt_count(opts), opts));
    ASSERT(!argvec_check_integrity(countof(w3), w3, opt_count(opts), opts));
    return 0;
}
