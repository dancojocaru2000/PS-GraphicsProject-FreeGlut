#include "GlutDrawing.h"
#include "GlutData.h"

#ifndef LINUX_PLATFORM
#ifndef MAC_PLATFORM
#include <windows.h>
#endif
#endif

#include <stdlib.h>

#ifdef MAC_PLATFORM
//use native GLUT and openGL from mac
#include <GLUT/glut.h>
#include <OpenGL/glu.h>
#else
#include <GL/freeglut.h>
#include <GL/glu.h>
#endif
#include <pthread.h>

void drawGlut()
{

	glClear(GL_COLOR_BUFFER_BIT); // Clear display window
	GLint r, g, b;
	GLint x1, y1, x2, y2;

	// Calculate color

	r = rand() % 2;
	g = rand() % 2;
	b = rand() % 2;

	/*
	// Calculate X1, Y1 Points
	x1 = rand() % 800;
	y1 = rand() % 600;
	// Calculate X2, Y2 Points
	x2 = rand() % 800;
	y2 = rand() % 600;
*/
	//glLineWidth(10);
	// Set line segment color as glColor3f(R,G,B)
//	glColor3f(r, g, b);
	glColor3f(1,1,1);

	glBegin(GL_POINTS);


	pthread_mutex_lock(&lock);
	std::list<__Point2D> pointList = GlutData::getInstance()->getPoints();
	pthread_mutex_unlock(&lock);

	std::list<__Point2D>::iterator itr;
	for(itr = pointList.begin(); itr != pointList.end(); itr++)
		glVertex2i(itr->X,itr->Y);


	glEnd();

	glBegin(GL_LINES);

	pthread_mutex_lock(&lock);
	pointList = GlutData::getInstance()->getLines();
	pthread_mutex_unlock(&lock);

	for(itr = pointList.begin(); itr != pointList.end(); itr++)
		glVertex2i(itr->X,itr->Y);


	glEnd();


	glBegin(GL_TRIANGLES);

	pthread_mutex_lock(&lock);
	pointList = GlutData::getInstance()->getTriangles();
	pthread_mutex_unlock(&lock);

	int i=0;
	for(itr = pointList.begin(); itr != pointList.end(); i++,itr++)
	{
	    if (i%3==0)
		glColor3f(itr->r,itr->g,itr->b);
	    glVertex2i(itr->X,itr->Y);
	}

	glEnd();
	// Process all OpenGL routine s as quickly as possible
	glFlush();
	glutSwapBuffers();

}

void* startGluthThread(void *ptr)
{
	/*
	int argc= 1;
	char * argv="drawings";
	glutInit(&argc, &argv);
	*/
	// Set display mode
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	// Set top - left display window position.
	glutInitWindowPosition(100, 100);
	// Set display window width and height
	glutInitWindowSize(WIN_MAX_X, WIN_MAX_Y);
	// Create display window with the given title
	glutCreateWindow("PII C++");
	// Execute initialization procedure
	//init();
	// Set display window color to as glClearColor(R,G,B,Alpha)
	glClearColor(0.0, 0.0, 0.0, 0.0);
	// Set projection parameters.
	glMatrixMode(GL_PROJECTION);
	// Set 2D Transformation as gluOrtho2D(Min Width, Max Width, Min Height, Max Height)
	gluOrtho2D(0.0, 800, 0.0, 600);
	// Send graphics to display window
	glutDisplayFunc(drawGlut);
	glutIdleFunc(drawGlut);
	// Display everything and wait.
	glutMainLoop();
	pthread_exit(NULL);
}
void initGlutDrawing(int argc, char**argv)
{
	// Initialize GLUT
	glutInit(&argc, argv);
	pthread_t thread1;
	int iret1;
	iret1 = pthread_create( &thread1, NULL, startGluthThread, NULL);
}
