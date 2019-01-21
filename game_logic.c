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
@locales = nada, cidades e vilas:
Se locales[a] = 0 = NADA
Se locales[b] = 1 = Vila do P1
Se locales[c] = 2 = Cidade do P1
Se locales[d] = 3 = Vila do P2
Se locales[e] = 4 = Cidade do P2
Ex de Locales: 04301200
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

/*100% Workingvvvvv*/
//inicializar funçao no main como: bank(playerMaterials,points); //points/playerMaterials é respetivo ao jogador que está a jogar
int bank (int playerMaterials[]) {
	char choice = '0';
	printf("Debug\n");

  	printf("\nYOU HAVE:\n Wool _____ %d \n Grain ____ %d \n Log ______ %d \n Steel ____ %d \n Brick ____ %d \n\n Points: %d",playerMaterials[0],playerMaterials[1],playerMaterials[2],playerMaterials[3],playerMaterials[4],points);

	printf("\nWant to trade in Materials[1]?\nExit[2]\n");
	scanf("%s", &choice);


	if (choice == '1'){
        //player wants to trade materials
    		printf("Want a Point[1] or another Material[2]?\n");
		scanf("%s", &choice);
		if (choice == '1'){
      			printf("With wich Material? \n Wool ..... [1] \n Grain .... [2] \n Log ...... [3] \n Steel .... [4] \n Brick .... [5] \n ");
			scanf("%s", &choice);
			/*Player wants a new point*/
			if (choice == '1'){
				if (playerMaterials[0] >= 10){
					playerMaterials[0] -= 10;
					points += 1;
				}else {
					printf("Sheep! Not enough Wool.");
				}
			}else if (choice == '2'){
				if (playerMaterials[1] >= 10){
					playerMaterials[1] -= 10;
					points += 1;
				} else {
					printf("Those are rookie numbers, you ain't got enough Grain.");
				}
			}else if (choice == '3'){
				if (playerMaterials[2] >= 10){
					playerMaterials[2] -= 10;
					points += 1;
				} else {
					printf("Connection time-out, LOG in failed, not enough Log.");
				}
			}else if (choice == '4'){
				if (playerMaterials[3] >= 10){
					playerMaterials[3] -= 10;
					points += 1;
				} else {
					printf("Caught you steeling, not enough Steel.");
				}
			}else if (choice == '5'){
				if (playerMaterials[4] >= 10){
					playerMaterials[4] -= 10;
					points += 1;
				} else {
					printf("Another Brick in The Wall... Not enough Brick.");
				}
			}else{
				printf("Wakanda material is that?");
      			}


		}else if (choice == '2') {
		/*player wants a new material*/
			printf("Trade in which Material? \n Wool ..... [1] \n Grain .... [2] \n Log ...... [3] \n Steel .... [4] \n Brick .... [5] \n ");
			scanf("%s", &choice);
	      		if (choice == '1'){ //wool
	        		if (playerMaterials[0] >= 4){
	          			playerMaterials[0] -= 4;
	      		    		printf("Receive which material? \n Wool ..... [1] \n Grain .... [2] \n Log ...... [3] \n Steel .... [4] \n Brick .... [5] \n ");
	          			scanf("%s", &choice);
	          			if (choice == '1'){
	          				playerMaterials[0] += 1;
	          			}else if (choice == '2'){
	            				playerMaterials[1] += 1;
	          			}else if (choice == '3'){
	            				playerMaterials[2] += 1;
	          			}else if (choice == '4'){
	            				playerMaterials[3] += 1;
	          			}else if (choice == '5'){
	            				playerMaterials[4] += 1;
	          			}
	        		} else {
	          			printf("Ah Sheeperds, you ain't got enough Wool.");
	        		}
			} else if (choice == '2'){/*Grain*/
	        		if (playerMaterials[1] >= 4){
	          			playerMaterials[1] -= 4;
	                		printf("Receive wich material? \n Wool ..... [1] \n Grain .... [2] \n Log ...... [3] \n Steel .... [4] \n Brick .... [5] \n ");
	          			scanf("%s", &choice);
	          			if (choice == '1'){
	            				playerMaterials[0] += 1;
	          			}else if (choice == '2'){
	            				playerMaterials[1] += 1;
	          			}else if (choice == '3'){
	            				playerMaterials[2] += 1;
	          			}else if (choice == '4'){
	            				playerMaterials[3] += 1;
	          			}else if (choice == '5'){
	            				playerMaterials[4] += 1;
	          			}
				} else {
	          			printf("Looks like you have no sand in your eyes, you ain't got enough GrAiN.");
	        		}
	      		} else if (choice == '3'){/*Log*/
	        		if (playerMaterials[2] >= 4){
	          			playerMaterials[2] -= 4;
	                		printf("Receive wich material? \n Wool ..... [1] \n Grain .... [2] \n Log ...... [3] \n Steel .... [4] \n Brick .... [5] \n ");
	          			scanf("%s", &choice);
	          			if (choice == '1'){
	            				playerMaterials[0] += 1;
	          			}else if (choice == '2'){
	          				playerMaterials[1] += 1;
	          			}else if (choice == '3'){
	            				playerMaterials[2] += 1;
	          			}else if (choice == '4'){
	            				playerMaterials[3] += 1;
	          			}else if (choice == '5'){
	            				playerMaterials[4] += 1;
	          			}
	        		} else {
	          			printf("Please Log in first, you ain't got enough Log.");
	        		}

	      		} else if (choice == '4'){/*Steel*/
	        		if (playerMaterials[3] >= 4){
	          			playerMaterials[3] -= 4;
	          			printf("Receive wich material? \n Wool ..... [1] \n Grain .... [2] \n Log ...... [3] \n Steel .... [4] \n Brick .... [5] \n ");
	          			scanf("%s", &choice);
	          				if (choice == '1'){
	            					playerMaterials[0] += 1;
	          				}else if (choice == '2'){
	            					playerMaterials[1] += 1;
	          				}else if (choice == '3'){
	            					playerMaterials[2] += 1;
	          				}else if (choice == '4'){
	            					playerMaterials[3] += 1;
	          				}else if (choice == '5'){
	            					playerMaterials[4] += 1;
	          				}
	        		} else {
	          			printf("Stand steel, you ain't got enough Steel.");
	        		}
	      		} else if (choice == '5'){ /*Brick*/
	        		if (playerMaterials[4] >= 4){
	          			playerMaterials[4] -= 4;
	                		printf("Receive wich material? \n Wool ..... [1] \n Grain .... [2] \n Log ...... [3] \n Steel .... [4] \n Brick .... [5] \n ");
			          	scanf("%s", &choice);
		          		if (choice == '1'){
		            			playerMaterials[0] += 1;
				        }else if (choice == '2'){
				            	playerMaterials[1] += 1;
				        }else if (choice == '3'){
				           	playerMaterials[2] += 1;
			          	}else if (choice == '4'){
			            		playerMaterials[3] += 1;
			          	}else if (choice == '5'){
			            		playerMaterials[4] += 1;
			          	}
			        } else {
			          	printf("Too bad, you ain't got enough.");
			        }
			} else {
				printf("Wakanda material is that");
			}
		}


	} else if (choice == '2'){
		/*Player wants to leave*/
		  printf("Returning...");
	}

	printf("\nYOU NOW HAVE HAVE:\n Wool _____ %d \n Grain ____ %d \n Log ______ %d \n Steel ____ %d \n Brick ____ %d \n\n Points: %d",playerMaterials[0],playerMaterials[1],playerMaterials[2],playerMaterials[3],playerMaterials[4],points);
	return *playerMaterials;
}
/*^^^^^^^^^^^^*/

int inventory (playerMaterials) {
	printf("\nYOUR INVENTORY \nWool: %d \nGrain: %d \nLog: %d \nSteel: %d \nBricky: %d", playerMaterials[0], playerMaterials[1], playerMaterials[2], playerMaterials[3], playerMaterials[4]);
	return 0;
}



//vvvvvvvvvvvvv algo de errado com o return vvvvvvvvvvvvvv
int buy(int locales[], int playerMaterials[]) {
	/*NAO ESTÁ DINAMICO && NAO ESTA A USAR A STRUCT DO BOARD*/
	char choice;
	int casa;
	printf("Want a Village[1] or a City[2]?\nExit[3]\n");
	scanf("%s", &choice);
	if (choice == '1') {
		/*Village*/
		printf("Besides what house do you want to build your new Village? (Insert house number)\n");
		scanf("%d", &casa);

		//debug
		printf("Casa = %d \nLocales = %d \n", casa, *locales);
		printf("\nWool _____ %d \n Grain ____ %d \n Log ______ %d \n Steel ____ %d \n Brick ____ %d \n", playerMaterials[0], playerMaterials[1], playerMaterials[2], playerMaterials[3], playerMaterials[4]);
		//
		if (locales[casa - 1] == 0 && ((((locales[casa - 2] == 0 || locales[casa] == 0) || locales[casa - 5] == 0) || locales[casa + 3] == 0))) {
			if (playerMaterials[4] >= 1 && playerMaterials[2] >= 1 && playerMaterials[1] >= 1 && playerMaterials[0] >= 1) {
				playerMaterials[4] -= 1;
				printf("Brick:%d \n", playerMaterials[4]);
				playerMaterials[2] -= 1;
				printf("Log:%d \n", playerMaterials[2]);
				playerMaterials[1] -= 1;
				printf("Grain:%d \n", playerMaterials[1]);
				playerMaterials[0] -= 1;
				printf("Wool:%d \n", playerMaterials[0]);
				locales[casa - 1] = 1;
				printf("Success!");
			}
			else {
				printf("\nYou don't have enough materials.");
			}
		}
		else {
			printf("Not a valid position...");
		}
	}
	else if (choice == '2') {
		/*City*/
		printf("Choose a village to upgrade. (Insert house number)\n");
		scanf("%d", &casa);
		if (locales[casa - 1] == 1) {
			printf("Yes");
		}

	}
	else if (choice == '3') {
		/*exit*/
		printf(".");
	}
	else {
		printf("Unknown Option");
	}
	return *playerMaterials;
}




















