#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N=1005;
struct Data{
	int x,y,s;
	Data(){}
	Data(int _x,int _y,int _s){
		x=_x;
		y=_y;
		s=_s;
	}
};
int n,m;
int _map[N][N];
bool vis[N][N];
int dx[]={-1,1,0,0},
	dy[]={0,0,-1,1};
bool ok(int x,int y){
	if(x>=0 && x<n && y>=0 && y<n && vis[x][y]==0 && _map[x][y]==0)
		return true;
	return false;
}
int gao(){
	memset(vis,0,sizeof(vis));
	queue<Data> q;
	q.push(Data(0,0,0));
	vis[0][0]=1;
	while(!q.empty()){
		Data now=q.front();
		q.pop();
		for(int i=0;i<4;++i){
			int tmpx=now.x+dx[i],
				tmpy=now.y+dy[i];
			if(ok(tmpx,tmpy)){
				if(tmpx==n-1 && tmpy==m-1)
					return now.s+1;
				q.push(Data(tmpx,tmpy,now.s+1));
				vis[tmpx][tmpy]=1;
			}
		}
	}
	return -1;
}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			scanf("%d",&_map[i][j]);
		}
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(i==0 && j==0)
				continue;
			if(_map[i][j]==_map[0][0]){
				_map[i][j]=0;
			}
		}
	}
	printf("%d\n",gao());
	}
	return 0;
}
