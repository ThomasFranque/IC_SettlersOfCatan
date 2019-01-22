#ifndef CONFIGMAP_H_INCLUDED
#define CONFIGMAP_H_INCLUDED

/** Unidade ou Casa do mapa*/
typedef struct{
/** Building inteiro com a informacao do edificio construido nesta celula (0 a 4)*/
	int Building;
/** Material vetor com a informacao lida da INI, posicao 0 contem o material do terreno*/
	char Material[3];
/** Quantidade numero a ser comparado quando se rolam os dados*/
	int Quantidade;
	int Player;
}UNIT; /** Unidade do mapa*/


/** MAP_CONFIG e a estrutura onde se guarda xdim e ydim do mapa */
typedef struct{
/**Dimensao x do mapa*/
	int xdim;
/**Dimensao y do mapa*/
	int ydim;
} MAP_CONFIG;

void print_map(int gridSizex, int gridSizey, UNIT *grid);
void atribuir_valores_ini(UNIT *grid, MAP_CONFIG map);
#endif
