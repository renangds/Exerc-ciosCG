#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

void display(void);
void reshape(int, int);
void init (void);
void keyboard(unsigned char key, int x, int y);

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (500,500);
   glutInitWindowPosition (150,50);
   glutCreateWindow ("Ex1");
   init ();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutMainLoop();

   return 0;
}

// � a rotina chamada automaticamente sempre que a
// janela ou parte dela precisa ser redesenhada
void display(void)
{
   // Limpar todos os pixels
   glOrtho(-1.0, 3, -1.5, 1.5, -100.0, 100.0);
   glClear (GL_COLOR_BUFFER_BIT);

   //Desenha triangulo

   glBegin(GL_LINES);
      //cor das linhas
      glColor3f(0.4, 0.4, 0.4);
      //eixo x
      glVertex3f(-0.99, 0.0, 0.0);
      glVertex3f(10, 0, 0);
      //eixo y
      glVertex3f(0.0, -2, 0.0);
      glVertex3f(0.0, 2, 0);
   glEnd();

   glBegin(GL_LINE_STRIP);
      int intervalo = 180;
      float res;
      glColor3f(0.0, 1.0, 0.0);
      for(float i = 0.0; i<=2*M_PI; i=i+((2*M_PI)/intervalo)){
         res = sin(i);
         glVertex3f(i,res, 0.0);
      }
   glEnd();

   glBegin(GL_LINE_STRIP);
      glColor3f(1.0, 1.0, 0.0);
      for(float i = 0.0; i<=2*M_PI; i=i+((2*M_PI)/intervalo)){
         res = cos(i);
         glVertex3f(i,res, 0.0);
      }
   glEnd();


   // N�o esperar!
   glFlush ();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();

   if (w <= h)
      glOrtho (-1, 1, -1*(GLfloat)h/(GLfloat)w, 1*(GLfloat)h/(GLfloat)w, -10.0, 10.0);
   else
      glOrtho (-1*(GLfloat)w/(GLfloat)h, 1*(GLfloat)w/(GLfloat)h, -1, 1, -10.0, 10.0);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void init (void)
{
   // selecionar cor de fundo (preto)
   glClearColor (0.0, 0.0, 0.0, 0.0);
}

void keyboard(unsigned char key, int x, int y)
{
   switch (key)
   {
      case 27:
         exit(0);
      break;
   }
}