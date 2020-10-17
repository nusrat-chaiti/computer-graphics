#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
void myDisplay(void){glClear (GL_COLOR_BUFFER_BIT);

glPointSize(4.0);

//glBegin(GL_POINTS);
//glVertex2i(100, 50);
//glVertex2i(100, 130);
//glVertex2i(150, 130);

/*glBegin(GL_LINE_LOOP);
glVertex2i(200,150);
glVertex2i(200,100);
glVertex2i(260,70);

glVertex2i(270, 80);
//glVertex2i(260, 250);

glVertex2i(280, 80);
glVertex2i(310, 70);

glVertex2i(340,80);
glVertex2i(350,80);
glVertex2i(360,70);

glVertex2i(410,100);
glVertex2i(410,150);
glVertex2i(350, 250);

glVertex2i(350, 150);
glVertex2i(320,150);
glVertex2i(320,250);

glVertex2i(290, 250);
glVertex2i(290, 150);
glVertex2i(260, 150);

glVertex2i(260, 250);*/

glBegin(GL_POLYGON);
glColor3ub (0, 0, 0);
glVertex2i(80,290);
glVertex2i(80,150);
glVertex2i(230,30);
glVertex2i(390,30);

glVertex2i(530,150);
glVertex2i(530,290);
glVertex2i(390,420);
glVertex2i(230,420);

glEnd();

glBegin(GL_POLYGON);
glColor3ub (255, 255, 0);
glVertex2i(100,290);
glVertex2i(100,150);
glVertex2i(230,50);
glVertex2i(390,50);

glVertex2i(510,150);
glVertex2i(510,290);
glVertex2i(390,400);
glVertex2i(230,400);

glEnd();

glColor3ub (0, 0, 0);
glBegin(GL_QUADS);
glVertex2i(280,340);
glVertex2i(280,290);
glVertex2i(340,290);
glVertex2i(340,340);
glEnd();

glBegin(GL_QUADS);
glVertex2i(230,290);
glVertex2i(230,150);
glVertex2i(390,150);
glVertex2i(390,290);

glEnd();

glBegin(GL_TRIANGLE_STRIP);
glVertex2i(290,150);
glVertex2i(310,100);
glVertex2i(340,150);
glEnd();

glBegin(GL_TRIANGLE_STRIP);
glVertex2i(230,340);
glVertex2i(150,250);
glVertex2i(230,250);

glEnd();

glBegin(GL_QUADS);
glVertex2i(150,250);
glVertex2i(150,190);
glVertex2i(230,190);
glVertex2i(230,290);


glEnd();

glBegin(GL_TRIANGLE_STRIP);
glVertex2i(150,190);
glVertex2i(230,100);
glVertex2i(230,190);

glEnd();
glBegin(GL_TRIANGLE_STRIP);
glVertex2i(390,340);
glVertex2i(390,250);
glVertex2i(470,250);

glEnd();

glBegin(GL_TRIANGLE_STRIP);
glVertex2i(390,190);
glVertex2i(390,100);
glVertex2i(470,190);

glEnd();

glBegin(GL_QUADS);
glVertex2i(390,250);
glVertex2i(390,190);
glVertex2i(470,190);
glVertex2i(470,250);
glEnd();

glBegin(GL_QUADS);
glVertex2i(280,360);
glVertex2i(280,340);
glVertex2i(295,340);
glVertex2i(295,360);
glEnd();

glBegin(GL_QUADS);
glVertex2i(325,360);
glVertex2i(325,340);
glVertex2i(340,340);
glVertex2i(340,360);
glEnd();




glFlush ();
}
void myInit (void)
{glClearColor(1.0, 1.0, 1.0, 0.0);
glColor3f(0.0f, 0.0f, 0.0f);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 640.0, 0.0, 480.0);}
int main(int argc, char** argv)
{glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (640, 480);
glutInitWindowPosition (100, 150);
glutCreateWindow ("my first attempt");
glutDisplayFunc(myDisplay);
myInit ();
glutMainLoop();
}
