
// Test01View.h : CTest01View ��Ľӿ�
//
#include "OpenGLView.h"
#include"Object.h"
#pragma once

#include"Data.h"
#include"Camera.h"
#include"Gworld.h"
#include"StartPanal.h"
#include"About.h"
#include"Menu.h"
#include"overpanal.h"
class CTest01View : public COpenGLView
{
protected: // �������л�����
	CTest01View();
	DECLARE_DYNCREATE(CTest01View)
//�������
public:


// ����
public:
	CTest01Doc* GetDocument() const;
// ����
public:
	Camera C;
	Camera C0;
	Start start;
	About about;
	Menu menu;
	Profile profile;
	Over over;
	Vector3 p;
	int gamestatus;
	int GamePre;//��¼ǰһ����Ϸ״̬��������Ϸ�������������˵���������ʱ���ɷ��أ����ǲ�û��������Ϸ�е��˵����棬��û��
	int GameNow;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void Display();
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void Init();
	

// ʵ��
public:
	virtual ~CTest01View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
public:
	Myworld world;
	
// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
//	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
     
//	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
//	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // Test01View.cpp �еĵ��԰汾
inline CTest01Doc* CTest01View::GetDocument() const
   { return reinterpret_cast<CTest01Doc*>(m_pDocument); }
#endif

