#include"stdafx.h"
#include"Object.h"
#include"Gworld.h"
#include<stdlib.h>
#include<math.h>
#include"Data.h"
#pragma(lib,"glut32.lib");
#include"glut.h"

extern void ATLLoadTexture(char *fileName, GLuint &texture);
extern void ATLLoadTextureWithAlpha(char *fileName, GLuint &texture);
extern void texture(GLuint textr);
void Myworld::init()
{
	targetalpha = 0.6;
	isTarget = false;
	tunestep = 0;
	tune[0] = 13;
	LoadPic();//����ͼƬ
	storynum = 0;
	//���������ʼλ��
	RoleReal.Set(0, -10, 0, 2, texBoy[0],texBoy[1],texBoy[2],0);
	RoleReal.SetMoveV(true);
	box0.Set(0, -20, 0,3,texBox[0],texBox[1],texBox[2],0);
	box0.SetAlpha(0.9);

	Role1.Set(-10, 0, -40, 2, texBoy[3], texBoy[4], texBoy[5], 1);
	box1.Set(-10, -10, -40, 3, texBox[3], texBox[4], texBox[5], 1);

	Role2.Set(-20, 0, -30, 2, texBoy[3], texBoy[4], texBoy[5], 2);
	box2.Set(-20, -10, -30, 3, texBox[3], texBox[4], texBox[5], 2);
    
	Role3.Set(-30, 0, -20, 2, texBoy[3], texBoy[4], texBoy[5], 3);
	box3.Set(-30, -10, -20, 3, texBox[3], texBox[4], texBox[5], 3);
    
	Role4.Set( 10, 0, -40, 2, texBoy[3], texBoy[4], texBoy[5], 4);
	box4.Set(10, -10, -40, 3, texBox[3], texBox[4], texBox[5], 4);
    
	Role5.Set(20, 0, -30, 2, texBoy[3], texBoy[4], texBoy[5], 5);
	box5.Set(20, -10, -30, 3, texBox[3], texBox[4], texBox[5], 5);
    
	Role6.Set(30, 0, -20, 2, texBoy[3], texBoy[4], texBoy[5], 6);
	box6.Set(30, -10, -20, 3, texBox[3], texBox[4], texBox[5], 6);
    
	Role7.Set(20, 0, 30, 2, texBoy[3], texBoy[4], texBoy[5], 7);
	box7.Set(20, -10, 30, 3, texBox[3], texBox[4], texBox[5], 7);

	Role8.Set(10, 0, 40, 2, texBoy[3], texBoy[4], texBoy[5], 8);
	box8.Set(10, -10, 40, 3, texBox[3], texBox[4], texBox[5], 8);

	Role9.Set(30, 0, 20, 2, texBoy[3], texBoy[4], texBoy[5], 9);
	box9.Set(30, -10, 20, 3, texBox[3], texBox[4], texBox[5], 9);
   
	Role10.Set(-10, 0, 40, 2, texBoy[3], texBoy[4], texBoy[5], 10);
	box10.Set(-10, -10, 40, 3, texBox[3], texBox[4], texBox[5], 10);

	Role11.Set(-20, 0, 30, 2, texBoy[3], texBoy[4], texBoy[5], 11);
	box11.Set(-20, -10, 30, 3, texBox[3], texBox[4], texBox[5], 11);

	Role12.Set(-30, 0, 20, 2, texBoy[3], texBoy[4], texBoy[5], 12);
	box12.Set(-30, -10, 20, 3, texBox[3], texBox[4], texBox[5], 12);

	boys[0] = RoleReal;
	boys[1] = Role1;
	boys[2] = Role2;
	boys[3] = Role3;
	boys[4] = Role4;
	boys[5] = Role5;
	boys[6] = Role6;
	boys[7] = Role7;
	boys[8] = Role8;
	boys[9] = Role9;
	boys[10] = Role10;
	boys[11] = Role11;
	boys[12] = Role12;

	boxs[0] = box0;
	boxs[1] = box1;
	boxs[2] = box2;
	boxs[3] = box3;
	boxs[4] = box4;
	boxs[5] = box5;
	boxs[6] = box6;
	boxs[7] = box7;
	boxs[8] = box8;
	boxs[9] = box9;
	boxs[10] = box10;
	boxs[11] = box11;
	boxs[12] = box12;
}
void Myworld::LoadPic()
{
	 /*���Ƿ��鼰��ɫ��ͼ����*/
	ATLLoadTextureWithAlpha("res\\musicbox_be.bmp", texBox[0]);//������ͼ����
	ATLLoadTextureWithAlpha("res\\up.bmp",texBox[1]);//������ͼ����
	ATLLoadTextureWithAlpha("res\\boxbottom.bmp", texBox[2]);//������ͼ����

	ATLLoadTextureWithAlpha("res\\role0.bmp", texBoy[0]);//��ɫ��ͼ�°�
	ATLLoadTextureWithAlpha("res\\role0.bmp", texBoy[1]);//��ɫ��ͼ�°�
	ATLLoadTextureWithAlpha("res\\role0.bmp", texBoy[2]);//��ɫ��ͼ�°�

	/*�������鼰��ɫ��ͼ����*/
	ATLLoadTextureWithAlpha("res\\musicbox_be2.bmp", texBox[3]);//������ͼ����
	ATLLoadTextureWithAlpha("res\\up2.bmp", texBox[4]);//������ͼ����
	ATLLoadTextureWithAlpha("res\\boxbottom.bmp", texBox[5]);//������ͼ����
    
	ATLLoadTextureWithAlpha("res\\roles.bmp", texBoy[3]);//��ɫ��ͼ�°�
	ATLLoadTextureWithAlpha("res\\roles.bmp", texBoy[4]);//��ɫ��ͼ�°�
	ATLLoadTextureWithAlpha("res\\roles.bmp", texBoy[5]);//��ɫ��ͼ�°�

	/*����Ŀ���ͼƬ*/
	ATLLoadTextureWithAlpha("res\\target.bmp",target[0]);

	/*������ťͼƬ����*/
	ATLLoadTextureWithAlpha("res\\backtomenu.bmp", backtomenu);

	/*��������ͼƬ*/
	ATLLoadTextureWithAlpha("res\\boxbottom.bmp", story[0]);
	ATLLoadTextureWithAlpha("res\\s1.bmp", story[1]);
	ATLLoadTextureWithAlpha("res\\s2.bmp", story[2]);
	ATLLoadTextureWithAlpha("res\\s3.bmp", story[3]);
	ATLLoadTextureWithAlpha("res\\s4.bmp", story[4]);
	ATLLoadTextureWithAlpha("res\\s5.bmp", story[5]);
	ATLLoadTextureWithAlpha("res\\s6.bmp", story[6]);
	ATLLoadTextureWithAlpha("res\\s7.bmp", story[7]);
	ATLLoadTextureWithAlpha("res\\s8.bmp", story[8]);
	ATLLoadTextureWithAlpha("res\\s9.bmp", story[9]);
	ATLLoadTextureWithAlpha("res\\s10.bmp", story[10]);
	ATLLoadTextureWithAlpha("res\\boxbottom.bmp", story[11]);
	ATLLoadTextureWithAlpha("res\\boxbottom.bmp", story[2]);
}
/*draw roles*/
void Myworld::DrawRole()
{
	for (int i = 0; i < 13; i++)
	{
		boys[i].DrawBoy();
	}
}
/*draw musicbox*/
void Myworld::DrawMusicBox()
{
	for (int i = 0; i < 13; i++)
	{
		boxs[i].DrawBox();
	}
}
void Myworld::UpdateMusicBox()
{
	for (int i = 0; i < 13; i++)
	{
		boxs[i].isTouched(boys[i]);
	}
}
void Myworld::UpdateBoys()
{
	for (int i = 0; i < 13; i++)
	{
		boys[i].UpandDown();
	}
}
/*���½�ɫ�����ѡ���������ͬʱ���¹������ֺͼ�¼�������������*/
void Myworld::UpdateSelectBoy(LineSegment &l)
{
	for (int i = 0; i < 13; i++)
	{
		if (boys[i].isSelected(l))
		{
			storynum = i;
			if (isTarget == true)
			{
				if (boys[i].GetM())
				{
					tune[tunestep] = boys[i].GetN();
					if (tunestep < 5)
					{
						tunestep++;
					}
				}	
			}
		}
	}
}
void Myworld::DrawTarget()
{
	glPushMatrix();
	glColor4f(1.0, 1.0, 1.0, targetalpha);
	glEnable(GL_BLEND);
	glEnable(GL_TEXTURE_2D);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_ALPHA_TEST);
	glTranslatef(0,20, 0);
	glRotatef(0, 0, 0, 0);
	glScalef(1, 1, 1);

	texture(target[0]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glEnd();

	texture(target[0]);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	glEnd();

	texture(target[0]);
	glBegin(GL_QUADS);
	// Top Face
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	glEnd();

	texture(target[0]);
	glBegin(GL_QUADS);
	// Bottom Face
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glEnd();

	texture(target[0]);
	glBegin(GL_QUADS);
	// Right face
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glEnd();

	texture(target[0]);
	glBegin(GL_QUADS);
	// Left Face
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_ALPHA);
	glPopMatrix();
}
void Myworld::DrawOver()
{
	glPushMatrix();
	glColor4f(1.0, 1.0, 1.0, 0.9);
	glEnable(GL_BLEND);
	glEnable(GL_TEXTURE_2D);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_ALPHA_TEST);
	glTranslatef(0, 25, 0);
	glRotatef(0, 0, 0, 0);
	glScalef(1, 1, 1);

	texture(backtomenu);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glEnd();

	texture(backtomenu);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	glEnd();

	texture(backtomenu);
	glBegin(GL_QUADS);
	// Top Face
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	glEnd();

	texture(backtomenu);
	glBegin(GL_QUADS);
	// Bottom Face
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glEnd();

	texture(backtomenu);
	glBegin(GL_QUADS);
	// Right face
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glEnd();

	texture(backtomenu);
	glBegin(GL_QUADS);
	// Left Face
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_ALPHA);
	glPopMatrix();
}
void Myworld::isTargetSelect(LineSegment &l)
{
	float xNow = (l.Far.x - l.Near.x)*(0 - l.Near.z) / (l.Far.z - l.Near.z) + l.Near.x;
	float yNow = (l.Far.y - l.Near.y)*(0 - l.Near.z) / (l.Far.z - l.Near.z) + l.Near.y;

	/*z�̶�*/
	if (xNow >= 0 - 1.5 && xNow <= 1.5 && yNow >= 20 - 1.5 && yNow <= 20 + 1.5)
	{
		if (isTarget==false)
		{
			targetalpha = 1.0;
			isTarget = true;
		}
		else if (isTarget == true)
		{
			isTarget = false;
			targetalpha = 0.6;
			tunestep = 0;
			for (int i = 0; i < 6; i++)
			{
				tune[i] = 13;
			}
		}
	}	
}
bool Myworld::isGameOver(LineSegment &l)
{
	float xNow = (l.Far.x - l.Near.x)*(0 - l.Near.z) / (l.Far.z - l.Near.z) + l.Near.x;
	float yNow = (l.Far.y - l.Near.y)*(0 - l.Near.z) / (l.Far.z - l.Near.z) + l.Near.y;

	/*z�̶�*/
	if (xNow >= 0 - 1.5 && xNow <= 1.5 && yNow >= 25 - 1.5 && yNow <= 25 + 1.5)
	{
		return true;
	}
	return false;
}
void Myworld::DrawStory()
{
	glPushMatrix();
	texture(story[storynum]);
	glColor4f(1.0, 1.0, 1.0, 1.0);
	glEnable(GL_BLEND);
	glEnable(GL_TEXTURE_2D);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_ALPHA_TEST);
	glTranslatef(0, 10, 0);
	glScalef(10, 10, 10);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);

	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);

	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);

	// Left Face
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glEnd();

	glDisable(GL_TEXTURE_2D);
	glDisable(GL_ALPHA);
	glPopMatrix();
}
//�ǿ�
void Myworld::CreateStars()
{
	srand(time(NULL));
	for (int i = 0; i < STARNUM; i++) {
		float nx = rand() % 10 * 0.1;
		float ny = rand() % 10 * 0.1;
		float nz = rand() % 10 * 0.1;
		switch (i%8)
		{
		case 0:
			break;
		case 1:
			nx = -nx;
			break;
		case 2:
			ny = -ny;
			break;
		case 3:
			nz = -nz;
			break;
		case 4:
			nx = -nx;
			ny = -ny;
			break;
		case 5:
			nx = -nx;
			nz = -nz;
			break;
		case 6:
			nx = -nx;
			ny = -ny;
			nz = -nz;
			break;
		case 7:
			ny = -ny;
			nz = -nz;
		default:
			break;
		}
		float r = sqrtf(nx*nx + ny*ny + nz*nz);
		float R = rand() % (WORLDRADIUSOUT - WORLDRADIUSIN) + WORLDRADIUSIN;
		float a = nx / r*R;
		float b = ny / r*R;
		float c = nz / r*R;
		Star s(a, b, c);
		Stars[i] = s;
	}
	
}
void Myworld::DrawS()
{
	srand(time(NULL));
	
	for (int i = 0; i < STARNUM; i++)
	{
		float Alpha = rand() % 10 * 0.1;
		Stars[i].DrawStar(Alpha);
	}
}
