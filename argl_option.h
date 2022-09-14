#ifndef ARGL_OPTION_H
#define ARGL_OPTION_H

#include <stdbool.h>

/* meld-cut-here */
struct argl_option
{
    char const *name;
    char const key;
    char const *arg_name;
    char const *arg_doc;
    bool is_flag;
};

#define ARGL_HELP_KEY '?'
#define ARGL_USAGE_KEY -1
#define ARGL_VERSION_KEY 'V'

#define ARGL_HELP_OPT                                                          \
    {                                                                          \
        "help", ARGL_HELP_KEY, 0, "Give this help list", true                  \
    }
#define ARGL_USAGE_OPT                                                         \
    {                                                                          \
        "usage", ARGL_USAGE_KEY, 0, "Give a short usage message", true         \
    }

#define ARGL_VERSION_OPT                                                       \
    {                                                                          \
        "version", ARGL_VERSION_KEY, 0, "Print program version", true          \
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
