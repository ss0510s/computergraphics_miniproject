#pragma once
/* object draw, texture 함수를 포함한 헤더파일*/

GLuint texName[20]; //texture 변수

/*texture obj 생성*/
void imgtexture(char* buf, int i) {
	int imgWidth, imgHeight, channels;
	glBindTexture(GL_TEXTURE_2D, texName[i]); //새로운 obj 생성
	uchar* img = readImageData(buf, &imgWidth, &imgHeight, &channels); //img 데이터를 read
	//printf("[cube]img%d width : %d, height : %d, ch : %d\n", i, imgWidth, imgHeight, channels);

	//texture 형식 지정

	glTexImage2D(GL_TEXTURE_2D, 0, /*INPUT CHANNEL*/3, imgWidth, imgHeight, 0, /*TEXEL CHANNEL*/GL_RGB, GL_UNSIGNED_BYTE, img);
	//texture mapping 방법 지정
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
}

/*texture 함수 호출*/
void texture() {
	glGenTextures(20, texName);
	char buf[200];
	//brick
	sprintf(buf, "img/brick.bmp");
	buf[strlen(buf)] = 0;
	imgtexture(buf, 0);

	sprintf(buf, "img/left.bmp");
	buf[strlen(buf)] = 0;
	imgtexture(buf, 1);

	sprintf(buf, "img/bottom.bmp");
	buf[strlen(buf)] = 0;
	imgtexture(buf, 2);

	sprintf(buf, "img/white.bmp");
	buf[strlen(buf)] = 0;
	imgtexture(buf, 3);

	sprintf(buf, "img/wood.bmp");
	buf[strlen(buf)] = 0;
	imgtexture(buf, 4);

	sprintf(buf, "img/wood_light.bmp");
	buf[strlen(buf)] = 0;
	imgtexture(buf, 5);

	sprintf(buf, "img/black_tile.bmp");
	buf[strlen(buf)] = 0;
	imgtexture(buf, 6);

	sprintf(buf, "img/calender.bmp");
	buf[strlen(buf)] = 0;
	imgtexture(buf, 7);

	sprintf(buf, "img/bottom_b.bmp");
	buf[strlen(buf)] = 0;
	imgtexture(buf, 8);

	sprintf(buf, "img/money.bmp");
	buf[strlen(buf)] = 0;
	imgtexture(buf, 9);

	sprintf(buf, "img/bottle.bmp");
	buf[strlen(buf)] = 0;
	imgtexture(buf, 10);

	sprintf(buf, "img/cup.bmp");
	buf[strlen(buf)] = 0;
	imgtexture(buf, 11);

	sprintf(buf, "img/paper1.bmp");
	buf[strlen(buf)] = 0;
	imgtexture(buf, 12);

	sprintf(buf, "img/phone.bmp");
	buf[strlen(buf)] = 0;
	imgtexture(buf, 13);

	sprintf(buf, "img/paper2.bmp");
	buf[strlen(buf)] = 0;
	imgtexture(buf, 14);

	sprintf(buf, "img/paper3.bmp");
	buf[strlen(buf)] = 0;
	imgtexture(buf, 15);

	sprintf(buf, "img/knife.bmp");
	buf[strlen(buf)] = 0;
	imgtexture(buf, 16);
}

/*불 스위치 그리기*/
void draw_light() {
	glColor3f(0.8, 0.8, 0.9);
	glBegin(GL_QUADS);
	glNormal3f(0, -1, 0);
	glVertex3f(-0.15, -0.3, 0.1);
	glVertex3f(-0.15, -0.3, 0);
	glVertex3f(0.15, -0.3, 0);
	glVertex3f(0.15, -0.3, 0.1);

	glNormal3f(-1, 0, 0);
	glVertex3f(-0.15, -0.3, 0.1);
	glVertex3f(-0.15, -0.3, 0);
	glVertex3f(-0.15, 0.3, 0);
	glVertex3f(-0.15, 0.3, 0.1);

	glNormal3f(0, 1, 0);
	glVertex3f(-0.15, 0.3, 0.1);
	glVertex3f(-0.15, 0.3, 0);
	glVertex3f(0.15, 0.3, 0);
	glVertex3f(0.15, 0.3, 0.1);

	glNormal3f(1, 0, 0);
	glVertex3f(0.15, -0.3, 0.1);
	glVertex3f(0.15, -0.3, 0);
	glVertex3f(0.15, 0.3, 0);
	glVertex3f(0.15, 0.3, 0.1);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(0, 0, -1);
	glVertex3f(-0.15, -0.3, 0);
	glVertex3f(-0.15, 0.3, 0);
	glVertex3f(-0.05, 0.3, 0);
	glVertex3f(-0.05, -0.3, 0);

	glVertex3f(-0.05, -0.3, 0);
	glVertex3f(-0.05, -0.2, 0);
	glVertex3f(0.15, -0.2, 0);
	glVertex3f(0.15, -0.3, 0);

	glVertex3f(0.15, -0.2, 0);
	glVertex3f(0.15, 0.3, 0);
	glVertex3f(0.05, 0.3, 0);
	glVertex3f(0.05, -0.2, 0);

	glVertex3f(0.05, 0.3, 0);
	glVertex3f(0.05, 0.2, 0);
	glVertex3f(-0.05, 0.2, 0);
	glVertex3f(-0.05, 0.3, 0);
	glEnd();
}

/* 불 스위치 그리기 2*/
void draw_light2() {
	glColor3f(0.7, 0.7, 0.9);
	glBegin(GL_QUADS);
	glNormal3f(0, -1, 0);
	glVertex3f(-0.1, -0.25, 0.05);
	glVertex3f(-0.1, -0.25, -0.05);
	glVertex3f(0.1, -0.25, -0.05);
	glVertex3f(0.1, -0.25, 0.05);

	glNormal3f(-1, 0, 0);
	glVertex3f(-0.1, -0.25, 0.05);
	glVertex3f(-0.1, -0.25, -0.05);
	glVertex3f(-0.1, 0.25, -0.05);
	glVertex3f(-0.1, 0.25, 0.05);

	glNormal3f(0, 1, 0);
	glVertex3f(-0.1, 0.25, 0.05);
	glVertex3f(-0.1, 0.25, -0.05);
	glVertex3f(0.1, 0.25, -0.05);
	glVertex3f(0.1, 0.25, 0.05);

	glNormal3f(1, 0, 0);
	glVertex3f(0.1, -0.25, 0.05);
	glVertex3f(0.1, -0.25, -0.05);
	glVertex3f(0.1, 0.25, -0.05);
	glVertex3f(0.1, 0.25, 0.05);

	glNormal3f(0, 0, 1);
	glVertex3f(-0.1, -0.25, 0.05);
	glVertex3f(-0.1, 0.25, 0.05);
	glVertex3f(0.1, 0.25, 0.05);
	glVertex3f(0.1, -0.25, 0.05);

	glNormal3f(0, 0, -1);
	glVertex3f(-0.1, -0.25, -0.05);
	glVertex3f(-0.1, 0.25, -0.05);
	glVertex3f(0.1, 0.25, -0.05);
	glVertex3f(0.1, -0.25, -0.05);

	glEnd();
}


/*돈그리기*/
void money() {
	glColor3f(0.5, 0.7, 0.5);
	glBindTexture(GL_TEXTURE_2D, texName[9]);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(0.07f, 0, 0.15f);
	glTexCoord2f(0, 1); glVertex3f(-0.07f, 0, 0.15f);
	glTexCoord2f(1, 1); glVertex3f(-0.12f, 0, -0.15f);
	glTexCoord2f(1, 0); glVertex3f(0.02f, 0, -0.15f);
	glEnd();
}
/*서류 봉투*/
void paper() {
	glColor3f(0.5, 0.5, 0.2);
	glBegin(GL_QUADS);
	glVertex3f(0.4f, 0, 0.6f);
	glVertex3f(-0.4f, 0, 0.6f);
	glVertex3f(-0.4f, 0, -0.6f);
	glVertex3f(0.4f, 0, -0.6f);

	glVertex3f(0.4f, 0.01f, 0.4f);
	glVertex3f(-0.4f, 0.01f, 0.4f);
	glVertex3f(-0.4f, 0.01f, -0.6f);
	glVertex3f(0.4f, 0.01f, -0.6f);

	glEnd();

	glEnable(GL_TEXTURE_2D);

}


/*달력 그리기*/
void calender() {
	glDisable(GL_TEXTURE_2D);
	glColor3f(0.1f, 0.1f, 0.1f);
	glBegin(GL_QUADS);
	glVertex3f(0, 0.5f, 0.2f);
	glVertex3f(0.15f, 0, 0.2f);
	glVertex3f(0.15f, 0, -0.2f);
	glVertex3f(0, 0.5f, -0.2f);

	glVertex3f(0, 0.5f, 0.2f);
	glVertex3f(-0.15f, 0, 0.2f);
	glVertex3f(-0.15f, 0, -0.2f);
	glVertex3f(0, 0.5f, -0.2f);

	glVertex3f(0, 0.1f, 0.2f);
	glVertex3f(0.15f, 0, 0.2f);
	glVertex3f(0.15f, 0, -0.2f);
	glVertex3f(0, 0.1f, -0.2f);

	glVertex3f(0, 0.1f, 0.2f);
	glVertex3f(-0.15f, 0, 0.2f);
	glVertex3f(-0.15f, 0, -0.2f);
	glVertex3f(0, 0.1f, -0.2f);
	glEnd();

	glEnable(GL_TEXTURE_2D);
	glColor3f(1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, texName[7]);
	glBegin(GL_QUADS);
	glNormal3f(1, 0, 0);
	glTexCoord2f(0, 1); glVertex3f(0, 0.5f, 0.2f);
	glTexCoord2f(0, 0); glVertex3f(0.2f, 0.1f, 0.2f);
	glTexCoord2f(1, 0); glVertex3f(0.2f, 0.1f, -0.2f);
	glTexCoord2f(1, 1); glVertex3f(0, 0.5f, -0.2f);
	glEnd();

	glDisable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
	glVertex3f(0, 0.5f, 0.2f);
	glVertex3f(-0.2f, 0.1f, 0.2f);
	glVertex3f(-0.2f, 0.1f, -0.2f);
	glVertex3f(0, 0.5f, -0.2f);
	glEnd();
	glEnable(GL_TEXTURE_2D);
	
}

/*kitchen 그리기*/
void draw_kitchen() {
	glColor3f(1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, texName[6]);

	glBegin(GL_QUADS);
	glNormal3f(-1, 0, 0); //법선벡터 -x방향
	glTexCoord2f(0, 0); glVertex3f(-0.5f, 0, -3.0f);
	glTexCoord2f(0, 1); glVertex3f(-0.5f, 1.5f, -3.0f);
	glTexCoord2f(2, 1); glVertex3f(-0.5f, 1.5f, 3.0f);
	glTexCoord2f(2, 0); glVertex3f(-0.5f, 0, 3.0f);

	glNormal3f(0, 0, -1); //법선벡터 -z방향
	glTexCoord2f(0, 0); glVertex3f(-0.5f, 0, -3.0f);
	glTexCoord2f(0, 1); glVertex3f(-0.5f, 1.5f, -3.0f);
	glTexCoord2f(1, 1); glVertex3f(0.5f, 1.5f, -3.0f);
	glTexCoord2f(1, 0); glVertex3f(0.5f, 0, -3.0f);

	glNormal3f(1, 0, 0); //법선벡터 x방향
	glTexCoord2f(0, 0); glVertex3f(0.5f, 0, -3.0f);
	glTexCoord2f(0, 1); glVertex3f(0.5f, 1.5f, -3.0f);
	glTexCoord2f(2, 1); glVertex3f(0.5f, 1.5f, 3.0f);
	glTexCoord2f(2, 0); glVertex3f(0.5f, 0, 3.0f);

	glNormal3f(0, 0, 1); //법선벡터 z방향
	glTexCoord2f(0, 0); glVertex3f(-0.5f, 0, 3.0f);
	glTexCoord2f(0, 1); glVertex3f(-0.5f, 1.5f, 3.0f);
	glTexCoord2f(1, 1); glVertex3f(0.5f, 1.5f, 3.0f);
	glTexCoord2f(1, 0); glVertex3f(0.5f, 0, 3.0f);

	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0); //obj 비활성화

}

/* room 그리기*/
void draw_near() {
	glColor3f(1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, texName[3]);//obj 활성화
	glBegin(GL_QUADS);
	glNormal3f(0, 0, -1); //법선벡터 -z방향
	glTexCoord2f(0, 3); glVertex3f(0, 4.0f, 5.0f);
	glTexCoord2f(0, 0); glVertex3f(0, 0, 5.0f);
	glTexCoord2f(10.5, 0); glVertex3f(7.0f, 0, 5.0f);
	glTexCoord2f(10.5, 3); glVertex3f(7.0f, 4.0f, 5.0f);

	glTexCoord2f(4.5, 0); glVertex3f(0, 3.0f, 5.0f);
	glTexCoord2f(4.5, 1); glVertex3f(0, 4.0f, 5.0f);
	glTexCoord2f(0, 1); glVertex3f(-1.5f, 4.0f, 5.0f);
	glTexCoord2f(0, 0); glVertex3f(-1.5f, 3.0f, 5.0f);

	glTexCoord2f(0, 3); glVertex3f(-7.0f, 4.0f, 5.0f);
	glTexCoord2f(0, 0); glVertex3f(-7.0f, 0, 5.0f);
	glTexCoord2f(6, 0); glVertex3f(-1.5f, 0, 5.0f);
	glTexCoord2f(6, 3); glVertex3f(-1.5f, 4.0f, 5.0f);
	glEnd();

	//옆면
	glBindTexture(GL_TEXTURE_2D, texName[0]);
	glBegin(GL_QUADS);
	glNormal3f(1, 0, 0);
	glTexCoord2f(0, 0); glVertex3f(7.0f, 0, 5.2f);
	glTexCoord2f(0.1, 0); glVertex3f(7.0f, 0, 5.0f);
	glTexCoord2f(0.1, 1); glVertex3f(7.0f, 4.0f, 5.0f);
	glTexCoord2f(0, 1); glVertex3f(7.0f, 4.0f, 5.2f);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(-1, 0, 0);
	glTexCoord2f(0, 0); glVertex3f(-7.0f, 0, 5.2f);
	glTexCoord2f(0.1, 0); glVertex3f(-7.0f, 0, 5.0f);
	glTexCoord2f(0.1, 1); glVertex3f(-7.0f, 4.0f, 5.0f);
	glTexCoord2f(0, 1); glVertex3f(-7.0f, 4.0f, 5.2f);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(0, 0, 1); //법선벡터 z방향
	glTexCoord2f(0, 1); glVertex3f(0, 4.0f, 5.2f);
	glTexCoord2f(0, 0); glVertex3f(0, 0, 5.2f);
	glTexCoord2f(3.5, 0); glVertex3f(7.0f, 0, 5.2f);
	glTexCoord2f(3.5, 1); glVertex3f(7.0f, 4.0f, 5.2f);

	glTexCoord2f(1.5, 0); glVertex3f(0, 3.0f, 5.2f);
	glTexCoord2f(1.5, 0.34); glVertex3f(0, 4.0f, 5.2f);
	glTexCoord2f(0, 0.34); glVertex3f(-1.5f, 4.0f, 5.2f);
	glTexCoord2f(0, 0); glVertex3f(-1.5f, 3.0f, 5.2f);

	glTexCoord2f(0, 1); glVertex3f(-7.0f, 4.0f, 5.2f);
	glTexCoord2f(0, 0); glVertex3f(-7.0f, 0, 5.2f);
	glTexCoord2f(2, 0); glVertex3f(-1.5f, 0, 5.2f);
	glTexCoord2f(2, 1); glVertex3f(-1.5f, 4.0f, 5.2f);
	glEnd();
}

void draw_room() {

	glColor3f(1.0, 1.0, 1.0);

	//texture 좌표 설정, vertex 좌표 설정
	//left
	glBindTexture(GL_TEXTURE_2D, texName[1]); //obj 활성화
	glBegin(GL_QUADS);
	glNormal3f(1, 0, 0);//법선벡터 x방향
	glTexCoord2f(0, 0); glVertex3f(-7.0f, 4.0f, -5.0f);
	glTexCoord2f(5, 0); glVertex3f(-7.0f, 0, -5.0f);
	glTexCoord2f(5, 5); glVertex3f(-7.0f, 0, 5.0f);
	glTexCoord2f(0, 5); glVertex3f(-7.0f, 4.0f, 5.0f);
	glEnd();

	//Right
	glBindTexture(GL_TEXTURE_2D, texName[3]);//obj 활성화
	glBegin(GL_QUADS);
	glNormal3f(-1, 0, 0); //법선벡터 -x방향
	glTexCoord2f(6, 3); glVertex3f(7.0f, 4.0f, 5.0f);
	glTexCoord2f(6, 0); glVertex3f(7.0f, 0, 5.0f);
	glTexCoord2f(0, 0); glVertex3f(7.0f, 0, -5.0f);
	glTexCoord2f(0, 3); glVertex3f(7.0f, 4.0f, -5.0f);
	glEnd();

	//Bottom
	glBindTexture(GL_TEXTURE_2D, texName[8]);//obj 활성화
	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0); //법선벡터 y 방향
	glTexCoord2f(0, 0); glVertex3f(-7.0f, 0, -5.0f);
	glTexCoord2f(0, 1); glVertex3f(7.0f, 0, -5.0f);
	glTexCoord2f(1, 1); glVertex3f(7.0f, 0, 5.0f);
	glTexCoord2f(1, 0); glVertex3f(-7.0f, 0, 5.0f);
	glEnd();

	//Top
	glBindTexture(GL_TEXTURE_2D, texName[3]);//obj 활성화
	glBegin(GL_QUADS);
	glNormal3f(0, -1, 0); //법선벡터 -y 방향
	glTexCoord2f(0, 0); glVertex3f(-7.0f, 4.0f, 5.0f);
	glTexCoord2f(5, 0); glVertex3f(7.0f, 4.0f, 5.0f);
	glTexCoord2f(5, 5); glVertex3f(7.0f, 4.0f, -5.0f);
	glTexCoord2f(0, 5); glVertex3f(-7.0f, 4.0f, -5.0f);
	glEnd();

	//Near
	draw_near();

	//Far
	glColor3f(1.0, 1.0, 1.0);
	glBindTexture(GL_TEXTURE_2D, texName[3]);//obj 활성화
	glBegin(GL_QUADS);
	glNormal3f(0, 0, 1); //법선벡터 z방향
	glTexCoord2f(6, 3); glVertex3f(7.0f, 4.0f, -5.0f);
	glTexCoord2f(0, 3); glVertex3f(-7.0f, 4.0f, -5.0f);
	glTexCoord2f(0, 0); glVertex3f(-7.0f, 0, -5.0f);
	glTexCoord2f(6, 0); glVertex3f(7.0f, 0, -5.0f);
	glEnd();

	

}

/*door 그리기*/
void draw_door_frame() {
	glColor3f(1.0, 1.0, 1.0);

	//앞면
	glBindTexture(GL_TEXTURE_2D, texName[4]);
	glBegin(GL_QUADS);
	glNormal3f(0, 0, 1);
	glTexCoord2f(0, 0); glVertex3f(-1.5f, 0, 5.25f);
	glTexCoord2f(0, 3); glVertex3f(-1.5f, 3.0f, 5.25f);
	glTexCoord2f(1, 3); glVertex3f(-1.4f, 2.9f, 5.25f);
	glTexCoord2f(1, 0); glVertex3f(-1.4f, 0, 5.25f);

	glTexCoord2f(0, 0); glVertex3f(-1.5f, 3.0f, 5.25f);
	glTexCoord2f(0, 2); glVertex3f(0, 3.0f, 5.25f);
	glTexCoord2f(1, 2); glVertex3f(-0.1f, 2.9f, 5.25f);
	glTexCoord2f(1, 0); glVertex3f(-1.4f, 2.9f, 5.25f);

	glTexCoord2f(0, 0); glVertex3f(-0.1f, 0, 5.25f);
	glTexCoord2f(0, 3); glVertex3f(-0.1f, 2.9f, 5.25f);
	glTexCoord2f(1, 3); glVertex3f(0, 3.0f, 5.25f);
	glTexCoord2f(1, 0); glVertex3f(0, 0, 5.25f);
	glEnd();

	//옆면
	glBindTexture(GL_TEXTURE_2D, texName[4]);
	glBegin(GL_QUADS);
	glNormal3f(-1, 0, 0);
	glTexCoord2f(0, 0); glVertex3f(-1.5f, 0, 5.25f);
	glTexCoord2f(0, 3); glVertex3f(-1.5f, 3.0f, 5.25f);
	glTexCoord2f(1, 3); glVertex3f(-1.5f, 3.0f, 4.95f);
	glTexCoord2f(1, 0); glVertex3f(-1.5f, 0, 4.95f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texName[4]);
	glBegin(GL_QUADS);
	glNormal3f(1, 0, 0);
	glTexCoord2f(0, 0); glVertex3f(-1.4f, 0, 5.25f);
	glTexCoord2f(0, 3); glVertex3f(-1.4f, 2.9f, 5.25f);
	glTexCoord2f(1, 3); glVertex3f(-1.4f, 2.9f, 4.95f);
	glTexCoord2f(1, 0); glVertex3f(-1.4f, 0, 4.95f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texName[4]);
	glBegin(GL_QUADS);
	glNormal3f(-1, 0, 0);
	glTexCoord2f(0, 0); glVertex3f(-0.1f, 0, 5.25f);
	glTexCoord2f(0, 3); glVertex3f(-0.1f, 2.9f, 5.25f);
	glTexCoord2f(1, 3); glVertex3f(-0.1f, 2.9f, 4.95f);
	glTexCoord2f(1, 0); glVertex3f(-0.1f, 0, 4.95f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texName[4]);
	glBegin(GL_QUADS);
	glNormal3f(1, 0, 0);
	glTexCoord2f(0, 0); glVertex3f(0, 0, 5.25f);
	glTexCoord2f(0, 3); glVertex3f(0, 3.0f, 5.25f);
	glTexCoord2f(1, 3); glVertex3f(0, 3.0f, 4.95f);
	glTexCoord2f(1, 0); glVertex3f(0, 0, 4.95f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texName[4]);
	glBegin(GL_QUADS);
	glNormal3f(0, -1, 0);
	glTexCoord2f(0, 0); glVertex3f(-1.4f, 2.9f, 4.95f);
	glTexCoord2f(0, 2); glVertex3f(-0.1f, 2.9f, 4.95f);
	glTexCoord2f(1, 2); glVertex3f(-0.1f, 2.9f, 5.25f);
	glTexCoord2f(1, 0); glVertex3f(-1.4f, 2.9f, 5.25f);
	glEnd();


	//뒷면
	glBindTexture(GL_TEXTURE_2D, texName[4]);
	glBegin(GL_QUADS);
	glNormal3f(0, 0, -1);
	glTexCoord2f(0, 0); glVertex3f(-1.5f, 0, 4.95f);
	glTexCoord2f(0, 3); glVertex3f(-1.5f, 3.0f, 4.95f);
	glTexCoord2f(1, 3); glVertex3f(-1.4f, 2.9f, 4.95f);
	glTexCoord2f(1, 0); glVertex3f(-1.4f, 0, 4.95f);

	glTexCoord2f(0, 0); glVertex3f(-1.5f, 3.0f, 4.95f);
	glTexCoord2f(0, 2); glVertex3f(0, 3.0f, 4.95f);
	glTexCoord2f(1, 2); glVertex3f(-0.1f, 2.9f, 4.95f);
	glTexCoord2f(1, 0); glVertex3f(-1.4f, 2.9f, 4.95f);

	glTexCoord2f(0, 0); glVertex3f(-0.1f, 0, 4.95f);
	glTexCoord2f(0, 3); glVertex3f(-0.1f, 2.9f, 4.95f);
	glTexCoord2f(1, 3); glVertex3f(0, 3.0f, 4.95f);
	glTexCoord2f(1, 0); glVertex3f(0, 0, 4.95f);
	glEnd();
}

/*door*/
void draw_door() {
	glColor3f(1, 1, 1);
	glDisable(GL_BLEND);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBindTexture(GL_TEXTURE_2D, texName[5]);
	//앞면
	glBegin(GL_QUADS);
	glNormal3f(0, 0, 1);
	glTexCoord2f(0, 0); glVertex3f(0, 0, 0.2f);
	glTexCoord2f(0, 1); glVertex3f(0, 2.9f, 0.2f);
	glTexCoord2f(3, 1); glVertex3f(0.15f, 2.75f, 0.2f);
	glTexCoord2f(3, 0); glVertex3f(0.15f, 0.15f, 0.2f);

	glTexCoord2f(0, 0); glVertex3f(1.15f, 0.15f, 0.2f);
	glTexCoord2f(0, 1); glVertex3f(1.15f, 2.75f, 0.2f);
	glTexCoord2f(3, 1); glVertex3f(1.3f, 2.9f, 0.2f);
	glTexCoord2f(3, 0); glVertex3f(1.3f, 0, 0.2f);

	glTexCoord2f(0, 0); glVertex3f(0, 2.9f, 0.2f);
	glTexCoord2f(0, 2); glVertex3f(1.3f, 2.9f, 0.2f);
	glTexCoord2f(1, 2); glVertex3f(1.15f, 2.75f, 0.2f);
	glTexCoord2f(1, 0); glVertex3f(0.15f, 2.75f, 0.2f);

	glTexCoord2f(0, 0); glVertex3f(0.15f, 0.15f, 0.2f);
	glTexCoord2f(0, 2); glVertex3f(1.15f, 0.15f, 0.2f);
	glTexCoord2f(1, 2); glVertex3f(1.3f, 0, 0.2f);
	glTexCoord2f(1, 0); glVertex3f(0, 0, 0.2f);
	glEnd();
	//뒷면

	glBegin(GL_QUADS);
	glNormal3f(0, 0, -1);
	glTexCoord2f(0, 0); glVertex3f(0, 0, 0);
	glTexCoord2f(0, 1); glVertex3f(0, 2.9f, 0);
	glTexCoord2f(3, 1); glVertex3f(0.15f, 2.75f, 0);
	glTexCoord2f(3, 0); glVertex3f(0.15f, 0.15f, 0);

	glTexCoord2f(0, 0); glVertex3f(1.15f, 0.15f, 0);
	glTexCoord2f(0, 1); glVertex3f(1.15f, 2.75f, 0);
	glTexCoord2f(3, 1); glVertex3f(1.3f, 2.9f, 0);
	glTexCoord2f(3, 0); glVertex3f(1.3f, 0, 0);

	glTexCoord2f(0, 0); glVertex3f(0, 2.9f, 0);
	glTexCoord2f(0, 2); glVertex3f(1.3f, 2.9f, 0);
	glTexCoord2f(1, 2); glVertex3f(1.15f, 2.75f, 0);
	glTexCoord2f(1, 0); glVertex3f(0.15f, 2.75f, 0);

	glTexCoord2f(0, 0); glVertex3f(0.15f, 0.15f, 0);
	glTexCoord2f(0, 2); glVertex3f(1.15f, 0.15f, 0);
	glTexCoord2f(1, 2); glVertex3f(1.3f, 0, 0);
	glTexCoord2f(1, 0); glVertex3f(0, 0, 0);
	glEnd();

	//옆면

	glBegin(GL_QUADS);
	glNormal3f(-1, 0, 0);
	glTexCoord2f(0, 0); glVertex3f(0, 0, 0.2f);
	glTexCoord2f(0, 1); glVertex3f(0, 2.9f, 0.2f);
	glTexCoord2f(3, 1); glVertex3f(0, 2.9f, 0);
	glTexCoord2f(3, 0); glVertex3f(0, 0, 0);

	glNormal3f(1, 0, 0);
	glTexCoord2f(0, 0); glVertex3f(0.15f, 0.15f, 0.2f);
	glTexCoord2f(0, 1); glVertex3f(0.15f, 2.75f, 0.2f);
	glTexCoord2f(3, 1); glVertex3f(0.15f, 2.75f, 0);
	glTexCoord2f(3, 0); glVertex3f(0.15f, 0.15f, 0);

	glNormal3f(-1, 0, 0);
	glTexCoord2f(0, 0); glVertex3f(1.15f, 0.15f, 0);
	glTexCoord2f(0, 1); glVertex3f(1.15f, 2.75f, 0);
	glTexCoord2f(3, 1); glVertex3f(1.15f, 2.75f, 0.2f);
	glTexCoord2f(3, 0); glVertex3f(1.15f, 0.15f, 0.2f);

	glNormal3f(1, 0, 0);
	glTexCoord2f(0, 0); glVertex3f(1.3f, 0, 0.2f);
	glTexCoord2f(0, 1); glVertex3f(1.3f, 2.9f, 0.2f);
	glTexCoord2f(3, 1); glVertex3f(1.3f, 2.9f, 0);
	glTexCoord2f(3, 0); glVertex3f(1.3f, 0, 0);

	glNormal3f(0, -1, 0);
	glTexCoord2f(0, 0); glVertex3f(0.15f, 2.75f, 0);
	glTexCoord2f(0, 2); glVertex3f(1.15f, 2.75f, 0);
	glTexCoord2f(1, 2); glVertex3f(1.15f, 2.75f, 0.2f);
	glTexCoord2f(1, 0); glVertex3f(0.15f, 2.75f, 0.2f);

	glNormal3f(0, 1, 0);
	glTexCoord2f(0, 0); glVertex3f(0.15f, 0.15f, 0);
	glTexCoord2f(0, 2); glVertex3f(1.15f, 0.15f, 0);
	glTexCoord2f(1, 2); glVertex3f(1.15f, 0.15f, 0.2f);
	glTexCoord2f(1, 0); glVertex3f(0.15f, 0.15f, 0.2f);

	glEnd();
}

/*문의 창 그리기*/
void tex_window() {
	glColor4f(1, 1, 1, 0.5f);
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	glBegin(GL_QUADS);
	glVertex3f(0.15f, 0.15f, 0.2f);
	glVertex3f(0.15f, 2.75f, 0.2f);
	glVertex3f(1.15f, 2.75f, 0.2f);
	glVertex3f(1.15f, 0.15f, 0.2f);

	glVertex3f(0.15f, 0.15f, 0);
	glVertex3f(0.15f, 2.75f, 0);
	glVertex3f(1.15f, 2.75f, 0);
	glVertex3f(1.15f, 0.15f, 0);

	glEnd();
	glDisable(GL_BLEND);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

/*obj 파일 draw*/
void draw_obj(ObjParser* objParser)
{
	glDisable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
	glBegin(GL_TRIANGLES);
	for (unsigned int n = 0; n < objParser->getFaceSize(); n += 3) {
		glNormal3f(objParser->normal[objParser->normalIdx[n] - 1].x,
			objParser->normal[objParser->normalIdx[n] - 1].y,
			objParser->normal[objParser->normalIdx[n] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n] - 1].x,
			objParser->vertices[objParser->vertexIdx[n] - 1].y,
			objParser->vertices[objParser->vertexIdx[n] - 1].z);

		glNormal3f(objParser->normal[objParser->normalIdx[n + 1] - 1].x,
			objParser->normal[objParser->normalIdx[n + 1] - 1].y,
			objParser->normal[objParser->normalIdx[n + 1] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n + 1] - 1].x,
			objParser->vertices[objParser->vertexIdx[n + 1] - 1].y,
			objParser->vertices[objParser->vertexIdx[n + 1] - 1].z);

		glNormal3f(objParser->normal[objParser->normalIdx[n + 2] - 1].x,
			objParser->normal[objParser->normalIdx[n + 2] - 1].y,
			objParser->normal[objParser->normalIdx[n + 2] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n + 2] - 1].x,
			objParser->vertices[objParser->vertexIdx[n + 2] - 1].y,
			objParser->vertices[objParser->vertexIdx[n + 2] - 1].z);
	}
	glEnd();
	glEnable(GL_TEXTURE_2D);
}