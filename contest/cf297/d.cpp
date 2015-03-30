#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
struct Dt{
	int x,y;
	Dt(){}
	Dt(int _x,int _y){ x=_x; y=_y; }
};
const int N=2005;
char str[N][N];
int n,m;
bool vis[N][N];
struct Nd{
	int l,r,u,d;
	Nd(){}
	Nd(int _l,int _r,int _u,int _d){
		l=_l;
		r=_r;
		u=_u;
		d=_d;
	}
	Nd ud(int _l,int _r,int _u,int _d){
		l=min(l,_l);
		r=max(r,_r);
		u=min(u,_u);
		d=max(d,_d);
		return Nd(l,r,u,d);
	}
}tt[N][N];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
bool ok(int x,int y){
	if(x>=0 && x<n && y>=0 && y<m && str[x][y]=='.' && vis[x][y]==0)
		return true;
	return false;
}
void update(int x,int y,int l,int r,int u,int d){
	if(tt[x][y].l==-1){
		tt[x][y]=Nd(l,r,u,d);
	}
	else{
		tt[x][y]=tt[x][y].ud(l,r,u,d);
	}
}
bool vv[N][N];
void gao(int x,int y){
	int l=y,r=y,u=x,d=x;
	queue<Dt> q;
	q.push(Dt(x,y));
	vv[x][y]=vis[x][y]=1;
	update(x,y,l,r,u,d);
	while(!q.empty()){
		Dt now=q.front();
		q.pop();
		for(int i=0;i<4;++i){
			int tmpx=now.x+dx[i];
			int tmpy=now.y+dy[i];
			if((u<=tmpx && tmpx<=d && l<=tmpy && tmpy<=r && vis[tmpx][tmpy]==0) 
				|| ok(tmpx,tmpy)){
				l=min(tmpy,l);
				r=max(tmpy,r);
				u=min(tmpx,u);
				d=max(tmpx,d);
				if(vv[tmpx][tmpy]==0){ q.push(Dt(tmpx,tmpy)); vv[tmpx][tmpy]=1; str[tmpx][tmpy]='.'; }
				else{
					Nd t=tt[tmpx][tmpy];
					l=min(t.l,l);
					r=max(t.r,r);
					u=min(t.u,u);
					d=max(t.d,d);
				}
				vis[tmpx][tmpy]=1;
			}
		}
	}
	//cout<<l<<' '<<r<<' '<<u<<' '<<d<<endl;
	//for(int i=u;i<=d;++i)
	//	for(int j=l;j<=r;++j){
	//		str[i][j]='.';
	//		update(i,j,l,r,u,d);
	//		//vis[i][j]=1;
	//	}

	//for(int i=u;i<=d;++i)
	for(int j=l;j<=r;++j){
		str[u][j]='.';
		update(u,j,l,r,u,d);
		str[d][j]='.';
		update(d,j,l,r,u,d);
		//vis[i][j]=1;
	}
	for(int i=u;i<=d;++i){
		str[i][l]='.';
		update(i,l,l,r,u,d);
		str[i][r]='.';
		update(i,r,l,r,u,d);
	}
}
int main(){
	memset(tt,-1,sizeof(tt));
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i)
		scanf("%s",str[i]);
	//for(int t=0;t<4;++t){
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				if(str[i][j]=='.' && vv[i][j]==0){
					memset(vis,0,sizeof(vis));
					gao(i,j);
				}
			}
		}
	//}

	for(int i=0;i<n;++i)
		puts(str[i]);
	return 0;
}
