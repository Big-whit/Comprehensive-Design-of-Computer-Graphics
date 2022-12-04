#include <iostream>
#include <GL/glut.h>
#pragma once

using namespace std;

float calLen(float x, float y) {
	return y + pow(x, 2) - 0.3;
}

void IF_sierpinski()
{
	glPushMatrix();
	long n = 20000;
	const int len = 6;
	float m[6][7] = {
		//  a     b     c     d     e     f     p
		   {0.05, 0,    0,    0.5,  0,    0,    0.166}, // 上树干
		   {0.05, 0,    0,    -0.5, 0,    1,    0.166}, // 下数干
		   {0.38, -0.32,0.38, 0.46, 0,    0.5,  0.166}, // 左树枝
		   {0.38, 0.32, -0.38,0.46, 0,    0.6,  0.166}, // 右树枝
		   {0.47, -0.17,0.15, 0.42, 0,    1,    0.166}, // 上左树枝
		   {0.44, -0.25,0.3,  0.52, 0,    1.1,  0.167}  // 上右树枝
	};
	float sumM[len] = {};
	sumM[0] = m[0][6];
	int i = 1;
	while (i < len) {
		sumM[i] = sumM[i - 1] + m[i][6];
		++i;
	}

	const float step = 0.1;
	float x = 0, y = 0, x1, y1, p, d;
	int selectI;
	i = 0;
	while (n > 0) {
		p = (float)rand() / RAND_MAX;
		selectI = 0;
		while (p > sumM[selectI])
			++selectI;

		x1 = (m[selectI][0] * x) + (m[selectI][1] * y) + m[selectI][4];
		y1 = (m[selectI][2] * x) + (m[selectI][3] * y) + m[selectI][5];
		x = x1; y = y1;
		d = max(0, calLen(x, y)) / 2.5;
		glColor3ub(142, 50 + d * 205, 15);
		glPointSize(2);
		glBegin(GL_POINTS);
		glVertex2f(x * 5 - 10, y * 5 - 5);
		glEnd();
		--n;
	}
	glPopMatrix();
}