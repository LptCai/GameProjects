#include"stdafx.h"
#include"StartPanal.h"
#include"Data.h"
extern void ATLLoadTextureWithAlpha(char *fileName, GLuint &texture);
extern void ATLLoadTexture(char*fileName, GLuint &texture);
extern void texture(GLuint textur);
Start::Start()
{
	
}
void Start::init()
{
	btnalpha = 0.85;
	LArrowAlpha = 0.85;
	RArrowAlpha = 0.85;
	Butterfly.set(-8, -22, 0);
	LoadPic();
}
void Start::LoadPic()
{
	ATLLoadTextureWithAlpha("res\\aim.bmp", tex[0]);
	ATLLoadTextureWithAlpha("res\\mai.bmp", tex[1]);
	ATLLoadTextureWithAlpha("res\\leftboy.bmp", tex[2]);
	ATLLoadTextureWithAlpha("res\\rightboy.bmp", tex[3]);
	ATLLoadTextureWithAlpha("res\\startbtn.bmp", tex[4]);
	ATLLoadTextureWithAlpha("res\\butterfly.bmp", tex[5]);
	ATLLoadTextureWithAlpha("res\\butterfly0.bmp", tex[6]);
	ATLLoadTextureWithAlpha("res\\butterfly1.bmp", tex[7]);
	ATLLoadTextureWithAlpha("res\\leftarrow.bmp", tex[8]);
	ATLLoadTextureWithAlpha("res\\rightarrow.bmp", tex[9]);
	ATLLoadTextureWithAlpha("res\\butterflyCo.bmp", tex[10]);
	ATLLoadTextureWithAlpha("res\\copyright.bmp", tex[11]);

}
void Start::DrawTitle()
{
	//绘制文字IAMMAI游戏题目
	glPushMatrix();
	texture(tex[0]);
	glColor4f(1.0, 1.0, 1.0, 1.0);
	glEnable(GL_BLEND);
	glEnable(GL_TEXTURE_2D);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_ALPHA_TEST);
	glTranslatef(-1, 15, 0);
	glScalef(17, 14, 14);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_ALPHA);
	glPopMatrix();
}
void Start::DrawStartbtn()
{
	//绘制开始按钮
	glPushMatrix();
	texture(tex[4]);
	glColor4f(1.0, 1.0, 1.0, btnalpha);
	glEnable(GL_BLEND);
	glEnable(GL_TEXTURE_2D);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_ALPHA_TEST);
	glTranslatef(0, -25, 0);
	glScalef(8, 7, 7);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_ALPHA);
	glPopMatrix();
}
void Start::DrawButterfly(int t)
{
	//绘制蝴蝶
	glPushMatrix();
	if (t % 2 == 0) {
		texture(tex[6]);
	}
	else
	{	
		texture(tex[7]);
	}
	glColor4f(1.0, 1.0, 1.0, 1.0);
	glEnable(GL_BLEND);
	glEnable(GL_TEXTURE_2D);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_ALPHA_TEST);
	glTranslatef(Butterfly.x, Butterfly.y, Butterfly.z);
	glScalef(3, 3, 3);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_ALPHA);
	glPopMatrix();
}
void Start::DrawLArrow()
{
	//绘制左箭头
	glPushMatrix();
	texture(tex[8]);
	glColor4f(1.0, 1.0, 1.0, LArrowAlpha);
	glEnable(GL_BLEND);
	glEnable(GL_TEXTURE_2D);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_ALPHA_TEST);
	glTranslatef(-15, -28, 0);
	glScalef(3, 3, 3);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_ALPHA);
	glPopMatrix();
}
void Start::DrawRArrow()
{
	//绘制右箭头
	glPushMatrix();
	texture(tex[9]);
	glColor4f(1.0, 1.0, 1.0,RArrowAlpha);
	glEnable(GL_BLEND);
	glEnable(GL_TEXTURE_2D);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_ALPHA_TEST);
	glTranslatef(15, -28, 0);
	glScalef(3, 3, 3);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_ALPHA);
	glPopMatrix();
}
void Start::DrawFlyCo()
{
	//绘制蝴蝶带
	glPushMatrix();
	texture(tex[10]);
	glColor4f(1.0, 1.0, 1.0, 1.0);
	glEnable(GL_BLEND);
	glEnable(GL_TEXTURE_2D);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_ALPHA_TEST);
	glTranslatef(-18, 8, 0);
	glScalef(20, 20, 20);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_ALPHA);
	glPopMatrix();

	glPushMatrix();
	texture(tex[10]);
	glColor4f(1.0, 1.0, 1.0, 1.0);
	glEnable(GL_BLEND);
	glEnable(GL_TEXTURE_2D);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_ALPHA_TEST);
	glTranslatef(15, 8, 0);
	glScalef(20, 20, 20);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_ALPHA);
	glPopMatrix();
}
void Start::DrawCopyright()
{
	glPushMatrix();
	texture(tex[11]);
	glColor4f(1.0, 1.0, 1.0, 0.8);
	glEnable(GL_BLEND);
	glEnable(GL_TEXTURE_2D);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_ALPHA_TEST);
	glTranslatef(0,-37, 0);
	glScalef(7, 7, 7);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_ALPHA);
	glPopMatrix();
}
void Start::Update()
{
	char dir='u';
	if (Butterfly.y <=-22)
	{
		dir = 'u';
	}
	if (Butterfly.y >=4)
	{
		dir = 'd';
	}
	if (Butterfly.x <= -10)
	{
		dir = 'r';
	}
	if (Butterfly.x >= 15)
	{
		dir = 'l';
	}
	int m = rand() % 2;
	if (m == 0)
	{
		m = -1;
	}
	else
	{
		m = 1;
	}
	
switch(dir)
	{
	case 'u':
		Butterfly.y += 2;
		Butterfly.x = Butterfly.x + m*rand()%6;
		break;
	case 'd':
		Butterfly.y -= 3;
		Butterfly.x = Butterfly.x + m*rand() % 6;
		break;
	case 'l':
		Butterfly.x -= 4;
		break;
	case 'r':
		Butterfly.x += 4;
		break;
	default:
		break;
	}
}