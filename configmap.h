#ifndef CONFIGMAP_H_INCLUDED
#define CONFIGMAP_H_INCLUDED
typedef struct{
/**Estrutura da unidade do mapa*/
	int Building;
	char Material[3];
	int Quantidade;
	int Player;
}UNIT;

typedef struct{
/**Simples estrutura de mapa*/
	int xdim;
	int ydim;
} MAP_CONFIG;

void print_map(int gridSizex, int gridSizey, UNIT *grid);
void atribuir_valores_ini(UNIT *grid, MAP_CONFIG map);
#endif
