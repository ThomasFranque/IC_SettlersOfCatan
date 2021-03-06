#include <stdio.h>
#include <stdlib.h>
#include "gamelogic.h"
#include <time.h>
#include "aiai.h"
/** @file*/
//AI MATERIALS E AI POINTS

/**
@brief descobre se ha edificios adjacentes a casa escolhida
@param map dimensoes de mapa do jogo
@param grid informacao da grid do jogo
@param casa celula do mapa
*/
int adjacenteAI(MAP_CONFIG map, UNIT *grid, int casa) {

	int y = casa % map.xdim;
	int x = casa - (map.xdim*y);
	for (int dx = -1; dx <= 1; ++dx) {
		for (int dy = -1; dy <= 1; ++dy) {
			if ((dx != 0 || dy != 0) && (abs(dx) != abs(dy)))
				if ((grid[map.xdim*(x + dx) + (y + dy)].Building != 0) && (grid[map.xdim*(x + dx) + (y + dy)].Building < 3))
					return 1;
		}
	}
	return 0;
}

/** @brief Funcao de temporizador para suspanse dentro do jogo
@param seconds segundos que o programa deve de esperar para a proxima instrucao.
*/
void delay(int seconds){ //time delay___________________________________________
  int milli_seconds = 1000*seconds;
  clock_t start = clock();
  while(clock() < start + milli_seconds); //"ocupar" o pc com outra coisa enquanto corre.
}

/** @brief Funcao para a compra do AI, para ser usada na funcao ai().
@param map dimensoes do mapa xdim e ydim.
@param grid vetor UNIT com o mapa.
@param playerMaterials materiais do AI.
*/
void buyAI(MAP_CONFIG map, UNIT *grid, int *playerMaterials) {
	/*NAO EST� DINAMICO && NAO ESTA A USAR A STRUCT DO BOARD*/
	char choice;
	int choiceInt;
	int casa;
	printf("Want a Village[1] or a City[2]?\nExit[3]\n");
	delay(1);
	printf(">hm...");
	choiceInt = rand() % 10;
	if (choiceInt == 3){
		choice = '1';
	}else if (choiceInt == 5){
		choice = '2';
	}
	delay(4);
	printf(">%d\n",choice);
	if (choice == '1') {
		/*Village*/
		printf("Where do you want to build your new Village? (Insert house number)\n");
		printf("Want a Village[1] or a City[2]?\nExit[3]\n");
		delay(1);
		printf(">Let me think...");
		casa = rand() % (map.xdim*map.ydim);
		delay(2);
		printf(">%d!", casa);
		delay(1);
		if (adjacenteAI(map, grid, casa) != 0) {
			if (playerMaterials[4] >= 1 && playerMaterials[2] >= 1 && playerMaterials[1] >= 1 && playerMaterials[0] >= 1) {
				playerMaterials[4] -= 1;
				playerMaterials[2] -= 1;
				playerMaterials[1] -= 1;
				playerMaterials[0] -= 1;
				grid[casa - 1].Building = 1;
				printf("Success!\n\n>");
			}
			else {
				printf("\nYou don't have enough materials.\n\n>AH, I do Have!! I can prove it!!\n");
			}
		}
		else {
			printf("Not a valid position...\n\n>I AM THE ONE WHO SAYS IF ITS VALID OR NOT\n!");
		}
	}
	else if (choice == '2') {
		/*City*/
		printf("Choose a village to upgrade. (Insert house number)\n");

		delay(1);
		printf(">Villages, hm...\n");
		casa = rand() % (map.xdim*map.ydim);
		delay(1);
		printf(">I choose village %d.\n", casa);
		if (grid[casa - 1].Building == 1) {
			grid[casa - 1].Building = 2;
			printf("That village is now a city.\n\n>Woah, it's almost impossible for me to get it right!\n");
		}

	}
}

/** @brief Funcao que tem o turno do AI, para um turno é só chamar esta função
@param aiMaterials vetor materiais à semelhança à do jogador.
@param aiPoints numero de pontos do ai para  verificar se ganha.
*/
void ai(int *aiMaterials, MAP_CONFIG map, UNIT *grid) {
	int choice;
	printf("It's JapAInese, the pun master turn!\n");
	delay(1);
	//My turn! You are gonna feel the wrath o a thousand puns!
	//
	//FANCY TEXT LINES HERE WITH IFS
	//
	//
	play(map, grid, aiMaterials); //receber os materiais
	choice = rand() % 10;
	if (choice >= 3) {
		buyAI(map, grid, aiMaterials);
	}else{
		printf("I skip this one.\n");
	}
}
