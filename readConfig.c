#include "readconfig.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void set_config_val(CONFIG *config, const char *key, int val) {
	/**
	Esta funcao atribui a uma estrutura CONFIG o valor x e y do board
	@param config = estrutura tipo CONFIG para xdim e ydim
	@param Key = palavra chave do que se le da INI
	@param val = valor que se vai atribuir a chave correspondente na estrutura
	*/
	if (config == NULL)
		return;
	if (strcmp(key, "xdim") == 0)
		config->xdim = val;
	else if (strcmp(key, "ydim") == 0)
		config->ydim = val;
	else
		;
}

void set_unit_val(UNIT *map_unit, const char *key, int val){
	/**
	Esta funcao faz o mesmo que a set_config_val mas serve para cada unidade do mapa
	@param map_unit = Uma estrutura tipo UNIT para guardar os valores das 4 direcoes a volta lidas da INI
	@param Key = palavra chave do que se le da INI
	@param val = valor que se vai atribuir a chave correspondente na estrutura
	*/
	if (map_unit ==NULL)
		return;
	if (strcmp(key, "N")== 0)
		map_unit->N = val
}

void read_config(CONFIG *config, UNIT * map_unit, FILE *f) {
	/**
	Esta funcao e onde de facto os valores vao ser atribuidos e procurados, quando se quer ler um ficheiro INI so e necessario
	chamar esta funcao com as estruturas pedidas.
	@param config = estrutura tipo CONFIG para xdim e ydim
	@param map_unit = Uma estrutura tipo UNIT para guardar os valores das 4 direcoes a volta lidas da INI
	@param f = ficheiro INI de onde se vao ler os valores para atribuir as estruturas passadas a funcao
	*/
	char str[MAX];
	char *token;
	const char *delim = "=\n";

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
	fclose(f);
	return;
}

