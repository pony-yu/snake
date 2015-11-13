#include"stdafx.h"
#include"CHero.h"

CHero::CHero()
{
	//初始化三节蛇身
	CPoint point;
	point=CPoint(200,200);
	snake.push_back(point);
	point=CPoint(190,200);
	snake.push_back(point);
	point=CPoint(180,200);
	snake.push_back(point);

	//初始化方向
	dir=RIGHT;
	isfood=FALSE;
	
}

void CHero::setfood()
{
	CPoint point(100,100);
	do
	{
		UINT x=rand()%(WIDTH-20);
		UINT y=rand()%(HEIGHT-20);
		UINT X=10*(x/10)+10;
		UINT Y=10*(y/10)+10;
		point=CPoint(X,Y);
	}while(point==food);
	food=CPoint(point);

}
BOOL CHero::move()
{
	CPoint point;
	point=snake[0];
	if(getdir()==UP)
		point.y-=10;
	else if(getdir()==DOWN)
		point.y+=10;
	else if(getdir()==LEFT)
		point.x-=10;
	else
		point.x+=10;
	//判断前方是否出界
	if(point.x<5||point.x>WIDTH-5||point.y<5||point.y>HEIGHT-5)
	{
		return FALSE;
	}

	//前方是否有食物
	if(point==food)
	{
		snake.push_back(*(snake.end()-1));
		for(vector<CPoint>::iterator iter=snake.end()-2;
			iter!=snake.begin();iter--)
		{
			iter->x=(iter-1)->x;
			iter->y=(iter-1)->y;
		}
		snake.begin()->x=point.x;
		snake.begin()->y=point.y;
		setfood();
	}
	else
	{
		for(vector<CPoint>::iterator iter=snake.end()-1;
			iter!=snake.begin();iter--)
		{
			iter->x=(iter-1)->x;
			iter->y=(iter-1)->y;
		}
		snake.begin()->x=point.x;
		snake.begin()->y=point.y;
	}
	
	return TRUE;
}

void CHero::setdir(UINT ndir)
{
	dir=ndir;
}

UINT CHero::getdir()
{
	return dir;
}
void CHero::setisfood(BOOL n)
{
	isfood=n;
}
BOOL CHero::getisfood()
{
	return isfood;
}