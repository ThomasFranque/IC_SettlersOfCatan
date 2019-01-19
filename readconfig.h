#include <stdio.h>
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
	UNIT *grid; /**Isto innicializa um apontador que contem UNITS*/
	unsigned int xdim;
	unsigned int ydim;
} MAP_CONFIG;


/**DECLARACAO DAS FUNCOES EM READCONFIG.C*/
void set_config_val(MAP_CONFIG *config, const char *key, int val);
void set_unit_val(UNIT *map_unit, char *key, char *val);
void read_config(MAP_CONFIG *config, FILE *f);

#endif
