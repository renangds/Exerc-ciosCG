#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include <GL/glut.h>

#define WIDTH 600.0
#define HEIGHT 600.0
#define PASSOS 100

float angle = 0, scale = 1.0;
float xtrans = 0, ytrans = 0, ztrans = 0;
float xtemp, ytemp;
float xinterval, yinterval;

float scaleTemp;
float scaleinterval;

float angleTemp;
float angleinterval;

void desenhaEixos()
{
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINES);

	glVertex2f(-WIDTH / 2, 0.0);
	glVertex2f(WIDTH / 2, 0.0);
	glVertex2f(0.0, -HEIGHT / 2);
	glVertex2f(0.0, HEIGHT / 2);

	glEnd();
}

void showMenu()
{
	int op;
	system("cls");
	printf("\n=== MENU ===");
	printf("\n1 - Translacao");
	printf("\n2 - Rotacao");
	printf("\n3 - Escala");
	printf("\n4 - Sair");
	printf("\nOpcao: ");

	scanf("%d", &op);
	switch (op)
	{
		case 1:
			xtemp = xtrans;
			ytemp = ytrans;
			
			printf("\n\nInforme o vetor de translacao (entre -300.0 e 300.0)");
			printf("\nX : ");
			scanf("%f", &xtrans);
			printf("Y : ");
			scanf("%f", &ytrans);

			xinterval = (xtrans - xtemp) / PASSOS;
			yinterval = (ytrans - ytemp) / PASSOS;

			for (int k = 0; k < PASSOS; k++) {
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
				glLoadIdentity(); // Inicializa com matriz identidade

				desenhaEixos();

				glColor3f(1.0, 0.0, 0.0);

				xtemp += xinterval;
				ytemp += yinterval;

				glTranslatef(xtemp, ytemp, 0.0);
				glRotatef(angle, 0.0, 0.0, 1.0);
				glScalef(scale, scale, scale);
				glutWireCube(40);

				glutSwapBuffers();
			}
			break;
		case 2:

			angleTemp = angle;


			printf("\n\nInforme o angulo de rotacao (em graus): ");
			scanf("%f", &angle);

			angleinterval = (angle - angleTemp) / PASSOS;

			for (int k = 0; k < PASSOS; k++) {
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
				glLoadIdentity(); // Inicializa com matriz identidade

				desenhaEixos();

				glColor3f(1.0, 0.0, 0.0);

				angleTemp += angleinterval;

				glPushMatrix();
				glTranslatef(xtrans, ytrans, 0.0);
				glRotatef(angleTemp, 0.0, 0.0, 1.0);
				glScalef(scale, scale, 0.0);
				glutWireCube(40);
				glPopMatrix();

				glutSwapBuffers();

				//printf("%f\n", angleTemp);
			}

			break;

		case 3:
			scaleTemp = scale;

			printf("\n\nInforme o fator de escala: ");
			scanf("%f", &scale);
			scaleinterval = (scale - scaleTemp) / PASSOS;

			for (int k = 0; k < PASSOS; k++) {
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
				glLoadIdentity(); // Inicializa com matriz identidade

				desenhaEixos();

				glColor3f(1.0, 0.0, 0.0);

				scaleTemp += scaleinterval;

				glPushMatrix();
				glTranslatef(xtrans, ytrans, 0.0);
				glRotatef(angle, 0.0, 0.0, 1.0);
				glScalef(scaleTemp, scaleTemp, 0.0);
				glutWireCube(40);
				glPopMatrix();

				glutSwapBuffers();
			}
			break;
		case 4:
			exit(1);
			break;
		default:
			printf("\n\nOpcao invalida\n\n");
			break;
	}
}

void display()
{
	// Limpar todos os pixels
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity(); // Inicializa com matriz identidade

	desenhaEixos();

	glColor3f(1.0, 0.0, 0.0);

	glPushMatrix();
	glTranslatef(xtrans, ytrans, 0.0);
	glRotatef(angle, 0.0, 0.0, 1.0);
	glScalef(scale, scale, scale);
	glutWireCube(40);
	glPopMatrix();

	glutSwapBuffers();
	glutPostRedisplay();

	showMenu();
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
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}