#include <cstdio>
#include<GL/gl.h>
#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
using namespace std;

int min_win_X, min_win_Y, max_win_X, max_win_Y; //took variable for maximum and minimum window points
int fst_point_X, fst_point_Y, scnd_point_X, scnd_point_Y; // took var for line points that we are gonna clip


//initializing the code values

int code1[4] = { 0, 0, 0, 0 };
int code2[4] = { 0, 0, 0, 0 };

bool isReject = false;


//here we are checking the code value to see if it crosses the window size
// if it does then we are gonna make that code value "1"
int getcode1(int x, int y) {
	if (y > max_win_Y)
	{
		code1[0] = 1;
	}

	if (y < min_win_Y)
	{
		code1[1] = 1;
	}

	if (x > max_win_X)
	{
		code1[2] = 1;
	}

	if (x < min_win_X)
	{
		code1[3] = 1;
	}

	int codeRes1 = code1[0] * 1000 + code1[1] * 100 + code1[2] * 10 + code1[3];

	return codeRes1;
}

//here we are checking the code value of other points  to see if it crosses the window size
// if it does then we are gonna make that code value "1"
int getcode2(int x, int y) {
	if (y > max_win_Y)
	{
		code2[0] = 1;
	}

	if (y < min_win_Y)
	{
		code2[1] = 1;
	}

	if (x > max_win_X)
	{
		code2[2] = 1;
	}

	if (x < min_win_X)
	{
		code2[3] = 1;
	}

	int codeRes2 = code2[0] * 1000 + code2[1] * 100 + code2[2] * 10 + code2[3];

	return codeRes2;
}

void generateCodeForPoints()  // function for generating code values
{
	getcode1(fst_point_X, fst_point_Y);
	getcode2(scnd_point_X, scnd_point_Y);
}


void drawLine(int x0, int y0, int x1, int y1) // this function will draw the line after clipping
{
	glBegin(GL_LINES);
	glVertex2i(x0, y0);
	glVertex2i(x1, y1);
	glEnd();
}


void cohen_suth_line()
{
    //here we will see if our line points are within window or not
    //if within window then we are gonna line draw the line, we dont need clipping

	if (getcode1(fst_point_X, fst_point_Y) == 0 && getcode2(scnd_point_X, scnd_point_Y) == 0 && isReject == false)
	{
		drawLine(fst_point_X, fst_point_Y, scnd_point_X, scnd_point_Y);
	}

	else
	{
		for (int i = 0; i < 4; i++)
		{
			// Is both point rejected
			if (code1[i] == code2[i] && code1[i] == 1)
			{
				isReject = true;
				break;
			}


		}

		if (isReject)
		{
			cout << "Both point rejected" << endl;
		}
		else
		{
		    //here we do the clipping part by searching the code of "1" in our array
            // if we get "1" then  we simply cut this line point upto window size

			for (int i = 0; i < 4; i++)
			{
				if (code1[i] == 1)
				{
					switch (i)
					{

					case 0:
						fst_point_Y = max_win_Y;
						break;

					case 1:
						fst_point_Y = min_win_Y;
						break;

					case 2:
						fst_point_X = max_win_X;
						break;

					case 3:
						fst_point_X = min_win_X;
						break;
					}
				}

				if (code2[i] == 1)
				{
					switch (i)
					{

					case 0:
						scnd_point_Y = max_win_Y;
						break;

					case 1:
						scnd_point_Y = min_win_Y;
						break;

					case 2:
						scnd_point_X = max_win_X;
						break;

					case 3:
						scnd_point_X = min_win_X;
						break;
					}
				}



			}

			drawLine(fst_point_X, fst_point_Y, scnd_point_X, scnd_point_Y);
		}
	}
}


void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}


void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0, 1.0, 0.0);
	glRecti(min_win_X, min_win_Y, max_win_X, max_win_Y);

	glColor3f(0.0, 0.0, 0.0);
	cohen_suth_line();

	glFlush();
}

int main(int argc, char** argv)
{



	cout << "Enter Minimum window co-ordinates: "; cin >> min_win_X >> min_win_Y; //taking input for window size
	cout << "Enter Maximum window co-ordinates: "; cin >> max_win_X >> max_win_Y;

	cout << "Enter co-ordinates of first point of line: "; cin >> fst_point_X >> fst_point_Y;  //first point of line
	cout << "Enter co-ordinates of second point of line: "; cin >> scnd_point_Y >> scnd_point_X; // second point of line

	// 4 digit code generator
	generateCodeForPoints();

	cout << "First  point code: " << code1[0] << code1[1] << code1[2]<< code1[3] << endl;
	cout << "Second point code: " << code2[0] << code2[1] << code2[2] << code2[3] << endl;



	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow(" Line Clipping with Cohen-Sutherland algorithm");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();

}
