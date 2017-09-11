
// Test01View.h : CTest01View 类的接口
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
protected: // 仅从序列化创建
	CTest01View();
	DECLARE_DYNCREATE(CTest01View)
//定义变量
public:


// 特性
public:
	CTest01Doc* GetDocument() const;
// 操作
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
	int GamePre;//记录前一刻游戏状态，当在游戏进行中跳出到菜单帮助界面时，可返回，但是并没有设置游戏中到菜单界面，还没用
	int GameNow;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void Display();
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void Init();
	

// 实现
public:
	virtual ~CTest01View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
public:
	Myworld world;
	
// 生成的消息映射函数
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

#ifndef _DEBUG  // Test01View.cpp 中的调试版本
inline CTest01Doc* CTest01View::GetDocument() const
   { return reinterpret_cast<CTest01Doc*>(m_pDocument); }
#endif

