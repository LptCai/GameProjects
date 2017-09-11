
// Test01View.cpp : CTest01View ���ʵ��
//

#include "stdafx.h"
#include "OpenGLView.h"
#include<math.h>

// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
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
//���ù�
float LightX = 0;
float LightY = -60;
float LightZ = 5;

float ambientLight[] = { 1.0f,1.0f,1.0f,1.0f };  //������
float diffuseLight[] = { 0.25f,0.25f,0.25f,1.0f }; //ɢ���
float specularLight[] = { 1.0f,1.0f,1.0f,1.0f };//�߹ⷴ��Ч��
float lightPosition[] = { LightX,LightY,LightZ,0.0f }; //��Դλ��

float matAmbient[] = { 1.0f,1.0f,1.0f,1.0f };
float matDiff[] = { 1.0f,1.0f,1.0f,1.0f };
float matSpec[] = { 1.0f,1.0f,1.0f,1.0f };
float matshine[] = { 50.0 };

CPoint lastPos;
LineSegment GetSelectionRay(LONG mouse_x, LONG mouse_y);//��������
bool isCross(LineSegment &l, float x, float y, float z,float size);//��������
int T0 = 0;//��ʼ�����ʱ�������
int TP = 0;//���½����ʱ�������
int TO = 0;//���������ʱ�������
CTest01View::CTest01View()
{


}

CTest01View::~CTest01View()
{
}

BOOL CTest01View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CTest01View ����

void CTest01View::OnDraw(CDC* /*pDC*/)
{
	CTest01Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	Display();
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}

void CTest01View::Display()
{
	CRect rc;
	GetClientRect(&rc);
	int Width = rc.Width();
	int Height = rc.Height();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // �������
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
	//�����ǿ�
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
		//������Ϸ����ͼ
		glEnable(GL_DEPTH_TEST);     //�޳�������
		glEnable(GL_CULL_FACE);      //���������α���
		glFrontFace(GL_CCW);      //�������ʱ�뷽��Ϊ����
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


// CTest01View ��ӡ
void CTest01View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CTest01View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CTest01View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CTest01View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


void CTest01View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CTest01View ���

#ifdef _DEBUG
void CTest01View::AssertValid() const
{
	CView::AssertValid();
}

void CTest01View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTest01Doc* CTest01View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTest01Doc)));
	return (CTest01Doc*)m_pDocument;
}
#endif //_DEBUG


// CTest01View ��Ϣ�������


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
	case 0://��ʼ�����ʱ��
		T0++;
		start.Update();
		break;
	case 1://��Ϸ�����м�ʱ��
		if (gamestatus == GAMEON)
		{
			world.UpdateMusicBox();
			world.UpdateBoys();
			Invalidate();
		}
		break;
	case 2://���¼�ʱ��
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
			SetTimer(0, 400, NULL);//��Ϸ��ʼ�����ʱ��
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
				if (world.tune[0]!= 13&&world.tune[TO-5]!=13)//���б������ִ�ʱ��������
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
	glShadeModel(GL_SMOOTH);     //ʹ��ƽ����������
	glEnable(GL_LIGHTING);      //���ù���
	//ΪLIGHT0��������
	glMaterialfv(GL_FRONT, GL_AMBIENT, matAmbient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiff);
	glMaterialfv(GL_FRONT, GL_SHININESS, matshine);
	glMaterialfv(GL_FRONT, GL_SPECULAR, matSpec);
	//���ڿ�ʼ��ЭLIGHT0
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);               //���û��������
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);               //����ɢ������
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);             //���ù�Դ�ڳ����е�λ��
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);             //���ø߹ⷴ��	
													 
	glEnable(GL_LIGHT0);
	glClearColor(0.0, 0.0, 0.0, 0);
	srand(time(NULL));


    //һϵ�г�ʼ������	
	SetTimer(2, 50, NULL);                                        //���½����ʱ��
	SetTimer(3, 300, NULL);                                       //���������ʱ��
	SetTimer(1, 100, NULL);                                       //�����м�ʱ��
	gamestatus = PROFILE;                                         //��ʼ����Ϸ״̬Ϊ����״̬
	C.setCamera(0, 0, 30, 0, 0, 0, 0, 10, 0);                     //��ʼ�����λ��
	C0.setCamera(0, 0, 50, 0, 0, 0, 0, 10, 0);                    //��ʼ����ֹ���λ��
	/*��ʼ�������˳�������ĵ�Ϊ����������*/
	p.x = world.boys[0].GetX();
	p.y = world.boys[0].GetY();
	p.z = world.boys[0].GetZ();
	/*��ʼ����������*/
	world.CreateStars();
	start.init();
	about.init();
	menu.init();
	world.init();
	profile.init();
	over.init();
	/*���ű�������*/
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
/*����ת����Ļ���꣬���������������������Զ��*/
LineSegment GetSelectionRay(LONG mouse_x, LONG mouse_y) {

	// ��ȡ Model-View��Projection ���� & ��ȡViewport����
	GLdouble    modelview[16];
	GLdouble    projection[16];
	GLint       viewport[4];
	glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
	glGetDoublev(GL_PROJECTION_MATRIX, projection);
	glGetIntegerv(GL_VIEWPORT, viewport);

	GLdouble world_x, world_y, world_z;
	// ��ȡ���ü����ϵĽ���
	gluUnProject((GLdouble)mouse_x, (GLdouble)mouse_y, 0.0,
		modelview, projection, viewport,
		&world_x, &world_y, &world_z);
	Point3 near_point(world_x, world_y, world_z);
	// ��ȡԶ�ü����ϵĽ���
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
			//��ʼ��Ϸ
			GamePre = STARTPANAL;
		    GameNow = GAMEON;
			gamestatus = GAMEON;
		}
		if (isCross(L, -15, -28, 0, 3))
		{
			//����ABOUT����
			GamePre = STARTPANAL;
			GameNow = ABOUT;
			gamestatus = ABOUT;
			Invalidate();
		}
		if (isCross(L, 15, -28, 0, 3))
		{
			//�����˵�����
			GamePre = STARTPANAL;
			GameNow = MENU;
			gamestatus = MENU;
		}
		break;
	case ABOUT:
		//�Ƿ񷵻�
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
/*�ж��Ƿ�����ѡ��ĳ����,�߶���ƽ��Ľ����Ƿ���ĳ����Χ��*/
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
