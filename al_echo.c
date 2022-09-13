#include "al_echo.h"
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

#define NCOL 80

static char buf[NCOL + 1] = {0};
static size_t pos = 0;
static int width = 0;

static void echo_empty_spaces(int n);
static void restart(void);
static void vecho(const char *fmt, va_list va);

void echo_start(int indent_width)
{
    width = indent_width;
    pos = 0;
    buf[0] = '\0';
}

void echof(char const *fmt, ...)
{
    va_list va;
    va_start(va, fmt);
    size_t r = vsnprintf(buf + pos, sizeof(buf) - pos, fmt, va);
    va_end(va);

    if (pos + r < sizeof buf)
    {
        pos += r;
        return;
    }

    buf[pos] = '\0';
    restart();

    echo_empty_spaces(width);
    va_start(va, fmt);
    vecho(fmt, va);
    va_end(va);
}

void echos(char const *str) { echof("%s", str); }

void echoc(char c) { echof("%c", c); }

void echo_end(void)
{
    if (pos > 0) puts(buf);
}

static void echo_empty_spaces(int n)
{
    while (n-- > 0)
        echof("%c", ' ');
}

static void restart(void)
{
    if (pos > 0) puts(buf);
    pos = 0;
    buf[0] = '\0';
}

static void vecho(const char *fmt, va_list va)
{
    pos += vsnprintf(buf + pos, sizeof(buf) - pos, fmt, va);
}
