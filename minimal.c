#include "argless.h"

static struct argl_option const options[] = {
    ARGL_DEFAULT,
    ARGL_END,
};

static struct argl argl = {.options = options,
                           .args_doc = ARGL_NULL,
                           .doc = "Lorem ipsum dolor sit amet.",
                           .version = "1.0.0"};

int main(int argc, char *argv[])
{
    argl_parse(&argl, argc, argv);
    return 0;
}
