#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<queue>
#include<cstring>
using namespace std;
int flag[400][400];
int dir[8][2]={{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2}};
int d;
int OK;
struct point
{
	int x,y,step;
}spoint,epoint;

bool bound(int x,int y)
{
	if (x >= 0 && x < d && y >= 0 && y <d)
		return true;
	return false;  
}

void BFS()
{
	OK=0;
	flag[spoint.x][spoint.y]=1;
	spoint.step=0;
	queue<point> q;
	q.push(spoint);
	while(!q.empty())
	{
		if(OK)
			break;
		point temp  =  q.front();
		q.pop();
		for(int i=0;i<8;i++)
		{
			if(OK)
				break;
			int x,y;
			x=temp.x+dir[i][0];
			y=temp.y+dir[i][1];
			if(bound(x,y) && flag[x][y]==0)
			{
				point s;
				s.x = x;
				s.y = y;
				s.step = temp.step + 1;
				if(x == epoint.x && y== epoint.y )
				{
					epoint.step = s.step;
					OK = 1;
				}
				flag[x][y] = 1;
				q.push(s);
			}
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		memset(flag,0,sizeof(flag));
		scanf("%d",&d);
		scanf("%d%d",&spoint.x,&spoint.y);
		scanf("%d%d",&epoint.x,&epoint.y);
		if(spoint.x==epoint.x&&spoint.y==epoint.y)
			printf("0\n");
		else
		{
			BFS();
			printf("%d\n",epoint.step);
		}
	}
	return 0;
}
