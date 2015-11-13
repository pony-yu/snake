
// snakeView.h : CsnakeView ��Ľӿ�
//

#pragma once

#include"CHero.h"
class CsnakeView : public CView
{
protected: // �������л�����
	CsnakeView();
	DECLARE_DYNCREATE(CsnakeView)

// ����
public:
	CsnakeDoc* GetDocument() const;

// ����
public:
	CHero hero;

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CsnakeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
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

#ifndef _DEBUG  // snakeView.cpp �еĵ��԰汾
inline CsnakeDoc* CsnakeView::GetDocument() const
   { return reinterpret_cast<CsnakeDoc*>(m_pDocument); }
#endif

