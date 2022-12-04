#pragma once
#include<gl/glut.h>
#include"Point3.h"

class DrawFloorAndWall{
public:
	GLuint floorTexture,WallTexture;

	GLvoid drawFloor(GLint width, GLint length) {
		glColor3ub(255, 255, 255);
		glBindTexture(GL_TEXTURE_2D, floorTexture);

		GLint rate = 5;
		for (GLint i = 0; i < width; i++) {
			for (GLint j = 0; j < length; j++) {
				glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0);
				glVertex3f(rate * i, rate * 0, rate * j);
				glTexCoord2f(1.0, 0.0);
				glVertex3f(rate * (i + 1), rate * 0, rate * j);
				glTexCoord2f(1.0, 1.0);
				glVertex3f(rate * (i + 1), rate * 0, rate * (j + 1));
				glTexCoord2f(0.0, 1.0);
				glVertex3f(rate * i, rate * 0, rate * (j + 1));
				glEnd();
			}
		}
	}

	GLvoid drawWall(GLfloat width,GLfloat height) {
		glColor3ub(255, 255, 255);
		glBindTexture(GL_TEXTURE_2D, WallTexture);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);
		glVertex3f(0, 0, 0);
		glTexCoord2f(1.0, 0.0);
		glVertex3f(width, 0, 0);
		glTexCoord2f(1.0, 1.0);
		glVertex3f(width, height, 0);
		glTexCoord2f(0.0, 1.0);
		glVertex3f(0, height, 0);
		glEnd();
	}
};