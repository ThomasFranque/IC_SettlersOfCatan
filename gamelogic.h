#ifndef GAMELOGIC_H_INCLUDED
#define GAMELOGIC_H_INCLUDED
#include "configmap.h"
int play (MAP_CONFIG map, UNIT *grid);
int bank (int playerMaterials[]);
int inventory (int *playerMaterials);
int adjacente(MAP_CONFIG map, UNIT *grid,int casa);
void adjacente_number(MAP_CONFIG map, UNIT *grid, UNIT *grid_adjacentes);
int buy(MAP_CONFIG map, UNIT *grid, int *playerMaterials);
#endif
