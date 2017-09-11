#pragma once
#include"gl\gl.h"
#include"gl\glu.h"
class Menu
{
public:
	Menu(){}
	~Menu(){}
	GLuint tex[2];
	float backAlpha;
	void init();
	void DrawBG();
	void DrawBack();
};
class Profile
{
public:
	Profile(){}
	~Profile(){}
	int letterNum;
	GLuint tex[3];
	float L1Alpha;
	float L2Alpha;
	void init();
	void DrawLetter1();
	void DrawLetter2();
};