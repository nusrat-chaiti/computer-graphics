#include<windows.h>

#include <GL/glut.h>

#include<math.h>

# define PI           3.14159265358979323846







//#include <GL/glut.h>

void myInit(void)

{

glClearColor(0.0, 1.0, 1.0, 1.0); // set the bg color to a bright black

glMatrixMode(GL_PROJECTION); // set up appropriate matrices-

//glLoadIdentity(); // to be explained

//gluOrtho2D(0.0, 640.0, 0.0, 480.0);

gluOrtho2D(-1.0, 1.0, -0.6, 0.6 );



}



float angle=30.f;



void myDisplay(void)

{

glClear(GL_COLOR_BUFFER_BIT); // clear the screenn

glPushMatrix();







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


// 4th floor window 1 outer

glBegin(GL_POLYGON);

      glColor3ub(180,180,180);

      glVertex2f(-0.47f, 0.3f);
      glVertex2f(-.44f, 0.3f);
      glVertex2f(-.44f, 0.335f);
      glVertex2f(-.47f, 0.335f);
   glEnd();
   // 4th floor window 1 inner

glBegin(GL_POLYGON);

      glColor3ub(54,54,54);

      glVertex2f(-0.467f, 0.301f);
      glVertex2f(-.443f, 0.301f);
      glVertex2f(-.443f, 0.329f);

      glVertex2f(-.467f, 0.329f);
   glEnd();
   //4th floor window 1 inner line
   glLineWidth(2.0);
   glBegin(GL_LINES);

      glColor3ub(255,255,255);
      glVertex2f(-.454f, 0.301f);
      glVertex2f(-.454f, 0.3295f);
   glEnd();

   // 4th floor window 2 outer

glBegin(GL_POLYGON);

      glColor3ub(180,180,180);

      glVertex2f(-0.42f, 0.3f);
      glVertex2f(-.390f, 0.3f);
      glVertex2f(-.390f, 0.335f);

      glVertex2f(-.42f, 0.335f);
   glEnd();
   // 4th floor window 2 inner

glBegin(GL_POLYGON);

      glColor3ub(54,54,54);

      glVertex2f(-0.415f, 0.301f);
      glVertex2f(-.395f, 0.301f);
      glVertex2f(-.395f, 0.329f);

      glVertex2f(-.415f, 0.329f);
   glEnd();
   //4th floor window 2 inner line
   glLineWidth(2.0);
   glBegin(GL_LINES);

      glColor3ub(255,255,255);
      glVertex2f(-.405f, 0.301f);
      glVertex2f(-.405f, 0.3295f);
   glEnd();

     // 4th floor window 3  outer

glBegin(GL_POLYGON);

      glColor3ub(180,180,180);

      glVertex2f(-0.37f, 0.3f);
      glVertex2f(-.34f, 0.3f);
      glVertex2f(-.34f, 0.335f);

      glVertex2f(-.37f, 0.335f);
   glEnd();
   // 4th floor window 3 inner

glBegin(GL_POLYGON);

      glColor3ub(54,54,54);

      glVertex2f(-0.366f, 0.301f);
      glVertex2f(-.344f, 0.301f);
      glVertex2f(-.344f, 0.329f);

      glVertex2f(-.366f, 0.329f);
   glEnd();
   //4th floor window 3 inner line
   glLineWidth(2.0);
   glBegin(GL_LINES);

      glColor3ub(255,255,255);
      glVertex2f(-.355f, 0.301f);
      glVertex2f(-.355f, 0.3295f);
   glEnd();

   // 4th floor window 4  outer

glBegin(GL_POLYGON);

      glColor3ub(180,180,180);

      glVertex2f(-0.32f, 0.3f);
      glVertex2f(-.29f, 0.3f);
      glVertex2f(-.29f, 0.335f);

      glVertex2f(-.32f, 0.335f);
   glEnd();
   // 4th floor window 4 inner

glBegin(GL_POLYGON);

      glColor3ub(54,54,54);

      glVertex2f(-0.315f, 0.301f);
      glVertex2f(-.295f, 0.301f);
      glVertex2f(-.295f, 0.329f);

      glVertex2f(-.315f, 0.329f);
   glEnd();
   //4th floor window 4 inner line
   glLineWidth(2.0);
   glBegin(GL_LINES);

      glColor3ub(255,255,255);
      glVertex2f(-.306f, 0.301f);
      glVertex2f(-.306f, 0.3295f);
   glEnd();

   // 4th floor window 5  outer

glBegin(GL_POLYGON);

      glColor3ub(180,180,180);

      glVertex2f(-0.27f, 0.3f);
      glVertex2f(-.24f, 0.3f);
      glVertex2f(-.24f, 0.335f);

      glVertex2f(-.27f, 0.335f);
   glEnd();
   // 4th floor window 5 inner

glBegin(GL_POLYGON);

      glColor3ub(54,54,54);

      glVertex2f(-0.266f, 0.301f);
      glVertex2f(-.244f, 0.301f);
      glVertex2f(-.244f, 0.329f);

      glVertex2f(-.266f, 0.329f);
   glEnd();
   //4th floor window 5 inner line
   glLineWidth(2.0);
   glBegin(GL_LINES);

      glColor3ub(255,255,255);
      glVertex2f(-.255f, 0.301f);
      glVertex2f(-.255f, 0.3295f);
   glEnd();

  // 4th floor window 6  outer

glBegin(GL_POLYGON);

      glColor3ub(180,180,180);

      glVertex2f(-0.22f, 0.3f);
      glVertex2f(-.19f, 0.3f);
      glVertex2f(-.19f, 0.335f);

      glVertex2f(-.22f, 0.335f);
   glEnd();
   // 4th floor window 6 inner

glBegin(GL_POLYGON);

      glColor3ub(54,54,54);

      glVertex2f(-0.217f, 0.301f);
      glVertex2f(-.195f, 0.301f);
      glVertex2f(-.195f, 0.329f);

      glVertex2f(-.217f, 0.329f);
   glEnd();
   //4th floor window 6 inner line
   glLineWidth(2.0);
   glBegin(GL_LINES);

      glColor3ub(255,255,255);
      glVertex2f(-.206f, 0.301f);
      glVertex2f(-.206f, 0.3295f);
   glEnd();

   // 4th floor window 7  outer

glBegin(GL_POLYGON);

      glColor3ub(180,180,180);

      glVertex2f(-.17f, 0.3f);
      glVertex2f(-.14f, 0.3f);
      glVertex2f(-.14f, 0.335f);

      glVertex2f(-.17f, 0.335f);
   glEnd();
   // 4th floor window 7 inner

glBegin(GL_POLYGON);

      glColor3ub(54,54,54);

      glVertex2f(-0.168f, 0.301f);
      glVertex2f(-.146f, 0.301f);
      glVertex2f(-.146f, 0.329f);

      glVertex2f(-.168f, 0.329f);
   glEnd();
   //4th floor window 7 inner line
   glLineWidth(2.0);
   glBegin(GL_LINES);

      glColor3ub(255,255,255);
      glVertex2f(-.157f, 0.301f);
      glVertex2f(-.157f, 0.3295f);
   glEnd();


   // 4th floor window 8  outer

glBegin(GL_POLYGON);

      glColor3ub(180,180,180);

      glVertex2f(.17f, 0.3f);
      glVertex2f(.14f, 0.3f);
      glVertex2f(.14f, 0.335f);

      glVertex2f(.17f, 0.335f);
   glEnd();
   // 4th floor window 8 inner

glBegin(GL_POLYGON);

      glColor3ub(54,54,54);

      glVertex2f(0.168f, 0.301f);
      glVertex2f(.146f, 0.301f);
      glVertex2f(.146f, 0.329f);

      glVertex2f(.168f, 0.329f);
   glEnd();
   //4th floor window 8 inner line
   glLineWidth(2.0);
   glBegin(GL_LINES);

      glColor3ub(255,255,255);
      glVertex2f(.157f, 0.301f);
      glVertex2f(.157f, 0.3295f);
   glEnd();

 // 4th floor window 9  outer

glBegin(GL_POLYGON);

      glColor3ub(180,180,180);

      glVertex2f(0.22f, 0.3f);
      glVertex2f(.19f, 0.3f);
      glVertex2f(.19f, 0.335f);

      glVertex2f(.22f, 0.335f);
   glEnd();
   // 4th floor window 9 inner

glBegin(GL_POLYGON);

      glColor3ub(54,54,54);

      glVertex2f(0.217f, 0.301f);
      glVertex2f(.195f, 0.301f);
      glVertex2f(.195f, 0.329f);

      glVertex2f(.217f, 0.329f);
   glEnd();
   //4th floor window 9 inner line
   glLineWidth(2.0);
   glBegin(GL_LINES);

      glColor3ub(255,255,255);
      glVertex2f(.206f, 0.301f);
      glVertex2f(.206f, 0.3295f);
   glEnd();

     // 4th floor window 10  outer

glBegin(GL_POLYGON);

      glColor3ub(180,180,180);

      glVertex2f(0.27f, 0.3f);
      glVertex2f(.24f, 0.3f);
      glVertex2f(.24f, 0.335f);

      glVertex2f(.27f, 0.335f);
   glEnd();
   // 4th floor window 10 inner

glBegin(GL_POLYGON);

      glColor3ub(54,54,54);

      glVertex2f(0.266f, 0.301f);
      glVertex2f(.244f, 0.301f);
      glVertex2f(.244f, 0.329f);

      glVertex2f(.266f, 0.329f);
   glEnd();
   //4th floor window 10 inner line
   glLineWidth(2.0);
   glBegin(GL_LINES);

      glColor3ub(255,255,255);
      glVertex2f(.255f, 0.301f);
      glVertex2f(.255f, 0.3295f);
   glEnd();

   // 4th floor window 11  outer

glBegin(GL_POLYGON);

      glColor3ub(180,180,180);

      glVertex2f(0.32f, 0.3f);
      glVertex2f(.29f, 0.3f);
      glVertex2f(.29f, 0.335f);

      glVertex2f(.32f, 0.335f);
   glEnd();
   // 4th floor window 11 inner

glBegin(GL_POLYGON);

      glColor3ub(54,54,54);

      glVertex2f(0.315f, 0.301f);
      glVertex2f(.295f, 0.301f);
      glVertex2f(.295f, 0.329f);

      glVertex2f(.315f, 0.329f);
   glEnd();
   //4th floor window 11 inner line
   glLineWidth(2.0);
   glBegin(GL_LINES);

      glColor3ub(255,255,255);
      glVertex2f(.306f, 0.301f);
      glVertex2f(.306f, 0.3295f);
   glEnd();

   // 4th floor window 12  outer

glBegin(GL_POLYGON);

      glColor3ub(180,180,180);

      glVertex2f(0.37f, 0.3f);
      glVertex2f(.34f, 0.3f);
      glVertex2f(.34f, 0.335f);

      glVertex2f(.37f, 0.335f);
   glEnd();
   // 4th floor window 12 inner

glBegin(GL_POLYGON);

      glColor3ub(54,54,54);

      glVertex2f(0.366f, 0.301f);
      glVertex2f(.344f, 0.301f);
      glVertex2f(.344f, 0.329f);

      glVertex2f(.366f, 0.329f);
   glEnd();
   //4th floor window 12 inner line
   glLineWidth(2.0);
   glBegin(GL_LINES);

      glColor3ub(255,255,255);
      glVertex2f(.355f, 0.301f);
      glVertex2f(.355f, 0.3295f);
   glEnd();

   // 4th floor window 13 outer

glBegin(GL_POLYGON);

      glColor3ub(180,180,180);

      glVertex2f(0.42f, 0.3f);
      glVertex2f(.390f, 0.3f);
      glVertex2f(.390f, 0.335f);

      glVertex2f(.42f, 0.335f);
   glEnd();
   // 4th floor window 13 inner

glBegin(GL_POLYGON);

      glColor3ub(54,54,54);

      glVertex2f(0.415f, 0.301f);
      glVertex2f(.395f, 0.301f);
      glVertex2f(.395f, 0.329f);

      glVertex2f(.415f, 0.329f);
   glEnd();
   //4th floor window 13 inner line
   glLineWidth(2.0);
   glBegin(GL_LINES);

      glColor3ub(255,255,255);
      glVertex2f(.405f, 0.301f);
      glVertex2f(.405f, 0.3295f);
   glEnd();
   // 4th floor window 14 outer

glBegin(GL_POLYGON);

      glColor3ub(180,180,180);

      glVertex2f(0.47f, 0.3f);
      glVertex2f(.44f, 0.3f);
      glVertex2f(.44f, 0.335f);
      glVertex2f(.47f, 0.335f);
   glEnd();
   // 4th floor window 14 inner

glBegin(GL_POLYGON);

      glColor3ub(54,54,54);

      glVertex2f(0.467f, 0.301f);
      glVertex2f(.443f, 0.301f);
      glVertex2f(.443f, 0.329f);

      glVertex2f(.467f, 0.329f);
   glEnd();
   //4th floor window 14 inner line
   glLineWidth(2.0);
   glBegin(GL_LINES);

      glColor3ub(255,255,255);
      glVertex2f(.454f, 0.301f);
      glVertex2f(.454f, 0.3295f);
   glEnd();







//grass side
glBegin(GL_POLYGON);

      glColor3ub(32,164,71);

      glVertex2f(-1.0f, 0.0f);
      glVertex2f(-1.0f, -1.0);
      glVertex2f(1.0f, -1.0f);

      glVertex2f(1.0f, 0.0f);
   glEnd();


//Road base

glBegin(GL_POLYGON);

      glColor3ub(145,145,145);

      glVertex2f(-1.0f, 0.0f);
      glVertex2f(-1.0f, -0.16f);
      glVertex2f(1.0f, -0.16f);

      glVertex2f(1.0f, 0.0f);
   glEnd();

   //Stair

glBegin(GL_POLYGON);

      glColor3f(0.8f, 0.8f, 0.9f);

      glVertex2f(-0.22f, -0.05f);
      glVertex2f(0.22f, -0.05f);
      glVertex2f(0.15f, 0.06f);
      glVertex2f(-0.15f, 0.06f);
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

      glVertex2f(-0.5f, -0.16f);
      glVertex2f(-0.8f, -1.0);
      glVertex2f(0.8f, -1.0f);

      glVertex2f(0.5f, -0.16);
   glEnd();


//road border middle grass
//left
glLineWidth(6.0);
glBegin(GL_LINES);

      glColor3ub(255,255,255);

      glVertex2f(-0.5f, -0.16f);//left
      glVertex2f(-0.8f, -1.0);

      glVertex2f(-0.503f, -.16f);//middle
      glVertex2f(0.503f, -0.16f);


      glVertex2f(0.5f, -0.16f);//right
      glVertex2f(0.8f, -1.0f);

      glVertex2f(-0.8f, -0.16f);//left left grass down
      glVertex2f(-1.2f, -1.0f);


      glVertex2f(-0.798f, -0.1605f);//left left grass up
      glVertex2f(-1.0f, -0.1605f);



      glVertex2f(0.8f, -0.16f);//right right grass down
      glVertex2f(1.2f, -1.0f);


      glVertex2f(0.798f, -0.1609f);//right right grass up
      glVertex2f(1.0f, -0.1609f);

      glVertex2f(-1.0f, -0.005f);//00 line under building
      glVertex2f(1.0f, -0.005f);


      glVertex2f(-1.0f, -0.08f);//1st dash under building
      glVertex2f(-0.92f, -0.08f);

      glVertex2f(-0.88f, -0.08f);//2nd dash under building
      glVertex2f(-0.80f, -0.08f);

      glVertex2f(-0.76f, -0.08f);//3rd dash under building
      glVertex2f(-0.68f, -0.08f);

      glVertex2f(-.64f, -0.08f);//4th dash under building
      glVertex2f(-0.56f, -0.08f);

      glVertex2f(-.52f, -0.08f);//5th dash under building
      glVertex2f(-0.44f, -0.08f);

      glVertex2f(-.40f, -0.08f);//6th dash under building
      glVertex2f(-0.32f, -0.08f);

      glVertex2f(-.28f, -0.08f);//7th dash under building
      glVertex2f(-0.20f, -0.08f);

      glVertex2f(-.16f, -0.08f);//8th dash under building
      glVertex2f(-0.08f, -0.08f);

      glVertex2f(-.04f, -0.08f);//9th dash under building
      glVertex2f(0.04f, -0.08f);

      glVertex2f(.08f, -0.08f);//10th dash under building
      glVertex2f(0.16f, -0.08f);

      glVertex2f(.20f, -0.08f);//11th dash under building
      glVertex2f(0.28f, -0.08f);

      glVertex2f(.32f, -0.08f);//12th dash under building
      glVertex2f(0.40f, -0.08f);

      glVertex2f(.44f, -0.08f);//13th dash under building
      glVertex2f(0.52f, -0.08f);

      glVertex2f(.56f, -0.08f);//14th dash under building
      glVertex2f(0.64f, -0.08f);

      glVertex2f(.68f, -0.08f);//15th dash under building
      glVertex2f(0.76f, -0.08f);

      glVertex2f(.80f, -0.08f);//16th dash under building
      glVertex2f(0.88f, -0.08f);

       glVertex2f(.92f, -0.08f);//17th dash under building
      glVertex2f(1.0f, -0.08f);


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

      glColor3ub(0,0,0);//frontleft

      glVertex2f(0.22f, -0.38f);

      glVertex2f(0.08f, -0.52f);



      glColor3ub(0,0,0);//frontright

      glVertex2f(0.18f, -0.38f);
      glVertex2f(0.30f, -0.57f);


      glColor3ub(0,0,0);//back right

      glVertex2f(0.46f, -0.35f);
      glVertex2f(0.58f, -0.55f);

      glVertex2f(0.50f, -0.365f);
      glVertex2f(0.48f, -0.385f);

      glEnd();

glFlush();  // Render now









}



int main(int iArgc, char** cppArgv)

{

glutInit(&iArgc, cppArgv); // initialize the toolkit

glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set the display mode

glutInitWindowSize(2000,1500); // set window size

glutInitWindowPosition(100, 150); // set window upper left corner position on screen

glutCreateWindow("My First Attempt"); // open the screen window (Title: My First Attempt)

// register the callback functions

glutDisplayFunc(myDisplay);

myInit(); // additional initializations as necessary

glutMainLoop(); // go into a endless loop

return 0;

}
