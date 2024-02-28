/*

BRSENHAM'S CIRCLE DRAWING ALGORITHM IMPLEMENTATION

Viswajith J.
Roll no. 60
S6 CSE

*/

#include <stdio.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <math.h>
#include <unistd.h>

void bresenham_circle() 
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPointSize(1);

	int x, y, xc, yc, radius, p;

	printf("Bresenham's Circle Drawing Algorithm\n\n");
	printf("Enter the x coordinate of center: ");
	scanf("%d", &xc);
	printf("Enter the y coordinate of center: ");
	scanf("%d", &yc);
	printf("Enter the radius of circle: ");
	scanf("%d", &radius);

	x = 0;
	y = radius;
	p = 3-2*radius;

	while(x<y)
	{	

		
		printf("(%d, %d)", x+xc, y+yc);
		printf("(%d, %d)", x+xc, -y+yc);
		printf("(%d, %d)", y+xc, -x+yc);
		printf("(%d, %d)", -y+xc, -x+yc);
		printf("(%d, %d)", -x+xc, -y+yc);
		printf("(%d, %d)", -x+xc, y+yc);
		printf("(%d, %d)", -y+xc, x+yc);
		printf("(%d, %d)", y+xc, x+yc);
		printf("\n");
		glBegin(GL_POINTS);
		glVertex2i(x+xc, y+yc);
		glVertex2i(x+xc, -y+yc);
		glVertex2i(y+xc, -x+yc);
		glVertex2i(-y+xc, -x+yc);
		glVertex2i(-x+xc, -y+yc);
		glVertex2i(-x+xc, y+yc);
		glVertex2i(-y+xc, x+yc);
		glVertex2i(y+xc, x+yc);
		
		if (p < 0) 
			p += (4*x) + 6;
		else
		{
			
			p += 4*(x-y) + 10;
			y--;
		}
		x++;
		
		glEnd();
		glFlush();
		

	}

}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);

	glutInitWindowSize(600, 600);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); 
	glutCreateWindow("Bresenham's Circle drawing algorithm");
	
	glClearColor(0,0,0,1);
	glColor3f(0,1,0);
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100);

	glutDisplayFunc(bresenham_circle);
	glutMainLoop();
}