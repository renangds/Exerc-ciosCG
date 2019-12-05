#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>

#define WIDTH 600.0
#define HEIGHT 600.0

float angle = 0, scale = 1.0;
float xtrans = 0, ytrans = 0, ztrans = 0;

void keyboard(unsigned char key, int x, int y) {
	switch (key)
	{
		case 'r':
			angle--;
			break;
		case 'R':
			angle++;
			break;
		case '+':
			scale++;
			break;
		case '-':
			scale--;
			break;
	}
	glutPostRedisplay();
}

void specialKeysPress(int key, int x, int y)
{
	switch (key)
	{
		case GLUT_KEY_UP:
			ytrans++;
			break;
		case GLUT_KEY_DOWN:
			ytrans--;
			break;
		case GLUT_KEY_RIGHT:
			xtrans++;;
			break;
		case GLUT_KEY_LEFT:
			xtrans--;
			break;
	}
	glutPostRedisplay();
}

void draw()
{
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINES);
	glVertex2f(-WIDTH / 2, 0.0);
	glVertex2f(WIDTH / 2, 0.0);
	glVertex2f(0.0, -HEIGHT / 2);
	glVertex2f(0.0, HEIGHT / 2);
	
	glEnd();

	glColor3f(1.0, 0.0, 0.0);

	glPushMatrix();
	glTranslatef(xtrans, ytrans, 0.0);
	glRotatef(angle, 0.0, 0.0, 1.0);
	glScalef(scale, scale, 0.0);
	glutWireCube(40);
	glPopMatrix();
}

void display(void)
{
	// Limpar todos os pixels
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity(); // Inicializa com matriz identidade

	draw();
	
	glutSwapBuffers();
	glutPostRedisplay();
}

void init(void)
{
	// selecionar cor de fundo (preto)
	glClearColor(0.0, 0.0, 0.0, 0.0);

	// inicializar sistema de viz.
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-WIDTH / 2, WIDTH / 2, -HEIGHT / 2, HEIGHT / 2, -100.0, 100.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("hello");
	init();
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKeysPress);
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}
