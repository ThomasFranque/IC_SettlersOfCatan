#include "stdio.h"
#include "stdlib.h"
#include "time.h"

/* FALTA ALTERAR PARA PODER SER CHAMADO NOUTRO SITIO */

int main () {
	int i, n, x,finalNumber, dices[2];
	time_t t;
	
	n = 2; /* qts numeros queremos gerar */
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
	
	return finalNumber;
}
