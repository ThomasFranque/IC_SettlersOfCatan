
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <windows.h>
#include "game.h"

#define COLUMNS 12
#define ROWS 12

void reshape_callback(int w, int h) {
	/**
	@brief Serve para reconfigurar e escrever o mapa como queremos, onde queremos
	@param w comprimento da janela
	@param h altura da janela
	*/
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION); /**Projecao 2d para projecao ortografica(x,y)*/
	glLoadIdentity();
	glOrtho(0.0, COLUMNS, 0.0, ROWS, -1.0, 1.0); /**Onde comeca e acaba cada coordenada, x,y,z*/
	glMatrixMode(GL_MODELVIEW);
}
void display_callback() {
	glClear(GL_COLOR_BUFFER_BIT);
	drawGrid();
	glutSwapBuffers();/**troca de frame quando glutDisplayFunc e chamado*/

}

void init() {
	glClearColor(1.0, 0, 0, 1.0);
	initGrid(COLUMNS, ROWS);
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
int main(int argc, char** argv) {
	int Height = 0, Width = 0;
	int *H = &Height, *W = &Width;
	GetMonitorResolution(H, W); /**Retira o tamanho do ecra para ser usado com openGL*/
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);/**display buffer e modo das cores*/
	glutInitWindowPosition(0, 0);/**posicao de entrada*/
	glutInitWindowSize(600, 600);/**tamanho da janela*/
	glutCreateWindow("Settlers of Japan");/**Cria a janela e da o nome a mesma*/

	glutDisplayFunc(display_callback);

	glutReshapeFunc(reshape_callback);
	init();
	glutMainLoop();
	return 0;
}
