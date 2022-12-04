#include<iostream>
#include<GLTools.h>
#include<gl/glut.h>
#include"drawTextureCube.h"
#include"drawTextureCylinder.h"
#include"ControlPointMatrix.h"
#include"drawTable.h"
#include"drawChair.h"
#include"drawFloorAndWall.h"
#include"drawTV.h"
#include"drawCabinet.h"
#include"drawPicture.h"
#include"drawTeaTable.h"
#include"LSystemDrawGinkgo.h"
#include"drawSofa.h"
#include"drawPillow.h"
#include"drawCurtain.h"
#include"ifs.h"
#include"drawLamp.h"
#include"drawDoor.h"
#include"drawLivingRoomLight.h"
#include"drawChineseknot.h"
#pragma comment(lib,"gltools.lib")
#define MAX 40

GLint width = 1600, height = 900;
GLfloat camera_X_Distance = 6.0f, camera_Y_Distance = 4.0f, camera_Z_Distance = 14.0f;
GLfloat delta_X_Distance, delta_Y_Distance, delta_Z_Distance = 0.0f;
GLfloat angleX = 0, angleY = 0;
GLfloat oldX, oldY;
GLuint texture[MAX];


GLvoid drawHouse() {
	DrawFloorAndWall DFW;
	DFW.floorTexture = texture[2];
	DFW.WallTexture = texture[3];


	glPushMatrix();
	glTranslatef(-20.0f, -5.0f, -12.5f);
	DFW.drawFloor(8, 5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-20.0f, -5.0f, -12.5f);
	DFW.drawWall(40, 15);
	glPopMatrix();
	
	DFW.WallTexture = texture[28];
	glPushMatrix();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(-12.5f, -5.0f, -20.0f);
	DFW.drawWall(25, 15);
	glPopMatrix();
	
	DFW.WallTexture = texture[3];
	glPushMatrix();
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(-20.0f, -5.0f, -12.5f);
	DFW.drawWall(40, 15);
	glPopMatrix();
	
	glPushMatrix();
	glRotatef(270.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(-12.5f, -5.0f, -20.0f);
	DFW.drawWall(25, 15);
	glPopMatrix();
	
	DFW.floorTexture = texture[3];
	glPushMatrix();
	glTranslatef(-20.0f, 10.0f, -12.5f);
	DFW.drawFloor(8, 5);
	glPopMatrix();
}

GLvoid drawTableAndChairs() {
	DrawTable DT;
	DT.desktopTexture = texture[0];
	DT.tableLegTexture = texture[0];

	DrawChair DC;
	DC.chairTop = texture[1];
	DC.chairLeg = texture[0];
	DC.chairBack = texture[0];

	glPushMatrix();
	DT.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5.0f, -1.1f, 0.0f);
	DC.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-5.0f, -1.1f, 0.0f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
	DC.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.5f, -1.1f, 3.5f);
	glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
	DC.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.5f, -1.1f, 3.5f);
	glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
	DC.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.5f, -1.1f, -3.5f);
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	DC.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.5f, -1.1f, -3.5f);
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	DC.draw();
	glPopMatrix();
}

GLvoid drawTvAndCabinet() {
	DrawTV DTV;
	DTV.monitorTexture[0] = texture[4];
	DTV.monitorTexture[1] = texture[5];
	DTV.monitorTexture[2] = texture[5];
	DTV.monitorTexture[3] = texture[5];
	DTV.monitorTexture[4] = texture[5];
	DTV.monitorTexture[5] = texture[5];
	DTV.baseTexture = texture[6];

	DrawCabinet DC;
	DC.cabinetTexture[0] = texture[7];
	DC.cabinetTexture[1] = texture[8];
	DC.cabinetTexture[2] = texture[8];
	DC.cabinetTexture[3] = texture[8];
	DC.cabinetTexture[4] = texture[8];
	DC.cabinetTexture[5] = texture[8];
	DC.baseTexture = texture[9];

	glPushMatrix();
	glTranslatef(0.0f, 1.0f, 0.0f);
	DTV.draw();
	glPopMatrix();

	DC.draw();
}

GLvoid drawPictures() {
	DrawPicture DP;
	DP.frameTexture = texture[10];
	DP.pictureTexture[0] = texture[11];
	DP.pictureTexture[1] = texture[12];
	DP.pictureTexture[2] = texture[13];
	DP.pictureTexture[3] = texture[14];

	glPushMatrix();
	glTranslatef(19.6f, 3.5f, 0.0f);
	glRotatef(-90.f, 0.0f, 1.0f, 0.0f);
	DP.draw(3.0f, 4.0f, DP.pictureTexture[0]);
	glPopMatrix();

	glPushMatrix();
	glScalef(1.3f, 1.3f, 1.0f);
	glTranslatef(-1.5f, 3.5f, 12.1f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
	DP.draw(1.85f, 5.0f, DP.pictureTexture[1]);
	glTranslatef(3.5f, 0.0f, 0.0f);
	DP.draw(3.71f, 5.0f, DP.pictureTexture[2]);
	glTranslatef(3.5f, 0.0f, 0.0f);
	DP.draw(1.85f, 5.0f, DP.pictureTexture[3]);
	glPopMatrix();

}

GLvoid drawTeaTableAndPot() {
	DrawTeaTable DTT;
	DTT.teaTableSurface[0] = texture[15];
	DTT.teaTableSurface[1] = texture[16];
	DTT.teaTableFrame = texture[17];

	DTT.draw();

	//draw utah teapot
	glBindTexture(GL_TEXTURE_2D, texture[18]);
	glPushMatrix();
	glTranslatef(0.2f, 0.6f, 0.0f);
	glutSolidTeapot(0.6);
	glPopMatrix();
}

GLvoid drawTree() {
	Ginkgo ginkgo;
	ginkgo.leaveTexture = texture[19];
	ginkgo.trunkTexture = texture[20];

	glPushMatrix();
	glScalef(0.6f, 2.0f, 0.6f);
	DrawTextureCylinder().draw(texture[22], texture[21]);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, 1.5f, 0.0f);
	ginkgo.drawGinkgo(ginkgo.LSystem(4));
	glPopMatrix();

}

GLvoid drawSofaAndPillow() {
	DrawSofa DF;
	DF.sofaSurfaceTexture[0] = texture[23];
	DF.sofaSurfaceTexture[1] = texture[24];
	DF.sofaBaseTexture = texture[25];
	DrawPillow DP;
	DP.pillowTexture = texture[26];

	glPushMatrix();
	glScalef(1.2f, 1.0f, 1.0f);
	DF.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(9.0f, 0.0f, 6.0f);
	glScalef(0.6f, 1.0f, 0.5f);
	glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
	DF.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5.0f, 1.5f, -1.0f);
	glRotatef(30.0f, 0.0f, 1.0f, 0.0f);
	glScalef(1.5f, 1.5f, 1.5f);
	DP.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3.5f, 1.5f, -1.0f);
	glRotatef(-30.0f, 1.0f, 0.0f, 0.0f);
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glScalef(1.5f, 1.5f, 1.5f);
	DP.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(9.3f, 1.5f, 6.0f);
	glRotatef(-15.0f, 0.0f, 0.0f, 1.0f);
	glScalef(1.5f, 1.5f, 1.5f);
	DP.draw();
	glPopMatrix();
}

GLvoid drawCurtain() {
	DrawCurtain DC;
	DC.curtainTexture = texture[27];

	glPushMatrix();
	glTranslatef(-19.5f,10.0f,-4.3f);
	glRotatef(90, 1.0f, 0.0f, 0.0f);
	glRotatef(30, 0.0f, 0.0f, 1.0f);
	DC.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-19.5f, 10.0f, 9.6f);
	glRotatef(90, 1.0f, 0.0f, 0.0f);
	glRotatef(30, 0.0f, 0.0f, 1.0f);
	DC.draw();
	glPopMatrix();
}

GLvoid drawLamp() {
	DrawLamp l;
	l.LampTexture = texture[29];
	l.bottomTex = texture[6];

	glPushMatrix();
	glTranslatef(0.0f, 0.3f, 0.0f);
	l.draw();
	glPopMatrix();
}

GLvoid drawDoorAndCouplet() {
	DrawDoor DD;
	DD.doorTexture = texture[30];
	DD.frameTexture = texture[31];
	
	glPushMatrix();
	glTranslatef(7.0f, 0.0f, 12.4f);
	DD.draw();
	glPopMatrix();
}

GLvoid drawLight_1() {
	DrawLivingRoomLight DLRL;
	DLRL.lightTexture[0] = texture[32];
	DLRL.lightTexture[1] = texture[33];
	DLRL.lightTexture[2] = texture[34];
	DLRL.lightTexture[3] = texture[35];
	DLRL.lightTexture[4] = texture[36];

	glPushMatrix();
	glTranslatef(-5.0f, 5.6f, 0.0f);
	DLRL.draw();
	glPopMatrix();
}

GLvoid drawChineseKnot() {
	DrawChineseknot k;
	k.tex = texture[37];
	k.cTex = texture[9];
	k.draw();
}

GLvoid myDraw() {

	//Draw wall、floor
	drawHouse();
	
	//Draw table、six chairs and foods
	glPushMatrix();
	glTranslatef(13.5f, -1.77f, 0.0f);
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	drawTableAndChairs();
	glPopMatrix();
	
	//Draw Tv and cabinet
	glPushMatrix();
	glTranslatef(-5.0f, -3.58f, -10.0f);
	drawTvAndCabinet();
	glPopMatrix();
	
	//Draw some picture(with goaden frame)
	glPushMatrix();
	drawPictures();
	glPopMatrix();
	
	//Draw tea table and utah teapot
	glPushMatrix();
	glTranslatef(-7.0f, -2.85f, 1.5f);
	drawTeaTableAndPot();
	glPopMatrix();
	
	//Draw tree
	glPushMatrix();
	glTranslatef(-15.0f, -4.95f, -9.0f);
	glRotatef(60.0f, 0.0f, 1.0f, 0.0f);
	drawTree();
	glPopMatrix();
	
	//Draw sofa and pillow
	glPushMatrix();
	glTranslatef(-6.0f, -3.65f, 8.5f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
	drawSofaAndPillow();
	glPopMatrix();
	
	//Draw curtain
	glPushMatrix();
	drawCurtain();
	glPopMatrix();
	
	//Draw lamp
	drawLamp();
	
	//Draw ifs dynamic tree
	glPushMatrix();
	glTranslatef(24, 0, -12);
	IF_sierpinski();
	glPopMatrix();
	
	//Draw door
	drawDoorAndCouplet();
	
	//Draw living room light
	drawLight_1();

	//Draw Chinese knot
	glPushMatrix();
	glTranslatef(13.5, 4, 0);
	drawChineseKnot();
	glPopMatrix();
}

GLboolean LoadTGATexture(const char* fileName, GLint minFilter, GLint magFilter, GLint wrapMode) {

	GLbyte* pBits;
	GLint nWidth, nHeight, nComponents;
	GLenum eFormat;

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapMode);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapMode);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilter);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFilter);

	if (minFilter == GL_LINEAR_MIPMAP_LINEAR ||
		minFilter == GL_LINEAR_MIPMAP_NEAREST ||
		minFilter == GL_NEAREST_MIPMAP_LINEAR ||
		minFilter == GL_NEAREST_MIPMAP_NEAREST) {
		//glGenerateMipmap(GL_TEXTURE_2D);
	}

	pBits = gltReadTGABits(fileName, &nWidth, &nHeight, &nComponents, &eFormat);
	if (pBits == NULL) {
		return false;
	}
	glTexImage2D(GL_TEXTURE_2D, 0, nComponents, nWidth, nHeight, 0, eFormat, GL_UNSIGNED_BYTE, pBits);
	free(pBits);

	return true;
}

GLvoid init() {

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glGenTextures(40, &texture[0]);

	//table and chair texture
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	LoadTGATexture("../resources/.tga/redWooden_1.tga", GL_NEAREST, GL_LINEAR, GL_CLAMP_TO_EDGE);

	glBindTexture(GL_TEXTURE_2D, texture[1]);
	LoadTGATexture("../resources/.tga/redWooden_2.tga", GL_NEAREST, GL_LINEAR, GL_CLAMP_TO_EDGE);

	glBindTexture(GL_TEXTURE_2D, texture[2]);
	LoadTGATexture("../resources/.tga/floor.tga", GL_NEAREST, GL_LINEAR, GL_CLAMP_TO_EDGE);

	//wall and floor texture
	glBindTexture(GL_TEXTURE_2D, texture[3]);
	LoadTGATexture("../resources/.tga/wall.tga", GL_NEAREST, GL_LINEAR, GL_CLAMP_TO_EDGE);

	glBindTexture(GL_TEXTURE_2D, texture[4]);
	LoadTGATexture("../resources/.tga/TvMonitorFront.tga", GL_NEAREST, GL_LINEAR, GL_CLAMP_TO_EDGE);

	//tv texture
	glBindTexture(GL_TEXTURE_2D, texture[5]);
	LoadTGATexture("../resources/.tga/TvMonitorAround.tga", GL_NEAREST, GL_LINEAR, GL_CLAMP_TO_EDGE);

	glBindTexture(GL_TEXTURE_2D, texture[6]);
	LoadTGATexture("../resources/.tga/TvBase.tga", GL_NEAREST, GL_LINEAR, GL_CLAMP_TO_EDGE);

	glBindTexture(GL_TEXTURE_2D, texture[7]);
	LoadTGATexture("../resources/.tga/cabinetFront.tga", GL_NEAREST, GL_LINEAR, GL_CLAMP_TO_EDGE);

	//cabinet texture
	glBindTexture(GL_TEXTURE_2D, texture[8]);
	LoadTGATexture("../resources/.tga/cabinetAround.tga", GL_NEAREST, GL_LINEAR, GL_CLAMP_TO_EDGE);

	glBindTexture(GL_TEXTURE_2D, texture[9]);
	LoadTGATexture("../resources/.tga/cabinetBase.tga", GL_NEAREST, GL_LINEAR, GL_CLAMP_TO_EDGE);

	glBindTexture(GL_TEXTURE_2D, texture[10]);
	LoadTGATexture("../resources/.tga/pictureFrame.tga", GL_NEAREST, GL_LINEAR, GL_CLAMP_TO_EDGE);

	//picture texture
	glBindTexture(GL_TEXTURE_2D, texture[11]);
	LoadTGATexture("../resources/.tga/picture_1.tga", GL_NEAREST, GL_LINEAR, GL_CLAMP_TO_EDGE);

	glBindTexture(GL_TEXTURE_2D, texture[12]);
	LoadTGATexture("../resources/.tga/picture_2(1).tga", GL_NEAREST, GL_LINEAR, GL_CLAMP_TO_EDGE);

	glBindTexture(GL_TEXTURE_2D, texture[13]);
	LoadTGATexture("../resources/.tga/picture_2(2).tga", GL_NEAREST, GL_LINEAR, GL_CLAMP_TO_EDGE);

	glBindTexture(GL_TEXTURE_2D, texture[14]);
	LoadTGATexture("../resources/.tga/picture_2(3).tga", GL_NEAREST, GL_LINEAR, GL_CLAMP_TO_EDGE);

	//tea table texture
	glBindTexture(GL_TEXTURE_2D, texture[15]);
	LoadTGATexture("../resources/.tga/teaTableSurface_1.tga", GL_NEAREST, GL_LINEAR, GL_CLAMP_TO_EDGE);

	glBindTexture(GL_TEXTURE_2D, texture[16]);
	LoadTGATexture("../resources/.tga/teaTableSurface_2.tga", GL_NEAREST, GL_LINEAR, GL_CLAMP_TO_EDGE);

	glBindTexture(GL_TEXTURE_2D, texture[17]);
	LoadTGATexture("../resources/.tga/teaTableFrame.tga", GL_NEAREST, GL_LINEAR, GL_CLAMP_TO_EDGE);

	glBindTexture(GL_TEXTURE_2D, texture[18]);
	LoadTGATexture("../resources/.tga/utahTeapot.tga", GL_NEAREST, GL_LINEAR, GL_CLAMP_TO_EDGE);

	//tree and vase texture
	glBindTexture(GL_TEXTURE_2D, texture[19]);
	LoadTGATexture("../resources/.tga/yellowLeave.tga", GL_NEAREST, GL_LINEAR, GL_CLAMP_TO_EDGE);

	glBindTexture(GL_TEXTURE_2D, texture[20]);
	LoadTGATexture("../resources/.tga/trunk.tga", GL_NEAREST, GL_LINEAR, GL_CLAMP_TO_EDGE);

	glBindTexture(GL_TEXTURE_2D, texture[21]);
	LoadTGATexture("../resources/.tga/vaseAround.tga", GL_NEAREST, GL_LINEAR, GL_CLAMP_TO_EDGE);

	glBindTexture(GL_TEXTURE_2D, texture[22]);
	LoadTGATexture("../resources/.tga/soil.tga", GL_NEAREST, GL_LINEAR, GL_CLAMP_TO_EDGE);

	//sofa and pillow texture
	glBindTexture(GL_TEXTURE_2D, texture[23]);
	LoadTGATexture("../resources/.tga/sofaSurface_1.tga", GL_NEAREST, GL_LINEAR, GL_CLAMP_TO_EDGE);

	glBindTexture(GL_TEXTURE_2D, texture[24]);
	LoadTGATexture("../resources/.tga/sofaSurface_2.tga", GL_NEAREST, GL_LINEAR, GL_CLAMP_TO_EDGE);

	glBindTexture(GL_TEXTURE_2D, texture[25]);
	LoadTGATexture("../resources/.tga/sofaBase.tga", GL_NEAREST, GL_LINEAR, GL_CLAMP_TO_EDGE);

	glBindTexture(GL_TEXTURE_2D, texture[26]);
	LoadTGATexture("../resources/.tga/pillow.tga", GL_NEAREST, GL_LINEAR, GL_CLAMP_TO_EDGE);

	//curtain texture
	glBindTexture(GL_TEXTURE_2D, texture[27]);
	LoadTGATexture("../resources/.tga/curtain.tga", GL_NEAREST, GL_LINEAR, GL_CLAMP_TO_EDGE);

	//shanghai window land scape texture
	glBindTexture(GL_TEXTURE_2D, texture[28]);
	LoadTGATexture("../resources/.tga/windowLandscape.tga", GL_NEAREST, GL_LINEAR, GL_CLAMP_TO_EDGE);

	//lamp texture
	glBindTexture(GL_TEXTURE_2D, texture[29]);
	LoadTGATexture("../resources/.tga/lamp.tga", GL_NEAREST, GL_LINEAR, GL_CLAMP_TO_EDGE);

	//door texture
	glBindTexture(GL_TEXTURE_2D, texture[30]);
	LoadTGATexture("../resources/.tga/door.tga", GL_NEAREST, GL_LINEAR, GL_CLAMP_TO_EDGE);

	glBindTexture(GL_TEXTURE_2D, texture[31]);
	LoadTGATexture("../resources/.tga/doorFrame.tga", GL_NEAREST, GL_LINEAR, GL_CLAMP_TO_EDGE);

	//living room light texture
	glBindTexture(GL_TEXTURE_2D, texture[32]);
	LoadTGATexture("../resources/.tga/light_1_1.tga", GL_NEAREST, GL_LINEAR, GL_CLAMP_TO_EDGE);

	glBindTexture(GL_TEXTURE_2D, texture[33]);
	LoadTGATexture("../resources/.tga/light_1_2.tga", GL_NEAREST, GL_LINEAR, GL_CLAMP_TO_EDGE);

	glBindTexture(GL_TEXTURE_2D, texture[34]);
	LoadTGATexture("../resources/.tga/light_1_3.tga", GL_NEAREST, GL_LINEAR, GL_CLAMP_TO_EDGE);

	glBindTexture(GL_TEXTURE_2D, texture[35]);
	LoadTGATexture("../resources/.tga/lightRope_1.tga", GL_NEAREST, GL_LINEAR, GL_CLAMP_TO_EDGE);

	glBindTexture(GL_TEXTURE_2D, texture[36]);
	LoadTGATexture("../resources/.tga/lightBase_1.tga", GL_NEAREST, GL_LINEAR, GL_CLAMP_TO_EDGE);

	glBindTexture(GL_TEXTURE_2D, texture[37]);
	LoadTGATexture("../resources/.tga/chineseKnot.tga", GL_NEAREST, GL_LINEAR, GL_CLAMP_TO_EDGE);

	//light setting
	GLfloat position_1[] = { 0.0f, 0.0f, -3.0f, 1.0f };
	GLfloat ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
	GLfloat mat_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat mat_shininess[] = { 80.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, position_1);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, mat_specular);
	
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);
	//glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

}

GLvoid myDisplay() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glRotatef(angleX, -1.0f, 0.0f, 0.0f);
	glRotatef(angleY, 0.0f, -1.0f, 0.0f);
	glTranslatef(delta_X_Distance, delta_Y_Distance, delta_Z_Distance);

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3ub(255, 255, 255);

	myDraw();

	glFlush();
	glutSwapBuffers();
}

GLvoid myReshape(GLint w, GLint h) {
	width = w;
	height = h;
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, 1.0 * (GLfloat)w / (GLfloat)h, 5.0, 45.0);
	gluLookAt(camera_X_Distance, camera_Y_Distance, camera_Z_Distance, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

GLvoid myMouse(GLint button, GLint state, GLint x, GLint y) {

	if (state == GLUT_DOWN) {
		if (button == GLUT_LEFT_BUTTON) {
			oldX = x; oldY = y;
			
		}
	}
}

GLvoid myMotion(GLint x, GLint y) {
	//To change the mouse position
	GLint deltaX = oldX - x, deltaY = oldY - y;
	angleY += 60 * (GLfloat)deltaX / (GLfloat)width;
	angleX += 60 * (GLfloat)deltaY / (GLfloat)height;
	oldX = x; oldY = y;
	glutPostRedisplay();
}

GLvoid myKeyboard(unsigned char key, GLint x, GLint y) {
	//Use a、s、w、d to change camera position
	switch (key) {
	case 97:
		delta_X_Distance += 1.0f;
		break;
	case 100:
		delta_X_Distance -= 1.0f;
		break;
	case 119:
		delta_Y_Distance -= 1.0f;
		break;
	case 115:
		delta_Y_Distance += 1.0f;
		break;
	case 27:
		exit(0);
	}
	glutPostRedisplay();
}

GLvoid mySpecial(GLint key, GLint x, GLint y) {
	switch (key) {
	case GLUT_KEY_UP:
		delta_Z_Distance += 1.0f;
		break;
	case GLUT_KEY_DOWN:
		delta_Z_Distance -= 1.0f;
		break;
	}
	glutPostRedisplay();
}

GLvoid myTimer(GLint value) {
	glutTimerFunc(20, myTimer, 0);
	glutPostRedisplay();
}

GLint main(GLint argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Project");
	init();

	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myReshape);
	glutMouseFunc(myMouse);
	glutMotionFunc(myMotion);
	glutKeyboardFunc(myKeyboard);
	glutSpecialFunc(mySpecial);
	//glutTimerFunc(20, myTimer, 0);

	glutMainLoop();
	return 0;
}