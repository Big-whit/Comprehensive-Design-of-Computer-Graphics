#pragma once
#include<gl/glut.h>
#include"Point3.h"
#include"drawTextureCube.h"

class DrawTable {
public:
	GLuint desktopTexture;
	GLuint tableLegTexture;

	GLvoid draw() {
		glColor3ub(255, 255, 255);

		//desktop
		glPushMatrix();
		glScalef(8.0f, 0.5f, 5.0f);
		DrawTextureCube().draw(desktopTexture);
		glPopMatrix();

		//four legs
		glPushMatrix();
		glScalef(0.4f, 3.0f, 0.4f);
		glTranslatef(9.5f, -0.58f, 5.7f);
		DrawTextureCube().draw(tableLegTexture);
		glPopMatrix();

		glPushMatrix();
		glScalef(0.4f, 3.0f, 0.4f);
		glTranslatef(9.5f, -0.58f, -5.7f);
		DrawTextureCube().draw(tableLegTexture);
		glPopMatrix();

		glPushMatrix();
		glScalef(0.4f, 3.0f, 0.4f);
		glTranslatef(-9.5f, -0.58f, -5.7f);
		DrawTextureCube().draw(tableLegTexture);
		glPopMatrix();

		glPushMatrix();
		glScalef(0.4f, 3.0f, 0.4f);
		glTranslatef(-9.5f, -0.58f, 5.7f);
		DrawTextureCube().draw(tableLegTexture);
		glPopMatrix();
	}
};
