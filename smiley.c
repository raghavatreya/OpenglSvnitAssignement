//smiley face
//u13co051
#include<stdio.h>
#include<GL/glut.h>
#include<conio.h>
#include<math.h>

//initialise here 
void Init(){
     // set clear color
     glClearColor(1.0,1.0,1.0,0);
     // set color black
     glColor3f(0.0,0.0,0.0);
     //set a 2d orthographic view
     gluOrtho2D(-500,500,-500,500);
     }

// function smiley
void Smiley(){
     int x,y,h,r=100;
     x=0;
     y=r;
     h=1-r;
     
     //clear the buffer to preset values
     glClear(GL_COLOR_BUFFER_BIT);
     
     //plot two side points
     glBegin(GL_POINTS);
     glVertex2d(-20,0);
     glVertex2d(20,0);
     glEnd();
     
     //plot nose
     glBegin(GL_LINES);
     glVertex3f(0,20,0);
     glVertex3f(0,-50,0);
     glEnd();
     
    //plot mouth
     //third
      glBegin(GL_POINTS);
     //third quad
      glVertex2d(-x,-y);
      //glVertex2d(-y,-x);
      //fourth
      glVertex2d(x,-y);
    // glVertex2d(y,-x);
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
            //third
             glVertex2d(-x,-y);
             //glVertex2d(-y,-x);
             //fourth
             glVertex2d(x,-y);
             //glVertex2d(y,-x); 
     }
     glEnd();
     glFlush();
     }

int main(int argc, char **argv)
{
    //initialise glut library
    glutInit(&argc,argv);
    //set initial display mode
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    //set initial window poistion
    glutInitWindowPosition(0,0);
    //set initial window size
    glutInitWindowSize(500,500);
    //create window with title
    glutCreateWindow("smiley face");
    //initialize drawing color
    Init();
    //call the display function
    glutDisplayFunc(Smiley);
    //keep displaying till the program is closed
    glutMainLoop();
    
    return 0;
}

    
    
    
