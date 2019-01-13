#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <windows.h>
#include "game.h"
#include "fad.h"

#define MAX 128

void reshape_callback(int w, int h) {
	/**
	@brief Serve para reconfigurar e escrever o mapa como queremos, onde queremos
	@param w comprimento da janela
	@param h altura da janela
	*/
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION); /**Projecao 2d para projecao ortografica(x,y)*/
	glLoadIdentity();
	glOrtho(0.0, 3, 0.0, 3, -1.0, 1.0); /**Onde comeca e acaba cada coordenada, x,y,z*/ /**SUBSTITUIR PARA XDIM E YDIM*/
	glMatrixMode(GL_MODELVIEW);
}
void display_callback() {
	glClear(GL_COLOR_BUFFER_BIT);
	drawGrid();
	glutSwapBuffers();/**troca de frame quando glutDisplayFunc e chamado*/

}

void init() { /**Adiocionar 2 parametros x e y*/
	glClearColor(0.0, 0.47, 0.75, 1.0);
	initGrid(3, 3); /**SUBSTITUIR PARA XDIM E YDIM*/
}


void GetMonitorResolution(int *horizontal, int *vertical) {
	/**
	@brief Recolhe e atribui a resolucao do pc em que esta a ser corrido o programa
	@param horizontal pixeis horizontais do ecra
	@param vertival pixeis verticais do ecra
	*/
	*horizontal = GetSystemMetrics(SM_CYSCREEN);
	*vertical = GetSystemMetrics(SM_CXSCREEN);
}


/**Aqui comeca o main com o loop do jogo e init do glut*/
int main(int argc, char **argv) {
	FILE *f;
	char *filename;
	char *str_ini;
	for (int i = 0; i < argc; i++)
		printf("Parametro %d: %s\n", i, argv[i]);
	if (argc >= 2) {
		filename = argv[1];
	}
	else {
		printf("A abrir o ficheiro de base...\n"); /**abre ficheiro standard se nao for oferecido como argumento um ficheiro*/
		filename = "mapa.ini";
	}

	abrirFicheiro(filename, "r"); /**abre ficheiro atraves de funcao*/
	/**RETIRAR TODA A INFORMACAO DO FICHEIRO AQUI*/
	/**retirar dimensoes do board*/
	while (1) {
		if (feof(f) != 0) break;
		fgets(str_ini, MAX, f);
		if (str_ini[0] == ";")
	}

	/**FECHAR FICHEIRO*/
	int Height = 0, Width = 0;
	int *H = &Height, *W = &Width;
	GetMonitorResolution(H, W); /**Retira o tamanho do ecra para ser usado com openGL*/
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);/**display buffer e modo das cores, isto significa modo RGB com 2 buffers,
												2 frames pre feitas e vai trocando enquando da update das mesmas*/

	glutInitWindowPosition(0, 0);/**posicao de entrada*/
	glutInitWindowSize(600, 600);/**tamanho da janela*/
	glutCreateWindow("Settlers of Japan");/**Cria a janela e da o nome a mesma*/

	glutDisplayFunc(display_callback);

	glutReshapeFunc(reshape_callback);
	init();
	glutMainLoop();
	return 0;
}
