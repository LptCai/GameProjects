// COpenGLView.cpp : implementation file
//

#include "stdafx.h"
#include "Test01.h"
#include "OpenGLView.h"



// COpenGLView

IMPLEMENT_DYNCREATE(COpenGLView, CView)

COpenGLView::COpenGLView()
{
	hRC = NULL;
	pDC = NULL;
}

COpenGLView::~COpenGLView()
{
}

BEGIN_MESSAGE_MAP(COpenGLView, CView)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_SIZE()
//	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// COpenGLView drawing

void COpenGLView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	Display();
}

void COpenGLView::Display()
{

}

BOOL COpenGLView::InitializeOpenGL() {
	pDC = new CClientDC(this);
	if (NULL == pDC) return FALSE;
	if (!SetupPixelFormat()) return FALSE;
	if (NULL == (hRC = wglCreateContext(pDC->GetSafeHdc())))
		return FALSE;
	if (!wglMakeCurrent(pDC->GetSafeHdc(), hRC))
		return FALSE;
	Init();
	return TRUE; 
}


BOOL COpenGLView::SetupPixelFormat() 
{
	PIXELFORMATDESCRIPTOR pfd = {sizeof(PIXELFORMATDESCRIPTOR), 1, PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL, PFD_TYPE_RGBA,24, 0,0,0,0,0,0, 0, 0, 0, 0,0,0,0, 0, 0, PFD_MAIN_PLANE, 0, 0,0,0 };
	int pf;
	pf = ChoosePixelFormat(pDC->GetSafeHdc(), &pfd);
	if (0 == pf) return FALSE;
	if (!SetPixelFormat(pDC->GetSafeHdc(), pf, &pfd))
		return FALSE;
   return TRUE;
}

void COpenGLView::Init() 
{
	glClearColor(0.0,0.0, 0.0, 0); 
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_POLYGON_SMOOTH);
}


// COpenGLView diagnostics

#ifdef _DEBUG
void COpenGLView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void COpenGLView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// COpenGLView message handlers


int COpenGLView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	InitializeOpenGL();
	// TODO:  Add your specialized creation code here

	return 0;
}

void COpenGLView::Reshape(int w, int h) {
	
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION); // 初始化投影矩阵
	glLoadIdentity();
	gluPerspective(90.0f, w / h, 1.0f, 100000.0f);
	//glFrustum(0, w, 0, h, 1.0, 1000.0);
	glMatrixMode(GL_MODELVIEW);
	
}


void COpenGLView::OnDestroy()
{
	wglMakeCurrent(NULL, NULL); // 清除绘制描述表和设备描述表
	wglDeleteContext(hRC);
	if (pDC) delete pDC;

	CView::OnDestroy();
	// TODO: Add your message handler code here
}


void COpenGLView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
	if ((cx > 0) && (cy>0))
		Reshape(cx, cy);
}



