#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "game_logic.h"
#include "ini.h"
#include "configmap.h"
#define MAX 128
/** @file*/
/**
@brief O jogo de tabuleiro Settlers of Catan modificado para peças quadradas, ver README.MD para mais informacao sobre como funciona
@param argc numero de argumentos dados ao main
@param argv vetor com os argumentos passados ao main
*/
int main(int argc, char **argv) {
	MAP_CONFIG map;
	UNIT grid;
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

	ini_t *config = ini_load(filename);
	map.xdim = atoi(ini_get(config,NULL, "xdim"));
	map.ydim = atoi(ini_get(config,NULL, "ydim"));
	atribuir_valores_ini(&grid, map);

	printf("Opening Map with dimensions---->X: %d Y: %d\n", map.xdim, map.ydim);

	print_unit(map.xdim, map.ydim, grid);

	getchar();
	free(grid);
	return 0;
}

/**
@brief Esta funcao contem o loop principal do jogo
*/
int Game_loop(){
	int choice
	printf("Hello, "); 	/*FALTA A PUTA DE UMA MENSAGEM AQUI TOMAS, EU NAO TE PAGO PARA ISTO*/
	while true:
		printf( "What do you want to do? %d"
			"Buy Village  .............. 1"
	      		"Upgarade Village .......... 2"
			"Check Inventory ........... 3"
	       		"Bank ...................... 4"
	       		"Roll Dice ................. 5" );
		scanf("\n %d", choice);

		switch(choice){
			/* Todas as funçoes estao no ficheiro game_logic */
			case '1':
				buy();
			case '2':
				upgrades();
			case '3':
				inventory();
			case '4':
				bank();
			case '5':
				play();
			default:
				print("Unvalid Input");
		}
}
