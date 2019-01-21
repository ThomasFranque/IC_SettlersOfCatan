#include <stdio.h>
#include <string.h>
#include "stdlib.h"
#include "ini.h"
#define MAX 128
typedef struct{
/**Estrutura da unidade do mapa, primeira posicao de cada array � uma letra, o resto um numero*/
	char Building[2];
	char Material[3];
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
		int cellsize = 4;
		int totalx = gridSizex * cellsize; /**5 é o tamanho das células*/
		int totaly = gridSizey * cellsize;
    /* Iterate over each row */
    for(int i=0; i<=totalx; i++)
    {
        /* Iterate over each column */
        for(int j=0; j<=totaly; j++)
        {
        if(i % cellsize == 0 || j % cellsize == 0){
        	printf("* ");
        }else if (i%cellsize == 2 && j%cellsize == 2){
        	printf("%c ", grid[(i/cellsize)*gridSizex +(j/cellsize)].Material[0]);
				}else if(i%cellsize == 3 && j%cellsize == 2){
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
	char casa[3];
	char linha[12];
	for(int i = 0; i<map.ydim; i++){ /**Itera sobre a dimensao do mapa e atribui os valores que le da INI na grid*/
		sprintf(linha,"linha %d", ((i%map.ydim)+1));
		for(int j =0; j<map.xdim;j++){
			sprintf(casa,"C%d", ((j%map.xdim)+1));
			ini_sget(config, linha, casa ,"%s", &grid[i*map.xdim + j].Material);
			grid[i*map.xdim + j].Quantidade = (int) strtol(strpbrk(grid[i*map.xdim + j].Material, "0123456789"), (char **)NULL, 10);
		}
	}
	ini_free(config);
/**Fecha o ficheiro*/
	printf("Opening Map with dimensions---->X: %d Y: %d\n", map.xdim, map.ydim);

	print_unit(map.xdim, map.ydim, grid);
	getchar();
	free(grid);
	return 0;
}
