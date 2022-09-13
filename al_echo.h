#ifndef AL_ECHO_H
#define AL_ECHO_H

void echo_start(int indent_width);
void echof(char const *fmt, ...);
void echos(char const *str);
void echoc(char c);
void echor(char const *str);
void echo_flush(void);
void echo_end(void);

#endif
