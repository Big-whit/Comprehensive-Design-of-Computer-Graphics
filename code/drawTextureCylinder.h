#pragma once
#include<cmath>
#include<gl/glut.h>
#define PI 3.1415926

class DrawTextureCylinder {
public:
	GLfloat radius = 1.0f;
	GLfloat height = 1.0f;

	GLvoid draw(GLuint cylinderTexture)
	{
		GLfloat angle = 0.0f;
		GLfloat angle_stepsize = 12.0f;
		glBindTexture(GL_TEXTURE_2D, cylinderTexture);

		//Draw the tube
		glBegin(GL_QUADS);
		while (angle <= 360.0f) {
			glTexCoord2f(1.0f * sin(angle * PI / 720.0f), 1.0f);
			glVertex3f(radius * cos(angle * PI / 180.0f), height, radius * sin(angle * PI / 180.0f));

			glTexCoord2f(1.0f * sin(angle * PI / 720.0f), 0.0f);
			glVertex3f(radius * cos(angle * PI / 180.0f), 0.0f, radius * sin(angle * PI / 180.0f));

			angle = angle + angle_stepsize;
			glTexCoord2f(1.0f * sin(angle * PI / 720.0f), 0.0f);
			glVertex3f(radius * cos(angle * PI / 180.0f), 0.0f, radius * sin(angle * PI / 180.0f));

			glTexCoord2f(1.0f * sin(angle * PI / 720.0f), 1.0f);
			glVertex3f(radius * cos(angle * PI / 180.0f), height, radius * sin(angle * PI / 180.0f));
		}
		glEnd();

		//Draw the circle on top of cylinder
		angle = 0.0f;
		glBegin(GL_POLYGON);
		while (angle <= 360.0f) {
			glTexCoord2f(0.5f + 0.5f * cos(angle * PI / 360.0f), 0.5f + 0.5f * sin(angle * PI / 360.0f));
			glVertex3f(radius * cos(angle * PI / 180.0f), height, radius * sin(angle * PI / 180.0f));
			angle = angle + angle_stepsize;
		}
		glEnd();

		//Draw the circle on bottom of cylinder
		angle = 0.0f;
		glBegin(GL_POLYGON);
		while (angle <= 360.0f) {
			glTexCoord2f(0.5f + 0.5f * cos(angle * PI / 360.0f), 0.5f + 0.5f * sin(angle * PI / 360.0f));
			glVertex3f(radius * cos(angle * PI / 180.0f), 0.0f, radius * sin(angle * PI / 180.0f));
			angle = angle + angle_stepsize;
		}
		glEnd();
	}

	GLvoid draw(GLuint cylinderSurfaceTexture, GLuint cylinderFrameTexture)
	{
		GLfloat angle = 0.0f;
		GLfloat angle_stepsize = 12.0f;
		glBindTexture(GL_TEXTURE_2D, cylinderFrameTexture);

		//Draw the tube
		glBegin(GL_QUADS);
		while (angle <= 360.0f) {
			glTexCoord2f(1.0f * sin(angle * PI / 720.0f), 1.0f);
			glVertex3f(radius * cos(angle * PI / 180.0f), height, radius * sin(angle * PI / 180.0f));

			glTexCoord2f(1.0f * sin(angle * PI / 720.0f), 0.0f);
			glVertex3f(radius * cos(angle * PI / 180.0f), 0.0f, radius * sin(angle * PI / 180.0f));

			angle = angle + angle_stepsize;
			glTexCoord2f(1.0f * sin(angle * PI / 720.0f), 0.0f);
			glVertex3f(radius * cos(angle * PI / 180.0f), 0.0f, radius * sin(angle * PI / 180.0f));

			glTexCoord2f(1.0f * sin(angle * PI / 720.0f), 1.0f);
			glVertex3f(radius * cos(angle * PI / 180.0f), height, radius * sin(angle * PI / 180.0f));
		}
		glEnd();

		glBindTexture(GL_TEXTURE_2D, cylinderSurfaceTexture);
		//Draw the circle on top of cylinder
		angle = 0.0f;
		glBegin(GL_POLYGON);
		while (angle <= 360.0f) {
			glTexCoord2f(0.5f + 0.5f * cos(angle * PI / 360.0f), 0.5f + 0.5f * sin(angle * PI / 360.0f));
			glVertex3f(radius * cos(angle * PI / 180.0f), height, radius * sin(angle * PI / 180.0f));
			angle = angle + angle_stepsize;
		}
		glEnd();

		//Draw the circle on bottom of cylinder
		angle = 0.0f;
		glBegin(GL_POLYGON);
		while (angle <= 360.0f) {
			glTexCoord2f(0.5f + 0.5f * cos(angle * PI / 360.0f), 0.5f + 0.5f * sin(angle * PI / 360.0f));
			glVertex3f(radius * cos(angle * PI / 180.0f), 0.0f, radius * sin(angle * PI / 180.0f));
			angle = angle + angle_stepsize;
		}
		glEnd();
	}
};