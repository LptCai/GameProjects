#include"stdafx.h"
#include"About.h"
extern void ATLLoadTextureWithAlpha(char *fileName, GLuint &texture);
extern void ATLLoadTexture(char*fileName, GLuint &texture);
extern void texture(GLuint textur);
void About::init() {
	backAlpha = 0.85;
	ATLLoadTexture("res\\aboutbg.bmp", tex[0]);
	ATLLoadTextureWithAlpha("res\\leftboy.bmp", tex[1]);
}
void About::DrawBG()
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
void About::DrawBack()
{
	glPushMatrix();
	texture(tex[1]);
	glColor4f(1.0, 1.0, 1.0, backAlpha);
	glEnable(GL_BLEND);
	glEnable(GL_TEXTURE_2D);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_ALPHA_TEST);
	glTranslatef(33, -30, 0);
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