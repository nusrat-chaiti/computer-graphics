#include <cstdio>
#include<GL/gl.h>
#include <GL/glut.h>

void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT);
glColor3ub (128, 128, 128);
glPointSize(5.0);

glBegin(GL_QUADS);
glVertex2i(280,400);
glVertex2i(380,400);
glVertex2i(380,380);
glVertex2i(280,380);

glEnd();

glBegin(GL_QUADS);
glVertex2i(260,380);
glVertex2i(260,360);
glVertex2i(400,360);
glVertex2i(400,380);

glEnd();

glBegin(GL_QUADS);
glVertex2i(240,360);
glVertex2i(240,340);
glVertex2i(280,340);
glVertex2i(280,360);

glEnd();

glBegin(GL_QUADS);
glVertex2i(220,340);
glVertex2i(220,320);
glVertex2i(300,320);
glVertex2i(300,340);

glEnd();

glBegin(GL_QUADS);
glVertex2i(200,320);
glVertex2i(200,300);
glVertex2i(280,300);
glVertex2i(280,320);

glEnd();

glBegin(GL_QUADS);
glVertex2i(200,300);
glVertex2i(200,220);
glVertex2i(270,220);
glVertex2i(270,300);

glEnd();

glBegin(GL_QUADS);
glVertex2i(270,240);
glVertex2i(270,220);
glVertex2i(280,220);
glVertex2i(280,240);

glEnd();

glBegin(GL_QUADS);
glVertex2i(220,220);
glVertex2i(220,200);
glVertex2i(300,200);
glVertex2i(300,220);

glEnd();

glBegin(GL_QUADS);
glVertex2i(240,200);
glVertex2i(240,180);
glVertex2i(280,180);
glVertex2i(280,200);

glEnd();

glBegin(GL_QUADS);
glVertex2i(260,180);
glVertex2i(260,160);
glVertex2i(400,160);
glVertex2i(400,180);

glEnd();

glBegin(GL_QUADS);
glVertex2i(280,160);
glVertex2i(280,140);
glVertex2i(380,140);
glVertex2i(380,160);

glEnd();

glBegin(GL_QUADS);
glVertex2i(380,200);
glVertex2i(380,180);
glVertex2i(420,180);
glVertex2i(420,200);

glEnd();

glBegin(GL_QUADS);
glVertex2i(360,220);
glVertex2i(360,200);
glVertex2i(440,200);
glVertex2i(440,220);

glEnd();

glBegin(GL_QUADS);
glVertex2i(370,240);
glVertex2i(370,220);
glVertex2i(460,220);
glVertex2i(460,240);

glEnd();

glBegin(GL_QUADS);
glVertex2i(390,300);
glVertex2i(390,240);
glVertex2i(460,240);
glVertex2i(460,300);

glEnd();

glBegin(GL_QUADS);
glVertex2i(370,320);
glVertex2i(370,300);
glVertex2i(460,300);
glVertex2i(460,320);

glEnd();

glBegin(GL_QUADS);
glVertex2i(360,340);
glVertex2i(360,320);
glVertex2i(440,320);
glVertex2i(440,340);

glEnd();

glBegin(GL_QUADS);
glVertex2i(370,360);
glVertex2i(370,340);
glVertex2i(410,340);
glVertex2i(410,360);

glEnd();

glBegin(GL_QUADS);
glVertex2i(320,320);
glVertex2i(330,320);
glVertex2i(330,300);
glVertex2i(320,300);

glEnd();

glBegin(GL_QUADS);
glVertex2i(310,300);
glVertex2i(310,290);
glVertex2i(340,290);
glVertex2i(340,300);

glEnd();

glBegin(GL_QUADS);
glVertex2i(300,290);
glVertex2i(300,270);
glVertex2i(350,270);
glVertex2i(350,290);

glEnd();

glBegin(GL_QUADS);
glVertex2i(310,270);
glVertex2i(310,250);
glVertex2i(340,250);
glVertex2i(340,270);

glEnd();

glBegin(GL_QUADS);
glVertex2i(320,250);
glVertex2i(320,230);
glVertex2i(330,230);
glVertex2i(330,250);

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
glutCreateWindow ("mid_lab_exam");
glutDisplayFunc(myDisplay);
myInit ();
glutMainLoop();
}
