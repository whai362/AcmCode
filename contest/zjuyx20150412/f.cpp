#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int INF=0x3f3f3f3f;
struct Pt{
	int x,y,d,t;
	Pt(){}
	Pt(int _x,int _y,int _d,int _t){
		x=_x;
		y=_y;
		d=_d;
		t=_t;
	}
};
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
int n,m,p;
char mp[15][15];
int vis[15][15][5][5];
bool ok(int x,int y,int d,int t,int mv){
	if(x>=0 && x<n && y>=0 && y<m && mp[x][y]!='*' && vis[x][y][d][mv%4]>t){
		return true;
	}
	return false;
}
int tx,ty;
void gao(Pt s){
	memset(vis,0x3f,sizeof(vis));
	queue<Pt> q;
	vis[s.x][s.y][0][0]=0;
	q.push(s);
	int mv=0;
	while(!q.empty()){
		Pt now=q.front();
		//cout<<now.x<<' '<<now.y<<' '<<now.d<<' '<<now.t<<endl;
		q.pop();
		int d=(now.d+1)%4;
		int mv=(now.t+1)/p;
		if(vis[now.x][now.y][d][mv%4]>now.t+1){
			vis[now.x][now.y][d][mv%4]=now.t+1;
			q.push(Pt(now.x,now.y,d,now.t+1));
		}
		d=(now.d-1+4)%4;	//inf
		if(vis[now.x][now.y][d][mv%4]>now.t+1){
			vis[now.x][now.y][d][mv%4]=now.t+1;
			q.push(Pt(now.x,now.y,d,now.t+1));
		}
		int dir=((now.d-now.t/p)%4+4)%4;
		int tmpx=now.x+dx[dir];
		int tmpy=now.y+dy[dir];
		if(ok(tmpx,tmpy,now.d,now.t+1,mv)){
			vis[tmpx][tmpy][now.d][mv%4]=now.t+1;
			q.push(Pt(tmpx,tmpy,now.d,now.t+1));
		}

		if(vis[now.x][now.y][now.d][mv%4]>now.t+1){
			vis[now.x][now.y][now.d][mv%4]=now.t+1;
			q.push(Pt(now.x,now.y,now.d,now.t+1));
		}
	}
	int ans=INF;
	//cout<<tx<<' '<<ty<<endl;
	for(int i=0;i<4;++i){
		for(int j=0;j<4;++j){
			ans=min(vis[tx][ty][i][j],ans);
			//cout<<vis[tx][ty][i][j]<<endl;
		}
	}
	if(ans==INF) puts("YouBadbad");
	else printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&p);
		for(int i=0;i<n;++i){
			scanf("%s",mp[i]);
		}
		int sx,sy;
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				if(mp[i][j]=='@'){
					sx=i;
					sy=j;
				}
				if(mp[i][j]=='$'){
					tx=i;
					ty=j;
				}
			}
		}
		gao(Pt(sx,sy,0,0));
	}
	return 0;
}
