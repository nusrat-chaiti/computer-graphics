#include <cstdio>
#include <GL/gl.h>
#include <GL/glut.h>

void Mydisplay(void)
{
 glClear (GL_COLOR_BUFFER_BIT);
  for(int i = 0;i < 8;i++ )
    {
      for(int j = 0;j < 8;j++ )
      {

          glBegin(GL_POLYGON);
          if((i%2) == 0)
            {
               if((j%2) == 0)
               {
                  glColor3f (1, 1, 1);
               }
              else{

                glColor3f (0, 0, 0);
              }
           }
           else
           {
           if((j%2) == 0)
            {
              glColor3f (0, 0, 0);
            }
           else{
             glColor3f (1, 1, 1);
               }
            }

 glVertex2f (i,j);
 glVertex2f (i+1,j);
 glVertex2f (i+1,j+1);
 glVertex2f (i,j+1);
 glEnd();
 }
 }
 glFlush ();
}
void Myinit (void)
{glClearColor (0.0, 0.0, 0.0, 0.0);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D(0.0, 8.0, 0.0, 8.0);

}
int main(int argc, char** argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize (640, 480);
 glutInitWindowPosition (100, 150);
 glutCreateWindow ("Chess_Board");
 glutDisplayFunc(Mydisplay);
  Myinit ();

 glutMainLoop();
 //return 0;
}
