#include <stdio.h>
#include <string.h>
#include "stdlib.h"
#include "ini.h"
#define MAX 128
typedef struct{
/**Estrutura da unidade do mapa, primeira posicao de cada array � uma letra, o resto um numero*/
	char Building[2];
	char Material;
	int Quantidade;
	int Player;
	int playerMat[5];
}UNIT;

typedef struct{
	int xdim;
	int ydim;
} MAP_CONFIG;

void print_unit(int gridSizex, int gridSizey, UNIT *grid)
{
		int totalx = gridSizex * 5; /**5 é o tamanho das células*/
		int totaly = gridSizey * 5;
    /* Iterate over each row */
    for(int i=0; i<=totalx; i++)
    {
        /* Iterate over each column */
        for(int j=0; j<=totaly; j++)
        {
        	if(i % 5 == 0 || j % 5 == 0){
            printf("* ");
          }else if (i%5 == 2 && j%5 == 2){
            printf("%s%d", grid[(i/5)*gridSizex +(j/5)].Material,grid[(i/5)*gridSizex +(j/5)].Quantidade);
					}else if(i%5 == 3 && j%5 == 2){
						printf("P ");
          }else{
						printf("  ");
					}
        }
        /* Move to the next line */
        printf("\n");
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
	char Value[3];
	for(int i = 0; i<map.ydim; i++){

		sprintf(linha,"linha %d", ((i%map.ydim)+1));
		for(int j =0; j<map.xdim;j++){
			sprintf(casa,"C%d", ((j%map.xdim)+1));
			printf(" %s %s\n", linha, casa);
			ini_sget(config, linha, casa ,"%s", &Value); //not this
			printf("%s", Value);
			//grid[i*map.xdim + j].Material = Value[0];
			grid[i*map.xdim + j].Quantidade = (int) strtol(strpbrk(Value, "0123456789"), (char **)NULL, 10);
		}
	}
	ini_free(config);
/**Fecha o ficheiro*/
	printf("%d %d\n", map.xdim, map.ydim);
	for(int i = 0; i<map.ydim; i++){
		printf("\n");
		for(int j =0; j<map.xdim;j++){
			printf("%s \n", grid[i*map.xdim +j].Material);
		}
	}
	print_unit(map.xdim, map.ydim, grid);
	getchar();
	return 0;
}
