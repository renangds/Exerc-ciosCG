#include <iostream>
#include <stdlib.h>
#include <vector>
#include <random>

#include <GL/glut.h>

#define WIDTH 1920
#define HEIGHT 1080
#define NTRIANGLES 4

int delay = 16;

struct Pos {
	float x, y;
};

struct Color {
	float r, g, b;
};

class Triangles {
public:
	Pos pos[3];
	Color color;
	float xCoef;
	float yCoef;
};

using namespace std;

vector<Triangles> listTriangles(NTRIANGLES);

void draw()
{
	for (int i = 0; i < NTRIANGLES; i++) {
		glBegin(GL_LINE_LOOP);
		glColor3f(listTriangles[i].color.r, listTriangles[i].color.g, listTriangles[i].color.b);
		for (int j = 0; j < 3; j++) {
			glVertex2f(listTriangles[i].pos[j].x, listTriangles[i].pos[j].y);
		}

		glEnd();
	}
	glEnd();
}

void display()
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	draw();
}

void init() {
	for (int i = 0; i < NTRIANGLES; i++) {
		for (int j = 0; j < 3; j++) {
			listTriangles[i].pos[j].x = rand() % (int)WIDTH;
			listTriangles[i].pos[j].y = rand() % (int)HEIGHT;

			listTriangles[i].color.r = ((float)rand() / RAND_MAX);
			listTriangles[i].color.g = ((float)rand() / RAND_MAX);
			listTriangles[i].color.b = ((float)rand() / RAND_MAX);

			
		}
		listTriangles[i].xCoef = 10 * ((float)rand() / RAND_MAX);
		listTriangles[i].yCoef = 10 * ((float)rand() / RAND_MAX);
	}
}

void keyboard(unsigned char key, int x, int y) {
	if (key == 'r') {
		init();
	}
	else if (key == 27) {
		exit(0);
	}
	glutPostRedisplay();
}

void timer(int delay) {
	for (int i = 0; i < NTRIANGLES; i++) {
		for (int j = 0; j < 3; j++) {
			if ((listTriangles[i].pos[j].x + listTriangles[i].xCoef) >= WIDTH || (listTriangles[i].pos[j].x + listTriangles[i].xCoef) <= 0.0) {
				listTriangles[i].xCoef *= -1.0;
				break;
			}
		}
		for (int j = 0; j < 3; j++) {
			listTriangles[i].pos[j].x += listTriangles[i].xCoef;
		}

		for (int j = 0; j < 3; j++) {
			if ((listTriangles[i].pos[j].y + listTriangles[i].yCoef) >= HEIGHT || (listTriangles[i].pos[j].y + listTriangles[i].yCoef) <= 0.0) {
				listTriangles[i].yCoef *= -1.0;
				break;
			}
		}
		for (int j = 0; j < 3; j++) {
			listTriangles[i].pos[j].y += listTriangles[i].yCoef;
		}
	}
		
	glutSwapBuffers();
	glutPostRedisplay();
	glutTimerFunc(delay, timer, delay);
}


int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("ScreenSaver");
	glOrtho(0.0, WIDTH, HEIGHT, 0.0, -1.0, 1.0);
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	glutFullScreen();
	glutTimerFunc(delay, timer, delay);
	init();
	glutMainLoop();
	return 0;
}