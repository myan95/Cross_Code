#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <glut.h>
#include <iomanip>

GLsizei winWidth = 400, winHeight = 300;

float xCameraPos = 400.0, yCameraPos = 0.0, zCameraPos = 0.0,
xCameraLookAt = 0.0, yCameraLookAt = 0.0, zCameraLookAt = 0.0;

GLfloat light_position[] = { 200.0, 200.0, 200.0, 0.0 };
GLfloat light_ambient[] = { 0.5, 0.5, 0.5, 1.0 };
int h = 0;
bool isLightOn;
float year =0.0; 


void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);

	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	isLightOn = true;
	glShadeModel(GL_SMOOTH);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, 1.33, 10, 2000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(xCameraPos, yCameraPos, zCameraPos, xCameraLookAt, yCameraLookAt, zCameraLookAt, 0.0, 1.0, 0.0);
}
void drawModel(void){

	 
	   glColor3f(0,0,1);
	glPolygonMode(GL_FRONT,GL_FILL);
	glPolygonMode(GL_BACK,GL_FILL);

	glPushMatrix();
	glRotated(90,1,0,0);
	glColor3f(1.0,0.8,0.3);
	glutSolidSphere(60,100,100);
    
  
    glPushMatrix();
	glRotated(year,0.0,1.0,0.0);
    glTranslatef(100,0,0);
	glRotatef(-year,0.0,1.0,0.0);
    glColor3f(0.4,0.6,0.3);
    glutSolidSphere(30,50,50);
    

   glPushMatrix();
    glTranslatef(0,0,100);
    glColor3f(0.3,0.3,0.5);
   glutSolidSphere(10,30,30);
 
	glPopMatrix();
	glPopMatrix();


}

void displayFunc(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	gluLookAt(xCameraPos, yCameraPos, zCameraPos, xCameraLookAt, yCameraLookAt, zCameraLookAt, 0.0, 1.0, 0.0);

	glPopMatrix();

	drawModel();

	glutSwapBuffers();
	glFlush();
}

void winReshapeFcn(GLint newWidth, GLint newHeight)
{
	glViewport(0, 0, newWidth, newHeight);
	glClear(GL_COLOR_BUFFER_BIT);
}

void keyboardFunc(unsigned char key, int x, int y){
	glRotatef(1.0, -1.0, 0.0, 0.0);
	    glutPostRedisplay();

	glRotatef(-1.0, 0.0, 1.0, 0.0);

    glutPostRedisplay();


}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);							// Initalise GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);	// Set display mode

	glutInitWindowPosition(100, 100);				// Set window position
	glutInitWindowSize(winWidth, winHeight);		// Set window size
	glutCreateWindow("Cross");			// Create display window

	init();

	glutDisplayFunc(displayFunc);	// Set the display function
	glutReshapeFunc(winReshapeFcn);	// Set up the window reshape callback function
	glutKeyboardFunc(keyboardFunc);	// Set the callback function for key presses

	glutMainLoop();

	return 0;
}

