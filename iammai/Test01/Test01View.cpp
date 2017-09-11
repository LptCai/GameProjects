
// Test01View.cpp : CTest01View 类的实现
//

#include "stdafx.h"
#include "OpenGLView.h"
#include<math.h>

// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Test01.h"
#endif
#include "Test01Doc.h"
#include "Test01View.h"
#include<stdlib.h>
#include"bitmap.h"
#include"Data.h"
#include"glut.h"
#pragma(lib,"glut32.lib")
#include   <mmsystem.h>  
#pragma   comment(lib,   "winmm.lib")  
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
// CTest01View

IMPLEMENT_DYNCREATE(CTest01View, COpenGLView)

BEGIN_MESSAGE_MAP(CTest01View, COpenGLView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTest01View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_ERASEBKGND()

//	ON_WM_KEYDOWN()
	ON_WM_TIMER()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()
extern wchar_t* playmusic[13];
extern wchar_t* closemusic[13];
extern wchar_t*music[13];
//设置光
float LightX = 0;
float LightY = -60;
float LightZ = 5;

float ambientLight[] = { 1.0f,1.0f,1.0f,1.0f };  //环境光
float diffuseLight[] = { 0.25f,0.25f,0.25f,1.0f }; //散射光
float specularLight[] = { 1.0f,1.0f,1.0f,1.0f };//高光反射效果
float lightPosition[] = { LightX,LightY,LightZ,0.0f }; //光源位置

float matAmbient[] = { 1.0f,1.0f,1.0f,1.0f };
float matDiff[] = { 1.0f,1.0f,1.0f,1.0f };
float matSpec[] = { 1.0f,1.0f,1.0f,1.0f };
float matshine[] = { 50.0 };

CPoint lastPos;
LineSegment GetSelectionRay(LONG mouse_x, LONG mouse_y);//声明函数
bool isCross(LineSegment &l, float x, float y, float z,float size);//声明函数
int T0 = 0;//开始界面的时间计数器
int TP = 0;//序章界面的时间计数器
int TO = 0;//结束界面的时间计数器
CTest01View::CTest01View()
{


}

CTest01View::~CTest01View()
{
}

BOOL CTest01View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CTest01View 绘制

void CTest01View::OnDraw(CDC* /*pDC*/)
{
	CTest01Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	Display();
	// TODO: 在此处为本机数据添加绘制代码
}

void CTest01View::Display()
{
	CRect rc;
	GetClientRect(&rc);
	int Width = rc.Width();
	int Height = rc.Height();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // 清除窗口
	glLoadIdentity();	
	switch (gamestatus)
	{
	case PROFILE:
		C0.UpdateView();
		world.DrawS();
		if (profile.letterNum == 0)
		{
			profile.DrawLetter1();
		}
		if (profile.letterNum == 1)
		{
			profile.DrawLetter2();
		}
		break;
	case STARTPANAL:	
	{
	C0.UpdateView();
	//绘制星空
	world.DrawS();
	start.DrawFlyCo();
	start.DrawTitle();
	start.DrawStartbtn();
	start.DrawButterfly(T0);
	start.DrawLArrow();
	start.DrawRArrow();
	start.DrawCopyright();
	break;
	}
	case GAMEON:
		//绘制游戏场景图
		glEnable(GL_DEPTH_TEST);     //剔除隐藏面
		glEnable(GL_CULL_FACE);      //不计算多边形背面
		glFrontFace(GL_CCW);      //多边形逆时针方向为正面
		C.UpdateView();
		world.DrawS();
		world.DrawRole();
		world.DrawMusicBox();
		world.DrawTarget();
		world.DrawOver();
		world.DrawStory();
		break;
	case ABOUT:
		C0.UpdateView();
		about.DrawBG();
		about.DrawBack();
		break;
	case GAMEOVER:
		C0.UpdateView();
		world.DrawS();
		//if (TO > 3)
		//{
			over.DrawBG();
			over.DrawPic();
		//}
		//if (TO < 3) {
			//over.DrawPS();
		//}		
		break;
	case MENU:
		C0.UpdateView();
		menu.DrawBG();
		menu.DrawBack();
		break;
	default:
		break;
	}	
	glFlush();
}


// CTest01View 打印
void CTest01View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CTest01View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CTest01View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CTest01View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


void CTest01View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CTest01View 诊断

#ifdef _DEBUG
void CTest01View::AssertValid() const
{
	CView::AssertValid();
}

void CTest01View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTest01Doc* CTest01View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTest01Doc)));
	return (CTest01Doc*)m_pDocument;
}
#endif //_DEBUG


// CTest01View 消息处理程序


BOOL CTest01View::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default
	return NULL;
}

void CTest01View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	switch (nIDEvent)
	{
	case 0://开始界面计时器
		T0++;
		start.Update();
		break;
	case 1://游戏进行中计时器
		if (gamestatus == GAMEON)
		{
			world.UpdateMusicBox();
			world.UpdateBoys();
			Invalidate();
		}
		break;
	case 2://序章计时器
		TP++;
		if (profile.letterNum == 0)
		{
			profile.L1Alpha -= 0.01;
		}	
		if (profile.L1Alpha <= 0)
		{
			profile.letterNum = 1;
		}
		if (profile.letterNum == 1)
		{
			profile.L2Alpha -= 0.01;
		}
		if (profile.L2Alpha <= 0)
		{
			gamestatus = STARTPANAL;
			SetTimer(0, 400, NULL);//游戏开始界面计时器
			KillTimer(2);
		}
		Invalidate();
		break;
	case 3:
		if (gamestatus == GAMEOVER)
		{
			TO++;
			if (TO > 4&&TO<11)
			{
				if (world.tune[0]!= 13&&world.tune[TO-5]!=13)//当有保存音乐簇时播放声音
				{
					mciSendString(music[world.tune[TO - 5]], NULL, 0, NULL);
					mciSendString(playmusic[world.tune[TO - 5]], NULL, 0, NULL);
					Sleep(100);
					mciSendString(closemusic[world.tune[TO - 5]], NULL, 0, NULL);
					over.alpha[TO - 5] = 1.0;
				}
			}
			Invalidate();
		}	
		break;
	default:
		break;
	}
	COpenGLView::OnTimer(nIDEvent);
	
}
void CTest01View::Init()
{	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_COLOR_MATERIAL);
	glLightModeli(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glShadeModel(GL_SMOOTH);     //使用平滑明暗处理
	glEnable(GL_LIGHTING);      //启用光照
	//为LIGHT0设置析质
	glMaterialfv(GL_FRONT, GL_AMBIENT, matAmbient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiff);
	glMaterialfv(GL_FRONT, GL_SHININESS, matshine);
	glMaterialfv(GL_FRONT, GL_SPECULAR, matSpec);
	//现在开始调协LIGHT0
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);               //设置环境光分量
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);               //设置散射光分量
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);             //设置光源在场景中的位置
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);             //设置高光反射	
													 
	glEnable(GL_LIGHT0);
	glClearColor(0.0, 0.0, 0.0, 0);
	srand(time(NULL));


    //一系列初始化工作	
	SetTimer(2, 50, NULL);                                        //序章界面计时器
	SetTimer(3, 300, NULL);                                       //结束界面计时器
	SetTimer(1, 100, NULL);                                       //进行中计时器
	gamestatus = PROFILE;                                         //初始化游戏状态为序章状态
	C.setCamera(0, 0, 30, 0, 0, 0, 0, 10, 0);                     //初始化相机位置
	C0.setCamera(0, 0, 50, 0, 0, 0, 0, 10, 0);                    //初始化静止相机位置
	/*初始化第三人称相机中心点为主人物坐标*/
	p.x = world.boys[0].GetX();
	p.y = world.boys[0].GetY();
	p.z = world.boys[0].GetZ();
	/*初始化各个界面*/
	world.CreateStars();
	start.init();
	about.init();
	menu.init();
	world.init();
	profile.init();
	over.init();
	/*播放背景音乐*/
	mciSendString(TEXT(" open res\\immunity.wav alias mysong"), NULL, 0, NULL);
	mciSendString(TEXT("play MySong"), NULL, 0, NULL);
}


void CTest01View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	switch (gamestatus)
	{
	case STARTPANAL:
	{
		CRect rc;
		GetClientRect(&rc);
		int Width = rc.Width();
		int Height = rc.Height();
		point.y = -point.y + Height;
		LineSegment L = GetSelectionRay(point.x, point.y);
		if (isCross(L, 0, -25, 0,6)==1)
		{
			start.btnalpha = 1.0;
			Invalidate();
		}
		if (isCross(L, -15, -28, 0, 3))
		{
			start.LArrowAlpha = 1.0;
			Invalidate();
		}
		if (isCross(L, 15, -28, 0, 3))
		{
			start.RArrowAlpha = 1.0;
			Invalidate();
		}
		if (isCross(L, 0, -25, 0,6)==0)
		{
			start.btnalpha = 0.8;
			Invalidate();
		}
		if (isCross(L, -15, -28, 0, 3) == 0)
		{
			start.LArrowAlpha = 0.8;
			Invalidate();
		}
		if (isCross(L, 15, -28, 0, 3) == 0)
		{
			start.RArrowAlpha = 0.8;
			Invalidate();
		}
		break;
	}
	case ABOUT:
	{
		CRect rc;
		GetClientRect(&rc);
		int Width = rc.Width();
		int Height = rc.Height();
		point.y = -point.y + Height;
		LineSegment L = GetSelectionRay(point.x, point.y);
		if (isCross(L, 33, -30, 0, 5) == 1)
		{
			about.backAlpha = 1.0;
			Invalidate();
		}
		if (!isCross(L, 33, -30, 0, 5))
		{
			about.backAlpha = 0.8;
			Invalidate();
		}
		break;
	}
	case GAMEON:
	{
		float dx = (point.x - lastPos.x);
		float dy = (point.y - lastPos.y);
		p.x = world.boys[0].GetX();
		p.y = world.boys[0].GetY();
		p.z = world.boys[0].GetZ();
		if (C.GetRotate() == true)
		{
			C.roll3(dx, dy, p);
		}
		lastPos = point;
	}
		break;
	case MENU:
	{
		CRect rc;
		GetClientRect(&rc);
		int Width = rc.Width();
		int Height = rc.Height();
		point.y = -point.y + Height;
		LineSegment L = GetSelectionRay(point.x, point.y);
		if (isCross(L, -33, -30, 0, 5) == 1)
		{
			menu.backAlpha = 1.0;
			Invalidate();
		}
		if (!isCross(L, 33, -30, 0, 5))
		{
			menu.backAlpha = 0.8;
			Invalidate();
		}
		break;
	}
	default:
		break;
	}	
    COpenGLView::OnMouseMove(nFlags, point);
}
void CTest01View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	lastPos = point;
	C.SetRotate(true);
	COpenGLView::OnRButtonDown(nFlags, point);
}


void CTest01View::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	C.SetRotate(false);
	COpenGLView::OnRButtonUp(nFlags, point);
}
/*矩阵转换屏幕坐标，返回世界坐标最近点与最远点*/
LineSegment GetSelectionRay(LONG mouse_x, LONG mouse_y) {

	// 获取 Model-View、Projection 矩阵 & 获取Viewport视区
	GLdouble    modelview[16];
	GLdouble    projection[16];
	GLint       viewport[4];
	glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
	glGetDoublev(GL_PROJECTION_MATRIX, projection);
	glGetIntegerv(GL_VIEWPORT, viewport);

	GLdouble world_x, world_y, world_z;
	// 获取近裁剪面上的交点
	gluUnProject((GLdouble)mouse_x, (GLdouble)mouse_y, 0.0,
		modelview, projection, viewport,
		&world_x, &world_y, &world_z);
	Point3 near_point(world_x, world_y, world_z);
	// 获取远裁剪面上的交点
	gluUnProject((GLdouble)mouse_x, (GLdouble)mouse_y, 1.0,
		modelview, projection, viewport,
		&world_x, &world_y, &world_z);
	Point3 far_point(world_x, world_y, world_z);
	
	return LineSegment(near_point, far_point);
}

void CTest01View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CRect rc;
	GetClientRect(&rc);
	int Width = rc.Width();
	int Height = rc.Height();
	point.y = -point.y + Height;
	LineSegment L=GetSelectionRay(point.x, point.y);
	switch (gamestatus)
	{
	case STARTPANAL:
		if (isCross(L, 0, -25, 0, 6) == 1)
		{
			//开始游戏
			GamePre = STARTPANAL;
		    GameNow = GAMEON;
			gamestatus = GAMEON;
		}
		if (isCross(L, -15, -28, 0, 3))
		{
			//弹出ABOUT界面
			GamePre = STARTPANAL;
			GameNow = ABOUT;
			gamestatus = ABOUT;
			Invalidate();
		}
		if (isCross(L, 15, -28, 0, 3))
		{
			//弹出菜单界面
			GamePre = STARTPANAL;
			GameNow = MENU;
			gamestatus = MENU;
		}
		break;
	case ABOUT:
		//是否返回
		if (isCross(L, 33, -30, 0, 5) == 1)
		{
			gamestatus = GamePre;
			GameNow = GamePre;
			Invalidate();
		}
		break;
	case GAMEON:
		world.UpdateSelectBoy(L);
		world.isTargetSelect(L);
		if (world.isGameOver(L))
		{
			gamestatus = GAMEOVER;
			TO = 0;
		}
		Invalidate();
		break;
	case MENU:
		if (isCross(L, -33, -30, 0, 5) == 1)
		{
			gamestatus = GamePre;
			GameNow = GamePre;
			Invalidate();
		}
		break;
	}

	COpenGLView::OnLButtonDown(nFlags, point);
}
/*判断是否点击或选中某区域,线段与平面的交点是否在某个范围内*/
bool isCross(LineSegment &l, float x, float y, float z,float size)
{
	//z is defined
	float xNow = (l.Far.x - l.Near.x)*(z- l.Near.z) / (l.Far.z - l.Near.z)+l.Near.x;
	float yNow = (l.Far.y - l.Near.y)*( z- l.Near.z) / (l.Far.z - l.Near.z) + l.Near.y;
	if (xNow >= x - size && xNow <= x + size && yNow >= y - size && yNow <= y + size)
	{
		return true;
	}
    return false;
}

void CTest01View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	if (nChar == VK_SPACE)
	{
		gamestatus = GAMEOVER;
		TO = 0;
	}
	COpenGLView::OnKeyDown(nChar, nRepCnt, nFlags);
}
