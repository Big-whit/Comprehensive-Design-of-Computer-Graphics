#pragma once
#include<gl/glut.h>
#include"drawTextureCube.h"
#include"drawTextureCylinder.h"


class DrawTeaTable {
public:
	GLuint teaTableSurface[10], teaTableFrame;

	GLvoid draw() {
		glColor3ub(255, 255, 255);

		//Draw white tea table
		glPushMatrix();
		glScalef(2.5f, 0.2f, 2.5f);
		DrawTextureCylinder().draw(teaTableSurface[0],teaTableFrame);
		glPopMatrix();

		glPushMatrix();
		glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
		glTranslatef(2.3f, -1.0f, 0.0f);
		glScalef(0.2f, 2.0f, 0.2f);
		DrawTextureCube().draw(teaTableFrame);
		glPopMatrix();

		glPushMatrix();
		glRotatef(120.0f, 0.0f, 1.0f, 0.0f);
		glTranslatef(2.3f, -1.0f, 0.0f);
		glScalef(0.2f, 2.0f, 0.2f);

		DrawTextureCube().draw(teaTableFrame);
		glPopMatrix();

		glPushMatrix();
		glRotatef(240.0f, 0.0f, 1.0f, 0.0f);
		glTranslatef(2.3f, -1.0f, 0.0f);
		glScalef(0.2f, 2.0f, 0.2f);
		DrawTextureCube().draw(teaTableFrame);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.0f, -2.1f, 0.0f);
		glScalef(2.5f, 0.2f, 2.5f);
		DrawTextureCylinder().draw(teaTableSurface[0],teaTableFrame);
		glPopMatrix();

		//Draw black tea table
		glPushMatrix();
		glTranslatef(4.0f, 0.2f, 0.0f);
		glScalef(2.5f, 0.2f, 2.5f);
		DrawTextureCylinder().draw(teaTableSurface[1], teaTableFrame);
		glPopMatrix();

		glPushMatrix();
		glRotatef(15.0f, 0.0f, 1.0f, 0.0f);
		glTranslatef(6.0f, -0.95f, 0.0f);
		glScalef(0.2f, 2.3f, 0.2f);
		DrawTextureCube().draw(teaTableFrame);
		glPopMatrix();

		glPushMatrix();
		glRotatef(-15.0f, 0.0f, 1.0f, 0.0f);
		glTranslatef(6.0f, -0.95f, 0.0f);
		glScalef(0.2f, 2.3f, 0.2f);
		DrawTextureCube().draw(teaTableFrame);
		glPopMatrix();
	}
};