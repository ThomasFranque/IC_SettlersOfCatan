#include <stdio.h>

#pragma once
#ifndef READCONFIG_H_INCLUDED
#define READCONFIG_H_INCLUDED
#define MAX 128

typedef struct { 
/**Estrutura da unidade do mapa, primeira posicao de cada array é uma letra, o resto um numero*/
	char N[4];
	char S[4];
	char W[4];
	char E[4];
	char Building;
}UNIT;

typedef struct{
	UNIT *grid;
	unsigned int xdim;
	unsigned int ydim;
} MAP_CONFIG;



void set_config_val(CONFIG *config, UNIT *map_unit const char *key, int val);
void set_unit_val(UNIT *map_unit, char *key, int val);
void read_config(CONFIG *config,UNIT *map_unit, FILE *f);

#endif
