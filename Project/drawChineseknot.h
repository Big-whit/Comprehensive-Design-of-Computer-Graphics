#pragma once
#include"Point3.h"
#include "ControlPointMatrix.h"
#include "drawTextureCylinder.h"
#pragma once

class DrawChineseknot {
protected:
	GLfloat basicMatrix[4][3] = { {0.5, 0, 0}, {-3.5, 5, 0}, {3.5, 5, 0}, {-0.5, 0, 0} };

	GLfloat textureControlPoints[2][2][2] =
	{
		{{0.0, 0.0}, {0.0, 1.0}},
		{{1.0, 0.0}, {1.0, 1.0}}
	};

	void calControlMatrix(float width, GLfloat* controlPoints, float sx, float sy, float sz) {
		float dd = width / 2;
		float d[4][3] = {
			{-dd, 0, 0},
			{-dd, 0, dd},
			{dd, 0, dd},
			{dd, 0, 0},
		};
		float d2[4][3] = {
			{0, dd, 0},
			{0, dd, dd},
			{0, -dd, dd},
			{0, -dd, 0},
		};

		d[1][1] = d[2][1] = -abs(dd) * tan(45);

		for (int i = 1; i < 3; ++i) {
			basicMatrix[i][0] *= sx;
			basicMatrix[i][1] *= sy;
			basicMatrix[i][2] *= sz;
		}

		for (int i = 0, j, k; i < 4; ++i) {
			for (j = 0; j < 4; ++j) {
				for (k = 0; k < 3; ++k) {
					if (j == 1 || j == 2) {
						*controlPoints = basicMatrix[j][k] + d2[i][k];
					}
					else if (j == 3) {
						*controlPoints = basicMatrix[j][k] + d[3 - i][k];
					}
					else {
						*controlPoints = basicMatrix[j][k] + d[i][k];
					}
					++controlPoints;
				}
			}
		}

		for (int i = 1; i < 3; ++i) {
			basicMatrix[i][0] /= sx;
			basicMatrix[i][1] /= sy;
			basicMatrix[i][2] /= sz;
		}
	}
	void drawOne(float width, float sx, float sy, float sz) {
		GLfloat controlMatrix[4][4][3], controlMatrix2[4][4][3];
		this->calControlMatrix(width, &controlMatrix[0][0][0], sx, sy, sz);
		this->calControlMatrix(-width, &controlMatrix2[0][0][0], sx, sy, sz);

		DrawTextureBezierSurface dtbs;
		dtbs.draw(&controlMatrix[0][0][0], &textureControlPoints[0][0][0], tex);
		dtbs.draw(&controlMatrix2[0][0][0], &textureControlPoints[0][0][0], tex);
	}

	GLvoid drawBasicAside(float x, float y, float z, float sx, float sy, float sz) {
		glPushMatrix();
		glTranslatef(x, y, z);

		glPushMatrix();
		glTranslatef(0, 1.8, 0);
		glScalef(2.0, 2.0, 2.0);
		drawOne(0.25, sx, sy, sz);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(1.4, 1.4, 0);
		glRotatef(-45, 0, 0, 1);
		drawOne(0.5, sx, sy, sz);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(1.8, 0, 0);
		glScalef(2.0, 2.0, 2.0);
		glRotatef(-90, 0, 0, 1);
		drawOne(0.25, sx, sy, sz);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-1.4, 1.4, 0);
		glRotatef(45, 0, 0, 1);
		drawOne(0.5, sx, sy, sz);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-1.8, 0, 0);
		glScalef(2.0, 2.0, 2.0);
		glRotatef(90, 0, 0, 1);
		drawOne(0.25, sx, sy, sz);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-1.4, -1.4, 0);
		glScalef(1, -1, 1);
		glRotatef(45, 0, 0, 1);
		drawOne(0.5, sx, sy, sz);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, -1.8, 0);
		glScalef(2.0, -2.0, 2.0);
		drawOne(0.25, sx, sy, sz);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(1.4, -1.4, 0);
		glScalef(1, -1, 1);
		glRotatef(-45, 0, 0, 1);
		drawOne(0.5, sx, sy, sz);
		glPopMatrix();

		glPopMatrix();
	}

	GLvoid drawAside() {
		drawBasicAside(0, 0, 0, 1, 1, 1);
		drawBasicAside(0, 0, 0.4, 1, 1, 1);
		drawBasicAside(0, 0, -0.4, 1, 1, 1);

		drawBasicAside(0, 0, 0, 0.9, 0.9, 0.9);
		drawBasicAside(0, 0, 0, 0.8, 0.8, 0.8);
		drawBasicAside(0, 0, 0, 0.7, 0.7, 0.7);
	}
public:
	GLuint tex, cTex;

	GLvoid draw() {
		glPushMatrix();

		glPushMatrix();
		glColor3ub(255, 255, 255);
		glTranslatef(0, 2.8, 0);
		glScalef(0.05, 3, 0.05);
		DrawTextureCylinder c;
		c.draw(NULL, cTex);
		glPopMatrix();

		glColor3ub(255, 255, 255);
		glScalef(0.3, 0.3, 0.3);

		drawAside();
		glRotatef(90, 0, 1, 0);
		drawAside();

		glPopMatrix();
	}
};