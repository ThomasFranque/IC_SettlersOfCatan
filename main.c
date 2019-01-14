#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "game.h"
#include "fad.h"
#include "readconfig.h"
#define MAX 128

int main(int argc, char **argv) {
	int *grid;
	CONFIG config;
	FILE *f;
	char *filename;
	for (int i = 0; i < argc; i++)
		printf("Parametro %d: %s\n", i, argv[i]);
	if (argc >= 2) {
		filename = argv[1];
	}
	else {
		printf("A abrir o ficheiro de base...\n"); /**abre ficheiro standard se nao for oferecido como argumento um ficheiro*/
		filename = "mapa.ini";
	}

	f = abreFicheiro(filename, "r"); /**abre ficheiro atraves de funcao*/
	/**RETIRAR TODA A INFORMACAO DO FICHEIRO AQUI*/
	/**retirar dimensoes do board*/
	read_config(&config, f);
	grid = calloc(config.xdim, sizeof(int));
	for (int i = 0; i < config.xdim; i++)
		grid[i] = calloc(config.ydim, sizeof(int));
	free(grid);


