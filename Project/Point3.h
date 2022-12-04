#pragma once
#include<gl/glut.h>
#pragma once
class Point3 {
public:
	GLfloat x;
	GLfloat y;
	GLfloat z;
	GLint w = 1;

	Point3() {
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}

	Point3(GLfloat x, GLfloat y, GLfloat z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Point3(const Point3& point) {
		this->x = point.x;
		this->y = point.y;
		this->z = point.z;
	}

	friend Point3 operator *(GLdouble num, const Point3& p) {
		return Point3(p.x * num, p.y * num, p.z * num);
	}

	friend Point3 operator *(const Point3& p, GLdouble num) {
		return Point3(p.x * num, p.y * num, p.z * num);
	}

	friend Point3 operator +(const Point3& p1, const Point3& p2) {
		return Point3(p1.x + p2.x, p1.y + p2.y, p1.z + p2.z);
	}

	friend Point3 operator -(const Point3& p1, const Point3& p2) {
		return Point3(p1.x - p2.x, p1.y - p2.y, p1.z - p2.z);
	}
};