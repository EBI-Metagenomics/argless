#ifndef ARGL_OPTION_H
#define ARGL_OPTION_H

#include <stdbool.h>

/* meld-cut-here */
struct argl_option
{
    char const *long_name;
    char const short_name;
    char const *arg_name;
    char const *arg_doc;
    bool is_flag;
};

#define ARGL_HELP_SHORT_NAME '?'
#define ARGL_USAGE_SHORT_NAME -1
#define ARGL_VERSION_SHORT_NAME 'V'

#define ARGL_HELP_OPT                                                          \
    {                                                                          \
        "help", ARGL_HELP_SHORT_NAME, 0, "Give this help list", true           \
    }
#define ARGL_USAGE_OPT                                                         \
    {                                                                          \
        "usage", ARGL_USAGE_SHORT_NAME, 0, "Give a short usage message", true  \
    }

#define ARGL_VERSION_OPT                                                       \
    {                                                                          \
        "version", ARGL_VERSION_SHORT_NAME, 0, "Print program version", true   \
    }

#define ARGL_NULL_OPT                                                          \
    {                                                                          \
        0, 0, 0, 0, 0                                                          \
    }

#define ARGL_DEFAULT_OPTS ARGL_HELP_OPT, ARGL_USAGE_OPT, ARGL_VERSION_OPT
/* meld-cut-here */

/* meld-cut-proto */
struct argl_option const *opt_get(struct argl_option const *opts,
                                  char const *arg);
int opt_count(struct argl_option const *opts);
/* meld-cut-proto */

#endif
