#ifndef AL_OS_H
#define AL_OS_H

/* meld-cut-proto */
enum
{
    AL_WINDOWS,
    AL_UNIX,
    AL_MACOS,
};

#if defined(_WIN16) || defined(_WIN32) || defined(_WIN64) || defined(__WIN32__)
#define AL_OS ZS_WINDOWS
#elif defined(__unix__) || defined(__unix)
#define AL_OS ZS_UNIX
#elif defined(__APPLE__)
#define AL_OS AL_MACOS
#endif

#ifdef MS_WINDOWS
#define AL_PATH_SEP '\\'
#endif

#ifndef AL_PATH_SEP
#define AL_PATH_SEP '/'
#endif
/* meld-cut-proto */

#endif
