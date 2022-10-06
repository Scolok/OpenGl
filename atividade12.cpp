#include <GL/freeglut.h>

#define DELTA 0.02
#define LARGURA 32
#define ALTURA 24

typedef struct {
	float x, y, z;
} Vetor;

Vetor direcao, posicao;

static void inicio() {

	glClearColor(0.5, 0.5, 0.5, 1);

	posicao.x = LARGURA / 2;
	posicao.y = ALTURA / 2;

	direcao.x = DELTA;
	direcao.y = DELTA;

}





static void desenharPontos()
{
	//Clear the frameBuffer with the background color
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, LARGURA, 0, ALTURA, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//Translation
	glTranslatef(posicao.x, posicao.y, 0);

	//It draws a red square center in origin
	glColor3f(1, 0, 10);
	glBegin(GL_LINES);
	glPointSize(10000);
	glVertex2f(-1, -1);
	glVertex2f(1, -1);
	glVertex2f(1, 1);
	glVertex2f(2, 2);
	glVertex2f(-2, 2);
	glVertex2f(-2, -2);
	glVertex2f(2, -2);
	glVertex2f(-3, 3);
	glVertex2f(3, 3);
	glVertex2f(-3, -3);
	glVertex2f(3, -3);
	glVertex2f(-4, 4);

	glEnd();

	// Change the GrameBuffers (double buffering)
	glutSwapBuffers();

}

int main(int argc, char** argv) {

	// Glut starting
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(1280, 960);
	glutCreateWindow("Atividade");

	inicio();

	glutDisplayFunc(desenharPontos);


	glutMainLoop();

	return 0;

}