#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

float shoulder = 0.0f, elbow = 0.0f, arm = 0.0f;
float garra = 0.0f;

int selected = 1;

void init(void)
{
	printf("Pressione as setas direita e esquerda para mover o braco.\n");
	printf("Selecione as teclas 1 e 2 para escolher o segmento a ser movido.\n");
	printf("Pressione ESC para sair.\n");

   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_SMOOTH);

   glEnable(GL_LIGHT0);                   
   glEnable(GL_COLOR_MATERIAL);          
   glColorMaterial(GL_FRONT, GL_DIFFUSE);

   glEnable(GL_LIGHTING);               
   glEnable(GL_DEPTH_TEST);             
   glEnable(GL_CULL_FACE);               
}

void desenhaEixos()
{
	glDisable(GL_LIGHTING);
   glBegin(GL_LINES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(10.0f, 0.0f, 0.0f);

		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 10.0f, 0.0f);

		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 10.0f);
   glEnd();
	glEnable(GL_LIGHTING);
}

void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   desenhaEixos();
	glColor3f(1.0f, 1.0f, 0.0f);

   glPushMatrix();
		glRotatef (shoulder, 0.0, 0.0, 1.0); // rota��o inicial da base (ombro) do bra�o
		glTranslatef (1.0, 0.0, 0.0); // Translada 1.0, pois o bra�o ter� 2.0 de comprimento
		glPushMatrix();
			glScalef (2.0, 0.5, 0.5);
			glutSolidCube (1.0);
		glPopMatrix();
      
		glTranslatef (1.0, 0.0, 0.0); // origem posicionada no cotovelo
		glRotatef (elbow, 0.0, 0.0, 1.0); // faz rota��o em rela��o ao cotovelo
		glTranslatef (1.0, 0.0, 0.0); // posiciona antebra�o de tamanho 2 na posi��o correta
		glPushMatrix();
			glScalef (2.0, 0.5, 0.5);
			glutSolidCube (1.0);
		glPopMatrix();

      glTranslatef (1.0, 0.0, 0.0);
      glRotatef (arm, 0.0, 0.0, 1.0);
      glTranslatef (1.0, 0.0, 0.0);
      glPushMatrix();
         glScalef (2.0, 0.5, 0.5);
         glutSolidCube (1.0);
      glPopMatrix();


      glColor3f(5.0,0.0,0.0);//Cor das garras
      

      if(garra<0)//limita pra que a garra nao se feche demais
         garra = 0;
      else if (garra>45)//limita que a garra nao abra demais
         garra = 45;

      glPushMatrix();//matriz do braço da garra de cima
         glTranslatef (1.0, 0.0, 0.0);
         glRotatef (garra, 0.0, 0.0, 1.0); //angulo da garra de cima
         glTranslatef (0.4, 0.0, 0.0);
         glPushMatrix();
            glRotatef (30.0, 0.0, 0.0, 1.0);
            glTranslatef (0.0, 0.3, 0.0);
            glScalef (0.8, 0.2, 0.3);
            glutSolidCube (1.0);
         glPopMatrix();

         glTranslatef (0.3, 0.0, 0.0);
         glPushMatrix();
            glRotatef (-35.0, 0.0, 0.0, 1.0);
            glTranslatef (0.0, 0.3, 0.0);
            glScalef (0.8, 0.2, 0.3);
            glutSolidCube (1.0);
         glPopMatrix();
      glPopMatrix();

      glPushMatrix(); //matriz do braço da garra de baixo
         glTranslatef (1.0, 0.0, 0.0);
         glRotatef (garra*-1, 0.0, 0.0, 1.0); //angulo da garra de baixo
         glTranslatef (0.4, 0.0, 0.0);
         glPushMatrix();
            glRotatef (-30.0, 0.0, 0.0, 1.0);
            glTranslatef (0.0, -0.3, 0.0);
            glScalef (0.8, 0.2, 0.3);
            glutSolidCube (1.0);
         glPopMatrix();

         glTranslatef (0.3, 0.0, 0.0);
         glPushMatrix();
            glRotatef (35.0, 0.0, 0.0, 1.0);
            glTranslatef (0.0, -0.3, 0.0);
            glScalef (0.8, 0.2, 0.3);
            glutSolidCube (1.0);
         glPopMatrix();
      glPopMatrix();

   glPopMatrix(); // origem volta para o sistema de coordenadas original
   glutSwapBuffers();
}

void reshape (int w, int h)
{
   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 200.0);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity ();
   gluLookAt (9.0, 9.0, 9.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void keyboard (unsigned char key, int x, int y)
{
   switch (key)
   {
   case '1':
		selected = 1;
   break;
   case '2':
		selected = 2;
	break;
   case '3':
      selected = 3;
   break;
   case 27:
      exit(0);
      break;
   default:
      break;
   }
}

// Special Keys callback
void specialKeys(int key, int x, int y)
{
   switch(key)
   {
      case GLUT_KEY_LEFT:
			if(selected == 1) shoulder = ((int) shoulder + 5) % 360;
			if(selected == 2) elbow = ((int) elbow + 5) % 360;
         if(selected == 3) arm = ((int) arm + 5) % 360;
      break;
      case GLUT_KEY_RIGHT:
			if(selected == 1) shoulder = ((int) shoulder - 5) % 360;
			if(selected == 2) elbow = ((int) elbow - 5) % 360;
         if(selected == 3) arm = ((int) arm - 5) % 360;
      break;
      case GLUT_KEY_UP:
            garra = ((int) garra + 5) % 360;
      break;
      case GLUT_KEY_DOWN:
            garra = ((int) garra - 5) % 360;
      break;


   }
   glutPostRedisplay();
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize (640, 640);
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutSpecialFunc( specialKeys );
   glutMainLoop();
   return 0;
}
