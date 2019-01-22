#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "gamelogic.h"
#include "ini.h"
#include "configmap.h"
#include "aiai.h"
#define MAX 128
/** @file*/

/**
@brief Esta funcao contem o loop principal do jogo
*/

void Game_loop(UNIT *grid, MAP_CONFIG map){
	char choice;
	int choiceInt;

	int playerMaterials[5]={0,0,0,0,0};
	int playerPoints = 0;

	int aiMaterials[5]={0,0,0,0,0};
	int aiPoints = 0;

	printf("Hello, welcome to our land, here, you will have to face the most brave punmaster, the one and only JapAInese.\n\n>Yes, me come forth child, for we are about to make history...\n");
	printf(">Tell me, where do you want you first steeltlement?");
	scanf("%d", &choiceInt);
	grid[choiceInt - 1].Building = 1;
	printf("GAME MASTER!! You heard the kid, time for some Ja in my pun.\n");
		while (1){
			printf("Your turn to roll player.\n>Inpun anything to Roll my son.");
			getchar();
			play(map, grid);
			printf("\nWhat do you want to do next?"
				"Buy Village  .............. 1"
				"Check Inventory ........... 2"
				"Bank ...................... 3"
				"Continue .................. 4");
			scanf("%s", &choice);

			switch (choice) {
			/* Todas as funçoes estao no ficheiro game_logic */
			case '1':
				buy(map, grid, playerMaterials);
			case '2':
				inventory( playerMaterials);
			case '3':
				bank( playerMaterials);
			case '4':
				break;
			default:
				printf(">WHAT DID YOU SAY? That's a very offensive word in Japunese");
			}

			ai(aiMaterials, aiPoints);

			if (playerPoints >= 6){
				printf("You Win!!");
				break;
			}
			else if (aiPoints >= 6){
				printf("HAHA! I WIN! PUNTASTIC! You are really bad...");
				break;
			}
		}

}
/**
@brief O jogo de tabuleiro Settlers of Catan modificado para peças quadradas, ver README.MD para mais informacao sobre como funciona
@param argc numero de argumentos dados ao main
@param argv vetor com os argumentos passados ao main
*/
int main(int argc, char **argv) {
	MAP_CONFIG map;
	UNIT grid;
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
	atribuir_valores_ini(&grid, map, config);

	printf("Opening Map with dimensions---->X: %d Y: %d\n", map.xdim, map.ydim);

	print_map(map.xdim, map.ydim, &grid);

	getchar();
	return 0;
}
