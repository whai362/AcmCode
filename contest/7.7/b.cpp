#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
struct Data{
	int x,y;
	Data(){}
	Data(int _x,int _y){
		x=_x;
		y=_y;
	}
};
const int N=205,
		  INF=0x3f3f3f3f;
char _map[N][N];
int ans,n,m,k;
int x[6],y[6],vi[6];
int path[6][6],vis[N][N];
int dx[]={1,-1,0,0},
	dy[]={0,0,1,-1};
bool ok(int x,int y){
	if(x>=0 && x<n && y>=0 && y<m && _map[x][y]!='#' && vis[x][y]==INF)
		return true;
	return false;
}
void bfs(int x,int y){
	memset(vis,0x3f,sizeof(vis));
	queue<Data> q;
	q.push(Data(x,y));
	vis[x][y]=0;
	while(!q.empty()){
		Data now=q.front();
		q.pop();
		for(int i=0;i<4;++i){
			int tmp_x=now.x+dx[i],tmp_y=now.y+dy[i];
			if(ok(tmp_x,tmp_y)){
				q.push(Data(tmp_x,tmp_y));
				vis[tmp_x][tmp_y]=vis[now.x][now.y]+1;
			}
		}
	}
}
void dfs(int st,int dis,int step){
	if(step==k){
		ans=min(dis,ans);
		return ;
	}
	for(int i=0;i<=k;++i){
		if(!vi[i]){
			vi[i]=1;
			dfs(i,dis+path[st][i],step+1);
			vi[i]=0;
		}
	}
}
int main(){
	int flag;
	while(scanf("%d%d",&n,&m) && (n || m)){
	memset(path,0,sizeof(path));
	for(int i=0;i<n;++i){
		scanf("%s",_map[i]);
	}
	scanf("%d",&k);
	for(int i=1;i<=k;++i){
		scanf("%d%d",&x[i],&y[i]);
		--x[i],--y[i];
	}
	flag=0;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(_map[i][j]=='@'){
				x[0]=i;
				y[0]=j;
				flag=1;
				break;
			}
		}
		if(flag==1)
			break;
	}
	for(int i=0;i<=k;++i){
		bfs(x[i],y[i]);
		for(int j=0;j<=k;++j){
			path[i][j]=vis[x[j]][y[j]];
		}
	}
	ans=INF;
	memset(vi,0,sizeof(vi));
	vi[0]=1;
	dfs(0,0,0);
	if(ans>=INF) printf("%d\n",-1);
	else printf("%d\n",ans);
	}
	return 0;
	
}
