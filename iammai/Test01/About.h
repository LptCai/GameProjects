#pragma once
#include"gl\gl.h"
#include"gl\glu.h"
class About
{
public:
	About(){}
	~About(){}
	float backAlpha;                              //���ذ�ť��͸����
	GLuint tex[2];                                //ͼƬ����
	void init();                                  //��ʼ��
	void DrawBG();                                //������
	void DrawBack();                              //�����������水ť
};