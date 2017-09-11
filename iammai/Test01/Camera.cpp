
#include"stdafx.h"
#include"Camera.h"
#include"gl/gl.h"
#include"gl/glu.h"
#include<math.h>
/* 构造函数 */

Camera::~Camera() {}

/* 设置摄像机的位置,朝向和向上向量 */
void Camera::setCamera(float eyeX, float eyeY, float eyeZ,
	float lookX, float lookY, float lookZ,
	float upX, float upY, float upZ)
{
	/* 构造向量 */
	eye.set(eyeX, eyeY, eyeZ);
	center.set(lookX, lookY, lookZ);
	up.set(upX, upY, upZ);
	Vector3 upvec(up.x - eye.x, up.y - eye.y, up.z - eye.z);
}
//第一人称左右旋转
void Camera::Turn(float turnAngle)
{
	Vector3 diff(center.x - eye.x,0,center.z - eye.z);
	float cs = cos(turnAngle);
	float sn = sin(turnAngle);
	Vector3 centerDiff(diff.x * cs - diff.z * sn,0,diff.x * sn + diff.z * cs);
	center.x = eye.x + centerDiff.x;
	center.z = eye.z + centerDiff.z;
}
//第一人称前俯后仰
void Camera::Stagger(float staggerAngle)
{
	float ceX = center.x - eye.x;
	float ceZ = center.z- eye.z;
	float distanceCE =sqrtf(ceX * ceX + ceZ * ceZ);
	Vector3 diff = Vector3(distanceCE, center.y - eye.y, 0);
	float cs = cos(staggerAngle);
	float sn = sin(staggerAngle);
	Vector3 centerDiff(diff.x * cs - diff.y * sn,
		diff.x * sn + diff.y * cs,
		0);
	center.y = eye.y + centerDiff.y;
	float percent = centerDiff.x / distanceCE;
	center.x = eye.x + percent * ceX;
	center.z = eye.z + percent * ceZ;
}
//摄像机随鼠标360度球面旋转
void Camera::rollC(float dx, float dy)
{
	float turnAngle = dx*TurnAngle;
	float staggerAngle = dy * StaggerAngle;
	Turn(turnAngle);
    Stagger(-staggerAngle);
}
//更新摄像机位置
void Camera::UpdateView()
{
	gluLookAt(eye.x, eye.y, eye.z,
		center.x, center.y, center.z,
		up.x, up.y, up.z);
}
//第三人称左右转动
void Camera::Turn3(float turnAngle,Vector3 person)
{
	Vector3 diff(eye.x - person.x, 0, eye.z - person.z);
	Vector3 diffl(person.z - eye.z, 0, eye.x - person.x);
	Vector3 CDiff(center.x - person.x, 0, center.z - person.z);
	Vector3 CDiffl(person.z - center.z, 0, center.x - person.x);
	float cs = cos(turnAngle);
	float sn = sin(turnAngle);
	Vector3 eyeDiff(diff.x * cs+diffl.x*sn, 0, diff.z * cs+diffl.z*sn);
    Vector3 centerDiff(CDiff.x*cs + CDiffl.x*sn, 0, CDiff.z*cs + CDiffl.z*sn);
	eye.x = person.x + eyeDiff.x;
	eye.z = person.z + eyeDiff.z;
	center.x = person.x + centerDiff.x;
	center.z = person.z + centerDiff.z;	
}
//第三人称俯仰角。以物体为球心计算，有BUG
void Camera::Stagger3(float staggerAngle,Vector3 person)
{
	float cpX = center.x - person.x;
	float cpZ = center.z - person.z;
	float epX = eye.x - person.x;
	float epZ = eye.z - person.z;
	float distanceCP = sqrtf(cpX*cpX + cpZ*cpZ);
	float distanceEP = sqrtf(epX*epX + epZ*epZ);
	Vector3 diffE(distanceEP, eye.y - person.y, 0);
	Vector3 diffEV(person.y - eye.y, distanceEP, 0);
	Vector3 diffC(distanceCP, center.y - person.y, 0);
	Vector3 diffCV(person.y - center.y, distanceCP, 0);
	float cs = cos(staggerAngle);
	float sn = sin(staggerAngle);
	Vector3 centerDiff(diffC.x*cs + diffCV.x*sn, diffC.y*cs + diffCV.y*sn, 0);
	Vector3 eyeDiff(diffE.x*cs + diffEV.x*sn, diffE.y*cs + diffEV.y*sn, 0);
	center.y = person.y + centerDiff.y;
	eye.y = person.y + eyeDiff.y;
	float percent = centerDiff.x / distanceCP;
	center.x = person.x + percent * cpX;
	center.z = person.z + percent * cpZ;
	float persent1 = eyeDiff.x / distanceEP;
	eye.x = person.x + persent1*epX;
	eye.z = person.z + persent1*epZ;
	
}
void Camera::roll3(float dx, float dy,Vector3 person)
{
	float turnAngle = dx*TurnAngle;
	float staggerAngle = dy * StaggerAngle;
	Turn3(turnAngle, person);//第三人称左右180度全景旋转
	//Stagger3(staggerAngle,person);//前俯后仰
}