#ifndef AL_OPT_H
#define AL_OPT_H

#include <stdbool.h>

/* meld-cut-here */
struct al_opt
{
    char const *long_name;
    char const short_name;
    char const *arg_name;
    char const *arg_doc;
    bool is_flag;
};

#define AL_HELP_SHORT_NAME '?'
#define AL_USAGE_SHORT_NAME -1
#define AL_VERSION_SHORT_NAME 'V'

#define AL_HELP_OPT                                                            \
    {                                                                          \
        "help", AL_HELP_SHORT_NAME, 0, "Give this help list", true             \
    }
#define AL_USAGE_OPT                                                           \
    {                                                                          \
        "usage", AL_USAGE_SHORT_NAME, 0, "Give a short usage message", true    \
    }

#define AL_VERSION_OPT                                                         \
    {                                                                          \
        "version", AL_VERSION_SHORT_NAME, 0, "Print program version", true     \
    }

#define AL_NULL_OPT                                                            \
    {                                                                          \
        0, 0, 0, 0, 0                                                          \
    }

#define AL_DEFAULT_OPTS AL_HELP_OPT, AL_USAGE_OPT, AL_VERSION_OPT
/* meld-cut-here */

/* meld-cut-proto */
struct al_opt const *opt_get(struct al_opt const *opts, char const *arg);
int opt_count(struct al_opt const *opts);
/* meld-cut-proto */

#endif
