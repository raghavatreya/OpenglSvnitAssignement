//shapes
//u13co022
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>

//initilise here
void init(void)
{
     //set clear color
	glClearColor(1.0,1.0,1.0,0.0);
	//set black color
	glColor3f(0.0,0.0,0.0);
	//set a 2D orthographic view
	gluOrtho2D(0.0,1000.0,0.0,1000.0);
	glShadeModel(GL_FLAT);
}

//shpes function
void Shapes(void)
{
     //clear the buffer
	glClear(GL_COLOR_BUFFER_BIT);
	
	
    //GL_POINTS
	glBegin(GL_POINTS);
	glVertex2d(40,960);
	glVertex2d(50,950);
	glVertex2d(70,950);
	glVertex2d(80,960);
	glVertex2d(90,970);
	glEnd();
    
    
    
	//GL_LINES
	glBegin(GL_LINES);
	glVertex2d(20,840);
	glVertex2d(60,900);

	glVertex2d(50,880);
	glVertex2d(110,870);

	glVertex2d(40,835);
	glVertex2d(80,815);

	glVertex2d(30,825);
	glVertex2d(80,840);
	glEnd();

  
	//GL_LINE_STRIP
	glBegin(GL_LINE_STRIP);
	glVertex2d(300,880);
	glVertex2d(500,815);
	glVertex2d(450,870);
	glVertex2d(350,840);
	glVertex2d(330,815);
	glEnd();

     
	//GL_LINE_LOOP
	glBegin(GL_LINE_LOOP);
	glVertex2d(700,880);
	glVertex2d(750,815);
	glVertex2d(950,815);
	glVertex2d(900,880);
	glVertex2d(850,840);
	glVertex2d(800,920);
	glEnd();

   
	//GL_TRIANGLES
	glBegin(GL_TRIANGLES);
	glVertex2d(20,450);
	glVertex2d(20,550);
	glVertex2d(170,450);
	glEnd();

   
	glBegin(GL_TRIANGLES);
	glVertex2d(220,500);
	glVertex2d(70,600);
	glVertex2d(370,600);
	glEnd();
   
   
	glBegin(GL_TRIANGLE_STRIP);
    	glColor3f(1,1,1);glVertex2d(500,600);
    	glColor3f(1,1,1);glVertex2d(500,400);
    	glColor3f(1,1,1);glVertex2d(550,600);
    	glColor3f(1,0,0);glVertex2d(600,400);
    	glColor3f(1,1,0);glVertex2d(650,600);
    	glColor3f(1,0,1);glVertex2d(680,350);
  	glEnd();


  
	glBegin(GL_TRIANGLE_FAN);
    	glColor3f(1,1,1);glVertex2d(850,450);
    	glColor3f(1,1,1);glVertex2d(850,550);
    	glColor3f(1,1,1);glVertex2d(900,510);
    	glColor3f(1,0,0);glVertex2d(925,470);
    	glColor3f(1,1,0);glVertex2d(910,420);
  	glEnd();

	glBegin(GL_QUADS);
	glVertex2d(20,100);
	glVertex2d(50,200);
	glVertex2d(150,230);
	glVertex2d(150,90);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2d(250,50);
	glVertex2d(270,300);
	glVertex2d(370,400);
	glVertex2d(320,50);
	glEnd();
	
	glBegin(GL_QUAD_STRIP);
	glColor3f(1,1,1);glVertex2d(450,100);
	glColor3f(1,1,1);glVertex2d(440,200);
	glColor3f(1,1,1);glVertex2d(480,100);
	glColor3f(1,1,0);glVertex2d(480,210);
	glColor3f(1,0,0);glVertex2d(550,130);
	glColor3f(1,0,1);glVertex2d(520,230);
	glColor3f(1,1,1);glVertex2d(580,140);
	glColor3f(0,1,1);glVertex2d(570,300);
	glEnd();
	
	glBegin(GL_POLYGON);
	glVertex2d(800,300);
	glVertex2d(900,340);
	glVertex2d(880,240);
	glVertex2d(750,70);
	glVertex2d(720,240);
	glEnd();
	


	glFlush();
}



int main(int argc, char **argv)
{
    //initialise glut library
	glutInit(&argc,argv);
	//set initial display mode
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	//set initial positon
	glutInitWindowPosition(0,0);
	// set window size
	glutInitWindowSize(1000,1000);
	//create window with title
	glutCreateWindow("Shapes");
	//initialise drawing color
    init();
    //call Shapes function
	glutDisplayFunc(Shapes);
	//keep displaying till the program is closed
	glutMainLoop();
	return 0;
}
