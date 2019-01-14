#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "fad.h"

/**funcoes adicionais aqui>>>>>>>>>>>>>>>*/

FILE *abreFicheiro(char *nome, char *mode) {
	FILE *f;
	printf("A abrir o ficheiro %s\n", nome);
	f = fopen(nome, mode);

	if (f == NULL) {
		fprintf(stderr, "*** Nao foi possivel abrir o ficheiro %s.", nome);
		exit(1);	
	}
	return f;
}