#ifndef AL_ECHO_H
#define AL_ECHO_H

void echo_start(int indent_width);
void echo(const char *fmt, ...);
void echo_end(void);

#endif
