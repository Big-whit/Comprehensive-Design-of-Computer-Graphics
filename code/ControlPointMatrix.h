#pragma once
#include<gl/glut.h>

class DrawTextureBezierSurface {
public:

	GLvoid draw(GLfloat* controlPoints, GLfloat* textureControlPoints, GLuint texture) {
	glBindTexture(GL_TEXTURE_2D, texture);
	glMap2f(GL_MAP2_TEXTURE_COORD_2, 0, 1, 2, 2, 0, 1, 4, 2, textureControlPoints);
	glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4, 0, 1, 12, 4, controlPoints);
	glMapGrid2f(10.0, 0.0, 1.0, 10.0, 0.0, 1.0);
	glEvalMesh2(GL_FILL, 0, 10, 0, 10);
	glEnable(GL_MAP2_VERTEX_3);
	glEnable(GL_MAP2_TEXTURE_COORD_2);
	}
};
