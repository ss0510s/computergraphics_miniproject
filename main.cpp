#pragma comment(lib,"winmm.lib") 

#include <Windows.h>
#include <mmsystem.h>;

#include "bmpfuncs.h"
#include "ObjParser.h"
#include "draw.h"
#include <stdio.h>
#include <gl/glut.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

MCI_OPEN_PARMS m_mciOpenParms;
MCI_PLAY_PARMS m_mciPlayParms;
DWORD m_dwDeviceID;
MCI_OPEN_PARMS mciOpen;
MCI_PLAY_PARMS mciPlay;

#define SOUND_DOOR "sound/door_creak1.wav"
#define SOUND_BGM "sound/bgm.wav"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800
#define PI 3.14159265

/* window size*/
int c_width = 800;
int c_height = 800;

/* ��ǥ�� ���*/
double cam[3] = { -0.75, 2.5, 6.5 }; // cam ��ǥ
double camUp[3] = { 0, 1, 0 }; //cam�� up
double camFront[3] = { 0, 0, -1.0 }; //cam�� ��
double yaw = -90, pitch = 0; // �þ� ȸ�� ��
double up[3] = { 0, 1, 0 }; //up vector

/* ȭ�� ���� */
int start = 0;

/* door ȸ�� ����*/
int count_door = 0;
double door_angle = 0;
int door_spin = -1;

/* select ���� ����*/
int g_nSelect = 0; //select ����
int g_nX, g_nY;
bool max = true;

// select ���� Ȯ��
int select1 = 0;
int select2 = 0;
int select3 = 0;
int select4 = 0;
int select5 = 0;
int select6 = 0;
int select7 = 0;
int select8 = 0;
int select9 = 0;
int select10 = 0;

// select�� object �̵� ����
double trans_1 = 0;
double trans_3 = 0.0;
double trans_3_2 = 0.0;

/* ���콺 Ŭ�� ����*/
int mouse_x;
int mouse_y;

/* question ��ȣ ����*/
int q1 = 0;
int q2 = 0;
int q3 = 0;
int q4 = 0;

/* �� ���� Ȯ�� ����*/
int answer1 = 0;
int answer2 = 0;
int answer3 = 0;
int answer4 = 0;

int dwID;

/* ����ġ ����*/
double switch_angle = 15;

/*�ʱ�ȭ �Լ�*/
void init(void);

/*�ݹ� �Լ�*/
void draw(void);
void resize(int, int);
void keyboard(unsigned char, int, int);
void specialKeyboard(int, int, int);
void mouse(int, int, int, int);
void idle();
void menu(int);

/*���� �Լ�*/
void light();
void roomlight();

/*���� �׸��� �Լ�*/
void draw_string(void*, const char*, float, float, float, float, float);
void draw_text();

/* select�� ȭ�� ���� �Լ�*/
void draw_background(GLuint);
void select_viewport();

/* �������̽� ��� */
void print_instruction();

/* select �Լ� */
void Picking(int, int);

/* room ���� object�� �׸��� �Լ� */
void draw_in_room();

/* room ���� select�� object�� �׸��� �Լ�*/
void draw_select();

/* ȭ�� ���� �Լ�*/
void draw_viewport();

/* �߸� ȭ�� �Լ�*/
void draw_criminal();

/* object var*/
ObjParser* kitchen_bottom;
ObjParser* kitchen2; ObjParser* kitchen3; ObjParser* kitchen4; ObjParser* kitchen5; ObjParser* kitchen6;
ObjParser* table; ObjParser* table2;
ObjParser* box;
ObjParser* knife;
ObjParser* phone;
ObjParser* cup; ObjParser* cup2;
ObjParser* bag; ObjParser* bag2;
ObjParser* money_box; ObjParser* money_box2;
ObjParser* bottle; ObjParser* bottles;
ObjParser* human;
ObjParser* refri; ObjParser* refri2;

using namespace std;

int main(int argc, char** argv) {

	/*window �ʱ�ȭ*/
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); //depth buffer ��� ����
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition(500, 100);
	glutCreateWindow("12191754 ������ �߸� ����");
	init();

	// ���ҽ� �ε�
	kitchen_bottom = new ObjParser("obj/kitchen_bottom.obj");
	kitchen2 = new ObjParser("obj/kitchen2.obj");
	kitchen3 = new ObjParser("obj/kitchen3.obj");
	kitchen4 = new ObjParser("obj/kitchen4.obj");
	kitchen5 = new ObjParser("obj/kitchen5.obj");
	kitchen6 = new ObjParser("obj/kitchen6.obj");

	table = new ObjParser("obj/table.obj");
	table2 = new ObjParser("obj/table2.obj");
	box = new ObjParser("obj/box.obj");

	cup = new ObjParser("obj/cup.obj");
	cup2 = new ObjParser("obj/cup2.obj");

	bag = new ObjParser("obj/bag.obj");
	bag2 = new ObjParser("obj/bag2.obj");
	phone = new ObjParser("obj/phone.obj");

	bottle = new ObjParser("obj/bottle.obj");
	bottles = new ObjParser("obj/bottles.obj");

	money_box = new ObjParser("obj/money_box.obj");
	money_box2 = new ObjParser("obj/money_box2.obj");
	knife = new ObjParser("obj/knife.obj");

	human = new ObjParser("obj/human.obj");
	refri = new ObjParser("obj/refri.obj");
	refri2 = new ObjParser("obj/refri2.obj");


	/* ���ù� ��� */
	printf("\n");
	print_instruction();

	/* �޴� ���� */
	glutCreateMenu(menu);
	glutAddMenuEntry("close", 1);
	glutAddMenuEntry("reasoning/room", 2);
	glutAddMenuEntry("game exit", 999);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	/*call back �Լ�*/
	glutReshapeFunc(resize);
	glutDisplayFunc(draw);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKeyboard);
	glutMouseFunc(mouse);
	glutIdleFunc(idle);

	glutMainLoop();

}
/*�ʱ�ȭ �Լ�*/
void init(void) {

	glClearColor(0.1f, 0.1f, 0.1f, 1.0f); // ���� ����

	//blending, antialiasing
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_POLYGON_SMOOTH);
	glEnable(GL_LINE_SMOOTH);
	glHint(GL_POLYGON_SMOOTH, GL_NICEST);
	glHint(GL_LINE_SMOOTH, GL_NICEST);

	/* �����Լ� */
	light(); //�ܺ� ����
	roomlight();// ���� ����

	glClearDepth(1.0f); //buffer clearing�� �̿��� ��
	glEnable(GL_DEPTH_TEST);//depth buffer Ȱ��ȭ

	glEnable(GL_TEXTURE_2D); //texture_2d Ȱ��ȭ
	texture();
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); //polygon�� ���� ����� texture ������ ���Ͽ� ���ο� ���� ����
	PlaySound(TEXT(SOUND_BGM), NULL, SND_ASYNC | SND_LOOP);
}

/*ũ�� �ʱ�ȭ*/
void resize(int width, int height) {
	c_width = width;
	c_height = height;
	glViewport(0, 0, width, height);
	//viewport T.F, x = 0, y = 0, width�� height�� window ũ�⿡ ���� �޶���
	glMatrixMode(GL_PROJECTION); //���� ���
	glLoadIdentity(); //���� ���

	/* ȭ�鿡 ���� �þ� �з�*/
	if (start == 1) {
		gluPerspective(80, (float)width / (float)height, 1, 500); //Projection T.F
	}
	else if (start == 2) {
		glOrtho(-width / 2.0f, width / 2.0f, -height / 2.0f, height / 2.0f,-100, 100);
	}
	glMatrixMode(GL_MODELVIEW); //�𵨺� ���
}

/*�ܺ� ���� ����*/
void light() {
	//������ color ����
	GLfloat light_ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

	glEnable(GL_LIGHTING); //light mode Ȱ��ȭ
	glEnable(GL_LIGHT0); //0�� ������ ��

	// ������ �ݻ� Ư�� ����
	GLfloat ambientMaterial[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	GLfloat diffuseMaterial[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat specularMaterial[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambientMaterial);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseMaterial);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specularMaterial);
	glMaterialf(GL_FRONT, GL_SHININESS, 64);

	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
}

/*���� ���� ����*/
void roomlight() {
	//������ color ����
	GLfloat light_ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	GLfloat light_diffuse[] = { 0.5f, 0.5f, 0.5f, 1.0f };
	GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);

	glEnable(GL_LIGHTING); //light mode Ȱ��ȭ
	glEnable(GL_LIGHT1); //1�� ������ ��

	// ������ �ݻ� Ư�� ����
	GLfloat ambientMaterial[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	GLfloat diffuseMaterial[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat specularMaterial[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambientMaterial);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseMaterial);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specularMaterial);
	glMaterialf(GL_FRONT, GL_SHININESS, 30);

	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
}

/* draw �Լ� */
void draw(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // depth buffer clearing

	glMatrixMode(GL_MODELVIEW); //�𵨺� ���
	glLoadIdentity(); //���� ���

	//�ܺ� ���� ��ġ
	GLfloat light_postion[] = { 15, 15, 15 ,1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, light_postion);

	//���� ���� ��ġ
	GLfloat light_position2[] = { 0, 3.5, 0, 1 };
	glLightfv(GL_LIGHT1, GL_POSITION, light_position2);


	/* ȭ�� ���� */
	if (start == 0 || start == 1) {
		//Viewing T.F
		gluLookAt(cam[0], cam[1], cam[2], cam[0] + camFront[0], cam[1] + camFront[1], cam[2] + camFront[2], up[0], up[1], up[2]);

		glEnable(GL_LIGHTING);
		draw_text();

		draw_viewport();
		select_viewport();

	}
	else if (start == 2) {
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-5, 5, -5, 5, -1, 1);
		glMatrixMode(GL_MODELVIEW);
		glDisable(GL_LIGHTING);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		draw_criminal();
	}

	glFlush();
	glutSwapBuffers(); // double buffering ��
}

/* room �� object*/
void draw_in_room() {
	
	glPushMatrix();

	/*room, door frame �׸���*/
	glPushMatrix();
	draw_room();
	draw_door_frame();
	glPopMatrix();
	
	/*door �׸��� ȸ��*/
	glPushMatrix();
	glTranslatef(-1.4, 0, 5.0);
	glRotatef(door_angle, 0, 1, 0);
	draw_door(); //door
	tex_window();//window
	glPopMatrix();

	/*kitchen �׸���*/
	glPushMatrix();
	glColor3f(0, 0, 0);
	draw_obj(kitchen4);
	glColor3f(0.1, 0.1, 0.1);
	draw_obj(kitchen3);
	glColor3f(0.2, 0.2, 0.2);
	draw_obj(kitchen_bottom);
	
	glColor3f(0.7, 0.7, 0.7);
	draw_obj(kitchen2);
	draw_obj(kitchen5);
	draw_obj(kitchen6); 
	glColor3f(0.1, 0.05, 0.05);
	draw_obj(table);
	glColor3f(0, 0, 0);
	draw_obj(table2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3.3, 0, -2.0);
	draw_kitchen();
	glPopMatrix();

	/*human �׸���*/
	glPushMatrix();
	glColor3f(0.5, 0, 0);
	glTranslatef(0, 0.1, 0);
	glDisable(GL_LIGHTING);
	draw_obj(human);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	/* ����� �׸���*/
	glPushMatrix();
	glColor3f(0.6, 0.6, 0.6);
	draw_obj(refri);
	glColor3f(0.5, 0.5, 0);
	draw_obj(refri2);
	glColor3f(0.3, 0.2, 0);
	draw_obj(box);
	glTranslatef(0, 0.4, 0);
	draw_obj(box);
	glPopMatrix();

	/*money �׸���*/
	glPushMatrix();
	glTranslatef(-3.3f, 1.7f, -3.0f);
	money();
	glTranslatef(-0.4f, 0, 0.2f);
	money();
	glPopMatrix();

	/* ���� cup �׸���*/
	glPushMatrix();
	glColor3f(0.8, 0.8, 0.8);
	draw_obj(cup2);
	glPopMatrix();

	/* ���� bottle �׸���*/
	glPushMatrix();
	glColor3f(0, 0.2, 0);
	glDisable(GL_BLEND);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	glTranslatef(0, 0.4, 0);
	draw_obj(bottles);
	glDisable(GL_BLEND);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glPopMatrix();

	/*���� �׸���*/
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);;
	glTranslatef(-2.2, 0.15, -3.5);
	draw_obj(bag);
	draw_obj(bag2);
	glPopMatrix();

	/*money_box �׸���*/
	glPushMatrix();
	glColor3f(0, 0, 0);;
	draw_obj(money_box);
	glPopMatrix();

	/*����ġ*/
	glPushMatrix();
	glTranslatef(1.0, 2.0, 4.9);
	draw_light();
	glPopMatrix();

	glPopMatrix();
}

/* selct object �Լ�*/
void draw_select() {
	glPushMatrix();

	glColor3f(1, 1, 1);
	/*paper*/
	glLoadName(1);
	glPushMatrix();
	glTranslatef(-2.2, 0.1, -3.5);
	paper();
	glDisable(GL_TEXTURE_2D);
	glTranslatef(0, 0, trans_1);
	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
	glVertex3f(0.3f, 0.005f, 0.5f);
	glVertex3f(-0.3f, 0.005f, 0.5f);
	glVertex3f(-0.3f, 0.005, -0.5f);
	glVertex3f(0.3f, 0.005f, -0.5f);
	glEnd();
	glPopMatrix();
	glEnable(GL_TEXTURE_2D);

	/* ���� cup �׸���*/
	glLoadName(2);
	glPushMatrix();
	glColor3f(0.8, 0.8, 0.8);
	draw_obj(cup);
	glPopMatrix();

	/*���� money_box*/
	glColor3f(0.2, 0.2, 0.2);
	glLoadName(3);
	glPushMatrix();
	glTranslatef(0, 0, trans_3);
	draw_obj(money_box2);
	glPopMatrix();

	glLoadName(8);
	glPushMatrix();
	glDisable(GL_TEXTURE_2D);
	glColor3f(1, 1, 1);
	glTranslatef(-3.5f, 2.0f, -4.0f);
	glTranslatef(0, trans_3_2, 0);
	glBegin(GL_QUADS);
	glVertex3f(0.2f, 0, 0.1f);
	glVertex3f(-0.2f, 0, 0.1f);
	glVertex3f(-0.2f, 0, -0.1f);
	glVertex3f(0.2f, 0, -0.1f);
	glEnd();
	glEnable(GL_TEXTURE_2D);
	glPopMatrix();

	/*���� phone*/
	
	glLoadName(4);
	glPushMatrix();
	glColor3f(0, 0, 0);
	draw_obj(phone);
	glDisable(GL_TEXTURE_2D);
	glColor3f(1, 1, 1);
	glTranslatef(1.17f, 1.69f, -2.2f);
	glBegin(GL_QUADS);
	glVertex3f(0.05f, 0, 0.09f);
	glVertex3f(-0.05f, 0, 0.09f);
	glVertex3f(-0.05f, 0, -0.09f);
	glVertex3f(0.05f, 0, -0.09f);
	glEnd();
	glPopMatrix();
	glEnable(GL_TEXTURE_2D);

	/*���� paper*/
	glDisable(GL_TEXTURE_2D);
	glLoadName(5);
	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslatef(1.8f, 0.8f, 4.5f);
	glBegin(GL_QUADS);
	glVertex3f(0.15f, 0, 0.15f);
	glVertex3f(-0.15f, 0, 0.15f);
	glVertex3f(-0.15f, 0, -0.15f);
	glVertex3f(0.15f, 0, -0.15f);
	glEnd();
	glPopMatrix();
	glEnable(GL_TEXTURE_2D);


	/* ���� bottle �׸���*/
	glLoadName(6);
	glPushMatrix();
	glColor3f(0, 0.2, 0);
	glDisable(GL_BLEND);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	glTranslatef(0, 0.1, 0);
	draw_obj(bottle);
	glDisable(GL_BLEND);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glPopMatrix();

	glColor3f(1, 1, 1);
	/*�޷� �׸���*/
	glLoadName(7);
	glPushMatrix();
	glTranslatef(-3.5f, 1.7f, 0);
	calender();
	glPopMatrix();

	/*knife*/
	glColor3f(0, 0, 0);
	glLoadName(9);
	glPushMatrix();
	draw_obj(knife);
	glPopMatrix();
	glColor3f(1, 1, 1);

	/*light switch*/
	glLoadName(10);
	glPushMatrix();
	glTranslatef(1.0, 2.0, 4.9);
	glRotatef(switch_angle, 0, 1, 0);
	draw_light2();
	glPopMatrix();

	glPopMatrix();
}

/*�ι�° ȭ�� ���� �Լ�*/
void draw_viewport() {
	glMatrixMode(GL_PROJECTION); //���� ���
	glLoadIdentity(); //���� ���
	gluPerspective(80, c_width / c_height, 1, 500); //Projection T.F
	glMatrixMode(GL_MODELVIEW); //�𵨺� ���

	draw_in_room();
	draw_select();

	glFlush();
}

/* select�� �� event*/
void select_viewport() {
	glColor3f(1, 1, 1);
	if (select1 == 2) {
		draw_background(texName[12]);
	}
	if (select2 == 1) {
		draw_background(texName[11]);
	}
	if (select3 == 2) {
		if (select8 == 1) {
			draw_background(texName[14]);
		}
	}
	if (select4 == 1) {
		draw_background(texName[13]);
	}
	if (select5 == 1) {
		draw_background(texName[15]);
	}
	if (select6 == 1) {
		draw_background(texName[10]);
	}
	if (select7 == 1) {
		draw_background(texName[7]);
	}
	if (select9 == 1) {
		draw_background(texName[16]);
	}
	if (select10 == 1) {
		switch_angle = -15;
		glDisable(GL_LIGHT1);
	}
	else {
		switch_angle = 15;
		glEnable(GL_LIGHT1);
	}
	glFlush();
}

/* �޴� �Լ� */
void menu(int option)
{
	switch (option) {
	case 1: // �� �ʱ�ȭ
		select1 = 0;
		select2 = 0;
		select3 = 0;
		select4 = 0;
		select5 = 0;
		select6 = 0;
		select7 = 0;
		select8 = 0;
		select9 = 0;

		glutPostRedisplay();
		break;
	case 2: //ȭ�� ����
		if (start == 1) {
			start = 2;
		}
		else if (start == 2) {
			start = 1;
		}
		glutPostRedisplay();
		break;
	}
	if (option == 999) { //exit
		exit(0);
	}
}

/* select�� ������ ȭ�� �Լ�*/
void draw_background(GLuint texname) {
	glPushAttrib(GL_LIGHTING_BIT);
	glDisable(GL_LIGHTING);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();

	gluOrtho2D(-5, 5, -5, 5);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glColor3f(1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, texname);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(-3, -3, 0);
	glTexCoord2f(0, 1);	glVertex3f(-3, 3, 0);
	glTexCoord2f(1, 1); glVertex3f(3, 3, 0);
	glTexCoord2f(1, 0); glVertex3f(3, -3, 0);
	glEnd();

	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopAttrib();
}

/* checkbox �Լ�*/
void draw_square(double x, double y) {
	glDisable(GL_TEXTURE_2D);
	glColor3f(1, 1, 0);
	glBegin(GL_LINE_LOOP);
	glVertex3f(x - 0.1, y - 0.1, 0);
	glVertex3f(x - 0.1, y + 0.1, 0);
	glVertex3f(x + 0.1, y + 0.1, 0);
	glVertex3f(x + 0.1, y - 0.1, 0);
	glEnd();
	glColor3f(1, 1, 1);
	glEnable(GL_TEXTURE_2D);
}

/* check �Լ� */
void draw_check(double x, double y) {
	glColor3f(1, 0, 0);
	glLineWidth(3);
	glBegin(GL_LINE_STRIP);
	glVertex3f(x - 0.13, y + 0.2, 0.1);
	glVertex3f(x, y, 0.1);
	glVertex3f(x + 0.13, y + 0.2, 0.1);
	glEnd();
	glColor3f(1, 1, 1);
}

/* �߸� ȭ�� ���� */
void draw_criminal() {
	glColor3f(0, 0, 0);
	glDisable(GL_TEXTURE_2D);

	char* str;
	str = (char*)"< REASONING > ";
	draw_string(GLUT_BITMAP_TIMES_ROMAN_24, str, -0.9, 4.5, 1, 1, 1);

	str = (char*)"observe the scene and answer the question!";
	draw_string(GLUT_BITMAP_HELVETICA_18, str, -4.5, 4.0, 1, 1, 1);

	str = (char*)"- case name : restaurant murder case";
	draw_string(GLUT_BITMAP_HELVETICA_18, str, -4.5, 3.5, 1, 1, 1);

	str = (char*)"- victim : ceo   suspect : employee, delivery man, wife";
	draw_string(GLUT_BITMAP_HELVETICA_18, str, -4.5, 3.0, 1, 1, 1);
	
	str = (char*)"1) What is the tool of the crime ?";
	draw_string(GLUT_BITMAP_HELVETICA_18, str, -4.5, 2.2, 1, 1, 1);
	
	str = (char*)"knife";
	draw_string(GLUT_BITMAP_HELVETICA_18, str, -3.9, 1.7, 1, 1, 1);
	draw_square(-4.2, 1.8);

	str = (char*)"bottle";
	draw_string(GLUT_BITMAP_HELVETICA_18, str, -1.0, 1.7, 1, 1, 1);
	draw_square(-1.3, 1.8);

	str = (char*)"hand";
	draw_string(GLUT_BITMAP_HELVETICA_18, str, 2.2, 1.7, 1, 1, 1);
	draw_square(1.9, 1.8);
	switch (q1) {
	case 1:
		draw_check(-4.2, 1.8);
		break;
	case 2:
		draw_check(-1.3, 1.8);
		break;
	case 3:
		draw_check(1.9, 1.8);
		break;
	}

	str = (char*)"2) What was the motive for the murder ?";
	draw_string(GLUT_BITMAP_HELVETICA_18, str, -4.5, 0.8, 1, 1, 1);

	str = (char*)"accounts receivable";
	draw_string(GLUT_BITMAP_HELVETICA_18, str, -3.9, 0.3, 1, 1, 1);
	draw_square(-4.2, 0.4);

	str = (char*)"death insurance";
	draw_string(GLUT_BITMAP_HELVETICA_18, str, -1.0, 0.3, 1, 1, 1);
	draw_square(-1.3, 0.4);

	str = (char*)"Part-time non - payment";
	draw_string(GLUT_BITMAP_HELVETICA_18, str, 2.2, 0.3, 1, 1, 1);
	draw_square(1.9, 0.4);
	switch (q2) {
	case 1:
		draw_check(-4.2, 0.4);
		break;
	case 2:
		draw_check(-1.3, 0.4);
		break;
	case 3:
		draw_check(1.9, 0.4);
		break;
	}


	str = (char*)"3) Who was the first discoverer?";
	draw_string(GLUT_BITMAP_HELVETICA_18, str, -4.5, -0.6, 1, 1, 1);

	str = (char*)"delivery man";
	draw_string(GLUT_BITMAP_HELVETICA_18, str, -3.9, -1.1, 1, 1, 1);
	draw_square(-4.2, -1.0);

	str = (char*)"wife";
	draw_string(GLUT_BITMAP_HELVETICA_18, str, -1.0, -1.1, 1, 1, 1);
	draw_square(-1.3, -1.0);

	str = (char*)"employee";
	draw_string(GLUT_BITMAP_HELVETICA_18, str, 2.2, -1.1, 1, 1, 1);
	draw_square(1.9, -1.0);
	switch (q3) {
	case 1:
		draw_check(-4.2, -1.0);
		break;
	case 2:
		draw_check(-1.3, -1.0);
		break;
	case 3:
		draw_check(1.9, -1.0);
		break;
	}

	str = (char*)"4) Who is the killer?";
	draw_string(GLUT_BITMAP_HELVETICA_18, str, -4.5, -2.0, 1, 1, 1);

	str = (char*)"delivery man";
	draw_string(GLUT_BITMAP_HELVETICA_18, str, -3.9, -2.5, 1, 1, 1);
	draw_square(-4.2, -2.4);

	str = (char*)"wife";
	draw_string(GLUT_BITMAP_HELVETICA_18, str, -1.0, -2.5, 1, 1, 1);
	draw_square(-1.3, -2.4);

	str = (char*)"employee";
	draw_string(GLUT_BITMAP_HELVETICA_18, str, 2.2, -2.5, 1, 1, 1);
	draw_square(1.9, -2.4);
	switch (q4) {
	case 1:
		draw_check(-4.2, -2.4);
		break;
	case 2:
		draw_check(-1.3, -2.4);
		break;
	case 3:
		draw_check(1.9, -2.4);
		break;
	}

	str = (char*)"submit";
	draw_string(GLUT_BITMAP_TIMES_ROMAN_24, str, -0.2, -3.5, 1, 0, 0);
	glColor3f(1, 1, 0);
	glBegin(GL_LINE_LOOP);
	glVertex3f(-0.3, -3.6, 0);
	glVertex3f(-0.3, -3.2, 0);
	glVertex3f(0.8, -3.2, 0);
	glVertex3f(0.8, -3.6, 0);
	glEnd();

	if (answer1 == 2 && answer2 == 2 && answer3 == 2 && answer4 == 2) {
		str = (char*)"! GAME CLEAR !";
		draw_string(GLUT_BITMAP_TIMES_ROMAN_24, str, -0.8, -4.1, 1, 1, 0);

		str = (char*)"Game exit";
		draw_string(GLUT_BITMAP_HELVETICA_18, str, -0.2, -4.5, 1, 1, 1);
	}
	if (answer1 == 1) {
		str = (char*)"=> Take a closer look at the corpse";
		draw_string(GLUT_BITMAP_HELVETICA_18, str, 0, 1.3, 1, 0, 0);
	}
	if (answer2 == 1) {
		str = (char*)"=> Take a closer look around";
		draw_string(GLUT_BITMAP_HELVETICA_18, str, 0, -0.1, 1, 0, 0);
	}
	if (answer3 == 1) {
		str = (char*)"=> Take a closer look around the corpse";
		draw_string(GLUT_BITMAP_HELVETICA_18, str, 0, -1.5, 1, 0, 0);
	}
	if (answer4 == 1) {
		str = (char*)"=> Look at the footprints";
		draw_string(GLUT_BITMAP_HELVETICA_18, str, 0, -2.9, 1, 0, 0);
	}
	glutPostRedisplay();

	glEnable(GL_TEXTURE_2D);
}

/* Ű���� �Լ� */
void keyboard(unsigned char key, int x, int y) {
	//��ǥ ���, ��/�Ʒ�/��/�� �̵� ����
	double cam_x = camFront[1] * camUp[2] - camUp[1] * camFront[2];
	double cam_y = camFront[2] * camUp[0] - camUp[2] * camFront[0];
	double cam_z = camFront[0] * camUp[1] - camUp[0] * camFront[1];

	double sum = pow(cam_x, 2) + pow(cam_y, 2) + pow(cam_z, 2);

	float cameraSpeed = 0.1f; //�̵��ӵ�
	switch (key) {
	case 'w':
		cam[0] += cameraSpeed * camFront[0];
		cam[1] += cameraSpeed * camFront[1];
		cam[2] += cameraSpeed * camFront[2];
		break;
	case 's':
		cam[0] -= cameraSpeed * camFront[0];
		cam[1] -= cameraSpeed * camFront[1];
		cam[2] -= cameraSpeed * camFront[2];
		break;
	case 'a':
		cam[0] -= cameraSpeed * cam_x / sqrt(sum);
		cam[1] -= cameraSpeed * cam_y / sqrt(sum);
		cam[2] -= cameraSpeed * cam_z / sqrt(sum);
		break;
	case 'd':
		cam[0] += cameraSpeed * cam_x / sqrt(sum);
		cam[1] += cameraSpeed * cam_y / sqrt(sum);
		cam[2] += cameraSpeed * cam_z / sqrt(sum);
		break;
	}
	/* �� �ܺη� ���� �ʵ��� ����*/
	if (start == 1) {
		if (cam[0] > 6.5) {
			cam[0] = 6.4;
		}
		if (cam[0] < -6.5) {
			cam[0] = -6.4;
		}
		if (cam[1] > 3.5) {
			cam[1] = 3.4;
		}
		if (cam[1] < 0.5) {
			cam[1] = 0.6;
		}

		if (cam[2] < -4.5) {
			cam[2] = -4.4;
		}
		if (cam[2] > 4.5) {
			cam[2] = 4.4;
		}
	}

	glutPostRedisplay();
}

/* special keyboard �Լ�*/
void specialKeyboard(int key, int x, int y) {
	//�þ� ���, ��/�Ʒ�/��/�� ȸ��
	switch (key) {
	case GLUT_KEY_LEFT:
		yaw -= 1.0f;
		break;
	case GLUT_KEY_RIGHT:
		yaw += 1.0f;
		break;
	case GLUT_KEY_UP:
		pitch += 1.0f;
		break;
	case GLUT_KEY_DOWN:
		pitch -= 1.0f;
		break;
	}
	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;
	if (start == 1) {
		double front[3];
		front[0] = cos(PI * pitch / 180) * cos(PI * yaw / 180);
		front[1] = sin(PI * pitch / 180);
		front[2] = cos(PI * pitch / 180) * sin(PI * yaw / 180);
		double sum = pow(front[0], 2) + pow(front[1], 2) + pow(front[2], 2);
		camFront[0] = front[0] / sqrt(sum);
		camFront[1] = front[1] / sqrt(sum);
		camFront[2] = front[2] / sqrt(sum);
	}

	glutPostRedisplay();
}

/* idle �Լ� */
void idle() {
	/* door ȸ�� ����*/
	if (door_spin == 0) {
		door_angle += 0.5;
		if (door_angle == 80) {
			door_spin = 1;
			return;
		}
	}
	else if (door_spin == 1) {
		cam[2] -= 0.01;
		count_door = count_door + 1;
		if (count_door == 400) {
			door_spin = 2;
			return;
		}
	}else if (door_spin == 2) {
		door_angle -= 0.5;
		if (door_angle == 0) {
			door_spin = -1;
			PlaySound(TEXT(SOUND_BGM), NULL, SND_ASYNC | SND_LOOP);
			return;
		}
	}
	/* money box �̵� ����*/
	if (select3 == 1) {
		trans_3 += 0.1;
		if (trans_3 == 0.5) {
			select3 = 2;
		}
	}else if (select3 == 2) {
		if (select8 == 1) {
			trans_3_2 = 0.2;
		}
	}
	else if (select3 == 0) {
		trans_3_2 = 0;
		trans_3 = 0;
		select8 = 0;
	}
	/* ���� �̵� ���� */
	if (select1 == 1) {
		trans_1 += 0.1;
		if (trans_1 == 0.5) {
			select1 = 2;
		}
	}
	else if (select1 == 0) {
		trans_1 = 0;
	}
	glutPostRedisplay();
}

/* ���콺 Ŭ���� event*/
void mouse_select() {
	if (mouse_x > 56 && mouse_x < 72 && mouse_y> 538 && mouse_y < 550) {
		q1 = 1;
	}
	else if (mouse_x > 288 && mouse_x < 302 && mouse_y> 538 && mouse_y < 550) {
		q1 = 2;
	}
	else if (mouse_x > 541 && mouse_x < 558 && mouse_y> 538 && mouse_y < 550) {
		q1 = 3;
	}
	if (mouse_x > 56 && mouse_x < 72 && mouse_y> 425 && mouse_y < 441) {
		q2 = 1;
	}
	else if (mouse_x > 288 && mouse_x < 302 && mouse_y> 425 && mouse_y < 441) {
		q2 = 2;
	}
	else if (mouse_x > 541 && mouse_x < 558 && mouse_y> 425 && mouse_y < 441) {
		q2 = 3;
	}
	if (mouse_x > 56 && mouse_x < 72 && mouse_y> 315 && mouse_y < 327) {
		q3 = 1;
	}
	else if (mouse_x > 288 && mouse_x < 302 && mouse_y> 315 && mouse_y < 327) {
		q3 = 2;
	}
	else if (mouse_x > 541 && mouse_x < 558 && mouse_y> 315 && mouse_y < 327) {
		q3 = 3;
	}
	if (mouse_x > 56 && mouse_x < 72 && mouse_y> 202 && mouse_y < 216) {
		q4 = 1;
	}
	else if (mouse_x > 288 && mouse_x < 302 && mouse_y> 202 && mouse_y < 216) {
		q4 = 2;
	}
	else if (mouse_x > 541 && mouse_x < 558 && mouse_y> 202 && mouse_y < 216) {
		q4 = 3;
	}
	if (mouse_x > 377 && mouse_x < 460 && mouse_y> 114 && mouse_y < 142) {
		if (q1 != 1) {
			answer1 = 1;
		}
		else {
			answer1 = 2;
		}
		if (q2 != 3) {
			answer2 = 1;
		}
		else {
			answer2 =2;
		}
		if (q3 != 2) {
			answer3 = 1;
		}
		else {
			answer3 = 2;
		}
		if (q4 != 3) {
			answer4 = 1;
		}
		else {
			answer4 = 2;
		}
	}
	if (answer1 == 2 && answer2 == 2 && answer3 == 2 && answer4 == 2) {
		if (mouse_x > 387 && mouse_x < 465 && mouse_y> 41 && mouse_y < 53) {
			exit(0);
		}
	}
}

/*���콺 �ݹ��Լ�*/
void mouse(int button, int state, int x, int y) {


	if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON) {
		if (start == 0) {
			door_spin = 0;
			start = 1;
			PlaySound(TEXT(SOUND_DOOR), NULL, SND_ASYNC);
		}
	}
	y = c_height - y; // y��ǥ
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (start == 1) {
			Picking(x, y); //x�� y��ǥ picking
		}
		else if (start == 2) {
			//���콺 Ŭ�� ��ǥ ����
			mouse_x = x;
			mouse_y = y;
			mouse_select();
		}
	}
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		g_nSelect = 0;
	}

	glutPostRedisplay();
}

/*���ù� �Լ�*/
void print_instruction() {
	printf("===========���� ���============\n");
	printf("w : ������ �̵�, s : �ڷ� �̵�\n");
	printf("a : ���� �̵�, d : ������ �̵�\n");
	printf("����Ű: �þ� ȸ��");
	printf("���콺 Ŭ�� : object ����\n");
	printf("�޴� ----\n");
	printf("close : object ���� ���\n");
	printf("reasoning/room : ȭ�� ��ȯ\n");
	printf("game exit : ���� ����\n");
}

/* ó�� ȭ���� text ����*/
void draw_text() {
	char* str, *str1,*str2,*str3,*str4,*str5;
	if (start == 0) {
		str = (char*)"Detective Game";
		str1 = (char*)"Game Start";
		str2 = (char*)"------METHOD------";
		str3 = (char*)"w, s, a, d : move";
		str4 = (char*)"left/right/up/down key : spin";
		str5 = (char*)"If you find a clue, click the mouse";
	}
	else {
		str = (char*)"  ";
		str1 = (char*)" ";
		str2 = (char*)"  ";
		str3 = (char*)"  ";
		str4 = (char*)"  ";
		str5 = (char*)"  ";
	}
	draw_string(GLUT_BITMAP_TIMES_ROMAN_24, str, -0.9, 0, 0, 0, 0);
	draw_string(GLUT_BITMAP_HELVETICA_18, str1, -0.5, -0.5, 0, 0, 0);
	draw_string(GLUT_BITMAP_HELVETICA_18, str2, -1.2, -1.2, 0, 0, 0);
	draw_string(GLUT_BITMAP_HELVETICA_18, str3, -0.7, -1.8, 0, 0, 0);
	draw_string(GLUT_BITMAP_HELVETICA_18, str4, -1.4, -2.4, 0, 0, 0);
	draw_string(GLUT_BITMAP_HELVETICA_18, str5, -1.5, -3.0, 0, 0, 0);
}

/* text ��� �Լ�*/
void draw_string(void* font, const char* str, float x_position, float y_position, float red, float green, float blue) {
	glPushAttrib(GL_LIGHTING_BIT);
	glDisable(GL_LIGHTING);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(-5, 5, -5, 5);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glColor3f(red, green, blue);
	glRasterPos3f(x_position, y_position, 0);
	for (unsigned int i = 0; i < strlen(str); i++) {
		glutBitmapCharacter(font, str[i]);
		glPopMatrix();
		glMatrixMode(GL_PROJECTION);
	}
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopAttrib();
}

/* ���� �Լ� */
void Picking(int x, int y)
{
	GLuint selectBuf[256]; //buffer�� select�� obj�� ���� ����
	// first step
	glSelectBuffer(256, selectBuf); //select data�� ������ �迭�� ����
	// second step
	glRenderMode(GL_SELECT);// ������ ��带 select��� ����
	// third step
	glInitNames(); //name stack �ʱ�ȭ
	// third step
	glPushName(-1);

	GLint viewport[4]; //viewport �迭
	glGetIntegerv(GL_VIEWPORT, viewport); //���� viewport ������ ����

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	// fourth step
	//���ο� viewing volume����
	gluPickMatrix(x, y, 0.1, 0.1, viewport);

	gluPerspective(80, c_width / c_height, 1, 500); //Projection T.F
	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();
	draw_select(); // ��ü ����
	glPopMatrix();

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glFlush();

	GLint hits; //hit ����
	// sixth step
	hits = glRenderMode(GL_RENDER); //render ���� ��ȯ�ϸ鼭 select�� ��ü�� ���� ��ȯ
	if (hits <= 0) return; //hit�� 0�� ��(������ ���� ���� ��), return
	//select buffer���� hit �� ��ü�� id�� depth�� ����
	int stack = selectBuf[0]; //namse stack�� name ��
	unsigned int zMin = selectBuf[1]; //min
	unsigned int zMax = selectBuf[2]; //max
	g_nSelect = selectBuf[3]; // obj id
	int index = 3 + stack;  //���� obj�� stack
	int i;
	for (i = 1; i < hits; i++) {
		stack = selectBuf[index];  //���� obj�� stack
		if (zMin > selectBuf[index + 1]) { //zMax�� ���� obj�� min�� ��
			zMin = selectBuf[index + 1]; //zMin update
			g_nSelect = selectBuf[index + 3]; //obj id update
		}
		index += 3 + stack; //���� obj ����
	}
	
	/* ���ý� ���� ���� ����*/
	switch (g_nSelect) {
	case 1:
		if (select1 == 0) {
			select1 = 1;
		}
		else {
			select1 = 0;
		}
		break;
	case 2:
		if (select2 == 0) {
			select2 = 1;
		}
		else {
			select2 = 0;
		}
		break;
	case 3:
		if (g_nSelect == 3) {
			if (select3 == 0) {
				select3 = 1;
			}
			else {
				select3 = 0;
			}
		}
		break;
	case 4:
		if (select4 == 0) {
			select4 = 1;
		}
		else {
			select4 = 0;
		}
		break;
	case 5:
		if (select5 == 0) {
			select5 = 1;
		}
		else {
			select5 = 0;
		}
		break;
	case 6:
		if (select6 == 0) {
			select6 = 1;
		}
		else {
			select6 = 0;
		}
		break;
	case 7:
		if (select7 == 0) {
			select7 = 1;
		}else {
			select7 = 0;
		}
		break;
	case 8:
		if (select8 == 0&& select3 != 0) {
			select8 = 1;
		}
		else { select8 = 0; }
		break;
	case 9:
		if (select9 == 0) {
			select9 = 1;
		}
		else {
			select9 = 0;
		}
		break;
	case 10:
		if (select10 == 0) {
			select10 = 1;
		}
		else {
			select10 = 0;
		}
	}
}
