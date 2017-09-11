#pragma once
#include"stdafx.h"
#include"Data.h"
#include"gl/gl.h"
#include"gl/glu.h"


class Start 
{
public:
	float btnalpha;
	float LArrowAlpha;
	float RArrowAlpha;
	Point3 Butterfly;
	GLuint tex[12];
	char *file[8];
	void init();
	void LoadPic();
	void DrawTitle();
	void DrawStartbtn();
	void DrawButterfly(int t);
	void DrawLArrow();
	void DrawRArrow();
	void DrawFlyCo();
	void DrawCopyright();
	void Update();
public:
	Start() ;
	~Start() {};
	
	
};
