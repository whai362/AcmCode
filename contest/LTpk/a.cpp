#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N=1005;
struct Data{
	int x,y,step;
	Data(){}
	Data(int _x,int _y,int _step){
		x=_x;
		y=_y;
		step=_step;
	}
};
bool vis[N][N];
char _map[N][N];
int n,m;
int dis[N*N],
	dx[]={1,-1,0,0},
	dy[]={0,0,1,-1};
bool ok(int x,int y){
	if(x>=0 && x<n && y>=0 && y<m && !vis[x][y] && _map[x][y]=='.'){
		return true;
	}
	return false;
}
void gao(){
	queue<Data> q;
	memset(vis,0,sizeof(vis));
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(_map[i][j]=='#'){
				q.push(Data(i,j,0));
				vis[i][j]=true;
			}
		}
	}
	while(!q.empty()){
		Data now=q.front();
		q.pop();
		if(_map[now.x][now.y]=='.'){
			++dis[now.step];
		}
		for(int i=0;i<4;++i){
			if(ok(now.x+dx[i],now.y+dy[i])){
				q.push(Data(now.x+dx[i],now.y+dy[i],now.step+1));
				vis[now.x+dx[i]][now.y+dy[i]]=true;
			}
		}
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(_map[i][j]=='.' && !vis[i][j]){
				++dis[0];
			}
		}
	}
}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
	memset(dis,0,sizeof(dis));
	for(int i=0;i<n;++i){
		scanf("%s",_map[i]);
	}
	gao();
	for(int i=0;i<=n*m;++i){
		if(dis[i]) printf("%d %d\n",i,dis[i]);
	}
	}
	return 0;
}
