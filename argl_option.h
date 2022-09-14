#ifndef ARGL_OPTION_H
#define ARGL_OPTION_H

#include <stdbool.h>
#include <stddef.h>

/* meld-cut-here */
struct argl_option
{
    char const *name;
    char const key;
    char const *arg_name;
    char const *arg_doc;
    bool const is_flag;
};

#ifndef NULL
#define NULL ((void *)0)
#endif

#ifndef nullptr
#define nullptr NULL
#endif

#define ARGL_HELP_KEY '?'
#define ARGL_USAGE_KEY -1
#define ARGL_VERSION_KEY 'V'

#define ARGL_HELP_OPT                                                          \
    {                                                                          \
        "help", ARGL_HELP_KEY, nullptr, "Give this help list", true            \
    }
#define ARGL_USAGE_OPT                                                         \
    {                                                                          \
        "usage", ARGL_USAGE_KEY, nullptr, "Give a short usage message", true   \
    }

#define ARGL_VERSION_OPT                                                       \
    {                                                                          \
        "version", ARGL_VERSION_KEY, nullptr, "Print program version", true    \
    }

#define ARGL_NULL_OPT                                                          \
    {                                                                          \
        nullptr, '\0', nullptr, nullptr, false                                 \
    }

#define ARGL_DEFAULT_OPTS ARGL_HELP_OPT, ARGL_USAGE_OPT, ARGL_VERSION_OPT
/* meld-cut-here */

/* meld-cut-proto */
struct argl_option const *opt_get(struct argl_option const *opts,
                                  char const *arg);
int opt_count(struct argl_option const *opts);
/* meld-cut-proto */

#endif
