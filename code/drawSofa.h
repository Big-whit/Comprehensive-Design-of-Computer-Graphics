#pragma once
#include<gl/glut.h>
#include"drawTextureCube.h"
#include"drawTextureCylinder.h"

class DrawSofa {
public:
	GLuint sofaSurfaceTexture[10], sofaBaseTexture;


	GLvoid draw() {
		glColor3ub(255, 255, 255);

		//Draw sofaSurface
		glPushMatrix();
		glScalef(10.0f, 1.0f, 5.0f);
		DrawTextureCube().draw(sofaSurfaceTexture[0]);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-5.5f, 1.5f, -0.5f);
		glScalef(1.0f, 4.0f, 6.0f);
		DrawTextureCube().draw(sofaSurfaceTexture[0]);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(5.5f, 1.5f, -0.5f);
		glScalef(1.0f, 4.0f, 6.0f);
		DrawTextureCube().draw(sofaSurfaceTexture[0]);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.0f, 1.5f, -3.0f);
		glScalef(10.0f, 4.0f, 1.0f);
		DrawTextureCube().draw(sofaSurfaceTexture[0]);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.0f, 1.0f, 0.0f);
		glScalef(10.0f, 1.0f, 5.0f);
		DrawTextureCube().draw(sofaSurfaceTexture[1]);
		glPopMatrix();

		//draw sofaBase
		glPushMatrix();
		glTranslatef(5.5f, -1.3f, 2.0f);
		glScalef(0.2f, 0.8f, 0.2f);
		DrawTextureCylinder().draw(sofaBaseTexture);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(5.5f, -1.3f, -2.0f);
		glScalef(0.2f, 0.8f, 0.2f);
		DrawTextureCylinder().draw(sofaBaseTexture);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-5.5f, -1.3f, -2.0f);
		glScalef(0.2f, 0.8f, 0.2f);
		DrawTextureCylinder().draw(sofaBaseTexture);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-5.5f, -1.3f, 2.0f);
		glScalef(0.2f, 0.8f, 0.2f);
		DrawTextureCylinder().draw(sofaBaseTexture);
		glPopMatrix();
	}
};