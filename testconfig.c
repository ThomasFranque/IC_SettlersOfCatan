#include <stdio.h>
#include <string.h>
#include "stdlib.h"
#include "ini.h"
#define MAX 128
typedef struct{
/**Estrutura da unidade do mapa, primeira posicao de cada array � uma letra, o resto um numero*/
	char Building[2];
	char Material[3];
}UNIT;

typedef struct{
	int xdim;
	int ydim;
	char E[MAX];
} MAP_CONFIG;

void print_unit(){
    int rows = 5, columns = 5;

    /* Iterate over each row */
    for(int i=1; i<=rows; i++)
    {
        /* Iterate over each column */
        for(int j=1; j<=columns; j++)
        {
        	if(i==1 || i==rows || j==1 || j==columns)
          {
                /* Print star for 1st and last row, column */
              printf("*");
          }
          else
          {
              printf("X");
          }
        }
        /* Move to the next line */
        printf("\n");
    }
}


void print_map(MAP_CONFIG config){
	for (int i = 0; i < config.xdim; i++){
		printf("\n");
		for(int j = 0; i< config.ydim; j++);
			print_unit();
	}
}

int main(int argc, char **argv) {
	MAP_CONFIG map;
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
	/**RETIRAR TODA A INFORMACAO DO FICHEIRO AQUI*/
	ini_t *config = ini_load(filename);
	map.xdim = atoi(ini_get(config,NULL, "xdim"));
	map.ydim = atoi(ini_get(config,NULL, "ydim"));

	UNIT *grid = calloc((map.xdim * map.ydim), sizeof(UNIT)); /**Isto aloca a grid com as estruturas UNIT la dentro*/
	char casa[128];
	char linha[12];
	for(int i = 0; i<map.ydim; i++){

		sprintf(linha,"linha %d", ((i%map.ydim)+1));
		for(int j =0; j<map.xdim;j++){

			sprintf(casa,"C%d", ((j%map.xdim)+1));
			printf(" %s %s\n", linha, casa);
			ini_sget(config, linha, casa ,"%s", &grid[i*map.xdim + j].Material); //not this
		}
	}
	ini_free(config);
/**Fecha o ficheiro*/

	printf("%d %d\n", map.xdim, map.ydim);
	for(int i = 0; i<map.ydim; i++){
		printf("\n");
		for(int j =0; j<map.xdim;j++){
			printf("%s ", grid[i*map.xdim +j].Material);
		}
	}
	print_map(map);
	getchar();
	return 0;
}
