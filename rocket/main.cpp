#include<windows.h>
#include <GL/glut.h>
#include<math.h>
#include<cstdio>

void myInit(void)
{
glClearColor(0.0, 1.0, 1.0, 0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(-1.0, 1.0, -1.0, 1.0 );

}



void Circle(GLfloat cx, GLfloat cy,GLfloat cz, GLfloat radius,int r,int g,int b)
{
	int triangleAmount = 40; //# of triangles used to draw circle
	GLfloat twicePi = 2.0f * 3.1416;
    int counter=0;
    glColor3ub(r,g,b);
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(cx, cy,cz); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			counter+=1;
			glVertex3f(
		            cx + (radius * cos(i *  twicePi / triangleAmount)),
			    cy + (radius * sin(i * twicePi / triangleAmount)),cz
			);
		}
	glEnd();
}


GLfloat position = 0.0f;
GLfloat position_R = 0.0f;

GLfloat position_B = 0.0f;


GLfloat speed = 0.079f;
GLfloat speed_R = 0.071f;

GLfloat speed_B = 0.071f;




void update(int value) {

    if(position > 1.0)
        position = -1.2f;

    position += speed;

     if(position_R > 1.0)
        position_R = -1.2f;
    position_R += speed_R;

 if(position_B > 1.0)
        position_B = -1.2f;
    position_B += speed_B;
   glutPostRedisplay();


	glutTimerFunc(100, update, 0);
}

/*void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			speed += 0.1f;
			printf("clicked at (%d, %d)\n", x, y);
		}
	}

	glutPostRedisplay();
}*/

void handleKeypress(unsigned char key, int x, int y) {

	switch (key) {

case 'L':
    speed_R -= 0.1f;
    if(position_R < -1.0)
        position_R = 1.2f;
    position_R -= speed_R;

    break;
case 'R':
    speed_R += 0.1f;
    if(position_R > 1.0)
        position_R = -1.2f;
    position_R += speed_R;
    break;


glutPostRedisplay();


	}
}
void bullet()
{
     glPushMatrix();
   glTranslatef(0.0f,position_B, 0.0f);

    Circle(-0.03f,0.015f,0.0f,0.019f,0,0,153);
    glPopMatrix();


}


void rocket()
{

   glPushMatrix();
   glTranslatef(position_R,0.0f, 0.0f);

    Circle(-0.03f,0.015f,0.0f,0.019f,0,0,153);

     glBegin(GL_QUADS);
      glColor3ub(255,102,102);

      glVertex2f(-0.1f, -0.19f);
      glVertex2f(-0.1f, -0.72f);
      glVertex2f(0.04f, -0.72f);

      glVertex2f(0.04f, -0.19f);


      glEnd();

       glBegin(GL_TRIANGLES);
      glColor3ub(204,0,0);

      glVertex2f(-0.03f, 0.015f);
      glVertex2f(-0.1f, -0.19f);
      glVertex2f(0.04f, -0.19f);



      glEnd();

       glBegin(GL_TRIANGLES);
      glColor3ub(204,255,255);

      glVertex2f(0.04f, -0.19f);
      glVertex2f(0.04f, -0.33f);
      glVertex2f(0.16f, -0.33f);



      glEnd();


       glBegin(GL_TRIANGLES);
      glColor3ub(204,255,255);

      glVertex2f(-0.1f, -0.19f);
      glVertex2f(-0.22f, -0.33f);
      glVertex2f(-0.1f, -0.33f);



      glEnd();

       glBegin(GL_TRIANGLES);
      glColor3ub(204,0,0);

      glVertex2f(0.04f, -0.44f);
      glVertex2f(0.04f, -0.72f);
      glVertex2f(0.16f, -0.72f);



      glEnd();

       glBegin(GL_TRIANGLES);
      glColor3ub(204,0,0);

      glVertex2f(-0.1f, -0.44f);
      glVertex2f(-0.22f, -0.72f);
      glVertex2f(-0.1f, -0.72f);



      glEnd();

       glBegin(GL_POLYGON);
      glColor3ub(204,204,0);

      glVertex2f(-0.1f, -0.72f);
      glVertex2f(-0.20f, -0.79f);
      glVertex2f(-0.03f, -0.91f);

      glVertex2f(0.13f, -0.79f);
      glVertex2f(0.04f, -0.72f);



      glEnd();


glPopMatrix();


}

void triangle_obj()
{
     glPushMatrix();
    glTranslatef(0,position,0);
     glBegin(GL_TRIANGLES);
      glColor3ub(255,153,153);

      glVertex2f(0.4f, 0.4f);
      glVertex2f(0.5f, 0.4f);
      glVertex2f(0.45f, 0.6f);



      glEnd();

       glBegin(GL_TRIANGLES);
      glColor3ub(0,0,204);

      glVertex2f(-0.25f, 0.7f);
      glVertex2f(-0.3f, 0.5f);
      glVertex2f(-0.2f, 0.5f);



      glEnd();

       glBegin(GL_TRIANGLES);
      glColor3ub(204,0,102);

      glVertex2f(-0.55f, 0.6f);
      glVertex2f(-0.6f, 0.4f);
      glVertex2f(-0.5f, 0.4f);



      glEnd();
          glPopMatrix();

}

void myDisplay(void)
{

glClear(GL_COLOR_BUFFER_BIT);
glLoadIdentity();
rocket();
triangle_obj();
bullet();



glFlush();  // Render now


}


int main(int iArgc, char** cppArgv)

{

glutInit(&iArgc, cppArgv);

glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

glutInitWindowSize(640,480);

glutInitWindowPosition(50, 150);

glutCreateWindow("rocket ");


glutDisplayFunc(myDisplay);

myInit();
glutKeyboardFunc(handleKeypress);
//glutMouseFunc(handleMouse);
glutTimerFunc(1000, update, 0);

glutMainLoop();

return 0;

}







