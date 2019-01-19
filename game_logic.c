#include <stdio.h>
#include "diceroll.h"

/*
@turnNumber = resultado final dos dados
@adjacentNumbers = placeholder para as casas adjacentes provavelmente vai ser preciso um for statement
@gameCards = o que o jogador ganhou este turno
gameCards[0] = wool
gameCards[1] = grain
/////////[2] = log
/////////[3] = steel
*/



int play () {
	int turnNumber = roll();
	int gameCards [4];
	gameCards = [0,0,0,0];
	if (turnNumber == adjacentNumbers[x][x]){
		switch(adjacentNumbers){
			case ('w'):
				gameCards[0] += 1;
			case ('g'):
				gameCards[1] += 1;
			case ('l'):
				gameCards[2] += 1;
			case ('s'):
				gameCards[3] += 1;
			default:
				break;
		printf("You got +%d Wool, +%d Grain, +%d Log, +%d Steel", gameCards[0], gameCards[1], gameCards[2], gameCards[3])
		return gameCards;
		
	} else {
		printf("No luck this time");
		return 0;
	}

}

int upgrades () {
	
}


int bank () {
	
}


int inventory () {
	
}


int buy () {
	
}
