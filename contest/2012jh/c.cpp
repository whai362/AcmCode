#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include <queue>
using namespace std;
const int N=205*2;
int _map[N][N];
struct Point{
	int x,y;
};	
struct Data{
	int x1,y1,x2,y2;
}d[55];
int x[N],y[N];
struct Node{
	int x,y,k;
	int turns;
};
Point s,t;
int xlim,ylim;
bool vis[N][N][4];
int ans[N][N][4];
int dx[]={0,1,0,-1},
	dy[]={1,0,-1,0};

bool reach(int x,int y,int k){
	if (x>=0&&x<=xlim&&y>=0&&y<=ylim&&_map[x][y]!=1&&!vis[x][y][k]){
		return true;
	}
	return false;
}

void bfs(){
	queue<Node> que;
	Node src;
	memset(vis,0,sizeof(vis));
	memset(ans,-1,sizeof(ans));
	src.x=s.x,src.y=s.y;src.turns=0;
	//ans[s.x][s.y]=0;
	for (int kk=0;kk<4;kk++){
		src.k=kk;
		vis[s.x][s.y][kk]=true;
		que.push(src);
	}
	while (!que.empty()){
		Node u=que.front();que.pop();
		Node v;
		int k=u.k;
		v.x=u.x+dx[k],v.y=u.y+dy[k];v.k=u.k;v.turns=u.turns;
		while (reach(v.x,v.y,k)){
			ans[v.x][v.y][k]=v.turns;
			que.push(v);
			vis[v.x][v.y][k]=true;
			v.x=v.x+dx[k],v.y=v.y+dy[k];v.k=v.k;v.turns=v.turns;
		}
		int k1=(k+1)%4;
		v.x=u.x+dx[k1],v.y=u.y+dy[k1];v.k=k1;v.turns=u.turns+1;
		while (reach(v.x,v.y,k1)){
			ans[v.x][v.y][k1]=v.turns;
			que.push(v);
			vis[v.x][v.y][k1]=true;
			v.x=v.x+dx[k1],v.y=v.y+dy[k1];v.k=v.k;v.turns=v.turns;
		}
		int k2=(k+3)%4;
		v.x=u.x+dx[k2],v.y=u.y+dy[k2];v.k=k2;v.turns=u.turns+1;
		while (reach(v.x,v.y,k2)){
			ans[v.x][v.y][k2]=v.turns;
			que.push(v);
			vis[v.x][v.y][k2]=true;
			v.x=v.x+dx[k2],v.y=v.y+dy[k2];v.k=v.k;v.turns=v.turns;
		}
	}
	return ;
}

void Work(){
	//cout<<s.x<<' '<<s.y<<endl;
	//cout<<t.x<<' '<<t.y<<endl;
	_map[s.x][s.y]=2;
	_map[t.x][t.y]=2;
	bfs();
	int Min=10000;
	for (int kk=0;kk<4;kk++){
		if (ans[t.x][t.y][kk]!=-1)
		Min=min(Min,ans[t.x][t.y][kk]);
	}
	if (Min==10000) Min=-1;
	printf("%d\n",Min);
	return ;
}
bool bianjie(int x,int y){
	int tx,ty;
	for (int kk=0;kk<4;kk++){
		tx=x+dx[kk];ty=y+dy[kk];
		if (_map[tx][ty]==0) return true;
	}
	return false;
}
int main(){
	int cnt1=0,cnt2=0;
	while(scanf("%d%d%d%d",&s.x,&s.y,&t.x,&t.y) && (s.x || s.y || t.x || t.y)){;
	x[cnt1++]=s.x;
	x[cnt1++]=t.x;
	y[cnt2++]=s.y;
	y[cnt2++]=t.y;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d%d%d%d",&d[i].x1,&d[i].y1,&d[i].x2,&d[i].y2);
		x[cnt1++]=d[i].x1;
		x[cnt1++]=d[i].x2;
		y[cnt2++]=d[i].y1;
		y[cnt2++]=d[i].y2;
	}
	sort(x,x+cnt1);
	sort(y,y+cnt2);
	cnt1=unique(x,x+cnt1)-x;
	cnt2=unique(y,y+cnt2)-y;
	s.x=(lower_bound(x,x+cnt1,s.x)-x+1)*2;
	t.x=(lower_bound(x,x+cnt1,t.x)-x+1)*2;
	s.y=(lower_bound(y,y+cnt2,s.y)-y+1)*2;
	t.y=(lower_bound(y,y+cnt2,t.y)-y+1)*2;
	for(int i=0;i<n;++i){
		d[i].x1=(lower_bound(x,x+cnt1,d[i].x1)-x+1)*2;
		d[i].x2=(lower_bound(x,x+cnt1,d[i].x2)-x+1)*2;
		d[i].y1=(lower_bound(y,y+cnt2,d[i].y1)-y+1)*2;
		d[i].y2=(lower_bound(y,y+cnt2,d[i].y2)-y+1)*2;
	}
	memset(_map,0,sizeof(_map));
	for(int i=0;i<n;++i){
		int le=min(d[i].x1,d[i].x2),
			ri=max(d[i].x1,d[i].x2),
			up=min(d[i].y1,d[i].y2),
			dn=max(d[i].y1,d[i].y2);
		for(int j=le;j<=ri;++j){
			for(int k=up;k<=dn;++k){
				//if(j==le || j==ri || k==up || k==dn)
					_map[j][k]=1;
				//else
				//	_map[j][k]=2;
			}
		}
	}
	xlim=2*cnt1+1,ylim=2*cnt2+1;

	for(int i=1;i<=xlim;++i){
		for(int j=1;j<=ylim;++j){
			if (_map[i][j]==1)
			if (bianjie(i,j)) _map[i][j]=2;
		}
	}
Work();

	for(int i=1;i<=xlim;++i){
		for(int j=1;j<=ylim;++j){
			cout<<_map[i][j];

		}
		cout<<endl;
	}
	
	}
	return 0;
}
