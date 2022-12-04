#pragma once
#include<gl/glut.h>
#include"drawTextureCube.h"
#include"drawTextureCylinder.h"

class DrawCabinet {
public:
	GLuint cabinetTexture[6], baseTexture;

	GLvoid draw() {
		glColor3ub(255, 255, 255);
		glPushMatrix();
		glScalef(15.0f, 2.0f, 3.0f);
		DrawTextureCube().draw(cabinetTexture);
		glPopMatrix();


		glPushMatrix();
		glTranslatef(7.0f, -1.4f, 1.0f);
		glScalef(0.3f, 0.4f, 0.3f);
		DrawTextureCylinder().draw(baseTexture);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(7.0f, -1.4f, -1.0f);
		glScalef(0.3f, 0.4f, 0.3f);
		DrawTextureCylinder().draw(baseTexture);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-7.0f, -1.4f, -1.0f);
		glScalef(0.3f, 0.4f, 0.3f);
		DrawTextureCylinder().draw(baseTexture);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-7.0f, -1.4f, 1.0f);
		glScalef(0.3f, 0.4f, 0.3f);
		DrawTextureCylinder().draw(baseTexture);
		glPopMatrix();


	}

};