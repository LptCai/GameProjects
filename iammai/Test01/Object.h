
#ifndef  OBJECT_H
#define  OBJECT_H
#define gravity 10

#include"Data.h"
#include"gl\gl.h"
#include"gl\glu.h"

class Star
{

private:
	float x;
	float y;
	float z;
public:
	Star(float sx=0, float sy=0, float sz=0)
	{
		x = sx;
		y = sy;
		z = sz;
	}
	~Star(){}
public:
	void DrawStar(float Alpha);
	void SetPosition(float sx, float sy, float sz) { x = sx; y = sy; z = sz; }
};
class Boy
{
	//数据
private:
	float X;
	float Y;
	float Z;
	float OriginalY;
	float size;
	float speedX;
	float speedY;
	float speedZ;
	GLuint tex[3];
	int type;
	char dir;
	bool moveVertical;

	//操作
public:
	float GetX() { return X; }//获取参数
	float GetY() { return Y; }
	float GetZ() { return Z; }
	float GetS() { return size; }
	float GetOY() { return OriginalY; }
	float GetN() { return type; }
	bool GetM() { return moveVertical; }
	void SetX(float x) { X = x; }
	void SetY(float y) { Y = y; }
	void SetZ(float z) { Z = z; }
	void SetMoveV(bool m) { moveVertical = m; }
	void DrawBoy();
	void Set(float x, float y, float z, float radius, GLuint t0, GLuint t1, GLuint t2, int ty);
	//运动
	void UpandDown();
	bool isSelected(LineSegment &l);
public:
	//构造析构函数
	Boy(float x=0, float y=0, float z=0, float radius=1, int ty=0)
	{
		X = x;
		Y = y;
		Z = z;
		size = radius;
		type = ty;
		OriginalY = Y;
		dir = 'd';
		moveVertical = false;
	}
	~Boy() {};
};
class MusicBox
{
//数据
private:
	  float L_ux;
	  float L_uy;
	  float L_uz;
	  float size;
	  int num;
	  GLuint tex[3];
	  wchar_t *rhymn;
	  float alpha;
	  bool isOpen;
	//操作
public:
		float GetX() { return L_ux; }	
		float GetY() { return L_uy; }
	    float GetZ() { return L_uz; }
	    float GetSize() { return size; }
		void SetAlpha(float a) { alpha = a; }
	    void DrawBox();
		void isTouched(Boy &b);                   
		void Set(float x, float y, float z, float s, GLuint t0,GLuint t2,GLuint t3, int n);

	//构造析构函数
	 MusicBox(float x=0,float y=0, float z=0, float s=1, GLuint t0=0, GLuint t1=0, GLuint t2=0,int n=0)
	{
		L_ux = x;
		L_uy = y;
		L_uz = z;
		size = s;
		tex[0] = t0;
		tex[1] = t1;
		tex[2] = t2;
		num = n;
		alpha = 0.75;
	}
	~MusicBox() {};
};

#endif