#ifndef GWORLD_H
#define GWORLD_H
#include<gl/gl.h>
#include<gl/GLU.h>
#include"3DS.h"
#include"Data.h"


//����1
class Myworld
{
public:
	Myworld() {
	}
	~Myworld() {
	}

private:
public:
	bool isTarget;                                                  //�Ƿ������ť����¼����
	float targetalpha;                                              //Ŀ�갴ť��͸��ֵ
	int tune[12];                                                   //������������
	int tunestep;                                                   //��¼��������ĵ�ǰ�±�
	int storynum;                                                   //����������ͼ�Ķ�Ӧ���
	GLuint texBox[11];                                              //������ͼ
	GLuint texBoy[6];                                               //��ɫ��ͼ
	GLuint target[1];                                               //��¼��ť��ͼ
	GLuint story[13];                                               //����������ͼ
	GLuint backtomenu;                                              //������ť��ͼ
	Boy boys[13];
	MusicBox boxs[6];
	//������ɫ
	Boy RoleReal;
	Boy Role1;
	Boy Role2;
	Boy Role3;
	Boy Role4;
	Boy Role5;
	Boy Role6;
	Boy Role7;
	Boy Role8;
	Boy Role9;
	Boy Role10;
	Boy Role11;
	Boy Role12;

	MusicBox box0;
	MusicBox box1;
	MusicBox box2;
	MusicBox box3;
	MusicBox box4;
	MusicBox box5;
	MusicBox box6;
	MusicBox box7;
	MusicBox box8;
	MusicBox box9;
	MusicBox box10;
	MusicBox box11;
	MusicBox box12;

	//�ǿ�����
	Star Stars[STARNUM];
	void CreateStars();
	void DrawS();                                                      //�����ǿ�

	void init();
	void LoadPic();
	void DrawRole();
	void DrawMusicBox();
	void UpdateMusicBox();
	void UpdateBoys();
	void DrawTarget();
	void DrawOver();
	bool isGameOver(LineSegment &l);
	void isTargetSelect(LineSegment &l);
	void UpdateSelectBoy(LineSegment &l);
	void DrawStory();
};



#endif