#pragma once
#include"Point3.h"
#include"drawTextureCube.h"

class DrawChair {
public:
	GLuint chairTop, chairLeg, chairBack;

	GLvoid draw() {
		glColor3ub(255, 255, 255);

		//chair top
		glPushMatrix();
		glScalef(2.0f, 0.3f, 2.0f);
		DrawTextureCube().draw(chairTop);
		glPopMatrix();

		//four legs
		glPushMatrix();
		glScalef(0.3f, 2.0f, 0.3f);
		glTranslatef(2.8f, -0.55f, 2.8f);
		DrawTextureCube().draw(chairLeg);
		glPopMatrix();

		glPushMatrix();
		glScalef(0.3f, 2.0f, 0.3f);
		glTranslatef(2.8f, -0.55f, -2.8f);
		DrawTextureCube().draw(chairLeg);
		glPopMatrix();

		glPushMatrix();
		glScalef(0.3f, 2.0f, 0.3f);
		glTranslatef(-2.8f, -0.55f, -2.8f);
		DrawTextureCube().draw(chairLeg);
		glPopMatrix();

		glPushMatrix();
		glScalef(0.3f, 2.0f, 0.3f);
		glTranslatef(-2.8f, -0.55f, 2.8f);
		DrawTextureCube().draw(chairLeg);
		glPopMatrix();

		//chair back
		glPushMatrix();
		glScalef(0.2f, 2.0f, 2.0f);
		glTranslatef(4.5f, 0.57f, 0.0f);
		DrawTextureCube().draw(chairBack);
		glPopMatrix();

	}
};
