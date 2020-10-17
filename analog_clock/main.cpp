#include <GL/gl.h>
#include <GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
float x,y,i;
float counter=0.0;
float counter_m=0.0;
float counter_h=0.0;

void clock(void)
{
	glClearColor(0.0,1.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    //main circle
    glPushMatrix();
	glBegin(GL_TRIANGLE_FAN);
		glColor3ub(192,192,192);
		for(i=0;i<=2*3.14;i+=0.0001)
		{
			x=0.8*sin(i);
			y=0.8*cos(i);
			glVertex2f(x,y);
		}
	glEnd();
    glPopMatrix();

    //main circle-2

    glPushMatrix();
	glBegin(GL_TRIANGLE_FAN);
		glColor3ub(0,102,204);
		for(i=0;i<=2*3.14;i+=0.0001)
		{
			x=0.7*sin(i);
			y=0.7*cos(i);
			glVertex2f(x,y);
		}
	glEnd();
    glPopMatrix();

    //lines-second

	glPushMatrix();
	glRotatef(counter,0.0,0.0,-1.0);
	counter+=0.08;
	glBegin(GL_QUAD_STRIP);
		glColor3ub(255,0,0);
		glVertex2f(0,0);
		glVertex2f(0,0.8);
		glVertex2f(0.02,0);
        glVertex2f(0.02,0.8);




	glEnd();
	glPopMatrix();

	//lines for min

       glPushMatrix();
	  glRotatef(counter_m,0.0,0.0,-1.0);
	  counter_m+=0.001333333;

	    glBegin(GL_QUADS);
		glColor3ub(0,0,0);
		glVertex2f(0,0);
		glVertex2f(0.55,0.45);
		glVertex2f(0.55,0.47);
        glVertex2f(0.0,0.02);




	glEnd();
	glPopMatrix();




     //lines for hour

     glPushMatrix();
	glRotatef(counter_h,0.0,0.0,-1.0);
	counter_h+=0.0002733333;
	glBegin(GL_QUADS);
		glColor3ub(0,204,204);
		glVertex2f(0,0);
		glVertex2f(-0.35,0.45);
		glVertex2f(-0.35,0.47);
        glVertex2f(0.0,0.02);




	glEnd();
	glPopMatrix();


	glPushMatrix();
	glBegin(GL_TRIANGLE_FAN);
		glColor3ub(0,0,102);
		for(i=0;i<=2*3.14;i+=0.0001)
		{
			x=0.1*sin(i);
			y=0.1*cos(i);
			glVertex2f(x,y);
		}
	glEnd();
    glPopMatrix();

    glPushMatrix();
	glBegin(GL_TRIANGLE_FAN);
		glColor3ub(192,192,192);
		for(i=0;i<=2*3.14;i+=0.0001)
		{
			x=0.07*sin(i);
			y=0.07*cos(i);
			glVertex2f(x,y);
		}
	glEnd();
    glPopMatrix();

	glutSwapBuffers();
}
int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
	glutInitWindowSize(640,480);
	glutCreateWindow("clock");
	glutDisplayFunc(clock);
	glutIdleFunc(clock);
	glutMainLoop();
	return 0;
}
