#include "readconfig.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void set_config_val(MAP_CONFIG *config, const char *key, int val) {
	/**
	Esta funcao atribui a uma estrutura CONFIG o valor x e y do board
	@param config = estrutura tipo MAP_CONFIG para xdim e ydim
	@param Key = palavra chave do que se le da INI
	@param val = valor que se vai atribuir a chave correspondente na estrutura
	*/
	if (config == NULL)
		return;
	if (strcmp(key, "xdim") == 0)
		config->xdim = val;
	else if (strcmp(key, "ydim") == 0)
		config->ydim = val;
	else{
		;
	}
}

void set_unit_val(UNIT *map_unit, const char *key, char *val){
	/**
	Esta funcao faz o mesmo que a set_config_val mas serve para cada unidade do mapa
	@param map_unit = Uma estrutura tipo UNIT para guardar os valores das 4 direcoes a volta lidas da INI
	@param Key = palavra chave do que se le da INI
	@param val = valor que se vai atribuir a chave correspondente na estrutura
	*/
	if (map_unit ==NULL)/**Presumo que isto de erro pois As posicoes sao strings e nao sei se isto mete como apontador se nao ¯\_(?)_/¯*/
		return;
	if (strcmp(key, "N")== 0)
		strcmp(map_unit->N, val);
	else if (strcmp(key, "S") == 0)
		strcmp(map_unit->S, val);
	else if (strcmp(key, "W") == 0)
		strcmp(map_unit->W, val);
	else if (strcmp(key, "E") == 0)
		strcmp(map_unit->E, val);
	else{
		;
	}
}

void read_config(MAP_CONFIG *config,FILE *f) {
	/**
	Esta funcao e onde de facto os valores vao ser atribuidos e procurados, quando se quer ler um ficheiro INI so e necessario
	chamar esta funcao com as estruturas pedidas.
	@param config = estrutura tipo MAP_CONFIG para xdim e ydim
	@param map_unit = Uma estrutura tipo UNIT para guardar os valores das 4 direcoes a volta lidas da INI
	@param f = ficheiro INI de onde se vao ler os valores para atribuir as estruturas passadas a funcao
	*/
	char str[MAX];
	char *token;
	const char *delim = "=\n";
	int counter = 0;
	MAP_CONFIG *world;
	
	while (fgets(str, MAX, f) != NULL) {
		if (strchr(str, ";"))
			;
		else if (strchr(str, "=")) {
			char varname[MAX];
			int value;

			token = strtok(str, delim);
			strcpy(varname, token);

			token = strtok(NULL, delim);
			value = atoi(token);

			set_config_val(config, varname, value);
		}
	}
	
	world = malloc(sizeof(MAP_CONFIG));
	world->grid = calloc(world.xdim * world.ydim, sizeof(UNIT)); /**Isto aloca a grid com as estruturas UNIT la dentro*/
	
	while (fgets(str, MAX, f) != NULL) { /**Le uma segunda vez a file para atribuir os valores a cada unidade do mapa*/
		if (strchr(str, ";"))
			;
		else if (strchr(str, "=")) {
			char varname[MAX];
			char *value;

			token = strtok(str, delim);
			strcpy(varname, token);

			token = strtok(NULL, delim);
			value = atoi(token);
			
			if (strcmp(varname, "N")==0) /**Conta em que unidade do mapa esta, cada unidade so tem um N um S, E,W*/
				counter += 1;
			set_unit_val(world->grid[counter-1], varname, value);/**Atribui os valores as unidades corretas*/
		}
	}
	fclose(f);
	return;
}

