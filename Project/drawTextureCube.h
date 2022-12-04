#pragma once
#include<gl/glut.h>
#include "Point3.h"

class DrawTextureCube {
public:
	Point3 identifyCubeVertex[8] =
	{
		Point3(-0.5f, 0.5f, 0.5f),
		Point3(-0.5f, 0.5f, -0.5f),
		Point3(0.5f, 0.5f, -0.5f),
		Point3(0.5f, 0.5f, 0.5f),
		Point3(-0.5f, -0.5f, 0.5f),
		Point3(-0.5f, -0.5f, -0.5f),
		Point3(0.5f, -0.5f, -0.5f),
		Point3(0.5f, -0.5f, 0.5f)
	};

	Point3 identifyTextureVertex[4] =
	{
		Point3(0.0f, 0.0f, 0.0f),
		Point3(1.0f, 0.0f, 0.0f),
		Point3(1.0f, 1.0f, 0.0f),
		Point3(0.0f, 1.0f, 0.0f)
	};

	GLint CubeIndexList[6][4] =
	{
		{4, 7, 3, 0},	//front
		{6, 5, 1, 2},	//back
		{0, 3, 2, 1},	//top
		{5, 6, 7, 4},	//bottom
		{5, 4, 0, 1},	//left
		{7, 6, 2, 3},	//right
	};

	GLvoid draw() {
		glColor3ub(255, 255, 255);
		glBegin(GL_QUADS);
		for (GLint i = 0; i < 6; i++) {
			for (GLint j = 0; j < 4; j++) {
				glTexCoord2f(identifyTextureVertex[j].x, identifyTextureVertex[j].y);
				glVertex3f(identifyCubeVertex[CubeIndexList[i][j]].x, identifyCubeVertex[CubeIndexList[i][j]].y, identifyCubeVertex[CubeIndexList[i][j]].z);
			}
		}
		glEnd();
	}

	GLvoid draw(GLuint textureName) {
		glColor3ub(255, 255, 255);
		glBindTexture(GL_TEXTURE_2D, textureName);
		glBegin(GL_QUADS);
		for (GLint i = 0; i < 6; i++) {
			for (GLint j = 0; j < 4; j++) {
				glTexCoord2f(identifyTextureVertex[j].x, identifyTextureVertex[j].y);
				glVertex3f(identifyCubeVertex[CubeIndexList[i][j]].x, identifyCubeVertex[CubeIndexList[i][j]].y, identifyCubeVertex[CubeIndexList[i][j]].z);
			}
		}
		glEnd();
	}

	GLvoid draw(GLuint (&textureName)[6]) {
		glColor3ub(255, 255, 255);
		for (GLint i = 0; i < 6; i++) {
			glBindTexture(GL_TEXTURE_2D, textureName[i]);
			for (GLint j = 0; j < 4; j++) {
				glBegin(GL_QUADS);
				glTexCoord2f(identifyTextureVertex[j].x, identifyTextureVertex[j].y);
				glVertex3f(identifyCubeVertex[CubeIndexList[i][j]].x, identifyCubeVertex[CubeIndexList[i][j]].y, identifyCubeVertex[CubeIndexList[i][j]].z);
				
			}
			glEnd();
		}
	}
};