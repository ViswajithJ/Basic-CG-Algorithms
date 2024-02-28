/*

DDA LINE DRAWING ALGORITHM IMPLEMENTATION

*/

#include <stdio.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <math.h>
#include <unistd.h>

void dda() 
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPointSize(1);

	float x1, y1, x2, y2, dx, dy, steps, x_inc, y_inc;

	printf("DDA Line Drawing Algorithm\n\n");
	printf("Enter the x coordinate of starting point: ");
	scanf("%f", &x1);
	printf("Enter the y coordinate of starting point: ");
	scanf("%f", &y1);
	printf("Enter the x coordinate of ending point: ");
	scanf("%f", &x2);
	printf("Enter the y coordinate of ending point: ");
	scanf("%f", &y2);
	
	// find dx, dy
	dx = x2 - x1;
	dy = y2 - y1;


	//calc step from greater of dx,dy
	if (fabs(dx) > fabs(dy)) 
		steps = fabs(dx);
	else
		steps = fabs(dy);

	// find increment valeus by dx/steps and dy/steps
	x_inc = dx/steps;
	y_inc = dy/steps;
	x_inc = round(x_inc*10.0)/10.0;
	y_inc = round(y_inc*10.0)/10.0;

	
	for (int i = 0; i <=steps; i++)
	{	
		glBegin(GL_POINTS);
		glVertex2i(round(x1),round(y1));
		glEnd();
		glFlush();
		
		printf("(%.0f, %.0f)\n", round(x1), round(y1));

		x1 = x1 + x_inc;
		y1 = y1 + y_inc;
	}
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);

	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); 
	glutCreateWindow("DDA line drawing algorithm");
	
	glClearColor(0,0,0,1);
	glColor3f(0,1,0);
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100);

	glutDisplayFunc(dda);
	glutMainLoop();
}