#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll (int number_of_dices) {
	int i, n, x,finalNumber;
	int *dices;
	time_t t;
	
	dices = malloc(number_of_dices * sizeof(int));
	
	n = number_of_dices; /* qts numeros queremos gerar */
	x = 6; /* Numero de lados */
	
	/* init */
	srand((unsigned) time(&t));
	
	/* print e definir  n numeros de 0 a x */
	for (i = 0 ; i < n ; i++) {
		dices[i] = rand() % x;
		
		/* roll n pode ser 0 */
		while (dices[i] == 0){
			dices[i] = rand() % x;
		}
		printf("Roll %d = %d\n",i+1 ,dices[i]);
	}
	/* somar os 2 numeros */
	finalNumber = dices[0] + dices[1];
	printf("Final number is: %d\n", finalNumber);
	
	free(dices);
	return finalNumber;
}