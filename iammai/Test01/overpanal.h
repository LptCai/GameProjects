#pragma once
#include"gl\gl.h"
#include"gl\glu.h"
#include"Particle.h"

class QUADS
{
public:
	QUADS(float x=0,float y=0,float z=0,float a=1,GLuint t=0) {
		X = x;
		Y = y;
		Z = z;
		Alpha = a;
		text = t;
	};
	~QUADS() {};
	void Draw();
	void Set(float x, float y, float z, float a, GLuint t){
		X = x;
		Y = y;
		Z = z;
		Alpha = a;
		text = t;
	}
private:
	float X;
	float Y;
	float Z;
	float Alpha;
	GLuint text;
};
class Over
{
public:
	Over(){}
	~Over(){}
	QUADS q[6];
	GLuint tex[3];
	GLuint tMusic[6];
	float alpha[6];
	ParticalSystem ps;
	void init();
	void LoadPic();
	void DrawBG();
	void DrawPS();
	void DrawPic();
};
