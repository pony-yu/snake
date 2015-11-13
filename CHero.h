#include"stdafx.h"
#include<vector>
#include<iterator>
using namespace std;

#define UP 1
#define RIGHT 2
#define DOWN 3
#define LEFT 4
#define HEIGHT 400
#define WIDTH  600

class CHero:public CObject
{
public:
	CHero();

	BOOL move();
	void setfood();
	void setdir(UINT);
	UINT getdir();
	BOOL getisfood();
	void setisfood(BOOL);
	vector<CPoint> snake;
	CPoint food;
private:
	UINT dir;
	BOOL isfood;
};