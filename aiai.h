#ifndef AIAI_H_INCLUDED
#define AIAI_H_INCLUDED
#include "configmap.h"
int adjacenteAI(MAP_CONFIG map, UNIT grid, int casa);
void delay(int number_of_seconds);
int random(int x);
int buyAI(MAP_CONFIG map, UNIT *grid, int *playerMaterials);
int ai(int *aiMaterials, int aiPoints);
#endif
