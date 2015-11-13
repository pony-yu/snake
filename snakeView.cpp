
// snakeView.cpp : CsnakeView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "snake.h"
#endif

#include "snakeDoc.h"
#include "snakeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include"resource.h"


// CsnakeView

IMPLEMENT_DYNCREATE(CsnakeView, CView)

BEGIN_MESSAGE_MAP(CsnakeView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_TIMER()
	ON_COMMAND(ID_START, &CsnakeView::OnSTART)
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CsnakeView ����/����

CsnakeView::CsnakeView()
{
	// TODO: �ڴ˴���ӹ������

}

CsnakeView::~CsnakeView()
{
}

BOOL CsnakeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CsnakeView ����

void CsnakeView::OnDraw(CDC* pdc)
{
	CsnakeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	
	CRect rect;
	GetClientRect(rect);
	SetRect(rect,0,0,WIDTH,HEIGHT);
	CBrush green(RGB(0,125,0));
	pdc->FillRect(rect,&green);
	CBrush blue(RGB(0,0,125));
	{
		SetRect(rect,hero.food.x-5,hero.food.y-5,
			hero.food.x+5,hero.food.y+5);
		pdc->FillRect(rect,&blue);
	}
	CBrush red(RGB(125,0,0));
	for(vector<CPoint>::iterator iter=hero.snake.begin();
		iter!=hero.snake.end();iter++)
	{
		SetRect(rect,(*iter).x-5,(*iter).y-5,
			(*iter).x+5,(*iter).y+5);
		pdc->FillRect(rect,&red);
	}
}

void CsnakeView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CsnakeView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS

#endif
}


// CsnakeView ���

#ifdef _DEBUG
void CsnakeView::AssertValid() const
{
	CView::AssertValid();
}

void CsnakeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CsnakeDoc* CsnakeView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CsnakeDoc)));
	return (CsnakeDoc*)m_pDocument;
}
#endif //_DEBUG


// CsnakeView ��Ϣ�������


void CsnakeView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(hero.move()!=TRUE)
	{
		KillTimer(nIDEvent);
	}
	Invalidate();

	CView::OnTimer(nIDEvent);
}

void CsnakeView::OnUp()
{
	if(hero.getdir()==LEFT||hero.getdir()==RIGHT)
		hero.setdir(UP);
}
void CsnakeView::OnDown()
{
	if(hero.getdir()==LEFT||hero.getdir()==RIGHT)
		hero.setdir(DOWN);
}
void CsnakeView::OnLeft()
{
	if(hero.getdir()==UP||hero.getdir()==DOWN)
		hero.setdir(LEFT);
}
void CsnakeView::OnRight()
{
	if(hero.getdir()==UP||hero.getdir()==DOWN)
		hero.setdir(RIGHT);
}


void CsnakeView::OnSTART()
{
	// TODO: �ڴ���������������
	MessageBox("��ӭ����Ϸ˵��������start��ͨ�����̵��������ҽ�����С��");
	SetTimer(1,100,NULL);
	srand((unsigned)time(NULL));
	hero.setfood();
}


void CsnakeView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(nChar==VK_UP)
		OnUp();
	if(nChar==VK_DOWN)
		OnDown();
	if(nChar==VK_LEFT)
		OnLeft();
	if(nChar==VK_RIGHT)
		OnRight();
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
