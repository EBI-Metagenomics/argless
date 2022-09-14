#ifndef ARGL_OS_H
#define ARGL_OS_H

/* meld-cut-proto */
enum
{
    ARGL_WINDOWS,
    ARGL_UNIX,
    ARGL_MACOS,
};

#if defined(_WIN16) || defined(_WIN32) || defined(_WIN64) || defined(__WIN32__)
#define ARGL_OS ZS_WINDOWS
#elif defined(__unix__) || defined(__unix)
#define ARGL_OS ZS_UNIX
#elif defined(__APPLE__)
#define ARGL_OS ARGL_MACOS
#endif

#ifdef MS_WINDOWS
#define ARGL_PATH_SEP '\\'
#endif

#ifndef ARGL_PATH_SEP
#define ARGL_PATH_SEP '/'
#endif
/* meld-cut-proto */

#endif
