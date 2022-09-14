#include "argl_os.h"
/* meld-cut-here */
#include <string.h>

char const *al_basename(char const *path)
{
    char *p = strrchr(path, ARGL_PATH_SEP);
    return p ? p + 1 : path;
}
/* meld-cut-here */
