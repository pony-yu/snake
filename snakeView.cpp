
// snakeView.cpp : CsnakeView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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

// CsnakeView 构造/析构

CsnakeView::CsnakeView()
{
	// TODO: 在此处添加构造代码

}

CsnakeView::~CsnakeView()
{
}

BOOL CsnakeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CsnakeView 绘制

void CsnakeView::OnDraw(CDC* pdc)
{
	CsnakeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	
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


// CsnakeView 诊断

#ifdef _DEBUG
void CsnakeView::AssertValid() const
{
	CView::AssertValid();
}

void CsnakeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CsnakeDoc* CsnakeView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CsnakeDoc)));
	return (CsnakeDoc*)m_pDocument;
}
#endif //_DEBUG


// CsnakeView 消息处理程序


void CsnakeView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
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
	// TODO: 在此添加命令处理程序代码
	MessageBox("欢迎！游戏说明：按下start后通过键盘的上下左右健控制小蛇");
	SetTimer(1,100,NULL);
	srand((unsigned)time(NULL));
	hero.setfood();
}


void CsnakeView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
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
