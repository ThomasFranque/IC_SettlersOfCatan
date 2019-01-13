#include <GL/freeglut.h>
#include "game.h"

int gridX, gridY;

struct map_unit {
	int id;
	char N;
	char S;
	char W;
	char E;
};

void initGrid(int x, int y) {
	gridX = x;
	gridY = y;

}

void drawGrid() {
	graphic_unit(2, 2);
}

void graphic_unit(int x, int y) { /**Mudar aqui a imagem para cada unidade do jogo*/
	/*!
	@brief Cria uma unidade grafica do tabuleiro do jogo
	@param x posicao x no tabuleiro da peca
	@param y posicao y no tabuleiro da peca
	*/
	glLineWidth(1.0);
	glColor3f(1.0,1.0,1.0);

	glBegin(GL_LINE_LOOP);
	/**a partir daqui desenha se tudo oque fizer parte dessa unidade*/
	glVertex2f(x,y);
	glVertex2f(x+1,y);
	glVertex2f(x+1,y+1);
	glVertex2f(x,y+1);
	glEnd();/**Comeca e acaba sempre em glBegin e glEnd*/
}
