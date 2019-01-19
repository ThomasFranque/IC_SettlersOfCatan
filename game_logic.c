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
/////////[4] = bricky
@playerMaterials = mesmo que o gameCards mas contem tudo
*/



int play () {
	int turnNumber = roll();
	int gameCards [5];
	gameCards = [0,0,0,0,0];
	
	if (turnNumber == adjacentNumbers[x][x]){
		switch(adjacentNumbers){
			case 'w':
				gameCards[0] += 1;
			case 'g':
				gameCards[1] += 1;
			case 'l':
				gameCards[2] += 1;
			case 's':
				gameCards[3] += 1;
			case 'b':
				gameCards[4] += 1;
			default:
				break;
		printf("You got +%d Wool, +%d Grain, +%d Log, +%d Steel, +%d Brick", gameCards[0], gameCards[1], gameCards[2], gameCards[3], gameCards[4]);
		return gameCards;
	} else {
		printf("No luck this time");
		return 0;
	}

}

int upgrades () {
	
}


int bank (playerMaterials,playerHouses) {
	int choice;
	int playerPoints;
	playerPoints = 0
	while (1){
		scanf("Want to trade in Materials[1] or Fields[2]?\nExit[3]\n %s", choice)';
		if (choice == 1){
			scanf("Want a Point[1] or another Material[2]?\n %s", choice);
			if (choice == 1){
				scanf("With wich Material? \n Wool ..... [1] \n Grain .... [2] \n Log ...... [3] \n Steel .... [4] \n Brick .... [5] \n %s", choice);
				switch(choice){
				/*Player wants a new point*/
					case '1':
						if playerMaterials[0] >= 10{
							playerMaterials[0] -= 10;
							playerPoints += 1;
							break;
						} else {
							print("Too bad, you ain't got enough.");
						}
					case '2':
						if playerMaterials[1] >= 10{
							playerMaterials[1] -= 10;
							playerPoints += 1;
							break;
						} else {
							print("Too bad, you ain't got enough.");
						}
					case '3':
						if playerMaterials[2] >= 10{
							playerMaterials[2] -= 10;
							playerPoints += 1;
							break;
						} else {
							print("Too bad, you ain't got enough.");
						}
					case '4':

						if playerMaterials[3] >= 10{
							playerMaterials[3] -= 10;
							playerPoints += 1;
							break;
						} else {
							print("Too bad, you ain't got enough.");
						}
					case '5':
						if playerMaterials[4] >= 10{
							playerMaterials[4] -= 10;
							playerPoints += 1;
							break;
						} else {
							print("Too bad, you ain't got enough.");
						}
					default:
						printf("Wakanda material is that?");
		}
		else if (choice == 2) {
			scanf("Trade in wich Material? \n Wool ..... [1] \n Grain .... [2] \n Log ...... [3] \n Steel .... [4] \n Brick .... [5] \n %s", choice);
			if (choice == 1){
			/*player wants a new material*/
				if playerMaterials[0] >= 4{
					playerMaterials[0] -= 4;
					scanf("Receive wich material? \n Wool ..... [1] \n Grain .... [2] \n Log ...... [3] \n Steel .... [4] \n Brick .... [5] \n %s", choice);
					switch(choice){
						case '1':
							playerMaterials[0] += 1
							break;

						case '2':
							playerMaterials[1] += 1{
							break;

						case '3':
							playerMaterials[2] += 1{
							break;

						case '4':
							playerMaterials[3] += 1{
							break;

						case '5':
							playerMaterials[4] += 1{
							break;
				} else {
					print("Too bad, you ain't got enough.");
				}
				
			} else if (choice == 2){

				if playerMaterials[1] >= 4{
					playerMaterials[1] -= 4;
					scanf("Receive wich material? \n Wool ..... [1] \n Grain .... [2] \n Log ...... [3] \n Steel .... [4] \n Brick .... [5] \n %s", choice);
					switch(choice){
						case '1':
							playerMaterials[0] += 1
							break;

						case '2':
							playerMaterials[1] += 1{
							break;

						case '3':
							playerMaterials[2] += 1{
							break;

						case '4':
							playerMaterials[3] += 1{
							break;

						case '5':
							playerMaterials[4] += 1{
							break;
				} else {
					print("Too bad, you ain't got enough.");
				}
				
			} else if (choice == 3){

				if playerMaterials[2] >= 4{
					playerMaterials[2] -= 4;
					scanf("Receive wich material? \n Wool ..... [1] \n Grain .... [2] \n Log ...... [3] \n Steel .... [4] \n Brick .... [5] \n %s", choice);
					switch(choice){
						case '1':
							playerMaterials[0] += 1
							break;

						case '2':
							playerMaterials[1] += 1{
							break;

						case '3':
							playerMaterials[2] += 1{
							break;

						case '4':
							playerMaterials[3] += 1{
							break;

						case '5':
							playerMaterials[4] += 1{
							break;
				} else {
					print("Too bad, you ain't got enough.");
				}
				
			} else if (choice == 4){

				}
				if playerMaterials[3] >= 4{
					playerMaterials[3] -= 4;
					scanf("Receive wich material? \n Wool ..... [1] \n Grain .... [2] \n Log ...... [3] \n Steel .... [4] \n Brick .... [5] \n %s", choice);
					switch(choice){
						case '1':
							playerMaterials[0] += 1
							break;

						case '2':
							playerMaterials[1] += 1{
							break;

						case '3':
							playerMaterials[2] += 1{
							break;

						case '4':
							playerMaterials[3] += 1{
							break;

						case '5':
							playerMaterials[4] += 1{
							break;
				} else {
					print("Too bad, you ain't got enough.");
				}
				
			} else if (choice == 5){

				if playerMaterials[4] >= 4{
					playerMaterials[4] -= 4;
					scanf("Receive wich material? \n Wool ..... [1] \n Grain .... [2] \n Log ...... [3] \n Steel .... [4] \n Brick .... [5] \n %s", choice);
					switch(choice){
						case '1':
							playerMaterials[0] += 1
							break;

						case '2':
							playerMaterials[1] += 1{
							break;

						case '3':
							playerMaterials[2] += 1{
							break;

						case '4':
							playerMaterials[3] += 1{
							break;

						case '5':
							playerMaterials[4] += 1{
							break;
				} else {
					print("Too bad, you ain't got enough.");
				}
				
			} else {
				printf("Wakanda material is that");
			}
		
		
		} else if (choice == 2){
		/*Player wants to trade houses*/
		
		}

int inventory (playerMaterials) {
	printf("\n-YOUR INVENTORY \nWool: %d \nGrain: %d \nLog: %d \nSteel: %d \nBricky: %d", playerMaterials[0], playerMaterials[1], playerMaterials[2], playerMaterials[3]);
	return 0;
}


int buy () {
	
}
