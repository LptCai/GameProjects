#pragma once

#include <gl/gl.h>
#include <gl/glu.h>

// COpenGLView view

class COpenGLView : public CView
{
	DECLARE_DYNCREATE(COpenGLView)

protected:
	COpenGLView();           // protected constructor used by dynamic creation
	virtual ~COpenGLView();

public:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

public:
	virtual BOOL SetupPixelFormat();
	virtual void Init();
	virtual void Reshape(int w, int h);
	virtual void Display();
private:
	BOOL InitializeOpenGL();

protected:
	DECLARE_MESSAGE_MAP()

	HGLRC hRC; // 绘制描述表
	CDC* pDC;  // 设备描述表
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
//	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};


