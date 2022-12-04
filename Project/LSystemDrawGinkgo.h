#pragma once
#include<iostream>
#include<cmath>
#include<stack>
#include<gl/glut.h>
#include"Point3.h"
#define PI 3.1415926
using namespace std;

Point3 identifyTextureVertex[4] =
{
	Point3(0.0f, 0.0f, 0.0f),
	Point3(1.0f, 0.0f, 0.0f),
	Point3(1.0f, 1.0f, 0.0f),
	Point3(0.0f, 1.0f, 0.0f)
};

class Ginkgo {
public:
	string GinkgoRule_1 = "F[++X][-X]F[--X][+X][X]";					//X ¡ú F[++X][-X]F[--X][+X][X]
	string GinkgoRule_2 = "FF";										    //F ¡ú FF
	string GinkgoRule_3 = "F[-L][++X][-X]F[+L][--X][+X][X]";			//X ¡ú F[-L][++X][-X]F[+L][--X][+X][X]
	GLuint leaveTexture, trunkTexture;

	string LSystem(GLint n);
	GLvoid drawLeave(Point3 start, GLfloat theta);
	Point3 drawTrunk(Point3 start, GLfloat theta, GLint count);
	GLvoid drawGinkgo(string rule);
};


string Ginkgo::LSystem(GLint n) {
	string rule = "X";
	for (GLint i = 0; i < n; i++) {
		GLint j = 0; string tempRule = "";
		while (j < rule.length()) {
			if (rule[j] == 'X') {
				if (n <= 2) {
					tempRule += GinkgoRule_1;
				}
				else {
					tempRule += GinkgoRule_3;
				}
			}
			else if (rule[j] == 'F') {
				tempRule += GinkgoRule_2;
			}
			else {
				tempRule += rule[j];
			}
			j++;
		}
		rule = tempRule;
	}
	return rule;
}

GLvoid Ginkgo::drawLeave(Point3 start, GLfloat theta) {
	GLfloat radiu = 0.1f;
	Point3 point_1(start.x + radiu / 2.0f * cos(theta * PI / 180.0f), start.y + radiu / 2 * sin(theta * PI / 180.0f), start.z);
	glLineWidth(1.0f);
	glBegin(GL_LINES);
	glVertex3f(start.x, start.y, start.z);
	glVertex3f(point_1.x, point_1.y, point_1.z);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, leaveTexture);
	glBegin(GL_POLYGON);
	glTexCoord2d(0.5f, 0.25f);
	glVertex3f(point_1.x, point_1.y, point_1.z);
	for (int i = 0; i < 121; i = i + 8) {
		glTexCoord2d(0.5f + 0.5f * cos((30.0f + (GLfloat)i) * PI / 180.0f), 0.25f + 0.5f * sin((30.0f + (GLfloat)i) * PI / 180.0f));
		glVertex3f(point_1.x + radiu * cos((theta - (GLfloat)60.0f + (GLfloat)i) * PI / 180.0f), point_1.y + radiu * sin((theta - (GLfloat)60.0f + (GLfloat)i) * PI / 180.0f), point_1.z);
	}
	glEnd();
}

Point3 Ginkgo::drawTrunk(Point3 start, GLfloat theta, GLint count) {
	GLfloat width = (0.1f / 3.0f) * count, length = count / 5.0f;
	Point3 point_1(start.x + width / 2.0f * cos((theta + (GLfloat)90.0f) * PI / 180.0f), start.y + width / 2 * sin((theta + (GLfloat)90.0f) * PI / 180.0f), start.z),
		point_2(start.x + width / 2.0f * cos((theta - (GLfloat)90.0f) * PI / 180.0f), start.y + width / 2 * sin((theta - (GLfloat)90.0f) * PI / 180.0f), start.z),
		point_3(point_2.x + length * cos(theta * PI / 180.0f), point_2.y + length * sin(theta * PI / 180.0f), point_2.z),
		point_4(point_1.x + length * cos(theta * PI / 180.0f), point_1.y + length * sin(theta * PI / 180.0f), point_1.z);

	glBindTexture(GL_TEXTURE_2D, trunkTexture);
	glBegin(GL_QUADS);
	glTexCoord2d(identifyTextureVertex[0].x, identifyTextureVertex[0].y);
	glVertex3f(point_1.x, point_1.y, point_1.z);

	glTexCoord2d(identifyTextureVertex[1].x, identifyTextureVertex[1].y);
	glVertex3f(point_2.x, point_2.y, point_2.z);

	glTexCoord2d(identifyTextureVertex[2].x, identifyTextureVertex[2].y);
	glVertex3f(point_3.x, point_3.y, point_3.z);

	glTexCoord2d(identifyTextureVertex[3].x, identifyTextureVertex[3].y);
	glVertex3f(point_4.x, point_4.y, point_4.z);
	glEnd();

	return (point_3 + point_4) * 0.5f;
}

GLvoid Ginkgo::drawGinkgo(string rule) {
	GLfloat theta = 90.0f, deltaTheta = 30.0f;
	GLfloat len = 0.1f, leaveWidth = 0.1;
	GLint count = 0;
	stack<Point3> tempPoint;
	stack<GLfloat> tempTheta;
	Point3 startPoint(0.0f, 0.0f, 0.0f), endPoint;

	for (GLint i = 0; i < rule.length(); i++) {
		switch (rule[i]) {
		case 'F':
			count = 1;
			while (i < rule.length()) {
				if (rule[i + 1] == 'F') {
					count++;
					i++;
				}
				else {
					break;
				}
			}
			glColor3ub(120, 80, 75);
			startPoint = drawTrunk(Point3(startPoint.x, startPoint.y, startPoint.z), theta, count);
			break;
		case'L':
			glColor3ub(255, 255, 255);
			drawLeave(Point3(startPoint.x, startPoint.y, startPoint.z + 0.02f * pow(-1, i)), theta);
			break;
		case '+':
			theta += deltaTheta;
			break;
		case '-':
			theta -= deltaTheta;
			break;
		case '[':
			tempPoint.push(startPoint);
			tempTheta.push(theta);
			break;
		case ']':
			startPoint = tempPoint.top();
			theta = tempTheta.top();
			tempPoint.pop();
			tempTheta.pop();
			break;
		}
	}
}