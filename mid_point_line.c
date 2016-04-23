// mid-point line  ALGO………
// u13co022...
#include <stdio.h>
#include <math.h>
#include <glut.h> or <GL/glut.h>
double X1, Y1, X2, Y2;


void LineMid(void)
{
   int x,y,dx,dy,d,deltaE, deltaNE;
   x = X1;
   y = Y1;   
   dx = X2-X1;
   dy = Y2-Y1;
   d = 2*dy-dx;
   deltaE = 2*dy;
   deltaNE = 2*(dy-dx);
   
    /* Clears buffers to preset values */
 glClear(GL_COLOR_BUFFER_BIT);
 
 /* Plot the points */
 glBegin(GL_POINTS);
   
   
    /* Plot the first point */
     glVertex2d(x,y);
 
   while(x<X2) {
   if(d<0) {
   
   d=d+deltaE;
   x=x+1;
}
   else {
   d=d+deltaNE;
   x=x+1;
   y=y+1;
}
    glVertex2d(x,y);
}


   
   
   

 


 glEnd();
 glFlush();
     
     
}



void Init()
{
 /* Set clear color to white */
 glClearColor(1.0,1.0,1.0,0);
 /* Set fill color to black */
 glColor3f(0.0,0.0,0.0);
 /* glViewport(0 , 0 , 640 , 480); */
 /* glMatrixMode(GL_PROJECTION); */
 /* glLoadIdentity(); */
 gluOrtho2D(0 , 640 , 0 , 480);
}



void main(int argc, char **argv)
{
 printf("Enter two end points of the line to be drawn:\n");
 printf("\n************************************");
 printf("\nEnter Point1( X1 , Y1):\n");
 scanf("%lf%lf",&X1,&Y1);
 printf("\n************************************");
 printf("\nEnter Point1( X2 , Y2):\n");
 scanf("%lf%lf",&X2,&Y2);
 
 
  /* Initialise GLUT library */
 glutInit(&argc,argv);
 
 /* Set the initial display mode */
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 
  /* Set the initial window position and size */
 glutInitWindowPosition(0,0);
 glutInitWindowSize(640,480);
 
 /* Create the window with title "DDA_Line" */
 glutCreateWindow("mid-point Line");
 
 /* Initialize drawing colors */
 Init();
 
 
  /* Call the displaying function */
 glutDisplayFunc(LineMid);
 
  /* Keep displaying untill the program is closed */
 glutMainLoop();
}


 
 
 
