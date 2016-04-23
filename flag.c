#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <GL/glut.h>

int xc=500, yc=300,r;
#define PI 3.14159265


void Circle(int r)
{
	int x=0,y=r,h=1-r;

	while(x<=y)
	{
		glBegin(GL_POINTS);
	
		glVertex2i(xc+x,yc+y);
		glVertex2i(xc+y,yc+x);
		glVertex2i(xc-x,yc+y);
		glVertex2i(xc-y,yc+x);
		glVertex2i(xc-x,yc-y);
		glVertex2i(xc-y,yc-x);
		glVertex2i(xc+x,yc-y);
		glVertex2i(xc+y,yc-x);

		glEnd();

		if(h<0)
			h+=2*x+3;
		else
		{
			h+=2*(x-y)+5;
			y--;
		}
		x++;
	}

}

double ang2rad(double angle)
{
  double radian = (PI/180)*angle;
  return radian;
}

void Lines(void)
{
	glBegin(GL_LINES);
	double angle_start_0 = 0;
	double angle_inc = 15;
        while (angle_start_0!=180) {
	  glVertex2f(xc + 100*cos(ang2rad(angle_start_0)), yc + 100*sin(ang2rad(angle_start_0)));
	  glVertex2f(xc + 100*cos(ang2rad(angle_start_0 + 180)), yc + 100*sin(ang2rad(angle_start_0 + 180)));
		     angle_start_0 += angle_inc;	     
	}
	   
	glEnd();
	
}

void Flag(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0,0.27,0.0);
	glRecti(0,600,1000,400);

	glColor3f(1.0,1.0,1.0);
	glRecti(0,400,1000,200);

	glColor3f(0.1,0.8,0.1);
	glRecti(0,200,1000,0);

	glColor3f(0.0,0.0,1.0);
	Circle(100);
	Lines();
	glFlush();
}

void init(void)
{
	glClearColor(0.0,0.0,0.0,0.0);
	gluOrtho2D(0.0,1000.0,0.0,600.0);
}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1000,600);
	glutInitWindowPosition(500,300);
	glutCreateWindow("Indian Flag");
	init();
	glutDisplayFunc(Flag);
	glutMainLoop();
	return 0;
}
