//clock 
//u13co022
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<GL/glut.h>
void Initialise();
void clock(void);
int r;
int main(int argc,char **argv)
{
    printf("Enter radius of circle\n");
    scanf("%d",&r);

    //initialise glut library
    glutInit(&argc,argv);
    //set initial display mode
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    //set initial window position
    glutInitWindowPosition(0,0);
    //set initial window size
    glutInitWindowSize(600,600);
    //create a window with the title"
    glutCreateWindow("Draw clock using open gl");
    //initialize drawing colours
    Initialise();
    //call the displaying function
    glutDisplayFunc(clock);
    //keep displaying till the program is closed
    glutMainLoop();
    
    return 0;
}
void Initialise()
{
     //set clear color to white
     glClearColor(1.0,1.0,1.0,0);
     //set fill color to black
     glColor3f(0.0,0.0,0.0);
     //set a 2d orthographic viewing region
     gluOrtho2D(-600,600,-600,600);
}
void clock(void)
{
     int x,y,h;
     x=0;
     y=r;
     h=1-r;
     //clear the buffer to preset values
     glClear(GL_COLOR_BUFFER_BIT);
     //plot the points
     glBegin(GL_POINTS);
     // plot the first point
     //first quard
     glVertex2d(x,y);
     glVertex2d(y,x);
     //third
     glVertex2d(-x,-y);
     glVertex2d(-y,-x);
     //second
     glVertex2d(-x,y);
     glVertex2d(-y,x);
     //fourth
     glVertex2d(x,-y);
     glVertex2d(y,-x);
     while(y>x)
     {
            if(h<0)
            {
                   h=h+2*x+3;
            } 
            else
            {
                h=h+2*(x-y)+5;
                y=y-1;
            }
            x=x+1;
            //first 
             glVertex2d(x,y);
             glVertex2d(y,x);
             //third
             glVertex2d(-x,-y);
             glVertex2d(-y,-x);
            //second
             glVertex2d(-x,y);
             glVertex2d(-y,x);
             //fourth
             glVertex2d(x,-y);
             glVertex2d(y,-x); 
     }
     glEnd();
     
     //draw minute line
     glBegin(GL_LINES);
		glVertex3f(0, 0, 0.0);
		glVertex3f(0, r-((r*5)/100), 0.0);
     
     glEnd();
     
     //draw hour line
      glBegin(GL_LINES);
      glVertex3f(0,0,0.0);
      glVertex3f(r/2,r/2, 0.0);
      glEnd();
     
     glFlush();
}
