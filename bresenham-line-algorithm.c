/*

BRESENHAM'S LINE DRAWING ALGORITHM IMPLEMENTATION

Viswajith J.
Roll no. 60
S6 CSE

*/

#include <stdio.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <math.h>
#include <unistd.h>

void bresenham_line() 
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPointSize(3);

	int x1, y1, x2, y2, dx, dy, p;

	printf("Bresenham's Line Drawing Algorithm\n\n");
	printf("Enter the x coordinate of starting point: ");
	scanf("%d", &x1);
	printf("Enter the y coordinate of starting point: ");
	scanf("%d", &y1);
	printf("Enter the x coordinate of ending point: ");
	scanf("%d", &x2);
	printf("Enter the y coordinate of ending point: ");
	scanf("%d", &y2);
	
	// find dx, dy
	dx = x2 - x1;
	dy = y2 - y1;

	p = 2*dy - dx;
	
	while(x1 <= x2)
	{	
		printf("(%d, %d)\n", x1, y1);
		glBegin(GL_POINTS);
		glVertex2i(x1, y1);
		
		x1++;

		if (p < 0) 
			p += 2*dy;
		else
		{
			y1++;
			p += 2*dy - 2*dx;
		}

		
		glEnd();
		glFlush();
		

	}
	
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);

	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); 
	glutCreateWindow("Bresenham's line drawing algorithm");
	
	glClearColor(0,0,0,1);
	glColor3f(0,1,0);
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100);
    
	glutDisplayFunc(bresenham_line);
	glutMainLoop();
}