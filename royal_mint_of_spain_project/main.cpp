#include<windows.h>
#include<mmsystem.h>
#include <GL/glut.h>
#include<math.h>
# define PI           3.14159265358979323846


void myInit(void)
{
glClearColor(0.0, 0.8, 1.0, 1.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(-1.0, 1.0, -0.8, 0.8 );
glLoadIdentity();

}


void rainf()
{
    int x=0;
    int y=1.5;
    static float a=-1.0f;
    if(a<=-1.5)
    {
         a=-1.0f;

    }
    else
    {
        a-=0.05f;
        //glColor3ub(r,g,b);
    }
    glColor3ub(255,255,255);
    glPushMatrix();
    glTranslatef(0.0f,a,0.0f);
    glBegin(GL_LINES);
    for(int i=500;i>=0;i--)
    {
        for(int j=0;j<=i;j++)
        {
            glVertex3i(x,y,0);
            glVertex3i(x+3,y+10,0);
            x+=rand()%1050;
        }
        y+=rand()%15;
        x=0;

    }
    glEnd();
    glPopMatrix();
    glutPostRedisplay();

}

void HCircle(GLfloat cx, GLfloat cy,GLfloat cz, GLfloat radius,int r,int g,int b)
{
	int triangleAmount = 40;
	GLfloat twicePi = 2.0f * 3.1416;
    int counter=0;
    glColor3ub(r,g,b);
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(cx, cy,cz);
		for(int i = 0; i <= triangleAmount;i++) {
			counter+=1;
			glVertex3f(
		            cx + (radius * 1.5*cos(i *  twicePi / triangleAmount)),
			    cy + (radius * sin(i * twicePi / triangleAmount)),cz
			);
		}
	glEnd();
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

void CloudCircle(GLfloat cx, GLfloat cy,GLfloat cz, GLfloat radius,int r,int g,int b, int c)
{
	int triangleAmount = 40; //# of triangles used to draw circle
	GLfloat twicePi = 2.0f * 3.1416;
    int counter=0;

    glColor4ub(r,g,b,c);
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


//car movement

//cloud movement
GLfloat position = 0.0f;
GLfloat cloud_position = 0.20f;
GLfloat cloud_position_1 = 0.19f;
GLfloat car3_pos = 0.0f;
GLfloat car4_pos = 0.78f;
GLfloat speed = 0.079f;
GLfloat cloud_speed = 0.008f;
GLfloat rainPos= -1.0;
GLfloat helicopterPos=1.2;
GLfloat poshuman2=-0.8;
void update(int value) {

    if(poshuman2>-0.05)
    {
        poshuman2=-1.0;
    }
    poshuman2+=0.01;
    if(helicopterPos<-1.0)
    {
        helicopterPos=1.2;
    }
    helicopterPos -=0.01f;
     if(rainPos<-1.0)
    {
        rainPos = -1.0;
    }
    rainPos -=1.47;


    if(position > 1.0)
        position = -1.2f;

    position += speed;

//cloud 1
    if(cloud_position > 1.5)
        cloud_position = -1.2f;
    cloud_position +=cloud_speed;
//cloud 2
    if(cloud_position_1 > 1.8)
        cloud_position_1 = -1.2f;
    cloud_position_1 +=cloud_speed;

    if(car3_pos < -1.0)
        car3_pos = 1.2f;

    car3_pos -= speed;

     if(car4_pos < -1.0)
        car4_pos = 1.2f;

    car4_pos -= speed;

	glutPostRedisplay();


	glutTimerFunc(100, update, 0);
}


void building()
{
    //full body
 glBegin(GL_QUADS);

      glColor3ub(255, 255, 255);
      glVertex2f(-0.50f, 0.0f);

      glColor3ub(212, 212, 212);
      glVertex2f(0.50f, 0.0f);

      glColor3ub(212, 212, 212);
      glVertex2f(0.5f, 0.36f);

      glColor3ub(255, 255, 255);
      glVertex2f(-0.5f, 0.36f);
glEnd();

//full body 4th floor inner line
glLineWidth(10.0);
glBegin(GL_LINES);
      glColor3ub(245, 245, 245);
      glVertex2f(-0.51f, 0.345f);

      glColor3ub(180, 180, 180);
      glVertex2f(0.51f, 0.345f);

glEnd();

//full body 4th floor line
glLineWidth(2.0);
glBegin(GL_LINES);

      glColor3ub(110,110,110);

      glVertex2f(-0.51f, 0.340f);
      glVertex2f(0.51f, 0.340f);

      glVertex2f(0.51f, 0.340f);
      glVertex2f(0.51f, 0.352f);

      glVertex2f(0.51f, 0.352f);
      glVertex2f(-0.51f, 0.352f);

      glVertex2f(-0.51f, 0.352f);
      glVertex2f(-0.51f, 0.340f);

glEnd();


//full body 4th floor line corner
glLineWidth(5.0);
glBegin(GL_LINES);

      glColor3ub(190, 190, 190);
      glVertex2f(-0.51f, 0.345f);
      glVertex2f(-0.50f, 0.33f);
      glVertex2f(0.51f, 0.345f);
      glVertex2f(0.50f, 0.33f);
glEnd();


//full body 3rd floor inner line
glLineWidth(10.0);
glBegin(GL_LINES);
       glColor3ub(245, 245, 245);
      glVertex2f(-0.51f, 0.29f);
      glColor3ub(180, 180, 180);
      glVertex2f(0.51f, 0.29f);

glEnd();
//full body 3rd floor outer line
glLineWidth(2.0);
glBegin(GL_LINES);

      glColor3ub(110, 110, 110);
      glVertex2f(-0.51f, 0.28f);
      glVertex2f(0.51f, 0.28f);

       glVertex2f(0.51f, 0.28f);
      glVertex2f(0.51f, 0.295f);

      glVertex2f(0.51f, 0.295f);
      glVertex2f(-0.51f, 0.295f);

      glVertex2f(-0.51f, 0.295f);
      glVertex2f(-0.51f, 0.28f);

      glVertex2f(-0.51f, 0.28f);
      glVertex2f(-0.50f, 0.26f);
      glVertex2f(0.51f, 0.28f);
      glVertex2f(0.50f, 0.26f);



glEnd();



//full body 2nd floor inner line
glLineWidth(10.0);
glBegin(GL_LINES);
       glColor3ub(245, 245, 245);
      glVertex2f(-0.51f, 0.15f);
      glColor3ub(180, 180, 180);
      glVertex2f(0.51f, 0.15f);

glEnd();
//full body 2nd floor outer line
glLineWidth(2.0);
glBegin(GL_LINES);

      glColor3ub(110, 110, 110);
      glVertex2f(-0.51f, 0.14f);
      glVertex2f(0.51f, 0.14f);

       glVertex2f(0.51f, 0.14f);
      glVertex2f(0.51f, 0.155f);

      glVertex2f(0.51f, 0.155f);
      glVertex2f(-0.51f, 0.155f);

      glVertex2f(-0.51f, 0.155f);
      glVertex2f(-0.51f, 0.14f);

glEnd();



//full body 1st floor inner line
glLineWidth(10.0);
glBegin(GL_LINES);
       glColor3ub(245, 245, 245);
      glVertex2f(-0.51f, 0.05f);
      glColor3ub(180, 180, 180);
      glVertex2f(0.51f, 0.05f);

glEnd();
//full body 1st floor outer line
glLineWidth(2.0);
glBegin(GL_LINES);

      glColor3ub(110, 110, 110);
      glVertex2f(-0.51f, 0.04f);
      glVertex2f(0.51f, 0.04f);

       glVertex2f(0.51f, 0.04f);
      glVertex2f(0.51f, 0.055f);

      glVertex2f(0.51f, 0.055f);
      glVertex2f(-0.51f, 0.055f);

      glVertex2f(-0.51f, 0.055f);
      glVertex2f(-0.51f, 0.04f);
glEnd();



//middle top box
glBegin(GL_QUADS);

       glColor3ub(255,255,255);

      glVertex2f(-0.123f, 0.28f);
      glVertex2f(0.123f, 0.28f);
       glColor3ub(250,250,250);

      glVertex2f(0.123f, 0.38f);
       glColor3ub(250,250,250);

      glVertex2f(-0.123f, 0.38f);



   glEnd();
//middle top
glBegin(GL_QUADS);

      glColor3f(0.8f, 0.8f, 0.8f);

      glVertex2f(-0.14f, 0.28f);
      glVertex2f(0.14f, 0.28f);
      glVertex2f(0.14f, 0.37f);
      glVertex2f(-0.14f, 0.37f);

   glEnd();





//middle middle box
glBegin(GL_QUADS);

      glColor3f(0.1f, 0.1f, 0.1f);

      glVertex2f(-0.03f, 0.3f);
      glVertex2f(0.03f, 0.3f);
      glVertex2f(0.03f, 0.34f);
      glVertex2f(-0.03f, 0.34f);



   glEnd();

//middle pillar box
glBegin(GL_QUADS);


      glColor3ub(255,255,255);
      glVertex2f(-0.158f, 0.25f);

      glColor3ub(172,172,172);
      glVertex2f(0.158f, 0.25);
      glVertex2f(0.158f, 0.281f);

      glColor3ub(172,172,172);
      glVertex2f(-0.158f, 0.281f);



   glEnd();

//middle pillar box line
glLineWidth(5.0);
glBegin(GL_LINES);

      glColor3ub(255,255,255);
      glVertex2f(-0.16f, 0.278f);

      glColor3ub(180,180,180);
      glVertex2f(0.16f, 0.278f);
   glEnd();


   //middle pillar box 2 top

glBegin(GL_POLYGON);

      glColor3f(0.81, 0.81f, 0.81f);

      glVertex2f(-.110f, 0.22f);
      glVertex2f(-.095f, 0.22f);
      glVertex2f(-.090f, 0.25f);
      glVertex2f(-.115f, 0.25f);
   glEnd();
//middle pillar box 2 middle

glBegin(GL_POLYGON);

      glColor3f(0.81, 0.81f, 0.81f);

      glVertex2f(-.110f, 0.038f);
      glVertex2f(-.095f, 0.038f);
      glVertex2f(-.095f, 0.22f);
      glVertex2f(-.110f, 0.22f);
   glEnd();

    //middle pillar box 3 top

glBegin(GL_POLYGON);

      glColor3f(0.81, 0.81f, 0.81f);

      glVertex2f(-.06f, 0.22f);
      glVertex2f(-.045f, 0.22f);
      glVertex2f(-.040f, 0.25f);
      glVertex2f(-.065f, 0.25f);
   glEnd();
//middle pillar box 3 middle

glBegin(GL_POLYGON);

      glColor3f(0.81, 0.81f, 0.81f);

      glVertex2f(-.06f, 0.038f);
      glVertex2f(-.045f, 0.038f);
      glVertex2f(-.045f, 0.22f);
      glVertex2f(-.06f, 0.22f);
   glEnd();

   //middle pillar box 4 top

glBegin(GL_POLYGON);

      glColor3f(0.81, 0.81f, 0.81f);

      glVertex2f(-.03f, 0.22f);
      glVertex2f(-.015f, 0.22f);
      glVertex2f(-.010f, 0.25f);
      glVertex2f(-.035f, 0.25f);
   glEnd();
//middle pillar box 4 middle

glBegin(GL_POLYGON);

      glColor3f(0.81, 0.81f, 0.81f);

      glVertex2f(-.03f, 0.038f);
      glVertex2f(-.015f, 0.038f);
      glVertex2f(-.015f, 0.22f);
      glVertex2f(-.03f, 0.22f);
   glEnd();

   //middle pillar box 5 top

glBegin(GL_POLYGON);

      glColor3ub(177,180,180);

      glVertex2f(0.03f, 0.22f);
      glVertex2f(0.015f, 0.22f);
      glVertex2f(0.010f, 0.25f);
      glVertex2f(0.035f, 0.25f);
   glEnd();
//middle pillar box 5 middle

glBegin(GL_POLYGON);

      glColor3ub(177,177,177);

      glVertex2f(0.03f, 0.038f);
      glVertex2f(0.015f, 0.038f);
      glVertex2f(0.015f, 0.22f);
      glVertex2f(0.03f, 0.22f);
   glEnd();


//middle pillar box 6 top

glBegin(GL_POLYGON);

      glColor3ub(177,180,180);

      glVertex2f(0.06f, 0.22f);
      glVertex2f(0.045f, 0.22f);
      glVertex2f(0.040f, 0.25f);
      glVertex2f(0.065f, 0.25f);
   glEnd();
//middle pillar box 6 middle

glBegin(GL_POLYGON);

      glColor3ub(177,177,177);

      glVertex2f(0.06f, 0.038f);
      glVertex2f(0.045f, 0.038f);
      glVertex2f(0.045f, 0.22f);
      glVertex2f(0.06f, 0.22f);
   glEnd();
//middle pillar box 7 top

glBegin(GL_POLYGON);

      glColor3ub(177,180,180);

      glVertex2f(0.110f, 0.22f);
      glVertex2f(0.095f, 0.22f);
      glVertex2f(0.090f, 0.25f);
      glVertex2f(0.115f, 0.25f);
   glEnd();
//middle pillar box 7 middle

glBegin(GL_POLYGON);

      glColor3ub(177,177,177);

      glVertex2f(0.110f, 0.038f);
      glVertex2f(0.095f, 0.038f);
      glVertex2f(0.095f, 0.22f);
      glVertex2f(0.110f, 0.22f);
   glEnd();


//middle pillar box 8 top

glBegin(GL_POLYGON);

      glColor3ub(177,180,180);

      glVertex2f(0.14f, 0.22f);
      glVertex2f(0.125f, 0.22f);
      glVertex2f(0.120, 0.25f);
      glVertex2f(0.145f, 0.25f);
   glEnd();
//middle pillar box 8 middle

glBegin(GL_POLYGON);

     glColor3ub(177,180,180);
      glVertex2f(0.14f, 0.048f);
      glVertex2f(0.125f, 0.048f);
      glVertex2f(0.125, 0.22f);

      glVertex2f(0.14f, 0.22f);
   glEnd();



//middle pillar box 8 bottom

glBegin(GL_POLYGON);

      glColor3ub(80, 80, 80);

      glVertex2f(.144f, 0.036f);
      glVertex2f(.121f, 0.036f);
      glVertex2f(.121, 0.048f);

      glVertex2f(.144f, 0.048f);
   glEnd();

   //middle pillar box 1 top

glBegin(GL_POLYGON);

      glColor3f(0.81, 0.81f, 0.81f);

      glVertex2f(-.14f, 0.22f);
      glVertex2f(-.125f, 0.22f);
      glVertex2f(-.120, 0.25f);

      glVertex2f(-.145f, 0.25f);
   glEnd();
//middle pillar box 1 middle

glBegin(GL_POLYGON);

      glColor3f(0.81, 0.81f, 0.81f);

      glVertex2f(-.14f, 0.048f);
      glVertex2f(-.125f, 0.048f);
      glVertex2f(-.125, 0.22f);

      glVertex2f(-.14f, 0.22f);
   glEnd();

//middle pillar box 1 bottom

glBegin(GL_POLYGON);

      glColor3f(0.0f, 0.0f, 1.0f);

      glVertex2f(-.144f, 0.036f);
      glVertex2f(-.121f, 0.036f);
      glVertex2f(-.121, 0.048f);

      glVertex2f(-.144f, 0.048f);
   glEnd();


// 4th floor left window outer border

float wx1,wx2,wy1,wy2;
wx1=-0.47; wx2=-0.44; wy1=0.3;wy2=0.335;
glColor3ub(180,180,180);
glBegin(GL_QUADS);
       for(int j=0; j<7;j++)
       {
          glVertex2f(wx1, wy1);
          glVertex2f(wx2, wy1);
          glVertex2f(wx2, wy2);
          glVertex2f(wx1, wy2);

          wx1=wx1+0.05;
          wx2=wx2+0.05;

       }

   glEnd();

// 4th floor left window inner border

glColor3ub(54,54,54);
float wix1=-0.467, wix2=-0.443, wiy1=0.301, wiy2=0.329;
glBegin(GL_QUADS);


        for(int j=0; j<7;j++)
       {
          glVertex2f(wix1, wiy1);
          glVertex2f(wix2, wiy1);
          glVertex2f(wix2, wiy2);
          glVertex2f(wix1, wiy2);

          wix1=wix1+0.05;
          wix2=wix2+0.05;

       }

   glEnd();

// 4th floor left window inner line

float wlx=-.454,wly1=0.301,wly2=0.3295;
glColor3ub(255,255,255);
glLineWidth(2.0);
glBegin(GL_LINES);

        for(int i=0; i<7; i++)
        {
            glVertex2f(wlx, wly1);
            glVertex2f(wlx, wly2);

            wlx=wlx+0.05;
        }

glEnd();


// 4th floor right window outer border

float wxr1=0.17,wxr2=0.14,wyr1=0.3,wyr2=0.335;
glColor3ub(180,180,180);
glBegin(GL_QUADS);

    for(int i=0; i<7; i++)
    {
      glVertex2f(wxr1, wyr1);
      glVertex2f(wxr2, wyr1);
      glVertex2f(wxr2, wyr2);
      glVertex2f(wxr1, wyr2);

      wxr1=wxr1+0.05;
      wxr2=wxr2+0.05;

    }


   glEnd();


// 4th floor right window inner border

float wixr1=0.168,wixr2=0.146,wiyr1=0.301,wiyr2=0.329;
 glColor3ub(54,54,54);
glBegin(GL_QUADS);

     for(int i=0; i<7; i++)
     {
          glVertex2f(wixr1, wiyr1);
          glVertex2f(wixr2, wiyr1);
          glVertex2f(wixr2, wiyr2);
          glVertex2f(wixr1, wiyr2);

          wixr1=wixr1+0.05;
          wixr2=wixr2+0.05;


     }
glEnd();

// 4th floor right window inner line

float wlxr=0.157,wlyr1=0.301,wlyr2=0.3295;
glLineWidth(2.0);
glColor3ub(255,255,255);
glBegin(GL_LINES);

    for(int i=0; i<7; i++)
    {

      glVertex2f(wlxr, wlyr1);
      glVertex2f(wlxr, wlyr2);

      wlxr=wlxr+0.05;
    }

glEnd();
//.......................

// 2nd floor left window outer border

float w2x1,w2x2,w2y1,w2y2;
w2x1=-0.47; w2x2=-0.44; w2y1=0.097;w2y2=0.132;
glColor3ub(180,180,180);
glBegin(GL_QUADS);
       for(int j=0; j<7;j++)
       {
          glVertex2f(w2x1, w2y1);
          glVertex2f(w2x2, w2y1);
          glVertex2f(w2x2, w2y2);
          glVertex2f(w2x1, w2y2);

          w2x1=w2x1+0.05;
          w2x2=w2x2+0.05;

       }

   glEnd();

// 2nd floor left window inner border

glColor3ub(54,54,54);
float w2ix1=-0.466, w2ix2=-0.444, w2iy1=0.098, w2iy2=0.127;
glBegin(GL_QUADS);


        for(int j=0; j<7;j++)
       {
          glVertex2f(w2ix1, w2iy1);
          glVertex2f(w2ix2, w2iy1);
          glVertex2f(w2ix2, w2iy2);
          glVertex2f(w2ix1, w2iy2);

          w2ix1=w2ix1+0.05;
          w2ix2=w2ix2+0.05;

       }

   glEnd();

// 2nd floor left window inner line

float w2x3=-.455,w2y3=0.098,w22y3=0.127;
glColor3ub(255,255,255);
glLineWidth(2.0);
glBegin(GL_LINES);

        for(int i=0; i<7; i++)
        {
            glVertex2f(w2x3, w2y3);
            glVertex2f(w2x3, w22y3);

            w2x3=w2x3+0.05;
        }

glEnd();

//.................................

// 2nd floor right window outer border

float w2rx1=0.17f,w2rx2=.14f,w2ry1= 0.097f,w2ry2=0.132f;
glColor3ub(180,180,180);
glBegin(GL_QUADS);

    for(int i=0; i<7; i++)
    {
      glVertex2f(w2rx1, w2ry1);
      glVertex2f(w2rx2, w2ry1);
      glVertex2f(w2rx2, w2ry2);
      glVertex2f(w2rx1, w2ry2);

      w2rx1=w2rx1+0.05;
      w2rx2=w2rx2+0.05;

    }


   glEnd();


// 2nd floor right window inner border

float w22rx1=0.168f,w22rx2=.146f,w22ry1=0.098f,w22ry2=0.127f;
 glColor3ub(54,54,54);
glBegin(GL_QUADS);

     for(int i=0; i<7; i++)
     {
          glVertex2f(w22rx1, w22ry1);
          glVertex2f(w22rx2, w22ry1);
          glVertex2f(w22rx2, w22ry2);
          glVertex2f(w22rx1, w22ry2);

          w22rx1=w22rx1+0.05;
          w22rx2=w22rx2+0.05;


     }
glEnd();

// 2nd floor right window inner line

float w222xr=.157f,w222yr1=0.098f,w222yr2=0.127f;
glLineWidth(2.0);
glColor3ub(255,255,255);
glBegin(GL_LINES);

    for(int i=0; i<7; i++)
    {

      glVertex2f(w222xr, w222yr1);
      glVertex2f(w222xr, w222yr2);

      w222xr=w222xr+0.05;
    }

glEnd();

//....................................................................

// 1st floor left window outer border

float w1x1,w1x2,w1y1,w1y2;
w1x1=-0.47; w1x2=-0.44; w1y1=0.005;w1y2=0.035;
glColor3ub(180,180,180);
glBegin(GL_QUADS);
       for(int j=0; j<7;j++)
       {
          glVertex2f(w1x1, w1y1);
          glVertex2f(w1x2, w1y1);
          glVertex2f(w1x2, w1y2);
          glVertex2f(w1x1, w1y2);

          w1x1=w1x1+0.05;
          w1x2=w1x2+0.05;

       }

   glEnd();

// 1st floor left window inner border

glColor3ub(54,54,54);
float w11x1=-0.467f, w11x2=-0.443f, w11y1=0.007f, w11y2=0.03f;
glBegin(GL_QUADS);


        for(int j=0; j<7;j++)
       {
          glVertex2f(w11x1, w11y1);
          glVertex2f(w11x2, w11y1);
          glVertex2f(w11x2, w11y2);
          glVertex2f(w11x1, w11y2);

          w11x1=w11x1+0.05;
          w11x2=w11x2+0.05;

       }

   glEnd();

// 1st floor left window inner line

float w11lx=-.454f,wl11y1=0.007f,wl11y2=0.03f;
glColor3ub(255,255,255);

glLineWidth(2.0);
glBegin(GL_LINES);

        for(int i=0; i<7; i++)
        {
            glVertex2f(w11lx, wl11y1);
            glVertex2f(w11lx, wl11y2);

            w11lx=w11lx+0.05;
        }

glEnd();


//........................................................................................................................................................


// 1st floor right window outer border

float w1rx1,w1rx2,w1ry1,w1ry2;
w1rx1=0.17; w1rx2=0.14; w1ry1=0.005;w1ry2=0.035;
glColor3ub(180,180,180);
glBegin(GL_QUADS);
       for(int j=0; j<7;j++)
       {
          glVertex2f(w1rx1, w1ry1);
          glVertex2f(w1rx2, w1ry1);
          glVertex2f(w1rx2, w1ry2);
          glVertex2f(w1rx1, w1ry2);

          w1rx1=w1rx1+0.05;
          w1rx2=w1rx2+0.05;

       }

   glEnd();

// 1st floor right window inner border

glColor3ub(54,54,54);
float w11rx1=0.168f, w11rx2=0.146f, w11ry1=0.007f, w11ry2=0.03f;
glBegin(GL_QUADS);


        for(int j=0; j<7;j++)
       {
          glVertex2f(w11rx1, w11ry1);
          glVertex2f(w11rx2, w11ry1);
          glVertex2f(w11rx2, w11ry2);
          glVertex2f(w11rx1, w11ry2);

          w11rx1=w11rx1+0.05;
          w11rx2=w11rx2+0.05;

       }

   glEnd();

// 1st floor right window inner line

float w11lrx=.157f,wl11ry1=0.007f,wl11ry2=0.03f;
glColor3ub(255,255,255);

glLineWidth(2.0);
glBegin(GL_LINES);

        for(int i=0; i<7; i++)
        {
            glVertex2f(w11lrx, wl11ry1);
            glVertex2f(w11lrx, wl11ry2);

            w11lrx=w11lrx+0.05;
        }

glEnd();


//.....................................................................................................

// 3rd floor left window outer border

float w3x1,w3x2,w3y1,w3y2;
w3x1=-0.47; w3x2=-0.44; w3y1=0.17f;w3y2=0.265f;
glColor3ub(180,180,180);
glBegin(GL_QUADS);
       for(int j=0; j<7;j++)
       {
          glVertex2f(w3x1, w3y1);
          glVertex2f(w3x2, w3y1);
          glVertex2f(w3x2, w3y2);
          glVertex2f(w3x1, w3y2);

          w3x1=w3x1+0.05;
          w3x2=w3x2+0.05;

       }

   glEnd();

// 3rd floor left window inner border

glColor3ub(54,54,54);
float w33x1=-0.467f, w33x2=-0.443f, w33y1=0.177f, w33y2=0.260f;
glBegin(GL_QUADS);


        for(int j=0; j<7;j++)
       {
          glVertex2f(w33x1, w33y1);
          glVertex2f(w33x2, w33y1);
          glVertex2f(w33x2, w33y2);
          glVertex2f(w33x1, w33y2);

          w33x1=w33x1+0.05;
          w33x2=w33x2+0.05;

       }

   glEnd();

   //3rd floor window 1 left inner middle x line

   glLineWidth(2.0);
   glColor3ub(255,255,255);
   float x1=-0.467f, x2=-0.443f, y1=0.238f;
   glBegin(GL_LINES);

          for(int j=0; j<7;j++ ){
             glVertex2f(x1, y1);
             glVertex2f(x2, y1);

             x1=x1+0.05;
             x2=x2+0.05;
          }

   glEnd();

// 3rd floor left window inner line

float w333x=-.454f,w333y1=0.177f,w333y2=0.260f;
glColor3ub(255,255,255);

glLineWidth(2.0);
glBegin(GL_LINES);

        for(int i=0; i<7; i++)
        {
            glVertex2f(w333x, w333y1);
            glVertex2f(w333x, w333y2);

            w333x=w333x+0.05;
        }

glEnd();


// 3rd floor right window outer border

float w3rx1,w3rx2,w3ry1,w3ry2;
w3rx1=0.17; w3rx2=0.14; w3ry1=0.17f;w3ry2=0.265f;
glColor3ub(180,180,180);
glBegin(GL_QUADS);
       for(int j=0; j<7;j++)
       {
          glVertex2f(w3rx1, w3ry1);
          glVertex2f(w3rx2, w3ry1);
          glVertex2f(w3rx2, w3ry2);
          glVertex2f(w3rx1, w3ry2);

          w3rx1=w3rx1+0.05;
          w3rx2=w3rx2+0.05;

       }

   glEnd();




// 3rd floor right window inner border

glColor3ub(54,54,54);
float w33rx1=0.168f, w33rx2=0.146f, w33ry1=0.177f, w33ry2=0.260f;
glBegin(GL_QUADS);


        for(int j=0; j<7;j++)
       {
          glVertex2f(w33rx1, w33ry1);
          glVertex2f(w33rx2, w33ry1);
          glVertex2f(w33rx2, w33ry2);
          glVertex2f(w33rx1, w33ry2);

          w33rx1=w33rx1+0.05;
          w33rx2=w33rx2+0.05;

       }

   glEnd();

   //3rd floor window 1 left inner middle x line

   glLineWidth(2.0);
   glColor3ub(255,255,255);
   float rx1=0.168f, rx2=0.146f, ry1=0.238f;
   glBegin(GL_LINES);

          for(int j=0; j<7;j++ ){
             glVertex2f(rx1, y1);
             glVertex2f(rx2, y1);

             rx1=rx1+0.05;
             rx2=rx2+0.05;
          }

   glEnd();

// 3rd floor right window inner line

float w333rx=.157f,w333ry1=0.177f,w333ry2=0.260f;
glColor3ub(255,255,255);

glLineWidth(2.0);
glBegin(GL_LINES);

        for(int i=0; i<7; i++)
        {
            glVertex2f(w333rx, w333ry1);
            glVertex2f(w333rx, w333ry2);

            w333rx=w333rx+0.05;
        }

glEnd();




//Stair
glBegin(GL_POLYGON);

      glColor3f(0.8f, 0.8f, 0.8f);

      glVertex2f(-0.22f, -0.01f);
      glVertex2f(0.22f, -0.01f);
      glVertex2f(0.15f, 0.06f);
      glVertex2f(-0.15f, 0.06f);
   glEnd();

//Stair lines
float stx1=-0.22, stx2=0.22, sty=-0.01;
glBegin(GL_LINES);
glColor3ub(255,255,255);

  for(int i=0; i<5; i++)
  {
      glVertex2f(stx1, sty);
      glVertex2f(stx2, sty);

      sty=sty+0.015;
      stx1=stx1+0.015;
      stx2=stx2-0.015;


  }

glEnd();


}

void grassANDroad()
{
       //Road base
glBegin(GL_POLYGON);

      glColor3ub(145,145,145);

      glVertex2f(-1.0f, 0.0f);
      glVertex2f(-1.0f, -0.2f);
      glVertex2f(1.0f, -0.2f);

      glVertex2f(1.0f, 0.0f);
   glEnd();

 //grass side

glBegin(GL_POLYGON);

      glColor3ub(32,164,71);

      glVertex2f(-1.0f, -0.2f);
      glVertex2f(-1.0f, -1.0);
      glVertex2f(1.0f, -1.0f);
      glVertex2f(1.0f, -0.2f);
   glEnd();


//Road base left right
glBegin(GL_POLYGON);

      glColor3ub(145,145,145);

      glVertex2f(-0.8f, -0.16f);
      glVertex2f(-1.2f, -1.0f);
      glVertex2f(1.2f, -1.0f);
      glVertex2f(0.8f, -0.16f);

   glEnd();

//grass middle
glBegin(GL_POLYGON);

      glColor3ub(32,164,71);

      glVertex2f(-0.5f, -0.26f);
      glVertex2f(-0.8f, -1.0);
      glVertex2f(0.8f, -1.0f);
      glVertex2f(0.5f, -0.26);
   glEnd();


//road borders
glLineWidth(6.0);
glBegin(GL_LINES);

      glColor3ub(255,255,255);

      glVertex2f(-0.5f, -0.26f);//middle grass left border
      glVertex2f(-0.8f, -1.0);
      glVertex2f(-0.503f, -.26f);//middle grass middle border
      glVertex2f(0.503f, -0.26f);
      glVertex2f(0.5f, -0.26f);//middle grass right border
      glVertex2f(0.8f, -1.0f);


      glVertex2f(-0.822f, -0.2f);//left grass right border
      glVertex2f(-1.2f, -1.0f);
      glVertex2f(-0.82f, -0.2f);//left grass upper border
      glVertex2f(-1.0f, -0.2f);


      glVertex2f(0.82f, -0.2f);//right grass left border
      glVertex2f(1.2f, -1.0f);
      glVertex2f(0.82f, -0.2f);//right grass upper border
      glVertex2f(1.0f, -0.2f);

      glVertex2f(-1.0f, -0.005f);//building front road border
      glVertex2f(1.0f, -0.005f);

    glEnd();

//Road lines
    float x1,x2,y, a,b;
    x1=-1.0; x2=-0.92; y=-0.0999;
    glLineWidth(6.0);

    glBegin(GL_LINES);

            for(int i =0; i<17; i++)
            {
                glVertex2f(x1,y );
                glVertex2f(x2,y);

                x1=x1+.12;
                x2=x2+.12;
            }

    glEnd();

//Tent quad
      glBegin(GL_POLYGON);

      glColor3ub(180,159,41);

      glVertex2f(0.2f, -0.4f);
      glVertex2f(0.28f, -0.555f);
      glVertex2f(0.55f, -0.52f);

      glVertex2f(0.48f, -0.38);


      glEnd();


//Tent triangle
      glBegin(GL_POLYGON);

      glColor3ub(126,79,52);

      glVertex2f(0.2f, -0.4f);
      glVertex2f(0.28f, -0.555f);
      glVertex2f(0.10f, -0.52f);

       glVertex2f(0.2f, -0.4f);


      glEnd();
//Tent triangle middle
      glBegin(GL_POLYGON);

      glColor3ub(61,37,24);

      glVertex2f(0.2f, -0.4f);
      glVertex2f(0.132f, -0.5290f);
      glVertex2f(0.22f, -0.541f);

       glVertex2f(0.2f, -0.4f);


      glEnd();




//Tent triangle line
      glBegin(GL_LINES);

      glColor3ub(0,0,0);//front left

      glVertex2f(0.22f, -0.38f);

      glVertex2f(0.08f, -0.52f);



      glColor3ub(0,0,0);//front right

      glVertex2f(0.18f, -0.38f);
      glVertex2f(0.30f, -0.57f);


      glColor3ub(0,0,0);//back right

      glVertex2f(0.46f, -0.35f);
      glVertex2f(0.58f, -0.55f);

      glVertex2f(0.50f, -0.365f);
      glVertex2f(0.48f, -0.385f);

      glEnd();


//tree-1(right-side of bank)////--------------

      glBegin(GL_QUADS);
      glColor3ub(102,51,0);

      glVertex2f(0.61f, 0.10f);
      glVertex2f(0.61f, 0.0f);
      glVertex2f(0.63f, 0.0f);

      glVertex2f(0.63f, 0.10f);


      glEnd();

      //tree shade

      glBegin(GL_QUADS);
      glColor3ub(153,76,0);

      glVertex2f(0.63f, 0.10f);
      glVertex2f(0.63f, 0.0f);
      glVertex2f(0.64f, 0.0f);

      glVertex2f(0.64f, 0.10f);


      glEnd();

      //tree layer-1

      glBegin(GL_POLYGON);
      glColor3ub(0,102,51);

      glVertex2f(0.59f, 0.13f);
      glVertex2f(0.57f, 0.10f);
      glVertex2f(0.68f, 0.10f);

      glVertex2f(0.66f, 0.13f);


      glEnd();

      //tree layer-2

       glBegin(GL_POLYGON);
      glColor3ub(0,153,0);

      glVertex2f(0.60f, 0.16f);
      glVertex2f(0.58f, 0.13f);
      glVertex2f(0.67f, 0.13f);

      glVertex2f(0.65f, 0.16f);


      glEnd();

      //tree layer-3

       glBegin(GL_POLYGON);
      glColor3ub(0,204,0);

      glVertex2f(0.61f, 0.19f);
      glVertex2f(0.59f, 0.16f);
      glVertex2f(0.66f, 0.16f);

      glVertex2f(0.64f, 0.19f);


      glEnd();
      //tree layer-4

       glBegin(GL_POLYGON);
      glColor3ub(128,255,0);

      glVertex2f(0.62f, 0.22f);
      glVertex2f(0.60f, 0.19f);
      glVertex2f(0.65f, 0.19f);
      glVertex2f(0.63f, 0.22f);

      glEnd();

      //tree-2(right-side of bank)////--------------

      glBegin(GL_QUADS);
      glColor3ub(102,51,0);

      glVertex2f(0.71f, 0.10f);
      glVertex2f(0.71f, 0.0f);
      glVertex2f(0.73f, 0.0f);

      glVertex2f(0.73f, 0.10f);


      glEnd();

     //tree shade

      glBegin(GL_QUADS);
      glColor3ub(153,76,0);

      glVertex2f(0.73f, 0.10f);
      glVertex2f(0.73f, 0.0f);
      glVertex2f(0.74f, 0.0f);

      glVertex2f(0.74f, 0.10f);


      glEnd();

      //tree layer-1

      glBegin(GL_POLYGON);
      glColor3ub(0,102,51);

      glVertex2f(0.69f, 0.13f);
      glVertex2f(0.67f, 0.10f);
      glVertex2f(0.78f, 0.10f);

      glVertex2f(0.76f, 0.13f);


      glEnd();

      //tree layer-2

       glBegin(GL_POLYGON);
      glColor3ub(0,153,0);

      glVertex2f(0.70f, 0.16f);
      glVertex2f(0.68f, 0.13f);
      glVertex2f(0.77f, 0.13f);

      glVertex2f(0.75f, 0.16f);


      glEnd();

      //tree layer-3

       glBegin(GL_POLYGON);
      glColor3ub(0,204,0);

      glVertex2f(0.71f, 0.19f);
      glVertex2f(0.69f, 0.16f);
      glVertex2f(0.76f, 0.16f);

      glVertex2f(0.74f, 0.19f);


      glEnd();
      //tree layer-4

       glBegin(GL_POLYGON);
      glColor3ub(128,255,0);

      glVertex2f(0.72f, 0.22f);
      glVertex2f(0.70f, 0.19f);
      glVertex2f(0.75f, 0.19f);
      glVertex2f(0.73f, 0.22f);


      //glVertex2f(0.72f, 0.44f);


     glEnd();

     //tree-3(right-side of bank)////--------------

      glBegin(GL_QUADS);
      glColor3ub(102,51,0);

      glVertex2f(0.81f, 0.10f);
      glVertex2f(0.81f, 0.0f);
      glVertex2f(0.83f, 0.0f);

      glVertex2f(0.83f, 0.10f);


      glEnd();

      //tree shade

      glBegin(GL_QUADS);
      glColor3ub(153,76,0);

      glVertex2f(0.83f, 0.10f);
      glVertex2f(0.83f, 0.0f);
      glVertex2f(0.84f, 0.0f);

      glVertex2f(0.84f, 0.10f);


      glEnd();

      //tree layer-1

      glBegin(GL_POLYGON);
      glColor3ub(0,102,51);

      glVertex2f(0.79f, 0.13f);
      glVertex2f(0.77f, 0.10f);
      glVertex2f(0.88f, 0.10f);

      glVertex2f(0.86f, 0.13f);


      glEnd();

      //tree layer-2

       glBegin(GL_POLYGON);
      glColor3ub(0,153,0);

      glVertex2f(0.80f, 0.16f);
      glVertex2f(0.78f, 0.13f);
      glVertex2f(0.87f, 0.13f);

      glVertex2f(0.85f, 0.16f);


      glEnd();

      //tree layer-3

       glBegin(GL_POLYGON);
      glColor3ub(0,204,0);

      glVertex2f(0.81f, 0.19f);
      glVertex2f(0.79f, 0.16f);
      glVertex2f(0.86f, 0.16f);

      glVertex2f(0.84f, 0.19f);


      glEnd();
      //tree layer-4

       glBegin(GL_POLYGON);
      glColor3ub(128,255,0);

      glVertex2f(0.82f, 0.22f);
      glVertex2f(0.80f, 0.19f);
      glVertex2f(0.85f, 0.19f);
      glVertex2f(0.83f, 0.22f);


      //glVertex2f(0.72f, 0.44f);
        glEnd();

//tree-4 (right-side of bank)////--------------

      glBegin(GL_QUADS);
      glColor3ub(102,51,0);

      glVertex2f(0.91f, 0.10f);
      glVertex2f(0.91f, 0.0f);
      glVertex2f(0.93f, 0.0f);

      glVertex2f(0.93f, 0.10f);

      glEnd();

      //tree shade

      glBegin(GL_QUADS);
      glColor3ub(153,76,0);

      glVertex2f(0.93f, 0.10f);
      glVertex2f(0.93f, 0.0f);
      glVertex2f(0.94f, 0.0f);

      glVertex2f(0.94f, 0.10f);


      glEnd();

      //tree layer-1

      glBegin(GL_POLYGON);
      glColor3ub(0,102,51);

      glVertex2f(0.89f, 0.13f);
      glVertex2f(0.87f, 0.10f);
      glVertex2f(0.98f, 0.10f);

      glVertex2f(0.96f, 0.13f);


      glEnd();

      //tree layer-2

       glBegin(GL_POLYGON);
      glColor3ub(0,153,0);

      glVertex2f(0.90f, 0.16f);
      glVertex2f(0.88f, 0.13f);
      glVertex2f(0.97f, 0.13f);

      glVertex2f(0.95f, 0.16f);


      glEnd();

      //tree layer-3

       glBegin(GL_POLYGON);
      glColor3ub(0,204,0);

      glVertex2f(0.91f, 0.19f);
      glVertex2f(0.89f, 0.16f);
      glVertex2f(0.96f, 0.16f);

      glVertex2f(0.94f, 0.19f);


      glEnd();
      //tree layer-4

       glBegin(GL_POLYGON);
      glColor3ub(128,255,0);

      glVertex2f(0.92f, 0.22f);
      glVertex2f(0.90f, 0.19f);
      glVertex2f(0.95f, 0.19f);
      glVertex2f(0.93f, 0.22f);


      //glVertex2f(0.72f, 0.44f);
      glEnd();

      //////////////////////////////////////////////////
      //tree-1(left-side of bank)////--------------

      glBegin(GL_QUADS);
      glColor3ub(102,51,0);

      glVertex2f(-0.61f, 0.10f);
      glVertex2f(-0.61f, 0.0f);
      glVertex2f(-0.63f, 0.0f);

      glVertex2f(-0.63f, 0.10f);


      glEnd();

      //tree shade

      glBegin(GL_QUADS);
      glColor3ub(153,76,0);

      glVertex2f(-0.63f, 0.10f);
      glVertex2f(-0.63f, 0.0f);
      glVertex2f(-0.64f, 0.0f);

      glVertex2f(-0.64f, 0.10f);


      glEnd();

      //tree layer-1

      glBegin(GL_POLYGON);
      glColor3ub(0,102,51);

      glVertex2f(-0.59f, 0.13f);
      glVertex2f(-0.57f, 0.10f);
      glVertex2f(-0.68f, 0.10f);

      glVertex2f(-0.66f, 0.13f);


      glEnd();

      //tree layer-2

       glBegin(GL_POLYGON);
      glColor3ub(0,153,0);

      glVertex2f(-0.60f, 0.16f);
      glVertex2f(-0.58f, 0.13f);
      glVertex2f(-0.67f, 0.13f);

      glVertex2f(-0.65f, 0.16f);


      glEnd();

      //tree layer-3

       glBegin(GL_POLYGON);
      glColor3ub(0,204,0);

      glVertex2f(-0.61f, 0.19f);
      glVertex2f(-0.59f, 0.16f);
      glVertex2f(-0.66f, 0.16f);

      glVertex2f(-0.64f, 0.19f);


      glEnd();
      //tree layer-4

       glBegin(GL_POLYGON);
      glColor3ub(128,255,0);

      glVertex2f(-0.62f, 0.22f);
      glVertex2f(-0.60f, 0.19f);
      glVertex2f(-0.65f, 0.19f);
      glVertex2f(-0.63f, 0.22f);


      //glVertex2f(0.72f, 0.44f);
      glEnd();

      //tree-2(left-side of bank)////--------------

      glBegin(GL_QUADS);
      glColor3ub(102,51,0);

      glVertex2f(-0.71f, 0.10f);
      glVertex2f(-0.71f, 0.0f);
      glVertex2f(-0.73f, 0.0f);

      glVertex2f(-0.73f, 0.10f);


      glEnd();

     //tree shade

      glBegin(GL_QUADS);
      glColor3ub(153,76,0);

      glVertex2f(-0.73f, 0.10f);
      glVertex2f(-0.73f, 0.0f);
      glVertex2f(-0.74f, 0.0f);

      glVertex2f(-0.74f, 0.10f);


      glEnd();

      //tree layer-1

      glBegin(GL_POLYGON);
      glColor3ub(0,102,51);

      glVertex2f(-0.69f, 0.13f);
      glVertex2f(-0.67f, 0.10f);
      glVertex2f(-0.78f, 0.10f);

      glVertex2f(-0.76f, 0.13f);


      glEnd();

      //tree layer-2

       glBegin(GL_POLYGON);
      glColor3ub(0,153,0);

      glVertex2f(-0.70f, 0.16f);
      glVertex2f(-0.68f, 0.13f);
      glVertex2f(-0.77f, 0.13f);

      glVertex2f(-0.75f, 0.16f);


      glEnd();

      //tree layer-3

       glBegin(GL_POLYGON);
      glColor3ub(0,204,0);

      glVertex2f(-0.71f, 0.19f);
      glVertex2f(-0.69f, 0.16f);
      glVertex2f(-0.76f, 0.16f);

      glVertex2f(-0.74f, 0.19f);


      glEnd();
      //tree layer-4

       glBegin(GL_POLYGON);
      glColor3ub(128,255,0);

      glVertex2f(-0.72f, 0.22f);
      glVertex2f(-0.70f, 0.19f);
      glVertex2f(-0.75f, 0.19f);
      glVertex2f(-0.73f, 0.22f);


      //glVertex2f(0.72f, 0.44f);


     glEnd();

    //tree-3(left-side of bank)////--------------

      glBegin(GL_QUADS);
      glColor3ub(102,51,0);

      glVertex2f(-0.81f, 0.10f);
      glVertex2f(-0.81f, 0.0f);
      glVertex2f(-0.83f, 0.0f);

      glVertex2f(-0.83f, 0.10f);


      glEnd();

      //tree shade

      glBegin(GL_QUADS);
      glColor3ub(153,76,0);

      glVertex2f(-0.83f, 0.10f);
      glVertex2f(-0.83f, 0.0f);
      glVertex2f(-0.84f, 0.0f);

      glVertex2f(-0.84f, 0.10f);


      glEnd();

      //tree layer-1

      glBegin(GL_POLYGON);
      glColor3ub(0,102,51);

      glVertex2f(-0.79f, 0.13f);
      glVertex2f(-0.77f, 0.10f);
      glVertex2f(-0.88f, 0.10f);

      glVertex2f(-0.86f, 0.13f);


      glEnd();

      //tree layer-2

       glBegin(GL_POLYGON);
      glColor3ub(0,153,0);

      glVertex2f(-0.80f, 0.16f);
      glVertex2f(-0.78f, 0.13f);
      glVertex2f(-0.87f, 0.13f);

      glVertex2f(-0.85f, 0.16f);


      glEnd();

      //tree layer-3

       glBegin(GL_POLYGON);
      glColor3ub(0,204,0);

      glVertex2f(-0.81f, 0.19f);
      glVertex2f(-0.79f, 0.16f);
      glVertex2f(-0.86f, 0.16f);

      glVertex2f(-0.84f, 0.19f);


      glEnd();
      //tree layer-4

       glBegin(GL_POLYGON);
      glColor3ub(128,255,0);

      glVertex2f(-0.82f, 0.22f);
      glVertex2f(-0.80f, 0.19f);
      glVertex2f(-0.85f, 0.19f);
      glVertex2f(-0.83f, 0.22f);


      //glVertex2f(0.72f, 0.44f);
        glEnd();

        //tree-4 (left-side of bank)////--------------

      glBegin(GL_QUADS);
      glColor3ub(102,51,0);

      glVertex2f(-0.91f, 0.10f);
      glVertex2f(-0.91f, 0.0f);
      glVertex2f(-0.93f, 0.0f);

      glVertex2f(-0.93f, 0.10f);

      glEnd();

      //tree shade

      glBegin(GL_QUADS);
      glColor3ub(153,76,0);

      glVertex2f(-0.93f, 0.10f);
      glVertex2f(-0.93f, 0.0f);
      glVertex2f(-0.94f, 0.0f);

      glVertex2f(-0.94f, 0.10f);


      glEnd();

      //tree layer-1

      glBegin(GL_POLYGON);
      glColor3ub(0,102,51);

      glVertex2f(-0.89f, 0.13f);
      glVertex2f(-0.87f, 0.10f);
      glVertex2f(-0.98f, 0.10f);

      glVertex2f(-0.96f, 0.13f);


      glEnd();

      //tree layer-2

       glBegin(GL_POLYGON);
      glColor3ub(0,153,0);

      glVertex2f(-0.90f, 0.16f);
      glVertex2f(-0.88f, 0.13f);
      glVertex2f(-0.97f, 0.13f);

      glVertex2f(-0.95f, 0.16f);


      glEnd();

      //tree layer-3

       glBegin(GL_POLYGON);
      glColor3ub(0,204,0);

      glVertex2f(-0.91f, 0.19f);
      glVertex2f(-0.89f, 0.16f);
      glVertex2f(-0.96f, 0.16f);

      glVertex2f(-0.94f, 0.19f);


      glEnd();
      //tree layer-4

       glBegin(GL_POLYGON);
      glColor3ub(128,255,0);

      glVertex2f(-0.92f, 0.22f);
      glVertex2f(-0.90f, 0.19f);
      glVertex2f(-0.95f, 0.19f);
      glVertex2f(-0.93f, 0.22f);


      //glVertex2f(0.72f, 0.44f);
      glEnd();
    glutPostRedisplay();
}


void lamp(int r, int g, int b)
{
     //Lamp-post-1(right side of the bank)
       glBegin(GL_POLYGON);
       glColor3ub(102,0,0);
      glVertex2f(0.54f, 0.02f);
      glVertex2f(0.54f, 0.0f);
      glVertex2f(0.56f, 0.0f);
      glVertex2f(0.56f, 0.02f);
      glEnd();

       glBegin(GL_POLYGON);
      glColor3ub(204,102,0);
      glVertex2f(0.546f, 0.03f);
      glVertex2f(0.54f, 0.02f);
      glVertex2f(0.56f, 0.02f);
      glVertex2f(0.553f, 0.03f);
      glEnd();

        //stand
       glBegin(GL_POLYGON);
      glColor3ub(64,64,64);
      glVertex2f(0.546f, 0.14f);
      glVertex2f(0.546f, 0.03f);
      glVertex2f(0.553f, 0.03f);
      glVertex2f(0.553f, 0.14f);
      glEnd();

      //border(lamp)

       glBegin(GL_POLYGON);
      glColor3ub(0,0,0);

      glVertex2f(0.529f, 0.18f);
      glVertex2f(0.545f, 0.14f);
      glVertex2f(0.554f, 0.14f);
      glVertex2f(0.571f, 0.18f);
      glEnd();
       //stand-upper portion(yellow one)

      glBegin(GL_POLYGON);
     // glColor3ub(255,255,51);
     glColor3ub(r,g,b);

      glVertex2f(0.53f, 0.18f);
      glVertex2f(0.546f, 0.14);
      glVertex2f(0.553f, 0.14f);
      glVertex2f(0.57f, 0.18f);
      glEnd();


      //border

      glBegin(GL_POLYGON);
      glColor3ub(0,0,0);
      glVertex2f(0.545f, 0.201f);
      glVertex2f(0.528f, 0.181f);
      glVertex2f(0.571f, 0.181f);
      glVertex2f(0.555f, 0.201f);
      glEnd();

      //

      glBegin(GL_POLYGON);
      glColor3ub(255,128,0);
      glVertex2f(0.546f, 0.20f);
      glVertex2f(0.53f, 0.18f);
      glVertex2f(0.57f, 0.18f);
      glVertex2f(0.553f, 0.20f);
      glEnd();


      //Lamp top portion

       glBegin(GL_QUADS);
      glColor3ub(153,76,13);
      glVertex2f(0.548f, 0.22f);
      glVertex2f(0.545f, 0.20f);
      glVertex2f(0.555f, 0.20f);
      glVertex2f(0.552f, 0.22f);

      glEnd();

      //lamp-post done

     /* glBegin(GL_TRIANGLES);
      glColor3ub(0,76,13);

      glVertex2f(0.555f, 0.23f);
      glVertex2f(0.548f, 0.22f);
      glVertex2f(0.552f, 0.22f);

      glEnd();*/

      //Lamp-post-2 (right side of the bank)
       glBegin(GL_POLYGON);
      glColor3ub(102,0,0);

      glVertex2f(-0.54f, 0.02f);
      glVertex2f(-0.54f, 0.0f);
      glVertex2f(-0.56f, 0.0f);
      glVertex2f(-0.56f, 0.02f);
      glEnd();


       glBegin(GL_POLYGON);
      glColor3ub(204,102,0);

      glVertex2f(-0.546f, 0.03f);
      glVertex2f(-0.54f, 0.02f);
      glVertex2f(-0.56f, 0.02f);
      glVertex2f(-0.553f, 0.03f);
      glEnd();

        //stand
       glBegin(GL_POLYGON);
      glColor3ub(64,64,64);

      glVertex2f(-0.546f, 0.14f);
      glVertex2f(-0.546f, 0.03f);
      glVertex2f(-0.553f, 0.03f);
      glVertex2f(-0.553f, 0.14f);
      glEnd();



      //border(lamp)

       glBegin(GL_POLYGON);
      glColor3ub(0,0,0);

      glVertex2f(-0.529f, 0.18f);
      glVertex2f(-0.545f, 0.14f);
      glVertex2f(-0.554f, 0.14f);
      glVertex2f(-0.571f, 0.18f);
      glEnd();




       //stand-upper portion(yellow one)

      glBegin(GL_POLYGON);
      glColor3ub(r,g,b);

      glVertex2f(-0.53f, 0.18f);
      glVertex2f(-0.546f, 0.14);
      glVertex2f(-0.553f, 0.14f);
      glVertex2f(-0.57f, 0.18f);
      glEnd();


      //border

      glBegin(GL_POLYGON);
      glColor3ub(0,0,0);

      glVertex2f(-0.545f, 0.201f);
      glVertex2f(-0.528f, 0.181f);
      glVertex2f(-0.571f, 0.181f);
      glVertex2f(-0.555f, 0.201f);
      glEnd();

      //

      glBegin(GL_POLYGON);
      glColor3ub(255,128,0);

      glVertex2f(-0.546f, 0.20f);
      glVertex2f(-0.53f, 0.18f);
      glVertex2f(-0.57f, 0.18f);
      glVertex2f(-0.553f, 0.20f);
      glEnd();


      //Lamp top portion

       glBegin(GL_QUADS);
      glColor3ub(153,76,13);

      glVertex2f(-0.548f, 0.22f);
      glVertex2f(-0.545f, 0.20f);
      glVertex2f(-0.555f, 0.20f);
      glVertex2f(-0.552f, 0.22f);

      glEnd();

      //lamp-post done



}

void rain()
{

float x=0.0;
float y=1.5;
float x1=-0.099;

     glPushMatrix();
    glTranslatef(cloud_position,0,0);
    CloudCircle(-0.58f,0.75f,0.0f,0.060f,47,79,79,150);//left cloud
    CloudCircle(-0.5f,0.82f,0.0f,0.068f,47,79,79,150);
    CloudCircle(-0.42f,0.75f,0.0f,0.068f,47,79,79,150);//right cloud
    CloudCircle(-0.5f,0.72f,0.0f,0.07f,47,79,79,150);
    glPopMatrix();

     glPushMatrix();
    glTranslatef(cloud_position_1,0,0);
    CloudCircle(-0.16f,0.69f,0.0f,0.060f,47,79,79,150);
    CloudCircle(-0.08f,0.76f,0.0f,0.068f,47,79,79,120);
    CloudCircle(0.0f,0.68f,0.0f,0.068f,47,79,79,120);
    CloudCircle(-0.08f,0.652f,0.0f,0.07f,47,79,79,120);


    glPopMatrix();

    glColor3ub(255,255,255);
    glPushMatrix();
    glTranslatef(0.0f,rainPos,0.0f);
    glBegin(GL_LINES);

    for(int i=600;i>=0;i--)
    {
        for(int j=0;j<=i;j++)
        {
            glVertex3f(x,y,0);
            glVertex3f(x+0.05,y+0.09,0);
            x+=float(rand()%5)/10;
           // x-=rand()%1050;
        }
        for(int j=0;j<=i;j++)
        {
            glVertex3f(x1,y,0);
            glVertex3f(x1+0.05,y+0.09,0);
            //x+=rand()%1050;
            x1-=float(rand()%5)/10;
        }
        y+=float(rand()%10)/10;
        //y-=rand()%15;
        x=0.0;
        x1=-0.099;

    }
    glEnd();
    glPopMatrix();
    glutPostRedisplay();

}


void car()
{
    glColor3ub(255,0,0);
    glPushMatrix();
    glTranslatef(position,0,0);
    glBegin(GL_POLYGON);

    glVertex3f(-0.3,-0.07,0);
    glVertex3f(-0.15,-0.07,0);
     glVertex3f(-0.15,-0.035,0);
    glVertex3f(-0.18,-0.035,0);
    glVertex3f(-0.20,-0.02,0);
    glVertex3f(-0.25,-0.02,0);
    glVertex3f(-0.27,-0.035,0);
     glVertex3f(-0.3,-0.035,0);
      glVertex3f(-0.27,-0.035,0);
      glVertex3f(-0.3,-0.07,0);
    glEnd();

    //car window
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);

    //car window left
    glVertex3f(-0.255,-0.038,0);
    glVertex3f(-0.235,-0.038,0);
    glVertex3f(-0.241,-0.030,0);
    glVertex3f(-0.248,-0.030,0);
    glVertex3f(-0.255,-0.035,0);
    glEnd();

     //car window right
    glBegin(GL_POLYGON);
    glVertex3f(-0.221,-0.038,0);
    glVertex3f(-0.20,-0.038,0);
    glVertex3f(-0.209,-0.030,0);
    glVertex3f(-0.216,-0.030,0);
    glVertex3f(-0.221,-0.035,0);
    glEnd();

    glColor3ub(185,0,0);
    glLineWidth(1.0);
    glBegin(GL_LINES);
    glVertex2f(-0.27,-.04);
    glVertex2f(-0.18,-.04);
    glEnd();

    //Wheels
    //backbumper
     Circle(-0.26f,-0.070f,0.0f,0.010f,0,0,0);
     //front bumper
    Circle(-0.199f,-0.07f,0.0f,0.01f,0,0,0);
glPopMatrix();

}

void car_2()
{

       glPushMatrix();
      glTranslatef(position,0,0);

      glBegin(GL_QUADS);
      glColor3ub(128,0,128);

      glVertex2f(0.025f, 0.001f);
      glVertex2f(0.025f, -0.045f);
      glVertex2f(0.222f, -0.045f);

      glVertex2f(0.222f, 0.001f);


      glEnd();

      //glass part of car

      glBegin(GL_POLYGON);
      glColor3ub(128,0,128);

      glVertex2f(0.065f, 0.031f);
      glVertex2f(0.055f, 0.001f);
      glVertex2f(0.20f, -0.001f);

      glVertex2f(0.185f, 0.031f);


      glEnd();
      //glass
       glBegin(GL_POLYGON);
      glColor3ub(168,204,215);

      glVertex2f(0.065f, 0.027f);
      glVertex2f(0.058f, 0.001f);
      glVertex2f(0.198f, 0.001f);

      glVertex2f(0.185f, 0.027f);


      glEnd();

      //head part

       glBegin(GL_POLYGON);
      glColor3ub(128,0,128);

      glVertex2f(0.222f, 0.001f);
      glVertex2f(0.222f, -0.045f);
      glVertex2f(0.252f, -0.045f);

      glVertex2f(0.252f, -0.033f);


      glEnd();

       glLineWidth(1.0);
       glBegin(GL_LINES);

      glColor3ub(128,0,128);
      glVertex2f(.12f, 0.031f);
      glVertex2f(.12f, -0.045f);
   glEnd();


   //headlight
      glBegin(GL_QUADS);
      glColor3ub(204,204,0);

      glVertex2f(0.233f, -0.033f);
      glVertex2f(0.233f, -0.038f);
      glVertex2f(0.252f, -0.038f);

      glVertex2f(0.252f, -0.033f);


      glEnd();

      // back light
       glBegin(GL_QUADS);
      glColor3ub(128,0,128);

      glVertex2f(0.015f, -0.035f);
      glVertex2f(0.015f, -0.045f);
      glVertex2f(0.025f, -0.045f);

      glVertex2f(0.025f, -0.035f);


      glEnd();

       //Wheels
    //backbumper

     Circle(0.055f,-0.045f,0.0f,0.010f,0,0,0);
     //front bumper
    Circle(0.20f,-0.045f,0.0f,0.01f,0,0,0);
glPopMatrix();

}

void car_3()
{
       glPushMatrix();
      glTranslatef(car3_pos,0,0);

      glBegin(GL_QUADS);
      glColor3ub(0,0,204);

      glVertex2f(0.04f, -0.14f);
      glVertex2f(0.04f, -0.19f);
      glVertex2f(0.19f, -0.19f);

      glVertex2f(0.19f, -0.14f);


      glEnd();

      //glass part of car

      glBegin(GL_POLYGON);
      glColor3ub(0,0,204);

      glVertex2f(0.078f, -0.11f);
      glVertex2f(0.055f, -0.14f);
      glVertex2f(0.16f, -0.14f);

      glVertex2f(0.13f, -0.11f);


      glEnd();
      //glass

      glBegin(GL_POLYGON);
      glColor3ub(168,204,215);

      glVertex2f(0.078f, -0.115f);
      glVertex2f(0.059f, -0.14f);
      glVertex2f(0.11f, -0.14f);
      glVertex2f(0.11f, -0.115f);


     // glVertex2f(0.155f, -0.14f);

     // glVertex2f(0.13f, -0.115f);


      glEnd();

      //glass-2
       glBegin(GL_POLYGON);
      glColor3ub(168,204,215);

      glVertex2f(0.113f, -0.115f);
      glVertex2f(0.113f, -0.14f);
      glVertex2f(0.155f, -0.14f);
      glVertex2f(0.13f, -0.115f);


      glEnd();



      //head part

       glBegin(GL_POLYGON);
      glColor3ub(0,0,204);

      glVertex2f(0.04f, -0.14f);
      glVertex2f(0.015f, -0.17f);
      glVertex2f(0.015f, -0.19f);

      glVertex2f(0.04f, -0.19f);


      glEnd();

    /*   glLineWidth(1.0);
       glBegin(GL_LINES);

      glColor3ub(128,0,128);
      glVertex2f(.12f, 0.031f);
      glVertex2f(.12f, -0.045f);
   glEnd(); */


   //headlight
      glBegin(GL_QUADS);
      glColor3ub(204,204,0);

      glVertex2f(0.015f, -0.17f);
      glVertex2f(0.015f, -0.18f);
      glVertex2f(0.029f, -0.18f);

      glVertex2f(0.029f, -0.17f);


      glEnd();

      // back light
       glBegin(GL_QUADS);
      glColor3ub(0,0,204);

      glVertex2f(0.19f, -0.18f);
      glVertex2f(0.19f, -0.19f);
      glVertex2f(0.196f, -0.19f);

      glVertex2f(0.196f, -0.18f);


      glEnd();

       //Wheels
    //backbumper

     Circle(0.068f,-0.19f,0.0f,0.010f,0,0,0);
     //front bumper
    Circle(0.15f,-0.19f,0.0f,0.01f,0,0,0);
glPopMatrix();


}

void car_4()
{
       glPushMatrix();
      glTranslatef(car4_pos,0,0);

      glBegin(GL_QUADS);
      glColor3ub(102,0,51);

      glVertex2f(0.04f, -0.14f);
      glVertex2f(0.04f, -0.19f);
      glVertex2f(0.19f, -0.19f);

      glVertex2f(0.19f, -0.14f);


      glEnd();

      //glass part of car

      glBegin(GL_POLYGON);
      glColor3ub(102,0,51);

      glVertex2f(0.078f, -0.11f);
      glVertex2f(0.055f, -0.14f);
      glVertex2f(0.16f, -0.14f);

      glVertex2f(0.13f, -0.11f);


      glEnd();
      //glass

      glBegin(GL_POLYGON);
      glColor3ub(168,204,215);

      glVertex2f(0.078f, -0.115f);
      glVertex2f(0.059f, -0.14f);
      glVertex2f(0.11f, -0.14f);
      glVertex2f(0.11f, -0.115f);


     // glVertex2f(0.155f, -0.14f);

     // glVertex2f(0.13f, -0.115f);


      glEnd();

      //glass-2
       glBegin(GL_POLYGON);
      glColor3ub(168,204,215);

      glVertex2f(0.113f, -0.115f);
      glVertex2f(0.113f, -0.14f);
      glVertex2f(0.155f, -0.14f);
      glVertex2f(0.13f, -0.115f);


      glEnd();



      //head part

       glBegin(GL_POLYGON);
      glColor3ub(102,0,51);

      glVertex2f(0.04f, -0.14f);
      glVertex2f(0.015f, -0.17f);
      glVertex2f(0.015f, -0.19f);

      glVertex2f(0.04f, -0.19f);


      glEnd();




   //headlight
      glBegin(GL_QUADS);
      glColor3ub(204,204,0);

      glVertex2f(0.015f, -0.17f);
      glVertex2f(0.015f, -0.18f);
      glVertex2f(0.029f, -0.18f);

      glVertex2f(0.029f, -0.17f);


      glEnd();

      // back light
       glBegin(GL_QUADS);
      glColor3ub(102,0,51);

      glVertex2f(0.19f, -0.18f);
      glVertex2f(0.19f, -0.19f);
      glVertex2f(0.196f, -0.19f);

      glVertex2f(0.196f, -0.18f);


      glEnd();

       //Wheels
    //backbumper

     Circle(0.068f,-0.19f,0.0f,0.010f,0,0,0);
     //front bumper
    Circle(0.15f,-0.19f,0.0f,0.01f,0,0,0);
glPopMatrix();


}
void police_car()
{
      glBegin(GL_QUADS);
      glColor3ub(255,255,255);

      glVertex2f(-0.78f, -0.41f);
      glVertex2f(-0.85f, -0.49f);
      glVertex2f(-0.76f, -0.49f);

      glVertex2f(-0.70f, -0.41f);


      glEnd();

            Circle(-0.776f,-0.57f,0.0f,0.015f,0,0,0);
            Circle(-0.709f,-0.459f,0.0f,0.015f,0,0,0);


      // car-back glass portion

      glBegin(GL_QUADS);
      glColor3ub(0,0,102);

      glVertex2f(-0.85f, -0.49f);
      glVertex2f(-0.88f, -0.57f);
      glVertex2f(-0.78f, -0.57f);

      glVertex2f(-0.76f, -0.49f);


      glEnd();

      //glass

       glBegin(GL_QUADS);
      glColor3ub(168,204,215);

      glVertex2f(-0.848f, -0.50f);
      glVertex2f(-0.87f, -0.56f);
      glVertex2f(-0.785f, -0.56f);

      glVertex2f(-0.77f, -0.50f);


      glEnd();

      //back of the car

        glBegin(GL_QUADS);
      glColor3ub(255,255,255);

      glVertex2f(-0.88f, -0.57f);
      glVertex2f(-0.91f, -0.61f);
      glVertex2f(-0.80f, -0.61f);

      glVertex2f(-0.78f, -0.57f);


      glEnd();

        glBegin(GL_QUADS);
      glColor3ub(255,0,0);

      glVertex2f(-0.91f, -0.61f);
      glVertex2f(-0.91f, -0.63f);
      glVertex2f(-0.80f, -0.63f);

      glVertex2f(-0.80f, -0.61f);


      glEnd();
      //back-light

       glBegin(GL_QUADS);
      glColor3ub(0,0,102);

      glVertex2f(-0.88f, -0.61f);
      glVertex2f(-0.88f, -0.63f);
      glVertex2f(-0.83f, -0.63f);

      glVertex2f(-0.83f, -0.61f);


      glEnd();

      //car-right part

       glBegin(GL_QUADS);
      glColor3ub(0,0,102);

      glVertex2f(-0.80f, -0.61f);
      glVertex2f(-0.80f, -0.63f);
      glVertex2f(-0.78f, -0.59f);

      glVertex2f(-0.78f, -0.57f);


      glEnd();

      /////////
       glBegin(GL_QUADS);
      glColor3ub(0,0,102);

      glVertex2f(-0.78f, -0.57f);
      glVertex2f(-0.78f, -0.59f);
      glVertex2f(-0.76f, -0.553f);

      glVertex2f(-0.76f, -0.49f);


      glEnd();
      //
       glBegin(GL_QUADS);
      glColor3ub(0,0,102);

      glVertex2f(-0.76f, -0.49f);
      glVertex2f(-0.76f, -0.553f);
      glVertex2f(-0.70f, -0.459f);

      glVertex2f(-0.70f, -0.41f);


      glEnd();
      //front part
       glBegin(GL_QUADS);
      glColor3ub(0,0,102);

      glVertex2f(-0.70f, -0.41f);
      glVertex2f(-0.70f, -0.459f);
      glVertex2f(-0.69f, -0.446f);

      glVertex2f(-0.69f, -0.397f);


      glEnd();

       glBegin(GL_QUADS);
      glColor3ub(224,224,224);

      glVertex2f(-0.76f, -0.41f);
      glVertex2f(-0.70f, -0.41f);
      glVertex2f(-0.69f, -0.397f);

      glVertex2f(-0.74f, -0.397f);


      glEnd();
      //right-glass

         glBegin(GL_POLYGON);
      glColor3ub(168,204,215);

      glVertex2f(-0.76f, -0.50f);
      glVertex2f(-0.78f, -0.564f);
      glVertex2f(-0.70f, -0.445f);

      glVertex2f(-0.70f, -0.42f);


      glEnd();


       glLineWidth(2.0);
       glBegin(GL_LINES);

      glColor3ub(102,0,51);
      glVertex2f(-0.73f, -0.45f);
      glVertex2f(-0.73f, -0.504f);
      glEnd();

          //reg-light
           glBegin(GL_POLYGON);
       glColor3ub(255,0,0);

      glVertex2f(-0.77f, -0.40f);
      glVertex2f(-0.77f, -0.43f);
      glVertex2f(-0.76f, -0.43f);

      glVertex2f(-0.76f, -0.40f);

    glEnd();





}


void cloud_1()
{
    ///glColor3ub(255,255,255);
     glPushMatrix();
    glTranslatef(cloud_position,0,0);
    CloudCircle(-0.58f,0.75f,0.0f,0.060f,211,245,245,150);//left cloud
    CloudCircle(-0.5f,0.82f,0.0f,0.068f,211,245,245,150);
    CloudCircle(-0.42f,0.75f,0.0f,0.068f,211,245,245,150);//right cloud
    CloudCircle(-0.5f,0.72f,0.0f,0.07f,211,245,245,150);

    glPopMatrix();

}

void cloud_2()
{

     glPushMatrix();
    glTranslatef(cloud_position_1,0,0);


    CloudCircle(-0.16f,0.69f,0.0f,0.060f,211,245,245,150);
    CloudCircle(-0.08f,0.76f,0.0f,0.068f,211,245,245,120);
    CloudCircle(0.0f,0.68f,0.0f,0.068f,211,245,245,120);
    CloudCircle(-0.08f,0.652f,0.0f,0.07f,211,245,245,120);


    glPopMatrix();

}

void bush_1()
{

     glBegin(GL_POLYGON);
       glColor3ub(153,76,0);

      glVertex2f(-0.59f, -0.58f);
      glVertex2f(-0.59f, -0.63f);
      glVertex2f(-0.57f, -0.63f);

      glVertex2f(-0.57f, -0.58f);
      glEnd();


    Circle(-0.55f,-0.56f,0.0f,0.03f,0,102,51);
    Circle(-0.59f,-0.56f,0.0f,0.03f,0,102,51);
    Circle(-0.63f,-0.555f,0.0f,0.03f,0,102,51);
    Circle(-0.56f,-0.52f,0.0f,0.03f,0,102,51);
    Circle(-0.58f,-0.526f,0.0f,0.03f,0,102,51);
    Circle(-0.603f,-0.52f,0.0f,0.03f,0,102,51);
    Circle(-0.58f,-0.49f,0.0f,0.03f,0,102,51);







}
void bush_2()
{

       glBegin(GL_POLYGON);
       glColor3ub(153,76,0);


      glVertex2f(-0.63f, -0.74f);
      glVertex2f(-0.63f, -0.79f);
      glVertex2f(-0.61f, -0.79f);

      glVertex2f(-0.61f, -0.74f);
      glEnd();


    Circle(-0.65f,-0.73f,0.0f,0.03f,0,102,51);
    Circle(-0.61f,-0.73f,0.0f,0.03f,0,102,51);
    Circle(-0.58f,-0.73f,0.0f,0.03f,0,102,51);

    Circle(-0.63f,-0.69f,0.0f,0.03f,0,102,51);
    Circle(-0.59f,-0.69f,0.0f,0.03f,0,102,51);

    Circle(-0.61f,-0.65f,0.0f,0.03f,0,102,51);
    //Circle(-0.58f,-0.65f,0.0f,0.03f,0,102,51);

    //////////////////////////third bush////////////////////

     glBegin(GL_POLYGON);
       glColor3ub(153,76,0);


      glVertex2f(-0.55f, -0.43f);
      glVertex2f(-0.55f, -0.48f);
      glVertex2f(-0.53f, -0.48f);

      glVertex2f(-0.53f, -0.43f);
      glEnd();


    Circle(-0.58f,-0.41f,0.0f,0.03f,0,102,51);
    Circle(-0.55f,-0.405f,0.0f,0.03f,0,102,51);
    Circle(-0.52f,-0.41f,0.0f,0.03f,0,102,51);

    Circle(-0.56f,-0.38f,0.0f,0.03f,0,102,51);
    Circle(-0.53f,-0.38f,0.0f,0.03f,0,102,51);

    Circle(-0.54f,-0.34f,0.0f,0.03f,0,102,51);
    //Circle(-0.58f,-0.65f,0.0f,0.03f,0,102,51);

    //////////////////////////////////////4th bush//////////////////

       glBegin(GL_POLYGON);
       glColor3ub(153,76,0);


      glVertex2f(-0.50f, -0.26f);
      glVertex2f(-0.50f, -0.34f);
      glVertex2f(-0.48f, -0.34f);

      glVertex2f(-0.48f, -0.26f);
      glEnd();


    Circle(-0.52f,-0.25f,0.0f,0.03f,0,102,51);
    Circle(-0.49f,-0.25f,0.0f,0.03f,0,102,51);
    Circle(-0.47f,-0.25f,0.0f,0.03f,0,102,51);

    Circle(-0.50f,-0.22f,0.0f,0.03f,0,102,51);
    Circle(-0.48f,-0.22f,0.0f,0.03f,0,102,51);

    Circle(-0.49f,-0.19f,0.0f,0.028f,0,102,51);
    //Circle(-0.58f,-0.65f,0.0f,0.03f,0,102,51);


    /////////////////5th bush//////////////
     glBegin(GL_POLYGON);
       glColor3ub(153,76,0);


      glVertex2f(0.50f, -0.26f);
      glVertex2f(0.50f, -0.34f);
      glVertex2f(0.48f, -0.34f);

      glVertex2f(0.48f, -0.26f);
      glEnd();


    Circle(0.52f,-0.25f,0.0f,0.03f,0,102,51);
    Circle(0.49f,-0.25f,0.0f,0.03f,0,102,51);
    Circle(0.47f,-0.25f,0.0f,0.03f,0,102,51);

    Circle(0.50f,-0.22f,0.0f,0.03f,0,102,51);
    Circle(0.48f,-0.22f,0.0f,0.03f,0,102,51);

    Circle(0.49f,-0.19f,0.0f,0.028f,0,102,51);
///////////////////////6th bush//////////////

  glBegin(GL_POLYGON);
       glColor3ub(153,76,0);


      glVertex2f(0.55f, -0.43f);
      glVertex2f(0.55f, -0.46f);
      glVertex2f(0.53f, -0.46f);

      glVertex2f(0.53f, -0.43f);
      glEnd();


    Circle(0.58f,-0.41f,0.0f,0.03f,0,102,51);
    Circle(0.55f,-0.405f,0.0f,0.03f,0,102,51);
    Circle(0.52f,-0.41f,0.0f,0.03f,0,102,51);

    Circle(0.56f,-0.38f,0.0f,0.03f,0,102,51);
    Circle(0.53f,-0.38f,0.0f,0.03f,0,102,51);

    Circle(0.54f,-0.34f,0.0f,0.03f,0,102,51);

    /////////////////////7th one////////////

     glBegin(GL_POLYGON);
       glColor3ub(153,76,0);


      glVertex2f(0.63f, -0.74f);
      glVertex2f(0.63f, -0.79f);
      glVertex2f(0.61f, -0.79f);

      glVertex2f(0.61f, -0.74f);
      glEnd();


    Circle(0.65f,-0.73f,0.0f,0.03f,0,102,51);
    Circle(0.61f,-0.73f,0.0f,0.03f,0,102,51);
    Circle(0.58f,-0.73f,0.0f,0.03f,0,102,51);

    Circle(0.63f,-0.69f,0.0f,0.03f,0,102,51);
    Circle(0.59f,-0.69f,0.0f,0.03f,0,102,51);

    Circle(0.61f,-0.65f,0.0f,0.03f,0,102,51);

    ////////////////////////garden left side/////////

       glBegin(GL_POLYGON);
       glColor3ub(153,76,0);


      glVertex2f(-0.92f, -0.26f);
      glVertex2f(-0.92f, -0.34f);
      glVertex2f(-0.90f, -0.34f);

      glVertex2f(-0.90f, -0.26f);
      glEnd();


    Circle(-0.94f,-0.25f,0.0f,0.03f,0,102,51);
    Circle(-0.90f,-0.25f,0.0f,0.03f,0,102,51);
    Circle(-0.87f,-0.25f,0.0f,0.03f,0,102,51);

    Circle(-0.92f,-0.22f,0.0f,0.03f,0,102,51);
    Circle(-0.89f,-0.22f,0.0f,0.03f,0,102,51);

    Circle(-0.91f,-0.19f,0.0f,0.028f,0,102,51);

    /////////////garden other side//////////////

     glBegin(GL_POLYGON);
       glColor3ub(153,76,0);


      glVertex2f(0.92f, -0.26f);
      glVertex2f(0.92f, -0.34f);
      glVertex2f(0.90f, -0.34f);

      glVertex2f(0.90f, -0.26f);
      glEnd();


    Circle(0.94f,-0.25f,0.0f,0.03f,0,102,51);
    Circle(0.90f,-0.25f,0.0f,0.03f,0,102,51);
    Circle(0.87f,-0.25f,0.0f,0.03f,0,102,51);

    Circle(0.92f,-0.22f,0.0f,0.03f,0,102,51);
    Circle(0.89f,-0.22f,0.0f,0.03f,0,102,51);

    Circle(0.91f,-0.19f,0.0f,0.028f,0,102,51);


}


void scallingObject(int e, float x1[10], float y1[10], float x, float y, int r,int g,int b)
{
    int i;

    for(i=0; i<e; i++)
        {
            glColor3ub(r,g,b);
            glBegin(GL_POLYGON);
            glVertex2f(x1[i]*x,y1[i]*y);

        }
        glEnd();

}

GLfloat countMove=0.0;
void helicoptor(){


glPushMatrix();
glTranslatef(helicopterPos,0.45f,0.0f);
//helicopter  stand 1
    glBegin(GL_QUADS);
    glColor3ub(128, 124, 124);
    glVertex2f(0.10f, 0.25f);
    glVertex2f(0.10f, 0.20f);
    glVertex2f(0.115f, 0.20f);
    glVertex2f(0.115f, 0.25f);

//helicopter  stand 2
    glBegin(GL_QUADS);
    glColor3ub(128, 124, 124);
    glVertex2f(0.14f, 0.25f);
    glVertex2f(0.14f, 0.20f);
    glVertex2f(0.155f, 0.20f);
    glVertex2f(0.155f, 0.25f);



    //helicopter  stand 3
    glBegin(GL_QUADS);
    glColor3ub(128, 124, 124);
    glVertex2f(0.06f, 0.20f);
    glVertex2f(0.06f, 0.18f);
    glVertex2f(0.20f, 0.18f);
    glVertex2f(0.20f, 0.20f);


//helicopter  stand 4
  /*  glBegin(GL_QUADS);
    glColor3ub(128, 124, 124);
    glVertex2f(0.06f, 0.17f);
    glVertex2f(0.06f, 0.16f);
    glVertex2f(0.20f, 0.16f);
    glVertex2f(0.20f, 0.17f);*/




   glEnd();


//helicopter border
  HCircle(0.13f,0.28f,0.0f,0.045f,0, 0, 0 );
//helicopter
  HCircle(0.13f,0.28f,0.0f,0.035f,39, 55, 70 );


// tail
 glBegin(GL_TRIANGLES);
      glColor3ub(39, 55, 70);
      glVertex2f(0.19f, 0.255f);
      glVertex2f(0.42f, 0.285f);
       glVertex2f(0.19f, 0.305f);



   glEnd();



//tail tail

 glBegin(GL_QUADS);
      glColor3ub(39, 55, 70);

        glVertex2f(0.36f, 0.280f);
        glVertex2f(0.40f, 0.270f);
        glVertex2f(0.43f, 0.30f);
        glVertex2f(0.40f, 0.32f);


   glEnd();


    glPushMatrix();
    glTranslatef(-0.015f,-0.165f,0.0f);

   // below turbine
glBegin(GL_QUADS);
      glColor3ub(182, 179, 178);
        glVertex2f(0.13f, 0.49f);
        glVertex2f(0.17f, 0.49f);
        glVertex2f(0.17f, 0.51f);
        glVertex2f(0.13f, 0.51f);


   glEnd();

//turbine1

 glBegin(GL_QUADS);
      glColor3ub(39, 55, 70);

        glVertex2f(-0.04f, 0.49f);
        glVertex2f(-0.03f, 0.46f);
        glVertex2f(0.31f, 0.57f);
        glVertex2f(0.30f, 0.60f);


   glEnd();

    glBegin(GL_QUADS);
      glColor3ub(39, 55, 70);
         glVertex2f(-0.06f, 0.55f);
        glVertex2f(-0.03f, 0.58f);
        glVertex2f(0.32f, 0.51f);
        glVertex2f(0.31f, 0.48f);



   glEnd();

 //helicopter turbine
 Circle(0.15f,0.53f,0.0f,0.0222f,128, 124, 124  );
 glPopMatrix();


//helicopter Triangle window
    glBegin(GL_TRIANGLES);
      glColor3ub(244, 246, 247);
        glVertex2f(0.09f, 0.27f);
        glVertex2f(0.12f, 0.27f);
        glVertex2f(0.12f, 0.30f);
   glEnd();

//helicopter  window
    glBegin(GL_QUADS);
      glColor3ub(244, 246, 247);
      glVertex2f(0.14f, 0.267f);
      glVertex2f(0.17f, 0.267f);
      glVertex2f(0.17f, 0.30f);
      glVertex2f(0.14f, 0.30f);
   glEnd();

glPopMatrix();
}

void huMan3()
{
 glPushMatrix();
    glTranslatef(-0.08f,-0.45f, 0.0f);
 Circle(0.2f,-0.05f,0.0f,0.025f, 0, 0, 0  );// hair

  Circle(0.2f,-0.053f,0.0f,0.02f,249, 236, 170 );// head
 Circle(0.2f,-0.10f,0.0f,0.027f,176, 58, 46 );//body


  glBegin(GL_QUADS);// upper body
      glColor3ub(176, 58, 46);
      glVertex2f(0.175f, -.1f);
      glVertex2f(0.225f, -.1f);
      glVertex2f(0.225f, -0.14f);
      glVertex2f(0.175f, -0.14f);
      glEnd();

      glBegin(GL_QUADS);// pants
      glColor3ub(176, 58, 46);
      glVertex2f(0.178f, -.14f);
      glVertex2f(0.222f, -.14f);
      glVertex2f(0.225f, -0.18f);
      glVertex2f(0.175f, -0.18f);

      glEnd();



    /*  glLineWidth(6.0);
      glBegin(GL_LINES);//pant divider
      glColor3ub(0, 0, 0);
      glVertex2f(0.200f, -0.14f);
      glVertex2f(0.200f, -0.18f);

      glEnd();*/



       glLineWidth(11.0);
      glBegin(GL_LINES);//hand left
      glColor3ub(205, 97, 85 );
      glVertex2f(0.175f, -.09f);
      glVertex2f(0.175f, -.14f);


      glEnd();

       glLineWidth(11.0);
      glBegin(GL_LINES);//hand left
      glColor3ub(205, 97, 85 );
      glVertex2f(0.225f, -.09f);
      glVertex2f(0.225f, -.14f);


      glEnd();


// Face
      glPointSize(5.0);
    glBegin(GL_POINTS);

     glColor3ub(255,255,255);
     glVertex2f(0.19f, -0.05f);

     glEnd();

 glPointSize(3.0);
    glBegin(GL_POINTS);

     glColor3ub(0,0,0);
     glVertex2f(0.19f, -0.05f);

     glEnd();


     glPointSize(5.0);
    glBegin(GL_POINTS);

     glColor3ub(255,255,255);
     glVertex2f(0.21f, -0.05f);

     glEnd();

     glPointSize(3.0);
    glBegin(GL_POINTS);

     glColor3ub(0,0,0);
     glVertex2f(0.21f, -0.05f);

     glEnd();


     glPointSize(5.0);
    glBegin(GL_POINTS);

     glColor3ub(146, 46, 19 );
     glVertex2f(0.1981f, -0.06f);

     glEnd();

     glPopMatrix();

}

void huManRob()
{

//hoody
  Circle(0.0f,0.13f,0.0f,0.0158f,246, 96, 66 );
//head & face
 Circle(0.0f,0.131f,0.0f,0.0095f,243, 192, 182  );
//upper body circle
  Circle(0.0f,0.109f,0.0f,0.012f,246, 96, 66 );

//upper body
float upx[4]={-0.08,0.08,0.08,-0.08};
float upy[4]={0.125,0.125,0.150,0.150};
scallingObject(4, upx, upy, 0.15, 0.74, 246, 96, 66);

// chain
glBegin(GL_LINES);
      glColor3ub(0,0,0);
      glVertex2f(.0f, 0.112f);
      glVertex2f(.0f, 0.095f);

   glEnd();
/*
//Shoes left
float lshx[3]={-0.005,-0.1,-0.005};
float lshy[3]={0.13,0.13,0.20};
scallingObject(3, lshx, lshy, 0.2, 0.2, 0,0,0);


//Shoes right
float shx[3]={0.005,0.1,0.005};
float shy[3]={0.13,0.13,0.20};
scallingObject(3, shx, shy, 0.2, 0.2, 0,0,0);

// pant left
float lpx[4]={-0.08f,-0.07f,-0.005f,-0.002f};
float lpy[4]={0.50f,0.18f,0.18f,0.50f};
scallingObject(4, lpx, lpy, 0.15, 0.2, 246, 96, 66);


// pant right
float rpx[4]={0.08f,0.07f,0.005f,0.002f};
float rpy[4]={0.50f,0.18f,0.18f,0.50f};
scallingObject(4, rpx, rpy, 0.15, 0.2, 246, 96, 66);
*/


// hand left top

float lhtx[4]={-0.15f,-0.10f,-0.04f,-0.08f};
float lhty[4]={0.35f,0.35f,0.45f,0.45f};
scallingObject(4, lhtx, lhty, 0.15, 0.25, 222, 59, 27);

/*// hand left bottom

float lhbx[4]={-0.10f,-0.15f,-0.08f,-0.02f};
float lhby[4]={0.35f,0.35f, 0.3f,0.3f};
scallingObject(4, lhbx, lhby, 0.15, 0.258, 222, 59, 27);*/

// hand right
float rhx[4]={0.05f,0.050f,0.09f,0.09f};
float rhy[4]={0.44f,0.34f, 0.34f,0.44f};
scallingObject(4, rhx, rhy, 0.15, 0.258, 222, 59, 27);

/*
//gun
glLineWidth(3.0);
glBegin(GL_LINES);
   glColor3ub(0, 0,0);
     glVertex2f(-0.02f, 0.075f);
      glVertex2f(0.02f, 0.108f);
glEnd();

glBegin(GL_LINES);
   glColor3ub(0, 0,0);
     glVertex2f(-0.019f, 0.058f);
      glVertex2f(0.0f, 0.097f);
glEnd();


// hand left finger
float lfx[4]={-0.09f,-0.03f,-0.03f,-0.09f};
float lfy[4]={0.30f,0.34f, 0.31f,0.29f};
scallingObject(4, lfx, lfy, 0.15, 0.258, 243, 192, 182);

// hand right finger
float rfx[4]={0.05f,0.050f,0.09f,0.09f};
float rfy[4]={0.30f,0.28f, 0.28f,0.30f};
scallingObject(4, rfx, rfy, 0.15, 0.258, 243, 192, 182);

*/
//right eye
glPointSize(2.0);
 glBegin(GL_POINTS);

     glColor3ub(255, 255, 255 );
     glVertex2f(0.0035f, 0.131f);
 glEnd();

 glPointSize(1.0);
 glBegin(GL_POINTS);

     glColor3ub(0, 0, 0 );
     glVertex2f(0.0034f, 0.131f);
 glEnd();

 //left eye

 glPointSize(2.0);
 glBegin(GL_POINTS);

     glColor3ub(255, 255, 255 );
     glVertex2f(-0.0035f, 0.131f);
 glEnd();

  glPointSize(1.0);
 glBegin(GL_POINTS);

     glColor3ub(0, 0, 0 );
     glVertex2f(-0.0034f, 0.131f);
 glEnd();


//moch



glPointSize(3.0);
 glBegin(GL_POINTS);

     glColor3ub(243, 192, 182 );
     glVertex2f(0.00f, 0.127f);

     glEnd();

     glPointSize(2.0);
 glBegin(GL_POINTS);

     glColor3ub(0 ,0, 0);
     glVertex2f(0.00f, 0.125f);

     glEnd();



}

void huManRob1()
{

//hoody
  Circle(0.0f,0.13f,0.0f,0.0158f,246, 96, 66 );
//head & face
 Circle(0.0f,0.131f,0.0f,0.0095f,243, 192, 182  );
//upper body circle
  Circle(0.0f,0.109f,0.0f,0.012f,246, 96, 66 );

//upper body
float upx[4]={-0.08,0.08,0.08,-0.08};
float upy[4]={0.125,0.125,0.150,0.150};
scallingObject(4, upx, upy, 0.15, 0.74, 246, 96, 66);

// chain
glBegin(GL_LINES);
      glColor3ub(0,0,0);
      glVertex2f(.0f, 0.112f);
      glVertex2f(.0f, 0.095f);

   glEnd();

//Shoes left
float lshx[3]={-0.005,-0.1,-0.005};
float lshy[3]={0.13,0.13,0.20};
scallingObject(3, lshx, lshy, 0.2, 0.2, 0,0,0);


//Shoes right
float shx[3]={0.005,0.1,0.005};
float shy[3]={0.13,0.13,0.20};
scallingObject(3, shx, shy, 0.2, 0.2, 0,0,0);

// pant left
float lpx[4]={-0.08f,-0.07f,-0.005f,-0.002f};
float lpy[4]={0.50f,0.18f,0.18f,0.50f};
scallingObject(4, lpx, lpy, 0.15, 0.2, 246, 96, 66);


// pant right
float rpx[4]={0.08f,0.07f,0.005f,0.002f};
float rpy[4]={0.50f,0.18f,0.18f,0.50f};
scallingObject(4, rpx, rpy, 0.15, 0.2, 246, 96, 66);



// hand left top

float lhtx[4]={-0.15f,-0.10f,-0.04f,-0.08f};
float lhty[4]={0.35f,0.35f,0.45f,0.45f};
scallingObject(4, lhtx, lhty, 0.15, 0.25, 222, 59, 27);

// hand left bottom

float lhbx[4]={-0.10f,-0.15f,-0.08f,-0.02f};
float lhby[4]={0.35f,0.35f, 0.3f,0.3f};
scallingObject(4, lhbx, lhby, 0.15, 0.258, 222, 59, 27);

// hand right
float rhx[4]={0.05f,0.050f,0.09f,0.09f};
float rhy[4]={0.44f,0.34f, 0.34f,0.44f};
scallingObject(4, rhx, rhy, 0.15, 0.258, 222, 59, 27);


//gun
glLineWidth(3.0);
glBegin(GL_LINES);
   glColor3ub(0, 0,0);
     glVertex2f(-0.02f, 0.075f);
      glVertex2f(0.02f, 0.108f);
glEnd();

glBegin(GL_LINES);
   glColor3ub(0, 0,0);
     glVertex2f(-0.019f, 0.058f);
      glVertex2f(0.0f, 0.097f);
glEnd();


// hand left finger
float lfx[4]={-0.09f,-0.03f,-0.03f,-0.09f};
float lfy[4]={0.30f,0.34f, 0.31f,0.29f};
scallingObject(4, lfx, lfy, 0.15, 0.258, 243, 192, 182);

// hand right finger
float rfx[4]={0.05f,0.050f,0.09f,0.09f};
float rfy[4]={0.30f,0.28f, 0.28f,0.30f};
scallingObject(4, rfx, rfy, 0.15, 0.258, 243, 192, 182);


//right eye
glPointSize(2.0);
 glBegin(GL_POINTS);

     glColor3ub(255, 255, 255 );
     glVertex2f(0.0035f, 0.131f);
 glEnd();

 glPointSize(1.0);
 glBegin(GL_POINTS);

     glColor3ub(0, 0, 0 );
     glVertex2f(0.0034f, 0.131f);
 glEnd();

 //left eye

 glPointSize(2.0);
 glBegin(GL_POINTS);

     glColor3ub(255, 255, 255 );
     glVertex2f(-0.0035f, 0.131f);
 glEnd();

  glPointSize(1.0);
 glBegin(GL_POINTS);

     glColor3ub(0, 0, 0 );
     glVertex2f(-0.0034f, 0.131f);
 glEnd();


//moch



glPointSize(3.0);
 glBegin(GL_POINTS);

     glColor3ub(243, 192, 182 );
     glVertex2f(0.00f, 0.127f);

     glEnd();

     glPointSize(2.0);
 glBegin(GL_POINTS);

     glColor3ub(0 ,0, 0);
     glVertex2f(0.00f, 0.125f);

     glEnd();



}

void huMan(){


//hoody
  Circle(0.0f,0.13f,0.0f,0.0158f,246, 96, 66 );
//head & face
 Circle(0.0f,0.131f,0.0f,0.0095f,243, 192, 182  );
//upper body circle
  Circle(0.0f,0.109f,0.0f,0.012f,246, 96, 66 );

//upper body
float upx[4]={-0.08,0.08,0.08,-0.08};
float upy[4]={0.125,0.125,0.150,0.150};
scallingObject(4, upx, upy, 0.15, 0.74, 246, 96, 66);

// chain
glBegin(GL_LINES);
      glColor3ub(0,0,0);
      glVertex2f(.0f, 0.112f);
      glVertex2f(.0f, 0.095f);

   glEnd();
//Shoes left
float lshx[3]={-0.005,-0.1,-0.005};
float lshy[3]={0.13,0.13,0.20};
scallingObject(3, lshx, lshy, 0.2, 0.2, 0,0,0);


//Shoes right
float shx[3]={0.005,0.1,0.005};
float shy[3]={0.13,0.13,0.20};
scallingObject(3, shx, shy, 0.2, 0.2, 0,0,0);

// pant left
float lpx[4]={-0.08f,-0.07f,-0.005f,-0.002f};
float lpy[4]={0.50f,0.18f,0.18f,0.50f};
scallingObject(4, lpx, lpy, 0.15, 0.2, 246, 96, 66);


// pant right
float rpx[4]={0.08f,0.07f,0.005f,0.002f};
float rpy[4]={0.50f,0.18f,0.18f,0.50f};
scallingObject(4, rpx, rpy, 0.15, 0.2, 246, 96, 66);


// hand left top

float lhtx[4]={-0.15f,-0.10f,-0.04f,-0.08f};
float lhty[4]={0.35f,0.35f,0.45f,0.45f};
scallingObject(4, lhtx, lhty, 0.15, 0.25, 222, 59, 27);

// hand left bottom

float lhbx[4]={-0.10f,-0.15f,-0.08f,-0.02f};
float lhby[4]={0.35f,0.35f, 0.3f,0.3f};
scallingObject(4, lhbx, lhby, 0.15, 0.258, 222, 59, 27);

// hand right
float rhx[4]={0.05f,0.050f,0.09f,0.09f};
float rhy[4]={0.44f,0.28f, 0.28f,0.44f};
scallingObject(4, rhx, rhy, 0.15, 0.258, 222, 59, 27);

//gun
glLineWidth(3.0);
glBegin(GL_LINES);
   glColor3ub(0, 0,0);
     glVertex2f(-0.02f, 0.075f);
      glVertex2f(0.02f, 0.108f);
glEnd();

glBegin(GL_LINES);
   glColor3ub(0, 0,0);
     glVertex2f(-0.019f, 0.058f);
      glVertex2f(0.0f, 0.097f);
glEnd();


// hand left finger
float lfx[4]={-0.09f,-0.03f,-0.03f,-0.09f};
float lfy[4]={0.30f,0.34f, 0.31f,0.29f};
scallingObject(4, lfx, lfy, 0.15, 0.258, 243, 192, 182);

// hand right finger
float rfx[4]={0.05f,0.050f,0.09f,0.09f};
float rfy[4]={0.30f,0.28f, 0.28f,0.30f};
scallingObject(4, rfx, rfy, 0.15, 0.258, 243, 192, 182);


//right eye
glPointSize(2.0);
 glBegin(GL_POINTS);

     glColor3ub(255, 255, 255 );
     glVertex2f(0.0035f, 0.131f);
 glEnd();

 glPointSize(1.0);
 glBegin(GL_POINTS);

     glColor3ub(0, 0, 0 );
     glVertex2f(0.0034f, 0.131f);
 glEnd();

 //left eye

 glPointSize(2.0);
 glBegin(GL_POINTS);

     glColor3ub(255, 255, 255 );
     glVertex2f(-0.0035f, 0.131f);
 glEnd();

  glPointSize(1.0);
 glBegin(GL_POINTS);

     glColor3ub(0, 0, 0 );
     glVertex2f(-0.0034f, 0.131f);
 glEnd();


//moch



glPointSize(3.0);
 glBegin(GL_POINTS);

     glColor3ub(243, 192, 182 );
     glVertex2f(0.00f, 0.127f);

     glEnd();

     glPointSize(2.0);
 glBegin(GL_POINTS);

     glColor3ub(0 ,0, 0);
     glVertex2f(0.00f, 0.125f);

     glEnd();



}


void human2()
{
    glPushMatrix();
    glTranslatef(0.0f,-0.45f, 0.0f);
 Circle(0.2f,-0.05f,0.0f,0.025f, 0, 0, 0  );// hair

  Circle(0.2f,-0.053f,0.0f,0.02f,249, 236, 170 );// head
 Circle(0.2f,-0.10f,0.0f,0.027f,47, 45, 44 );//body


  glBegin(GL_QUADS);// upper body
      glColor3ub(47, 45, 44);
      glVertex2f(0.175f, -.1f);
      glVertex2f(0.225f, -.1f);
      glVertex2f(0.225f, -0.14f);
      glVertex2f(0.175f, -0.14f);
      glEnd();

      glBegin(GL_QUADS);// pants
      glColor3ub(47, 45, 44 );
      glVertex2f(0.175f, -.14f);
      glVertex2f(0.225f, -.14f);
      glVertex2f(0.225f, -0.18f);
      glVertex2f(0.175f, -0.18f);

      glEnd();



      glLineWidth(6.0);
      glBegin(GL_LINES);//pant divider
      glColor3ub(0, 0, 0);
      glVertex2f(0.200f, -0.14f);
      glVertex2f(0.200f, -0.18f);

      glEnd();



       glLineWidth(11.0);
      glBegin(GL_LINES);//hand left
      glColor3ub(60,60,61);
      glVertex2f(0.175f, -.09f);
      glVertex2f(0.175f, -.14f);


      glEnd();

       glLineWidth(11.0);
      glBegin(GL_LINES);//hand left
      glColor3ub(60,60,61);
      glVertex2f(0.225f, -.09f);
      glVertex2f(0.225f, -.14f);


      glEnd();


// Face
      glPointSize(5.0);
    glBegin(GL_POINTS);

     glColor3ub(255,255,255);
     glVertex2f(0.19f, -0.05f);

     glEnd();

 glPointSize(3.0);
    glBegin(GL_POINTS);

     glColor3ub(0,0,0);
     glVertex2f(0.19f, -0.05f);

     glEnd();


     glPointSize(5.0);
    glBegin(GL_POINTS);

     glColor3ub(255,255,255);
     glVertex2f(0.21f, -0.05f);

     glEnd();

     glPointSize(3.0);
    glBegin(GL_POINTS);

     glColor3ub(0,0,0);
     glVertex2f(0.21f, -0.05f);

     glEnd();


     glPointSize(5.0);
    glBegin(GL_POINTS);

     glColor3ub(146, 46, 19 );
     glVertex2f(0.1981f, -0.06f);

     glEnd();

     glPopMatrix();

}
void human2rain()
{
    glPushMatrix();
    glTranslatef(0.0f,-0.45f, 0.0f);
 Circle(0.2f,-0.05f,0.0f,0.025f, 0, 0, 0  );// hair

  Circle(0.2f,-0.053f,0.0f,0.02f,0,0,0 );// head
 Circle(0.2f,-0.10f,0.0f,0.027f,47, 45, 44 );//body


  glBegin(GL_QUADS);// upper body
      glColor3ub(47, 45, 44);
      glVertex2f(0.175f, -.1f);
      glVertex2f(0.225f, -.1f);
      glVertex2f(0.225f, -0.14f);
      glVertex2f(0.175f, -0.14f);
      glEnd();

      glBegin(GL_QUADS);// pants
      glColor3ub(47, 45, 44 );
      glVertex2f(0.175f, -.14f);
      glVertex2f(0.225f, -.14f);
      glVertex2f(0.225f, -0.18f);
      glVertex2f(0.175f, -0.18f);

      glEnd();



      glLineWidth(6.0);
      glBegin(GL_LINES);//pant divider
      glColor3ub(0, 0, 0);
      glVertex2f(0.200f, -0.14f);
      glVertex2f(0.200f, -0.18f);

      glEnd();



       glLineWidth(11.0);
      glBegin(GL_LINES);//hand left
      glColor3ub(60,60,61);
      glVertex2f(0.175f, -.09f);
      glVertex2f(0.175f, -.14f);


      glEnd();

       glLineWidth(11.0);
      glBegin(GL_LINES);//hand left
      glColor3ub(60,60,61);
      glVertex2f(0.225f, -.09f);
      glVertex2f(0.225f, -.14f);


      glEnd();


// Face
      glPointSize(5.0);
    glBegin(GL_POINTS);

     glColor3ub(0,0,0);
     glVertex2f(0.19f, -0.05f);

     glEnd();

 glPointSize(3.0);
    glBegin(GL_POINTS);

     glColor3ub(0,0,0);
     glVertex2f(0.19f, -0.05f);

     glEnd();


     glPointSize(5.0);
    glBegin(GL_POINTS);

     glColor3ub(0,0,0);
     glVertex2f(0.21f, -0.05f);

     glEnd();

     glPointSize(3.0);
    glBegin(GL_POINTS);

     glColor3ub(0,0,0);
     glVertex2f(0.21f, -0.05f);

     glEnd();


     glPointSize(5.0);
    glBegin(GL_POINTS);

     glColor3ub(0,0,0 );
     glVertex2f(0.1981f, -0.06f);

     glEnd();

     glPopMatrix();

}


void skynight(){


glBegin(GL_QUADS);
	glColor3ub(70,130,180);
	glVertex2f(-1,1);
	glVertex2f(1,1);
	glVertex2f(1,0);
	glVertex2f(-1,0);
	glEnd();


}
void star(){


glPointSize(2);
glBegin(GL_POINTS);
	glColor3ub(255,255,255);

	glVertex2f(-0.9,0.9);
	glVertex2f(-0.8,0.8);
	glVertex2f(-0.85,0.95);
    glVertex2f(-0.75,0.85);
    glVertex2f(-0.55,0.85);
    glVertex2f(-0.25,0.85);
    glVertex2f(-0.25,0.75);
    glVertex2f(-0.0,0.75);
    glVertex2f(0.25,0.85);
    glVertex2f(0.275,0.75);
    glVertex2f(0.0,0.75);
    glVertex2f(0.9,0.91);
	glVertex2f(0.82,0.82);
	glVertex2f(0.875,0.95);
    glVertex2f(0.75,0.815);
    glVertex2f(0.55,0.815);



glEnd();




}

//SUN

void sun()
{

     glPushMatrix();
    //glTranslatef(6,0,0);
   glTranslatef(0.8, 0.8, 0.0);
   glColor3f(1.0,1.0,0.0);
	glBegin(GL_POLYGON);

	for(int i=0;i<600;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.06;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y);
	}
	glEnd();
	glPopMatrix();
glBegin(GL_LINES);
	glColor3f(1.0,1.0,0.0);
	glVertex3f(0.8,0.8,0.0);
	glVertex3f(0.8,0.6,0.0);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,0.0);
	glVertex3f(0.8,0.8,0.0);
	glVertex3f(0.7,0.6,0.0);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,0.0);
	glVertex3f(0.8,0.8,0.0);
	glVertex3f(0.9,0.6,0.0);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,0.0);
	glVertex3f(0.8,0.8,0.0);
	glVertex3f(0.8,1.0,0.0);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,0.0);
	glVertex3f(0.8,0.8,0.0);
	glVertex3f(0.9,1.0,0.0);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,0.0);
	glVertex3f(0.8,0.8,0.0);
	glVertex3f(0.7,1.0,0.0);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,0.0);
	glVertex3f(0.8,0.8,0.0);
	glVertex3f(1.2,1.0,0.0);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,0.0);
	glVertex3f(0.8,0.8,0.0);
	glVertex3f(1.0,0.8,0.0);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,0.0);
	glVertex3f(0.8,0.8,0.0);
	glVertex3f(1.0,0.6,0.0);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,0.0);
	glVertex3f(0.8,0.8,0.0);
	glVertex3f(0.5,0.7,0.0);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,0.0);
	glVertex3f(0.8,0.8,0.0);
	glVertex3f(0.5,0.5,0.0);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,0.0);
	glVertex3f(0.8,0.8,0.0);
	glVertex3f(0.5,0.9,0.0);
	glEnd();
}


//MOON

int triangleAmount = 20;
GLfloat twicePi = 2.0f * PI;
GLfloat radus =.05f,radis=0.01;
void moon(){

GLfloat ggg=0.5; GLfloat hhh=0.8, rads=0.1;


	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(240,230,140);
		glVertex2f(ggg, hhh); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            ggg + (rads * cos(i *  twicePi / triangleAmount)),
			    hhh+ (rads * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


}

void displayrain()
{

glClear(GL_COLOR_BUFFER_BIT);
glClearColor(0.27, 0.50, 0.70, 1.0);
//glLoadIdentity();

building();
building();
grassANDroad();
lamp(255,255,51 );
car();
car_2();
car_3();
rain();
//police_car();
bush_1();
bush_2();

glPushMatrix();
glTranslatef(0.0f,poshuman2,0.0f);
human2rain();
glPopMatrix();
huMan3();
//glFlush();
glutSwapBuffers();

}
void displayday(void)
{

glClear(GL_COLOR_BUFFER_BIT);
glClearColor(0.0, 0.8, 1.0, 1.0);
//glLoadIdentity();
building();
sun();
grassANDroad();
lamp(255,255,255);
//lamp(255,255,51 );

car();
car_2();

//cloud_1();
//cloud_2();
car_3();
car_4();
//police_car();
bush_1();
bush_2();
//huMan();
human2();
huMan3();
//helicoptor();
//glFlush();  // Render now
glutSwapBuffers();


}

GLfloat robRotate=0.0;
void displaydayHeist(void)
{

glClear(GL_COLOR_BUFFER_BIT);
glClearColor(0.0, 0.8, 1.0, 1.0);
//glLoadIdentity();
building();
sun();
grassANDroad();
lamp(255,255,255);
//lamp(255,255,51 );

//car();
//car_2();

//cloud_1();
//cloud_2();
//car_3();
//car_4();
police_car();
bush_1();
bush_2();

glPushMatrix();
glTranslatef(-0.4f, 0.27f,0.0f);
huManRob();
glPopMatrix();

glPushMatrix();
glTranslatef(0.1f, -0.02f,0.0f);
huMan();
glPopMatrix();

glPushMatrix();
glTranslatef(-0.1f,-0.02f,0.0f);
huManRob1();
glPopMatrix();
 huMan();
//human2();
//huMan3();
helicoptor();
//glFlush();  // Render now
glutSwapBuffers();


}
void displaynight(){

skynight();
moon();
star();
building();
grassANDroad();
lamp(255,255,51 );
car();
car_2();
cloud_1();
cloud_2();
car_3();
car_4();
police_car();
bush_1();
bush_2();

huMan();

/*glPushMatrix();
     glTranslatef(po,0.0f, 0.0f);
car();
glPopMatrix();
glPushMatrix();
     glTranslatef(po,0.0f, 0.0f);
car_2();
glPopMatrix();

//cloud_1();
//cloud_2();
  glPushMatrix();
      glTranslatef(pos,0.0f, 0.0f);
car_3();
 glPopMatrix();
 glPushMatrix();
      glTranslatef(pos,0.0f, 0.0f);

car_4();
glPopMatrix();




      glPushMatrix();

  glTranslatef(0.0f,pos, 0.0f);



     glPopMatrix();
     police_car();
bush_1();

*/
     //glFlush();
    glutSwapBuffers();


 }


 void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {

        case  'h':
	        glutDestroyWindow(1);
	        glutInitWindowSize(1300,800);
          glutInitWindowPosition(200,0);
            glutCreateWindow("Highway Roadside View");
            glutKeyboardFunc(handleKeypress);
            glutDisplayFunc(displaydayHeist);
            break;

	    case  'd':
	        glutDestroyWindow(1);
	        glutInitWindowSize(1300,800);
          glutInitWindowPosition(200,0);
            glutCreateWindow("Highway Roadside View");
            glutKeyboardFunc(handleKeypress);
            glutDisplayFunc(displayday);
            break;

       case 'r':
            glutDestroyWindow(1);
	        glutInitWindowSize(1300,800);
           glutInitWindowPosition(200,0);
            glutCreateWindow("Highway Roadside View");
            glutKeyboardFunc(handleKeypress);
            glutDisplayFunc(displayrain);

           // PlaySound(TEXT("rain-07.wav"), NULL, SND_ASYNC);
            break;
         case 'n':
            glutDestroyWindow(1);
	        glutInitWindowSize(1300,800);
          glutInitWindowPosition(200,0);
            glutCreateWindow("Highway Roadside View");
            glutKeyboardFunc(handleKeypress);
            glutDisplayFunc(displaynight);

           // PlaySound(TEXT("cricket-2.wav"), NULL, SND_ASYNC);
          //  glutPostRedisplay();
            break;

         case  'H':
	        glutDestroyWindow(1);
	        glutInitWindowSize(1300,800);
          glutInitWindowPosition(100,0);
            glutCreateWindow("Highway Roadside View");
            glutKeyboardFunc(handleKeypress);
            glutDisplayFunc(displaydayHeist);
            break;

        case  'D':
	        glutDestroyWindow(1);
	        glutInitWindowSize(1300,800);
           glutInitWindowPosition(100,0);
            glutCreateWindow("Highway Roadside View");
            glutKeyboardFunc(handleKeypress);
            glutDisplayFunc(displayday);
            break;

        case 'R':
            glutDestroyWindow(1);
	        glutInitWindowSize(1300, 1200);
            glutInitWindowPosition(100,0);
            glutCreateWindow("Highway Roadside View");
            glutKeyboardFunc(handleKeypress);
            glutDisplayFunc(displayrain);

           // PlaySound(TEXT("rain-07.wav"), NULL, SND_ASYNC);
            break;
         case 'N':
            glutDestroyWindow(1);
	        glutInitWindowSize(1300,1200);
            glutInitWindowPosition(100,0);
            glutCreateWindow("Highway Roadside View");
            glutKeyboardFunc(handleKeypress);
            glutDisplayFunc(displaynight);

           // PlaySound(TEXT("cricket-2.wav"), NULL, SND_ASYNC);
          //  glutPostRedisplay();
            break;



    }
}

void sound()
{

    //PlaySound("a.wav", NULL, SND_ASYNC|SND_FILENAME);
    PlaySound("rain-01_2.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);

}


int main(int iArgc, char** cppArgv)

{

glutInit(&iArgc, cppArgv); // initialize the toolkit

glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // set the display mode

glutInitWindowSize(1300,800); // set window size


glutInitWindowPosition(100,0); // set window upper left corner position on screen

glutCreateWindow("A Heist in Royal Mint of Spain"); // open the screen window (Title: My First Attempt)

// register the callback functions

glutDisplayFunc(displayday);
myInit(); // additional initializations as necessary

glutKeyboardFunc(handleKeypress);
glutTimerFunc(1500, update, 0);
sound();

glutMainLoop(); // go into a endless loop

return 0;

}

