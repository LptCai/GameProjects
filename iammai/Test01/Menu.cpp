
#include"stdafx.h"
#include"Menu.h"
extern void ATLLoadTextureWithAlpha(char *fileName, GLuint &texture);
extern void ATLLoadTexture(char*fileName, GLuint &texture);
extern void texture(GLuint textur);
void Menu::init() {
	backAlpha = 0.8;
	ATLLoadTexture("res\\menubg.bmp", tex[0]);
	ATLLoadTextureWithAlpha("res\\rightboy.bmp", tex[1]);
}
void Menu::DrawBG()
{
	glPushMatrix();
	texture(tex[0]);
	glColor4f(1.0, 1.0, 1.0, 1.0);
	glEnable(GL_BLEND);
	glEnable(GL_TEXTURE_2D);
	glTranslatef(0, 0, 0);
	glScalef(25, 25, 25);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
void Menu::DrawBack()
{
	glPushMatrix();
	texture(tex[1]);
	glColor4f(1.0, 1.0, 1.0, backAlpha);
	glEnable(GL_BLEND);
	glEnable(GL_TEXTURE_2D);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_ALPHA_TEST);
	glTranslatef(-33, -30, 0);
	glScalef(5, 5, 5);
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
//****************profile*******************************************************************************
void Profile::init()
{
	L1Alpha = 1.0;
	L2Alpha = 1.0;
	letterNum = 0;
	ATLLoadTextureWithAlpha("res\\01letter.bmp", tex[0]);
	ATLLoadTextureWithAlpha("res\\02letter.bmp", tex[1]);
}
void Profile::DrawLetter1()
{
	glPushMatrix();
	texture(tex[0]);
	glColor4f(1.0, 1.0, 1.0, L1Alpha);
	glEnable(GL_BLEND);
	glEnable(GL_TEXTURE_2D);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_ALPHA_TEST);
	glTranslatef(0, 0, 0);
	glScalef(22, 20, 20);
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
void Profile::DrawLetter2()
{
	glPushMatrix();
	texture(tex[1]);
	glColor4f(1.0, 1.0, 1.0, L2Alpha);
	glEnable(GL_BLEND);
	glEnable(GL_TEXTURE_2D);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_ALPHA_TEST);
	glTranslatef(0, 0, 0);
	glScalef(22, 20, 20);
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
