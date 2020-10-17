#include <cstdio>
#include<GL/gl.h>
#include <GL/glut.h>

void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT);
glColor3ub (128, 128, 128);
glPointSize(5.0);

glBegin(GL_LINES);
glVertex2i(320,0);
glVertex2i(320, 480);
glVertex2i(0, 240);
glVertex2i(640, 240);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2i(50, 70);
glVertex2i(160, 70);
glVertex2i(90, 180);
glEnd();


glBegin(GL_LINES);
glVertex2i(360,50);
glVertex2i(360, 150);
glVertex2i(490, 50);
glVertex2i(490, 150);
glVertex2i(490, 100);
glVertex2i(360, 100);


glEnd();



glBegin(GL_LINES);
glVertex2i(360,280);
glVertex2i(490, 380);
glVertex2i(490, 280);
glVertex2i(360, 380);
glEnd();

/*glBegin(GL_LINES);
glVertex2i(50,380);
glVertex2i(50, 280);
glVertex2i(50, 280);
glVertex2i(160, 280);
glVertex2i(160, 280);
glVertex2i(160, 380);
glVertex2i(160, 380);
glVertex2i(50, 380);
glEnd();*/

glBegin(GL_QUAD_STRIP);
glVertex2i(50,280);
glVertex2i(50, 380);
glVertex2i(160, 280);
glVertex2i(160, 380);
glEnd();

glFlush ();
}

void myInit (void)
{
glClearColor(0.0, 0.0, 0.0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}





int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (640, 480);
glutInitWindowPosition (100, 150);
glutCreateWindow ("");
glutDisplayFunc(myDisplay);
myInit ();
glutMainLoop();
}
