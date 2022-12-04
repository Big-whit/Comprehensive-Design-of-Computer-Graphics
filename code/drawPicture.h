#pragma once
#include<gl/glut.h>
#include"drawTextureCube.h"

class DrawPicture {
public:
	GLuint pictureTexture[10], frameTexture;

	GLvoid draw(GLfloat width, GLfloat height, GLuint pictureTexture) {
		glColor3ub(255, 255, 255);
		glBindTexture(GL_TEXTURE_2D, frameTexture);

		glPushMatrix();
		glTranslatef(0.0f, 0.0f, -0.2f);
		glScalef(width, height, 0.2f);
		DrawTextureCube().draw(frameTexture);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.0f, height / 2.0f, 0.0f);
		glScalef(width, 0.2, 0.2f);
		DrawTextureCube().draw(frameTexture);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.0f, -height / 2.0f, 0.0f);
		glScalef(width, 0.2, 0.2f);
		DrawTextureCube().draw(frameTexture);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-width / 2.0f - 0.1f, 0.0f, 0.0f);
		glScalef(0.2, (height + 0.2f), 0.2f);
		DrawTextureCube().draw(frameTexture);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(width / 2.0f + 0.1f, 0.0f, 0.0f);
		glScalef(0.2, (height + 0.2f), 0.2f);
		DrawTextureCube().draw(frameTexture);
		glPopMatrix();

		glBindTexture(GL_TEXTURE_2D, pictureTexture);
		glBegin(GL_QUADS);
		glTexCoord2d(0.0f, 0.0f);
		glVertex3f(-width / 2.0f, -height / 2.0f + 0.1f, 0.0f);

		glTexCoord2d(1.0f, 0.0f);
		glVertex3f(width / 2.0f, -height / 2.0f + 0.1f, 0.0f);

		glTexCoord2d(1.0f, 1.0f);
		glVertex3f(width / 2.0f, height / 2.0f - 0.1f, 0.0f);

		glTexCoord2d(0.0f, 1.0f);
		glVertex3f(-width / 2.0f, height / 2.0f - 0.1f, 0.0f);
		glEnd();
	}
};