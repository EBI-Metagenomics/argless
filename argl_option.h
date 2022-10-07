#ifndef ARGL_OPTION_H
#define ARGL_OPTION_H

#include <stdbool.h>
#include <stddef.h>

/* meld-cut-here */
struct argl_text
{
    char const *name;
    char const *default_value;
};

struct argl_flag
{
    int : 0;
};

struct argl_def
{
    int type;
    union
    {
        struct argl_text s;
        struct argl_flag b;
    };
};

enum
{
    ARGL_TEXT_TYPE = 0,
    ARGL_FLAG_TYPE = 1,
};

#define ARGL_TEXT(NAME, DEFAULT)                                               \
    (struct argl_def)                                                          \
    {                                                                          \
        ARGL_TEXT_TYPE,                                                        \
        {                                                                      \
            .s = { NAME, DEFAULT }                                             \
        }                                                                      \
    }
#define ARGL_FLAG()                                                            \
    (struct argl_def)                                                          \
    {                                                                          \
        ARGL_FLAG_TYPE,                                                        \
        {                                                                      \
            {                                                                  \
                0                                                              \
            }                                                                  \
        }                                                                      \
    }

struct argl_option
{
    char const *name;
    char const key;
    struct argl_def arg_def;
    char const *arg_doc;
};

#define ARGL_NULL ((void *)0)

#define ARGL_HELP_KEY '?'
#define ARGL_USAGE_KEY -1
#define ARGL_VERSION_KEY 'V'

#define ARGL_HELP_OPT                                                          \
    {                                                                          \
        "help", ARGL_HELP_KEY, ARGL_FLAG(), "Give this help list"              \
    }
#define ARGL_USAGE_OPT                                                         \
    {                                                                          \
        "usage", ARGL_USAGE_KEY, ARGL_FLAG(), "Give a short usage message"     \
    }

#define ARGL_VERSION_OPT                                                       \
    {                                                                          \
        "version", ARGL_VERSION_KEY, ARGL_FLAG(), "Print program version"      \
    }

#define ARGL_END                                                               \
    {                                                                          \
        0                                                                      \
    }

#define ARGL_DEFAULT ARGL_HELP_OPT, ARGL_USAGE_OPT, ARGL_VERSION_OPT
/* meld-cut-here */

/* meld-cut-proto */
struct argl_option const *opts_search(struct argl_option const *opts,
                                      char const *arg);
struct argl_option const *opts_get(struct argl_option const *opts,
                                   char const *name);
int opts_count(struct argl_option const *opts);
bool opt_has_user_default(struct argl_option const *opt);
char const *opt_get_default(struct argl_option const *opt);
bool opt_is_flag(struct argl_option const *opt);
char const *opt_arg_name(struct argl_option const *opt);
/* meld-cut-proto */

#endif
