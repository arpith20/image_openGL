/************************************************************************
Author: Arpith
System: Ubuntu 12.04; Code::Blocks 10.05;

Note:SOIL library has been used in this code.
You may download the library from here: http://www.lonesock.net/soil.html
************************************************************************/

#include <iostream>
#include<GL/glut.h>
#include "src/SOIL.h"

using namespace std;

GLuint tex_2d;

int x=500;

void init()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(1.0,0.0,0.0);
	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,499.0,0.0,499.0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,1.0);

	glEnable(GL_TEXTURE_2D);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	tex_2d = SOIL_load_OGL_texture
		 (
			 "img_test.png",
			 SOIL_LOAD_RGB,
			 SOIL_CREATE_NEW_ID,
			 SOIL_FLAG_NTSC_SAFE_RGB
		 );
	glBindTexture(GL_TEXTURE_2D, tex_2d);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    //determint coordinates of the quad on which you will 'load' an image
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 1.0);
	glVertex2f(0,0);
	glTexCoord2f(0.0, 0.0);
	glVertex2f(0,x);
	glTexCoord2f(1.0, 0.0);
	glVertex2f(x,x);
	glTexCoord2f(1.0, 1.0);
	glVertex2f(x,0);
	glEnd();
        glDisable(GL_TEXTURE_2D);
        glFlush();

}


int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Image -- Arpith");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
