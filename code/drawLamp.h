#pragma once
#include"Point3.h"
#include "ControlPointMatrix.h"
#include "drawTextureCube.h"
#pragma once

class DrawLamp {
public:
	GLuint LampTexture;
	GLuint bottomTex;
	GLfloat controlPoints[4][4][3] =
	{ 
		{{0, 0, 0}, {-2, 1, 0}, {-2, 2, 4}, {0, 3, 4}},							
		{{0, 0.5, 0}, {-2, 1.5, 0}, {-2, 2.5, 4}, {0, 3.5, 4}},							
		{{0, 1, 0}, {-2, 2, 0}, {-2, 3, 4}, {0, 4, 4}},					
		{{0, 1.5, 0}, {-2, 2.5, 0}, {-2, 3.5, 4}, {0, 4.5, 4}}
	};

	GLfloat textureControlPoints[2][2][2] = 
	{ 
		{{0.0, 0.0}, {0.0, 1.0}},			 
		{{1.0, 0.0}, {1.0, 1.0}} 
	};

	GLvoid drawOne() {
		DrawTextureBezierSurface dtbs;
		glPushMatrix();
		glScalef(0.5, 0.5, 0.5);

		glPushMatrix();
		dtbs.draw(&controlPoints[0][0][0], &textureControlPoints[0][0][0], LampTexture);
		glTranslatef(0.0, 7.5, 0.0);
		glScalef(-1.0, -1.0, 1.0);
		dtbs.draw(&controlPoints[0][0][0], &textureControlPoints[0][0][0], LampTexture);
		glPopMatrix();

		glPushMatrix();
		glScalef(-1.0, 1, -1);
		glTranslatef(0.0, 0.0, -4.0);
		dtbs.draw(&controlPoints[0][0][0], &textureControlPoints[0][0][0], LampTexture);;
		glTranslatef(0.0, 7.5, 0.0);
		glScalef(-1.0, -1.0, 1.0);
		dtbs.draw(&controlPoints[0][0][0], &textureControlPoints[0][0][0], LampTexture);
		glPopMatrix();

		glPopMatrix();
	}

	GLvoid draw() {
		glPushMatrix();
		glTranslatef(4.0, -5.0, -11.0);

		glPushMatrix();
		glTranslatef(1.0, 0.0, 0.0);
		glScalef(3, 0.5, 2);
		DrawTextureCube().draw(bottomTex);
		glPopMatrix();

		glTranslatef(0.0, 0.4, 0.0);
		glRotatef(90, 0, 1, 0);
		drawOne();
		glTranslatef(0.0, 1.5, 0.0);
		drawOne();
		glTranslatef(0.0, 1.5, 0.0);
		drawOne();
		glPopMatrix();
	}
};