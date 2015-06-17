/*百度之星2015 1005 下棋
  思路：
  对于任意一个格子，设国王到达这个格子至少需要x步，骑士到达这个格子至少需要y步，则：
  对于这个格子，
  1)国王到达这个格子需要的步数为：x+k步，其中k=0,1,2,3,4,5,...
  2)骑士到达这个格子需要的步数为：x+2*k步，其中k=0,1,2,3,4,5,...
  然后对1000*1000个格子都算一遍最小相遇的步数，然后再取个最小值就行了。
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N=1005;
const int INF=0x3f3f3f3f;
int n,m,k;
int G[N][N];
struct Pt{
	short x,y;
	Pt(){}
	Pt(short _x,short _y){
		x=_x;
		y=_y;
	}
};

queue<Pt> q;
int dx[]={-2,-1,-2,-1,1,2,2,1};
int dy[]={-1,-2,1,2,-2,-1,1,2};
int _abs(int x){
	if(x<0) return -x;
	return x;
}
int get_t(int x1,int y1,int x2,int y2){
	int dx=_abs(x1-x2);
	int dy=_abs(y1-y2);
	int ret=max(dx,dy);
	if(ret==0) ret=2;
	return ret;
}
bool ok(int x,int y,int x1,int y1){
	if(x>=0 && x<n && y>=0 && y<m && G[x][y]==-1)
		return true;
	return false;
}
void bfs(Pt S,Pt T){
	q.push(S);
	G[S.x][S.y]=0;
	while(!q.empty()){
		Pt now=q.front();
		q.pop();
		for(int i=0;i<8;++i){
			int tmpx=now.x+dx[i];
			int tmpy=now.y+dy[i];
			if(ok(tmpx,tmpy,T.x,T.y)){
				//cout<<tmpx<<' '<<tmpy<<endl;
				q.push(Pt(tmpx,tmpy));
				G[tmpx][tmpy]=G[now.x][now.y]+1;
			}
		}
	}
}



void gao(int x1,int y1,int x2,int y2){
	--x1;
	--y1;
	--x2;
	--y2;
	memset(G,-1,sizeof(G));
	bfs(Pt(x2,y2),Pt(x1,y1));
	//for(int i=0;i<n;++i){
	//	for(int j=0;j<m;++j){
	//		cout<<G[i][j]<<' ';
	//	}
	//	cout<<endl;
	//}
	int ans=INF;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			int t=get_t(i,j,x1,y1);
			//cout<<t<<','<<G[i][j]<<' ';
			//if(t<=G[i][j] && G[i][j]<=k)
			if(G[i][j]!=-1){
				if(t<=G[i][j]){
					if(G[i][j]<=k)
						ans=min(ans,G[i][j]);
				}
				else{
					int tmp;
					if((t-G[i][j])%2==0) tmp=t;
					else tmp=t+1;
					if(tmp<=k) ans=min(ans,tmp);
				}
			}
		}
		//cout<<endl;
	}
	if(ans==INF) puts("OH,NO!");
	else printf("%d\n",ans);
}
int main(){
	int T;
	int cas=0;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		int x1,y1;
		int x2,y2;
		scanf("%d%d",&x1,&y1);
		scanf("%d%d",&x2,&y2);
		printf("Case #%d:\n",++cas);
		gao(x1,y1,x2,y2);
	}
	return 0;
}
