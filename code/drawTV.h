#pragma once
#include<gl/glut.h>
#include"drawTextureCube.h"
#include"drawTextureCylinder.h"

class DrawTV {
public:
	GLuint monitorTexture[6], baseTexture;

	GLvoid draw() {
		glColor3ub(255, 255, 255);

		glPushMatrix();
		glScalef(2.0f, 0.2f, 1.0f);
		DrawTextureCylinder().draw(baseTexture);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.0f, 0.2f, 0.0f);
		glScalef(0.2f, 1.0f, 0.2f);
		DrawTextureCylinder().draw(baseTexture);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.0f, 3.45f, 0.0f);
		glScalef(9.0f, 4.5f, 0.2f);
		DrawTextureCube().draw(monitorTexture);
		glPopMatrix();
	}
};