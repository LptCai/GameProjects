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
	/* ���캯������������ */
	Camera()
	{
		TurnAngle = 0.005;
		StaggerAngle = 0.02;
		isThree = FALSE;
		isRotate = false;
	}
	~Camera();
	//�����Ƿ�����˳�
	BOOL isThree;
	void Turn(float turnAngle);                                     //��һ�˳�������ת                        
	void Stagger(float staggerAngle);                               //��һ�˳Ƹ���
	void rollC(float dx, float dy);                                 //��һ�˳���������ת������
	void UpdateView();                                              //�������������
	void setCamera(float eyeX, float eyeY, float eyeZ,
		float lookX, float lookY, float lookZ,
		float upX, float upY, float upZ);
	void Turn3(float turnAngle,Vector3 person);
	void Stagger3(float staggerAngle,Vector3 person);
	void roll3(float dx,float dy,Vector3 person);
	void SetRotate(bool isR) { isRotate = isR; }
	bool GetRotate() { return isRotate; }
private:
	/* ��������� */
	Point3         eye, center, up;
	Vector3        u, v, n;
	float          viewAngle, aspect, nearDist, farDist;
	float          TurnAngle;
	float          StaggerAngle;
	bool           isRotate;//��������Ƿ���ƶ�

};
