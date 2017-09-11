#include"stdafx.h"
#include<gl/gl.h>
#include<gl/GLU.h>
#include"Object.h"
#include<mmsystem.h> 
#include<math.h>
#include"glut.h"
#include"bitmap.h"
#pragma(lib,"glut32.lib");
#pragma   comment(lib,   "winmm.lib")  
wchar_t* playmusic[13] = { _T("play song0"),_T("play song1"),_T("play song2"),_T("play song3"),
_T("play song4"),_T("play song5"),_T("play song6"),_T("play song7"),_T("play song8"),
_T("play song9"),_T("play song10"),_T("play song11"),_T("play song12") };

wchar_t* closemusic[13] = { _T("close song0"),_T("close song1"),_T("close song2"),_T("close song3"),
_T("close song4"),_T("close song5"),_T("close song6"),_T("close song7"),_T("close song8"),
_T("close song9"),_T("close song10"),_T("close song11"),_T("close song12") };

wchar_t*music[13] = { _T("open res\\88-C小字5组.wav alias song0"),
_T("open res\\68-E-小字3组.wav alias song1"),
_T("open res\\69-F-小字3组.wav alias song2"),
_T("open res\\70-F#-小字3组.wav alias song3"),
_T("open res\\71-G-小字3组.wav alias song4"),
_T("open res\\72-G#-小字3组.wav alias song5"),
_T("open res\\73-A-小字3组.wav alias song6"),
_T("open res\\74-A#-小字3组.wav alias song7"),
_T("open res\\75-B-小字3组.wav alias song8"),
_T("open res\\76-C-小字4组.wav alias song9"),
_T("open res\\65-C#-小字3组.wav alias song10"),
_T("open res\\66-D-小字3组.wav alias song11"),
_T("open res\\67-D#-小字3组.wav alias song12") };

//*********************************************纹理加载***************************************
//加载带透明通道的BMP图片
void ATLLoadTextureWithAlpha(char *fileName, GLuint &texture)
{
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	BITMAPINFOHEADER bitHeader;
	unsigned char *buffer;
	buffer = LoadBitmapFileWithAlpha(fileName, &bitHeader);
	gluBuild2DMipmaps(GL_TEXTURE_2D,
		4,
		bitHeader.biWidth,
		bitHeader.biHeight,
		GL_RGBA,
		GL_UNSIGNED_BYTE,
		buffer
	);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
	free(buffer);
}
//加载不带透明通道的BMP图片
void ATLLoadTexture(char *fileName, GLuint &texture)
{
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	BITMAPINFOHEADER bitHeader;
	unsigned char *buffer;
	buffer = LoadBitmapFile(fileName, &bitHeader);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, bitHeader.biWidth, bitHeader.biHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, buffer);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	free(buffer);
}
//选择纹理，指定应用方式
void texture(GLuint textur)
{
	glBindTexture(GL_TEXTURE_2D, textur);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}
//检测两个正方体是否相撞
bool Box_to_Box(MusicBox &m,Boy &b)
{
	if ((m.GetY() + m.GetSize()) >= (b.GetY()))
	{
		return true;
	}
	return false;
}

//************************************角色物体**********************************************
void Boy::Set(float x, float y, float z, float radius, GLuint t0,GLuint t1,GLuint t2, int ty)
{
	X = x;
	Y = y;
	Z = z;
	size = radius;
	tex[0] = t0;
	tex[1] = t1;
	tex[2] = t2;
	type = ty;
	OriginalY = Y;
	speedY = 0.5;
	dir = 'u';
}
void Boy::DrawBoy()
{
	glPushMatrix();
	glColor4f(1.0, 1.0, 1.0, 1.0);
	glEnable(GL_BLEND);
	glEnable(GL_TEXTURE_2D);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_ALPHA_TEST);
	glTranslatef(Boy::X, Boy::Y,Boy::Z);
	glRotatef(0, 0, 0, 0);
	glScalef(size, size, size);

	texture(Boy::tex[0]);
	glBegin(GL_QUADS);	
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glEnd();

	texture(Boy::tex[0]);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	glEnd();

	texture(Boy::tex[1]);
	glBegin(GL_QUADS);
	// Top Face
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	glEnd();

	texture(Boy::tex[2]);
	glBegin(GL_QUADS);
	// Bottom Face
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glEnd();

	texture(Boy::tex[0]);
	glBegin(GL_QUADS);
	// Right face
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glEnd();

	texture(Boy::tex[0]);
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
void Boy::UpandDown()
{
	if (moveVertical) {
		speedY -= GRAVITY;
		if (Y <= OriginalY - 2)
		{
			speedY = 0.5;
		}
		Y += speedY;
	}	
}

bool Boy::isSelected(LineSegment &l)
{
	/*判断方块角色是否被鼠标选中，坐标不对？？？求出垂足，判断垂足与中心点的距离是否在立体范围内*/
	/*float dx = l.Near.x - l.Far.x;
	float dy = l.Near.y = l.Far.y;
	float dz = l.Near.y - l.Far.z;
	float length = sqrtf(dx*dx+dy*dy+dz*dz);
	Point3 L0(dx/length, dy/length, dz/length);//直线的方向向量
	Point3 LP(X - l.Near.x, Y - l.Near.y, Z - l.Near.z);//过直线上一点与直线外一点的向量
	float crossX=L0.y*LP.z-LP.y*L0.z;
	float crossY=L0.z*LP.x-LP.z*L0.x;
	float crossZ=L0.x*LP.y-LP.x*L0.y;
	float K = (l.Far.x - X)*dx*+(l.Far.y - Y)*dy + (l.Far.z - Z)*dz / (dx*dx + dy*dy + dz*dz);
	float CX = K*dx + l.Far.x;
	float CY = K*dy + l.Far.y;
	float CZ = K*dz + l.Far.z;
	if ((fabs(CX - X) <= size) && (fabs(CY - Y) <= size) && (fabs(CZ - Z) <= size))
	{
		return true;
		moveVertical = true;
		speedY = 0.5;
	}*/
	float xNow = (l.Far.x - l.Near.x)*(Z - l.Near.z) / (l.Far.z - l.Near.z) + l.Near.x;
	float yNow = (l.Far.y - l.Near.y)*(Z - l.Near.z) / (l.Far.z - l.Near.z) + l.Near.y;
	
	/*z固定*/
	if (xNow >= X - size*1.5 && xNow <= X + size*1.5 && yNow >= Y - size*1.5 && yNow <= Y + size*1.5)
	{		
		if (moveVertical == false)
		{
			moveVertical = true;
			speedY = 0.5;
		}
		else if (moveVertical == true)
		{
			moveVertical = false;
			speedY = 0.0;
			Y = OriginalY;
		}

		return true;
	}
	return false;
}

//************************************方块物体**********************************************
void MusicBox::Set(float x, float y, float z, float s, GLuint t0, GLuint t1, GLuint t2, int n)
{
	L_ux = x;
	L_uy = y;
	L_uz = z;
	size = s;
	tex[0] = t0;
	tex[1] = t1;
	tex[2] = t2;
	num = n;
	alpha = 0.9;
	isOpen = false;
	
}
void MusicBox::DrawBox()
{
	glPushMatrix();
	glColor4f(1.0, 1.0, 1.0, alpha);
	glEnable(GL_BLEND);
	glEnable(GL_TEXTURE_2D);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_ALPHA_TEST);
	glTranslatef(MusicBox::L_ux, MusicBox::L_uy, MusicBox::L_uz);
	glRotatef(0, 0, 0, 0);
	glScalef(size, size*2, size);
	texture(tex[0]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glEnd();

	texture(tex[0]);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	glEnd();

	texture(tex[1]);
	glBegin(GL_QUADS);
	// Top Face
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	glEnd();

	texture(tex[2]);
	glBegin(GL_QUADS);
	// Bottom Face
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glEnd();

	texture(tex[0]);
	glBegin(GL_QUADS);
	// Right face
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glEnd();

	texture(tex[0]);
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
void MusicBox::isTouched(Boy &b)
{
	if (b.GetY()<=b.GetOY()-2)
	{
		alpha = 1.0;
		mciSendString(music[num], NULL, 0, NULL);
		mciSendString(playmusic[num], NULL, 0, NULL);
		Sleep(100);
		mciSendString(closemusic[num], NULL, 0, NULL);
	}
	else
	{
		alpha = 0.7;		
		
	}
}


//**********************************星空物体***********************************************
void Star::DrawStar(float Alpha)
{
	glPushMatrix();
	glColor4f(1.0, 1.0, 1.0,Alpha);
	glTranslatef(x, y, z);
	glutSolidSphere(0.3, 5, 10);
	glPopMatrix();
}

