

#include <GL/gl.h>
#include <GL/glut.h>


#include <iostream>
using namespace std;

int x1, y1, x2, y2;


void myInit() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 640, 0, 480);
    glColor3f(0.0, 1.0, 0.0);
}

void draw_pixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void draw_line(int x1, int x2, int y1, int y2) {
    int incx = 1, incy = 1;

    int dx = x2 - x1;
    int dy = y2 - y1;
    int pk= 2*dy-dx;
    if (pk>=0)
    {
        x1++;
        y1++;
        draw_pixel(x1,y1);
    }
    else if(pk<0)
    {
        x1++;
        y1=y1;
        draw_pixel(x1,y1);

    }
   for(int i=0;i<dx;i++)
   {
        int pk1=pk+2*dy-2*dx*(y1-(y1-1));
    if (pk1>=0)
    {
        x1++;
        y1++;

        draw_pixel(x1,y1);

    }
    else if(pk1<0)
    {
         x1++;
        y1=y1;
        draw_pixel(x1,y1);


    }
   }



}

void myDisplay() {
    draw_line(x1, x2, y1, y2);
    glFlush();
}



int main(int argc, char **argv) {

    cout << "Enter (x1, y1), (x2, y2)" << endl;
   cin >> x1 >> y1 >> x2 >> y2;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("mid point line  algorithm");
    myInit();
    glutDisplayFunc(myDisplay);

    glutMainLoop();

    return 0;
}
