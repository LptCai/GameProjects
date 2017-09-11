#pragma once
#include<math.h>
#include"Data.h"

class Vector3
{
public:
	float x, y, z;
	void set(float dx, float dy, float dz)
	{
		x = dx; y = dy; z = dz;
	}
	void set(Vector3& v)
	{
		x = v.x; y = v.y; z = v.z;
	}
	void flip()
	{
		x = -x; y = -y; z = -z;
	}
	void setDiff(Point3& a, Point3& b)
	{
		x = a.x - b.x; y = a.y - b.y; z = a.z - b.z;
	}
	void normalize()
	{
		float base = pow(x, 2) + pow(y, 2) + pow(z, 2);
		x = x / pow(base, 0.5f);
		y = y / pow(base, 0.5f);
		z = z / pow(base, 0.5f);
	}
	Vector3(float xx, float yy, float zz)
	{
		x = xx; y = yy; z = zz;
	}
	Vector3(Vector3 &v)
	{
		x = v.x; y = v.y; z = v.z;
	}
	Vector3()
	{
		x = 0; y = 0; z = 0;
	}

	Vector3 cross(Vector3 b)
	{
		float x1, y1, z1;
		x1 = y*b.z - z*b.y;
		y1 = z*b.x - x*b.z;
		z1 = x*b.y - y*b.x;
		Vector3 c(x1, y1, z1);
		return c;
	}

	float dot(Vector3 b)
	{
		float d = x*b.x + y*b.y + z*b.z;
		return d;
	}
};

class Camera
{
public:
	/* 构造函数和析构函数 */
	Camera()
	{
		TurnAngle = 0.005;
		StaggerAngle = 0.02;
		isThree = FALSE;
		isRotate = false;
	}
	~Camera();
	//设置是否第三人称
	BOOL isThree;
	void Turn(float turnAngle);                                     //第一人称左右旋转                        
	void Stagger(float staggerAngle);                               //第一人称俯仰
	void rollC(float dx, float dy);                                 //第一人称相机随鼠标转动函数
	void UpdateView();                                              //更新摄像机参数
	void setCamera(float eyeX, float eyeY, float eyeZ,
		float lookX, float lookY, float lookZ,
		float upX, float upY, float upZ);
	void Turn3(float turnAngle,Vector3 person);
	void Stagger3(float staggerAngle,Vector3 person);
	void roll3(float dx,float dy,Vector3 person);
	void SetRotate(bool isR) { isRotate = isR; }
	bool GetRotate() { return isRotate; }
private:
	/* 摄像机属性 */
	Point3         eye, center, up;
	Vector3        u, v, n;
	float          viewAngle, aspect, nearDist, farDist;
	float          TurnAngle;
	float          StaggerAngle;
	bool           isRotate;//设置相机是否可移动

};
