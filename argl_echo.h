#ifndef ARGL_ECHO_H
#define ARGL_ECHO_H

/* meld-cut-proto */
void echo_start(int indent_width);
void echof(char const *fmt, ...);
void echos(char const *str);
void echoc(char c);
void echor(char const *str);
void echo_flush(void);
void echo_end(void);
/* meld-cut-proto */

#endif
