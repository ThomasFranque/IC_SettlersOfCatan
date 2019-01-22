#ifndef GAMELOGIC_H_INCLUDED
#define GAMELOGIC_H_INCLUDED
#include "configmap.h"
void play (MAP_CONFIG map, UNIT *grid, int *materiais);
void bank (int *playerMaterials, int * points);
void inventory (int *playerMaterials);
int adjacente(MAP_CONFIG map, UNIT *grid,int casa);
void adjacente_number(MAP_CONFIG map, UNIT *grid, UNIT *grid_adjacentes);
void buy(MAP_CONFIG map, UNIT *grid, int *playerMaterials);
#endif
