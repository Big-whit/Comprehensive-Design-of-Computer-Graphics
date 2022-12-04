#pragma once
#include<cmath>
#include<gl/glut.h>
#define PI 3.1415926

class DrawTextureRing {
public:
	GLfloat outerRadius = 1.0f;
	GLfloat height = 1.0f;

	GLvoid draw(GLfloat innerRadius, GLuint ringTexture) {

		GLfloat angle = 0.0f;
		GLfloat angle_stepsize = 12.0f;
		glBindTexture(GL_TEXTURE_2D, ringTexture);

		//Draw the outer tube
		glBegin(GL_QUADS);
		while (angle <= 360.0f) {
			glTexCoord2f(1.0f * sin(angle * PI / 720.0f), 1.0f);
			glVertex3f(outerRadius * cos(angle * PI / 180.0f), height, outerRadius * sin(angle * PI / 180.0f));

			glTexCoord2f(1.0f * sin(angle * PI / 720.0f), 0.0f);
			glVertex3f(outerRadius * cos(angle * PI / 180.0f), 0.0f, outerRadius * sin(angle * PI / 180.0f));

			angle = angle + angle_stepsize;
			glTexCoord2f(1.0f * sin(angle * PI / 720.0f), 0.0f);
			glVertex3f(outerRadius * cos(angle * PI / 180.0f), 0.0f, outerRadius * sin(angle * PI / 180.0f));

			glTexCoord2f(1.0f * sin(angle * PI / 720.0f), 1.0f);
			glVertex3f(outerRadius * cos(angle * PI / 180.0f), height, outerRadius * sin(angle * PI / 180.0f));
		}
		glEnd();

		//Draw inner tube
		angle = 0.0f;
		glBegin(GL_QUADS);
		while (angle <= 360.0f) {
			glTexCoord2f(1.0f * sin(angle * PI / 720.0f), 1.0f);
			glVertex3f(innerRadius * cos(angle * PI / 180.0f), height, innerRadius * sin(angle * PI / 180.0f));

			glTexCoord2f(1.0f * sin(angle * PI / 720.0f), 0.0f);
			glVertex3f(innerRadius * cos(angle * PI / 180.0f), 0.0f, innerRadius * sin(angle * PI / 180.0f));

			angle = angle + angle_stepsize;
			glTexCoord2f(1.0f * sin(angle * PI / 720.0f), 0.0f);
			glVertex3f(innerRadius * cos(angle * PI / 180.0f), 0.0f, innerRadius * sin(angle * PI / 180.0f));

			glTexCoord2f(1.0f * sin(angle * PI / 720.0f), 1.0f);
			glVertex3f(innerRadius * cos(angle * PI / 180.0f), height, innerRadius * sin(angle * PI / 180.0f));
		}
		glEnd();

		//Draw top surface
		angle = 0.0f;
		glBegin(GL_QUADS);
		while (angle <= 360.0f) {
			glTexCoord2f(1.0f * sin(angle * PI / 720.0f), 1.0f);
			glVertex3f(innerRadius * cos(angle * PI / 180.0f), height, innerRadius * sin(angle * PI / 180.0f));

			glTexCoord2f(1.0f * sin(angle * PI / 720.0f), 0.0f);
			glVertex3f(outerRadius * cos(angle * PI / 180.0f), height, outerRadius * sin(angle * PI / 180.0f));

			angle = angle + angle_stepsize;
			glTexCoord2f(1.0f * sin(angle * PI / 720.0f), 0.0f);
			glVertex3f(outerRadius * cos(angle * PI / 180.0f), height, outerRadius * sin(angle * PI / 180.0f));

			glTexCoord2f(1.0f * sin(angle * PI / 720.0f), 1.0f);
			glVertex3f(innerRadius * cos(angle * PI / 180.0f), height, innerRadius * sin(angle * PI / 180.0f));
		}
		glEnd();

		//Draw bottom surface
		angle = 0.0f;
		glBegin(GL_QUADS);
		while (angle <= 360.0f) {
			glTexCoord2f(1.0f * sin(angle * PI / 720.0f), 1.0f);
			glVertex3f(innerRadius * cos(angle * PI / 180.0f), 0.0f, innerRadius * sin(angle * PI / 180.0f));

			glTexCoord2f(1.0f * sin(angle * PI / 720.0f), 0.0f);
			glVertex3f(outerRadius * cos(angle * PI / 180.0f), 0.0f, outerRadius * sin(angle * PI / 180.0f));

			angle = angle + angle_stepsize;
			glTexCoord2f(1.0f * sin(angle * PI / 720.0f), 0.0f);
			glVertex3f(outerRadius * cos(angle * PI / 180.0f), 0.0f, outerRadius * sin(angle * PI / 180.0f));

			glTexCoord2f(1.0f * sin(angle * PI / 720.0f), 1.0f);
			glVertex3f(innerRadius * cos(angle * PI / 180.0f), 0.0f, innerRadius * sin(angle * PI / 180.0f));
		}
		glEnd();
	}

	GLvoid draw(GLfloat innerRadius, GLuint innerRingTexture, GLuint outerRingTexture, GLuint topBottomTexture) {
		
		GLfloat angle = 0.0f;
		GLfloat angle_stepsize = 12.0f;
		glBindTexture(GL_TEXTURE_2D, outerRingTexture);

		//Draw the outer tube
		glBegin(GL_QUADS);
		while (angle <= 360.0f) {
			glTexCoord2f(1.0f * sin(angle * PI / 720.0f), 1.0f);
			glVertex3f(outerRadius * cos(angle * PI / 180.0f), height, outerRadius * sin(angle * PI / 180.0f));

			glTexCoord2f(1.0f * sin(angle * PI / 720.0f), 0.0f);
			glVertex3f(outerRadius * cos(angle * PI / 180.0f), 0.0f, outerRadius * sin(angle * PI / 180.0f));

			angle = angle + angle_stepsize;
			glTexCoord2f(1.0f * sin(angle * PI / 720.0f), 0.0f);
			glVertex3f(outerRadius * cos(angle * PI / 180.0f), 0.0f, outerRadius * sin(angle * PI / 180.0f));

			glTexCoord2f(1.0f * sin(angle * PI / 720.0f), 1.0f);
			glVertex3f(outerRadius * cos(angle * PI / 180.0f), height, outerRadius * sin(angle * PI / 180.0f));
		}
		glEnd();

		glBindTexture(GL_TEXTURE_2D, innerRingTexture);
		//Draw inner tube
		angle = 0.0f;
		glBegin(GL_QUADS);
		while (angle <= 360.0f) {
			glTexCoord2f(1.0f * sin(angle * PI / 720.0f), 1.0f);
			glVertex3f(innerRadius * cos(angle * PI / 180.0f), height, innerRadius * sin(angle * PI / 180.0f));

			glTexCoord2f(1.0f * sin(angle * PI / 720.0f), 0.0f);
			glVertex3f(innerRadius * cos(angle * PI / 180.0f), 0.0f, innerRadius * sin(angle * PI / 180.0f));

			angle = angle + angle_stepsize;
			glTexCoord2f(1.0f * sin(angle * PI / 720.0f), 0.0f);
			glVertex3f(innerRadius * cos(angle * PI / 180.0f), 0.0f, innerRadius * sin(angle * PI / 180.0f));

			glTexCoord2f(1.0f * sin(angle * PI / 720.0f), 1.0f);
			glVertex3f(innerRadius * cos(angle * PI / 180.0f), height, innerRadius * sin(angle * PI / 180.0f));
		}
		glEnd();

		glBindTexture(GL_TEXTURE_2D, topBottomTexture);
		//Draw top surface
		angle = 0.0f;
		glBegin(GL_QUADS);
		while (angle <= 360.0f) {
			glTexCoord2f(1.0f * sin(angle * PI / 720.0f), 1.0f);
			glVertex3f(innerRadius * cos(angle * PI / 180.0f), height, innerRadius * sin(angle * PI / 180.0f));

			glTexCoord2f(1.0f * sin(angle * PI / 720.0f), 0.0f);
			glVertex3f(outerRadius * cos(angle * PI / 180.0f), height, outerRadius * sin(angle * PI / 180.0f));

			angle = angle + angle_stepsize;
			glTexCoord2f(1.0f * sin(angle * PI / 720.0f), 0.0f);
			glVertex3f(outerRadius * cos(angle * PI / 180.0f), height, outerRadius * sin(angle * PI / 180.0f));

			glTexCoord2f(1.0f * sin(angle * PI / 720.0f), 1.0f);
			glVertex3f(innerRadius * cos(angle * PI / 180.0f), height, innerRadius * sin(angle * PI / 180.0f));
		}
		glEnd();

		//Draw bottom surface
		angle = 0.0f;
		glBegin(GL_QUADS);
		while (angle <= 360.0f) {
			glTexCoord2f(1.0f * sin(angle * PI / 720.0f), 1.0f);
			glVertex3f(innerRadius * cos(angle * PI / 180.0f), 0.0f, innerRadius * sin(angle * PI / 180.0f));

			glTexCoord2f(1.0f * sin(angle * PI / 720.0f), 0.0f);
			glVertex3f(outerRadius * cos(angle * PI / 180.0f), 0.0f, outerRadius * sin(angle * PI / 180.0f));

			angle = angle + angle_stepsize;
			glTexCoord2f(1.0f * sin(angle * PI / 720.0f), 0.0f);
			glVertex3f(outerRadius * cos(angle * PI / 180.0f), 0.0f, outerRadius * sin(angle * PI / 180.0f));

			glTexCoord2f(1.0f * sin(angle * PI / 720.0f), 1.0f);
			glVertex3f(innerRadius * cos(angle * PI / 180.0f), 0.0f, innerRadius * sin(angle * PI / 180.0f));
		}
		glEnd();

	}
};