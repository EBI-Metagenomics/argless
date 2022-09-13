#ifndef AL_PARSE_H
#define AL_PARSE_H

struct al_opt;

void al_parse(int argc, char *argv[], int nopts, struct al_opt const *opts);

#endif
