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

int upgrades () {
	
}

^/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
int bank () {
	//debug stuff all variables should be defined on func
	char choice = '0';
  int playerPoints;
	int playerMaterials[] = {11,1,0,0,0,};
	playerPoints = 0;
	printf("Debug\n");

	printf("Want to trade in Materials[1] or Fields[2]?\nExit[3]\n");
	scanf("%s", &choice);
	if (choice == '1'){
    		printf("Want a Point[1] or another Material[2]?\n ");
		scanf("%s", &choice);
		if (choice == '1'){
      			printf("With wich Material? \n Wool ..... [1] \n Grain .... [2] \n Log ...... [3] \n Steel .... [4] \n Brick .... [5] \n ");
			scanf("%s", &choice);
			/*Player wants a new point*/
				if (choice == '1'){
					if (playerMaterials[0] >= 10){
						playerMaterials[0] -= 10;
						playerPoints += 1;
            printf("%d",playerMaterials[0]);
					} else {
						printf("Too bad, you ain't got enough.");
					}
				}else if (choice == '2'){
					if (playerMaterials[1] >= 10){
						playerMaterials[1] -= 10;
						playerPoints += 1;
					} else {
						printf("Too bad, you ain't got enough.");
					}
				}else if (choice == '3'){
					if (playerMaterials[2] >= 10){
						playerMaterials[2] -= 10;
						playerPoints += 1;
					} else {
						printf("Too bad, you ain't got enough.");
					}
				}else if (choice == '4'){
					if (playerMaterials[3] >= 10){
						playerMaterials[3] -= 10;
						playerPoints += 1;
					} else {
						printf("Too bad, you ain't got enough.");
					}
				}else if (choice == '5'){
					if (playerMaterials[4] >= 10){
						playerMaterials[4] -= 10;
						playerPoints += 1;
					} else {
						printf("Too bad, you ain't got enough.");
					}
				}else{
					printf("Wakanda material is that?");
      				}
	  }else if (choice == '2') {
    		printf("Trade in wich Material? \n Wool ..... [1] \n Grain .... [2] \n Log ...... [3] \n Steel .... [4] \n Brick .... [5] \n ");
		scanf("%s", choice);
		/*player wants a new material*/
		if (choice == '1'){
			if (playerMaterials[0] >= 4){
				playerMaterials[0] -= 4;
        			printf("Receive wich material? \n Wool ..... [1] \n Grain .... [2] \n Log ...... [3] \n Steel .... [4] \n Brick .... [5] \n ");
				scanf("%s", choice);
				switch(choice){/*Wool*/
					case '1':
						playerMaterials[0] += 1;
						break;
					case '2':
						playerMaterials[1] += 1;
						break;
					case '3':
						playerMaterials[2] += 1;
						break;
					case '4':
						playerMaterials[3] += 1;
						break;
					case '5':
						playerMaterials[4] += 1;
						break;
        }
		  } else {
				printf("Too bad, you ain't got enough.");
		  }
			
		} else if (choice == '2'){/*Grain*/
			if (playerMaterials[1] >= 4){
				playerMaterials[1] -= 4;
        			printf("Receive wich material? \n Wool ..... [1] \n Grain .... [2] \n Log ...... [3] \n Steel .... [4] \n Brick .... [5] \n ");
				scanf("%s", choice);
				switch(choice){
					case '1':
						playerMaterials[0] += 1;
						break;
					case '2':
						playerMaterials[1] += 1;
						break;
					case '3':
						playerMaterials[2] += 1;
						break;
					case '4':
						playerMaterials[3] += 1;
						break;
					case '5':
						playerMaterials[4] += 1;
						break;
        }
			} else {
				printf("Too bad, you ain't got enough.");
			}
			
		} else if (choice == '3'){/*Log*/
			if (playerMaterials[2] >= 4){
				playerMaterials[2] -= 4;
        			printf("Receive wich material? \n Wool ..... [1] \n Grain .... [2] \n Log ...... [3] \n Steel .... [4] \n Brick .... [5] \n ");
				scanf("%s", choice);
				switch(choice){
					case '1':
						playerMaterials[0] += 1;
						break;
					case '2':
						playerMaterials[1] += 1;
						break;
					case '3':
						playerMaterials[2] += 1;
						break;
					case '4':
						playerMaterials[3] += 1;
						break;
					case '5':
						playerMaterials[4] += 1;
						break;
        }
			} else {
				printf("Too bad, you ain't got enough.");
			}
			
		} else if (choice == '4'){/*Steel*/
			}
			if (playerMaterials[3] >= 4){
				playerMaterials[3] -= 4;
        			printf("Receive wich material? \n Wool ..... [1] \n Grain .... [2] \n Log ...... [3] \n Steel .... [4] \n Brick .... [5] \n ");
				scanf("%s", choice);
				switch(choice){
					case '1':
						playerMaterials[0] += 1;
						break;
					case '2':
						playerMaterials[1] += 1;
						break;
					case '3':
						playerMaterials[2] += 1;
						break;
					case '4':
						playerMaterials[3] += 1;
						break;
					case '5':
						playerMaterials[4] += 1;
						break;
        }
			} else {
				printf("Too bad, you ain't got enough.");
			}
			
		} else if (choice == '5'){ /*Brick*/
			if (playerMaterials[4] >= 4){
				playerMaterials[4] -= 4;
        			printf("Receive wich material? \n Wool ..... [1] \n Grain .... [2] \n Log ...... [3] \n Steel .... [4] \n Brick .... [5] \n ");
				scanf("%s", choice);
				switch(choice){
					case '1':
						playerMaterials[0] += 1;
						break;
					case '2':
						playerMaterials[1] += 1;
						break;
					case '3':
						playerMaterials[2] += 1;
						break;
					case '4':
						playerMaterials[3] += 1;
						break;
					case '5':
						playerMaterials[4] += 1;
						break;
        }
			} else {
				printf("Too bad, you ain't got enough.");
			}
			
		} else {
			printf("Wakanda material is that");
		}
	
	
	} else if (choice == '2'){
		/*Player wants to trade houses*/
		  printf("kk");
	}
  return 0;
}
/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
int inventory (playerMaterials) {
	printf("\n-YOUR INVENTORY \nWool: %d \nGrain: %d \nLog: %d \nSteel: %d \nBricky: %d", playerMaterials[0], playerMaterials[1], playerMaterials[2], playerMaterials[3], playerMaterials[4]);
	return 0;
}


int buy (locales,playerMaterials) {
	/*NAO ESTÁ DINAMICO && NAO ESTA A USAR A STRUCT DO BOARD*/
	char choice;
	int casa;
	while (1){
		scanf("Want a Village[1] or a City[2]?\nExit[3]\n%s",choice);
		if (choice == '1'){
			/*Village*/
			printf("Besides what house do you want to build your new Village? (Insert house number)\n")
			scanf("%d", casa)
			if (locales[casa-1] == '0' && (locales[casa-2] == '0' || locales[casa] == '0' || locales[casa-5] == '0' || locales[casa + 3] == '0')){
				playerMaterials[4] >= 1 ? playerMaterials[4] -= 1 : printf("\nRoad Block! Not enough Brick."); //brick
				
				playerMaterials[2] >= 1 ? playerMaterials[2] -= 1 : printf("\nFriend of the enviroment I see, not enough Log."); //log
				
				playerMaterials[1] >= 1 ? playerMaterials[1] -= 1 : printf("\nSa(n)d, not enough Grain."); //grain
				
				playerMaterials[0] >= 1 ? playerMaterials[0] -= 1 : printf("\nSheep! Not enough Wool."); //wool
				
				locales[casa-1] = 1;
				
				printf("Success!");
			} else {
				printf("Not a valid position...");
			}
		} else if (choice == '2'){
			/*Cityyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyhereyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy*/
			printf("Choose a village to upgrade. (Insert house number)\n")
			scanf("%d", casa)
			if (locales[casa-1] == 1){
				playerMaterials[4] >= 1 ? playerMaterials[1] -= 1 : printf("\nRoad Block! Not enough Brick."); //grain
				
				playerMaterials[2] >= 1 ? playerMaterials[3] -= 1 : printf("\nFriend of the enviroment I see, not enough Log."); //steel
			}
		
		} else if (choice == '3'){
			/*exit*/
			printf(".")
		} else {
			print("Unknown Option")
		}
	}
}























