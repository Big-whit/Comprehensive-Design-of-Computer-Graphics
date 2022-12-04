#include"Point3.h"
#include "ControlPointMatrix.h"
#pragma once

class DrawPillow {
public:
	GLuint pillowTexture;
	GLfloat controlPoints[4][4][3] =
	{ 
		{{0,0,0.6},{0, 0, 0.2},{0, 0, -0.2}, {0, 0, -0.6}},						
		{{0,0.3,0.4},{0.5, 0.3, 0.3},{0.5, 0.3, -0.3}, {0, 0.3, -0.4}},									
		{{0,0.6,0.4},{0.5, 0.6, 0.3},{0.5, 0.6, -0.3}, {0, 0.6, -0.4}},									
		{{0,0.9,0.6},{0, 0.9, 0.2},{0, 0.9, -0.2}, {0, 0.9, -0.6}} 
	};
	
	GLfloat textureControlPoints[2][2][2] = 
	{ 
		{{0.0, 0.0}, {0.0, 1.0}},						 
		{{1.0, 0.0}, {1.0, 1.0}} 
	};

	GLvoid draw() {
		DrawTextureBezierSurface dtbs;
		glColor3ub(103, 179, 240);

		glPushMatrix();	
		glScalef(2.0, 2.0, 2.0);
		dtbs.draw(&controlPoints[0][0][0], &textureControlPoints[0][0][0], pillowTexture);
		glScalef(-1.0, 1.0, 1.0);
		dtbs.draw(&controlPoints[0][0][0], &textureControlPoints[0][0][0], pillowTexture);
		glPopMatrix();
	}
};