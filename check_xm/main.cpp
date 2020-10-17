#include <cstdio>
#include<GL/gl.h>
#include <GL/glut.h>

void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT);
glColor3ub (128, 100, 100);
glPointSize(9.0);

glBegin(GL_POINTS);
glVertex2i(100, 50);
glVertex2i(110, 130);
glVertex2i(250, 130);
glEnd();

//glBegin(GL_LINES);
//glVertex2f(100,200);
//glVertex2f(100,200);
//glVertex2f(100,200);

//glVertex2f(100,200);
//glVertex2f(300,200);
//glEnd();

glBegin(GL_POLYGON);
glVertex2f(100,100);
glVertex2f(100,100);
glVertex2f(200,100);
glVertex2f(150,200);
glEnd();

glBegin(GL_LINE_STRIP);
glVertex2f(100,200);
glVertex2f(100,200);
glVertex2f(300,200);
//glVertex2f(150,200);
glEnd();



/*glBegin(GL_TRIANGLES);
glVertex2f(100,100);
glVertex2f(100,100);
glVertex2f(200,100);
glVertex2f(150,200);
glEnd();
*/
glFlush ();
}

void myInit (void)
{
glClearColor(0.0, 1.0, 0.0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 640.0, 0.0, 480.0);
//gluOrtho2D(-1, 1, -1, 1);

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
