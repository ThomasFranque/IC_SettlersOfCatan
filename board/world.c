#include "world.h"
#include <stdlib.h>

WORLD *world_new(unsigned int xdim, unsigned int ydim) {

    WORLD *wrld = NULL;
    wrld = malloc(sizeof(WORLD));
    wrld->grid = calloc(xdim * ydim, sizeof(AGENT));
    wrld->xdim = xdim;
    wrld->ydim = ydim;
    return wrld;
}

void world_destroy(WORLD *wrld) {
    free(wrld->grid);
    free(wrld);
}

void world_put(WORLD *wrld, unsigned int x, unsigned int y, AGENT ag) {

    wrld->grid[y * wrld->xdim + x] = ag;

}

AGENT world_get(WORLD *wrld, unsigned int x, unsigned int y) {

    return wrld->grid[y * wrld->xdim + x];
}

