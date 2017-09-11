#pragma once
#define HALFMAP 20
#define BOXEDGE 2
#define WORLDRADIUSIN 80
#define WORLDRADIUSOUT 90
#define roleX  0
#define roleY  1
#define roleZ  0
#define STARNUM 200
#define GRAVITY 0.05
enum GAMESTATE{PROFILE,STARTPANAL,GAMEON,GAMEOVER,MENU,ABOUT};              //ÓÎÏ·×´Ì¬

class Point3
{
public:
	float x, y, z;
	void set(float dx = 0, float dy = 0, float dz = 0)
	{
		x = dx; y = dy; z = dz;
	}
	void set(Point3& p)
	{
		x = p.x; y = p.y; z = p.z;
	}
	Point3(float xx, float yy, float zz)
	{
		x = xx; y = yy; z = zz;
	}
	Point3()
	{
		x = y = z = 0;
	}
	void build4tuple(float v[])
	{
		v[0] = x; v[1] = y; v[2] = z; v[3] = 1.0f;
	}
	Point3 operator* (float a)
	{
		float ax = x*a;
		float ay = y*a;
		float az = z*a;
		return Point3(ax,ay,az);
	}
	Point3 operator+ (Point3& b)
	{
		float ax = x + b.x;
		float ay = y + b.y;
		float az = z + b.z;
		return Point3(ax, ay, az);
	}
};
class LineSegment
{
public:
	Point3  Near;
	Point3 Far;
	LineSegment(Point3 &n, Point3 &f){
		Near = n;
		Far = f;
	}
	~LineSegment() {};

};