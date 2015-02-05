#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;


const int inf = 0x3f3f3f3f;
const int N = 205; //总顶点数
const int A = 15 ;  //要包含的顶点数
int id[A];         //包含顶点的序号
int d[N][N];       //距离矩阵
int dp[1<<A][N];  //dp[i][j]表示点j到联通的集合i的最短距离


char _map[10][10];
bool vis[10][10];
struct Point{
	int x,y;
	Point(){}
	Point(int _x,int _y){
		x=_x;
		y=_y;
	}
}s,p[100],tab[100];
int dx[]={-1,1,0,0},
	dy[]={0,0,-1,1};
int n,seq,cnt;
int _id[10][10];
bool ok(int x,int y){
	if(x>=0 && x<n && y>=0 && y<n && !vis[x][y] && _map[x][y]=='@')
		return true;
	return false;
}
void bfs(Point s){
	if(vis[s.x][s.y] || _map[s.x][s.y]!='@') return ;
	queue<Point> q;
	q.push(s);
	vis[s.x][s.y]=true;
	_map[s.x][s.y]=seq;
	while(!q.empty()){
		Point now=q.front();
		q.pop();
		for(int i=0;i<4;++i){
			int tmpx=now.x+dx[i],
				tmpy=now.y+dy[i];
			if(ok(tmpx,tmpy)){
				q.push(Point(tmpx,tmpy));
				vis[tmpx][tmpy]=true;
				_map[tmpx][tmpy]=seq;
			}
		}
	}
	++seq;
}
int getC(int x,int y){
	if(_map[x][y]>='0' && _map[x][y]<='9')
		return _map[x][y]-'0';
	else if(_map[x][y]=='X')
		return inf;
	else return 0;
}
int getC(int k){
	Point p=tab[k];
	return getC(p.x,p.y);
}
void deal(int x,int y){
	int u,v;
	u=_id[x][y];
	tab[u]=Point(x,y);
	d[u][u]=getC(x,y);
	for(int i=0;i<4;++i){
		int tmpx=x+dx[i],
			tmpy=y+dy[i];
		if(tmpx>=0 && tmpx<n && tmpy>=0 && tmpy<n){
			v=_id[tmpx][tmpy];
			if(getC(x,y)==inf || getC(tmpx,tmpy)==inf)
				d[u][v]=inf;
			else
				d[u][v]=getC(x,y)+getC(tmpx,tmpy);
		}
	}
}

void floyd(int n){
	for(int k=0;k<n;k++)      //vertex 0---n-1
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(d[i][j]>d[i][k]+d[k][j]-getC(k) && (d[i][k]!=inf && d[k][j]!=inf))
					d[i][j]=d[i][k]+d[k][j]-getC(k);
}

int stn(int n,int a)
{
	int top = 1<<a;

	for(int i=0;i<top;i++)
		for(int j=0;j<n;j++)
			dp[i][j]=inf;

	for(int i=0;i<a;i++)
	{
		for(int j=0;j<n;j++)
			dp[1<<i][j]=d[id[i]][j];
	}
	for(int i=1;i<top;i++)
	{
		if(i&(i-1)==0)
			continue;
		for(int k=0;k<n;k++)   //init
		{
			for(int j=1;j<i;j++)
			{
				if((i|j)==i && dp[i][k]>dp[j][k]+dp[i-j][k]-getC(k))
					dp[i][k]=dp[j][k]+dp[i-j][k]-getC(k);
			}
		}

		for(int j=0;j<n;j++)  //update
		{
			for(int k=0;k<n;k++)
			{
				if(dp[i][j]>dp[i][k]+d[k][j]-getC(k))
					dp[i][j]=dp[i][k]+d[k][j]-getC(k);
			}
		}
	}

	int ans = inf;
	for(int i=0;i<n;i++)
	{
		if(ans > dp[top-1][i])
			ans=dp[top-1][i];
	}
	return ans;
}


int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			scanf("%s",_map[i]);
		s.x=s.y=n/2;
		_map[s.x][s.y]='@';
		seq=0;
		memset(vis,0,sizeof(vis));
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				bfs(Point(i,j));
		cnt=seq;
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				if((_map[i][j]>='0' && _map[i][j]<='9') || _map[i][j]=='X')
					_id[i][j]=cnt++;
				else
					_id[i][j]=(int)_map[i][j];

		//for(int i=0;i<n;++i){
		//	for(int j=0;j<n;++j)
		//		cout<<_id[i][j]<<' ';
		//	cout<<endl;
		//}

		memset(d,0x3f,sizeof(d));
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				deal(i,j);

		//for(int i=0;i<cnt;++i){
		//	for(int j=0;j<cnt;++j)
		//		cout<<d[i][j]<<' ';
		//	cout<<endl;
		//}

		floyd(cnt);

		//for(int i=0;i<cnt;++i){
		//	for(int j=0;j<cnt;++j)
		//		cout<<d[i][j]<<' ';
		//	cout<<endl;
		//}

		for(int i=0;i<seq;++i){
			id[i]=i;
		}
		int ans=stn(cnt,seq);
		if(ans==inf) puts("-1");
		else printf("%d\n",ans);
	}
	return 0;
}
