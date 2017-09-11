#ifndef GWORLD_H
#define GWORLD_H
#include<gl/gl.h>
#include<gl/GLU.h>
#include"3DS.h"
#include"Data.h"


//世界1
class Myworld
{
public:
	Myworld() {
	}
	~Myworld() {
	}

private:
public:
	bool isTarget;                                                  //是否点亮按钮，记录音符
	float targetalpha;                                              //目标按钮的透明值
	int tune[12];                                                   //存音符的数组
	int tunestep;                                                   //记录音符数组的当前下标
	int storynum;                                                   //故事文字贴图的对应序号
	GLuint texBox[11];                                              //柱子贴图
	GLuint texBoy[6];                                               //角色贴图
	GLuint target[1];                                               //记录按钮贴图
	GLuint story[13];                                               //故事文字贴图
	GLuint backtomenu;                                              //结束按钮贴图
	Boy boys[13];
	MusicBox boxs[6];
	//创建角色
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

	//星空粒子
	Star Stars[STARNUM];
	void CreateStars();
	void DrawS();                                                      //绘制星空

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