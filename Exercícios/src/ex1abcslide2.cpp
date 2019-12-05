#include <stdio.h>
#include <GL/glut.h>

void display(void);
void init (void);
void keyboard(unsigned char key, int x, int y);

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (450, 450);
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("Quad Color Test");
   init ();
   glutDisplayFunc(display);
   glutKeyboardFunc(keyboard);

	printf("Pressione ESC para fechar.\n");

   glutMainLoop();

   return 0;
}

// � a rotina chamada automaticamente sempre que a
// janela ou parte dela precisa ser redesenhada
void display(void)
{
   // Limpar todos os pixels
   glClear (GL_COLOR_BUFFER_BIT);

   glColor3f(1.0,1.0,0.0);
   
   glBegin(GL_LINE_LOOP);
        glVertex2f(0.4f, 0.0f);
        glVertex2f(0.6f, 0.4f);
        glVertex2f(0.8f, 0.0f); 
   glEnd();

   glBegin(GL_TRIANGLES);
        glVertex2f(0, 0);
        glVertex2f(0.2f, -0.4f);
        glVertex2f(0.4f, 0); 
   glEnd();
    
    glBegin(GL_LINES);
      glColor3f (1.0, 0.0, 0.0);
      glVertex3f(-10.0, 0.0, 0.0);
      glVertex3f( 10.0, 0.0, 0.0);
      glColor3f (  0.0,   1.0, 0.0);
      glVertex3f(0.0, -10.0, 0.0);
      glVertex3f(0.0,  10.0, 0.0);
   glEnd();
   /*
   glBegin(GL_LINE_STRIP);
        glVertex2f(-0.2f, 0.4f);
        glVertex2f(-0.4f, 0.f);
        glVertex2f(-0.2f, -0.4f);
        glVertex2f(0.2f, -0.4f);
        glVertex2f(0.4f, 0.0f);
        glVertex2f(0.2f, 0.4f);
   glEnd();
   */

   glutSwapBuffers ();
}

void init (void)
{
   // selecionar cor de fundo (preto)
   glClearColor (0.0, 0.0, 0.0, 0.0);

   // inicializar sistema de viz.
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

   glMatrixMode(GL_MODELVIEW); // Select The Modelview Matrix
   glLoadIdentity();           // Inicializa com matriz identidade
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