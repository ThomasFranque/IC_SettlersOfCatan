#ifndef WORLD_H
#define WORLD_H

#include "agent.h"

typedef struct {
    AGENT *grid;
    unsigned int xdim;
    unsigned int ydim;
} WORLD;

WORLD *world_new(unsigned int xdim, unsigned int ydim);
void world_destroy(WORLD *wrld);

void world_put(WORLD *wrld, unsigned int x, unsigned int y, AGENT ag);
AGENT world_get(WORLD *wrld, unsigned int x, unsigned int y);

#endif
