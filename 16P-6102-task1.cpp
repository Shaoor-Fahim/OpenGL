#include <GL\glew.h>
#include <GL\freeglut.h>
#include<math.h>
#include <iostream>
using namespace std;
GLfloat	theta;
GLfloat xpos= 10.00;
GLfloat ypos = 170.00;
GLfloat yr,xr;
GLint cunt=0;
GLfloat g = -9.81;
void timer(int x);
void drawcircle()
{
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		theta = i * 3.142 / 180;
		glVertex2f(xpos+(20*cos(theta)), ypos+(20*sin(theta)));
		cout << xpos<<"   "<<ypos<<endl;
		yr = ypos;
	}
	glEnd();
	glFlush();
}
void drawline()
{
	glColor3f(0, 1, 1);
	glBegin(GL_LINES);
	glVertex2f(0, 150);
	glVertex2f(500, 150);
	glEnd();	
}
void display()
{
	glClearColor(0.0, 0.0, 0.0, 0.0); // Background (R, G, B, alpha), all b/w 0 and 1
	glClear(GL_COLOR_BUFFER_BIT); // Clear output buffer to window color
	drawcircle();
	drawline();
	glFlush(); // force OpenGL to empty the buffer and render
}
void timer(int x)
{
	if (x == 1)
	{
		if(xpos>0)
		xpos = xpos - 10;
		glutTimerFunc(1000 / 25., timer, 1);
	}
	if (x == 2)
	{
		if(xpos<500)
		xpos = xpos + 10;
		glutTimerFunc(1000 / 25., timer, 2);
	}
	if (x == 0)
	{
		ypos = ypos + 10;
		if (ypos >= 240)
		{
			glutTimerFunc(1000 / 25, timer, 4);
		}
		glutTimerFunc(1000 / 25, timer, 0);
	}
	if (x == 4)
	{
		if (ypos >= 170)
		{
			ypos = ypos - 10;
		}
		glutTimerFunc(1000 / 25, timer, 4);
	}
	glutPostRedisplay();
}
void specialkey(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		timer(0);
		break;
	case GLUT_KEY_LEFT:
		timer(1);
		break;
	case GLUT_KEY_RIGHT:
		timer(2);
		break;
	}
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv); // Initializes GLUT Toolkit
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(300, 300);
	glutCreateWindow("Simple Circle");
	gluOrtho2D(0, 500, 0, 500);
	glutDisplayFunc(display); // Register call back routine for window updates
	glutSpecialFunc(specialkey);
	glutTimerFunc(1000 / 25., timer, 0);
	glutMainLoop(); // Starts the toolkit loop (infinite)
}