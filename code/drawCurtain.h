#pragma once
#include<gl/glut.h>
#include"ControlPointMatrix.h"

class DrawCurtain {
public:
	GLuint curtainTexture;
	GLfloat controlPoints[4][4][3] = 
	{
		{{2.0f,2.0f,0.0f},{0.0f,1.0f,0.0f},{2.0f,0.0f,0.0f},{0.0f,-1.0f,0.0f } },
		{{2.0f,2.0f,5.0f},{0.0f,1.0f,5.0f},{2.0f,0.0f,5.0f},{0.0f,-1.0f,5.0f } },
		{{2.0f,2.0f,10.0f},{0.0f,1.0f,10.0f},{2.0f,0.0f,10.0f},{0.0f,-1.0f,10.0f } },
		{{2.0f,2.0f,14.0f},{0.0f,1.0f,14.0f},{2.0f,0.0f,14.0f},{0.0f,-1.0f,14.0f } },

	};


	GLfloat textureControlPoints[2][2][2] = { {{0.0, 0.0}, {0.0, 1.0}},
										 {{1.0, 0.0}, {1.0, 1.0}} };

	GLvoid draw() {
		DrawTextureBezierSurface dtbs;
		glColor3ub(255, 255, 255);

		glPushMatrix();
		dtbs.draw(&controlPoints[0][0][0], &textureControlPoints[0][0][0], curtainTexture);
		glTranslatef(-2.0f, -3.0f, 0.0f);
		dtbs.draw(&controlPoints[0][0][0], &textureControlPoints[0][0][0], curtainTexture);
		glTranslatef(-2.0f, -3.0f, 0.0f);
		dtbs.draw(&controlPoints[0][0][0], &textureControlPoints[0][0][0], curtainTexture);
		glPopMatrix();

	}
};