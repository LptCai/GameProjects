#pragma once
#include"gl\gl.h"
#include"gl\glu.h"
class About
{
public:
	About(){}
	~About(){}
	float backAlpha;                              //返回按钮的透明度
	GLuint tex[2];                                //图片数组
	void init();                                  //初始化
	void DrawBG();                                //画背景
	void DrawBack();                              //画返回主界面按钮
};