
// snakeView.h : CsnakeView 类的接口
//

#pragma once

#include"CHero.h"
class CsnakeView : public CView
{
protected: // 仅从序列化创建
	CsnakeView();
	DECLARE_DYNCREATE(CsnakeView)

// 特性
public:
	CsnakeDoc* GetDocument() const;

// 操作
public:
	CHero hero;

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CsnakeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnUp();
	afx_msg void OnDown();
	afx_msg void OnLeft();
	afx_msg void OnRight();
	afx_msg void OnSTART();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // snakeView.cpp 中的调试版本
inline CsnakeDoc* CsnakeView::GetDocument() const
   { return reinterpret_cast<CsnakeDoc*>(m_pDocument); }
#endif

