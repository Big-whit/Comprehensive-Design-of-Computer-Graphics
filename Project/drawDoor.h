#pragma once
#include<gl/glut.h>
#include"drawTextureCube.h"

class DrawDoor {
public:
	GLuint doorTexture, frameTexture;

	GLvoid draw() {
		glColor3ub(255, 255, 255);


		glPushMatrix();
		glScalef(4.0f, 10.0f, 0.1f);
		DrawTextureCube().draw(doorTexture);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(2.1f, 0.1f, -0.1f);
		glScalef(0.2f, 10.2f, 0.3f);
		DrawTextureCube().draw(frameTexture);
		glPopMatrix();
		
		glPushMatrix();
		glTranslatef(-2.1f, 0.1f, -0.1f);
		glScalef(0.2f, 10.2f, 0.3f);
		DrawTextureCube().draw(frameTexture);
		glPopMatrix();
		
		glPushMatrix();
		glTranslatef(0.0f, 5.1f, -0.05f);
		glScalef(4.0f, 0.2f, 0.2f);
		DrawTextureCube().draw(frameTexture);
		glPopMatrix();

	}

};