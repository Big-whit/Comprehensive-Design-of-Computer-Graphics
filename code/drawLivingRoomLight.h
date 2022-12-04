#pragma once
#include<gl/glut.h>
#include"drawTextureCylinder.h"
#include"drawTextureRing.h"

class DrawLivingRoomLight {
public:
	GLuint lightTexture[5];

	GLvoid draw() {
		glColor3ub(255, 255, 255);

		//Draw base
		glPushMatrix();
		glTranslatef(0.0f, 4.0f, 0.0f);
		glScalef(0.7f, 0.3f, 0.7f);
		DrawTextureCylinder().draw(lightTexture[4]);
		glPopMatrix();


		//Draw light body
		glPushMatrix();
		glTranslatef(0.0f, 2.0f, 0.0f);
		glRotatef(-30.0f, 0.5f, 0.0f, 1.0f);
		glScalef(2.0f, 0.3f, 2.0f);
		DrawTextureRing().draw(0.9f, lightTexture[1], lightTexture[0], lightTexture[1]);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.0f, 1.0f, 0.0f);
		glRotatef(20.0f, 0.5f, 1.0f, 1.0f);
		glScalef(1.5f, 0.3f, 1.5f);
		DrawTextureRing().draw(0.9f, lightTexture[2]);
		glPopMatrix();

		glPushMatrix();
		glRotatef(-10.0f, 0.5f, 0.0f, 1.0f);
		glScalef(1.0f, 0.3f, 1.0f);
		DrawTextureRing().draw(0.9f, lightTexture[1], lightTexture[0], lightTexture[1]);
		glPopMatrix();

		
		//Draw rope
		glBindTexture(GL_TEXTURE_2D, lightTexture[3]);
		glBegin(GL_LINES);
		glVertex3f(-0.5f * cos(0 * PI / 180), 4.0f, -0.5f * sin(0 * PI / 180));
		glVertex3f(-1.6f, 3.1f, 0.0f);
		glVertex3f(-0.5f * cos(120 * PI / 180), 4.0f, -0.5f * sin(120 * PI / 180));
		glVertex3f(1.0f, 1.3f, -1.5f);
		glVertex3f(-0.5f * cos(240 * PI / 180), 4.0f, -0.5f * sin(240 * PI / 180));
		glVertex3f(0.85f, 2.3f, 1.6f);


		glVertex3f(-0.35f * cos(0 * PI / 180), 4.0f, -0.35f * sin(0 * PI / 180));
		glVertex3f(-1.4f, 1.0f, 0.0f);
		glVertex3f(-0.35f * cos(120 * PI / 180), 4.0f, -0.35f * sin(120 * PI / 180));
		glVertex3f(0.5f, 1.5f, -1.2f);
		glVertex3f(-0.35f * cos(240 * PI / 180), 4.0f, -0.35f * sin(240 * PI / 180));
		glVertex3f(0.6f, 1.2f, 1.2f);


		glVertex3f(-0.2f * cos(0 * PI / 180), 4.0f, -0.35f * sin(0 * PI / 180));
		glVertex3f(-0.85f, 0.4f, 0.0f);
		glVertex3f(-0.2f * cos(120 * PI / 180), 4.0f, -0.35f * sin(120 * PI / 180));
		glVertex3f(0.15f, 0.15f, -1.0f);
		glVertex3f(-0.2f * cos(240 * PI / 180), 4.0f, -0.35f * sin(240 * PI / 180));
		glVertex3f(0.4f, 0.2f, 0.82f);
		glEnd();

	}
};

