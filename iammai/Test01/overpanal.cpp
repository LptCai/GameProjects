#include"stdafx.h"
#include"overpanal.h"
#include<math.h>
extern void ATLLoadTexture(char *fileName, GLuint &texture);
extern void ATLLoadTextureWithAlpha(char *fileName, GLuint &texture);
extern void texture(GLuint textr);
void QUADS::Draw()
{
	glPushMatrix();
	texture(text);
	glColor4f(1.0, 1.0, 1.0, Alpha);
	glEnable(GL_BLEND);
	glEnable(GL_TEXTURE_2D);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_ALPHA_TEST);
	glTranslatef(X, Y, Z);
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
void Over::init()
{
	LoadPic();
	ps = ParticalSystem(50, -5.0);
	ps.init();
	for (int i = 0; i < 6; i++)
	{
		alpha[i] = 0.7;
	}
	float ax = -32;
	float ay = -35;
	float az = 0;
	for (int i = 0; i < 6; i++)
	{
		q[i].Set(ax + i * 13, ay, az, alpha[i], tMusic[i]);
	}
}
void Over::LoadPic()
{
	ATLLoadTextureWithAlpha("res\\overbg.bmp", tex[0]);
	ATLLoadTextureWithAlpha("res\\butterfly0.bmp", tex[1]);
	ATLLoadTextureWithAlpha("res\\butterflyw.bmp", tex[2]);

	/*¼ÓÔØÒô·ûÍ¼Æ¬*/
	ATLLoadTextureWithAlpha("res\\r0.bmp", tMusic[0]);
	ATLLoadTextureWithAlpha("res\\r1.bmp", tMusic[1]);
	ATLLoadTextureWithAlpha("res\\r2.bmp", tMusic[2]);
	ATLLoadTextureWithAlpha("res\\r3.bmp", tMusic[3]);
	ATLLoadTextureWithAlpha("res\\r4.bmp", tMusic[4]);
	ATLLoadTextureWithAlpha("res\\r5.bmp", tMusic[5]);
	
}
void Over::DrawBG()
{
	glPushMatrix();
	texture(tex[0]);
	glColor4f(1.0, 1.0, 1.0, 1.0);
	glEnable(GL_BLEND);
	glEnable(GL_TEXTURE_2D);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_ALPHA_TEST);
	glTranslatef(0, 0, 0);
	glScalef(22, 28, 20);
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
void Over::DrawPS()
{
	ps.simulate(0.05);
	glTranslatef(0, 0, 0);
	if (ps.isStop()) {
		ps.render();
	}
}
void Over::DrawPic()
{
	for (int i = 0; i < 6; i++)
	{
		q[i].Draw();
	}
}