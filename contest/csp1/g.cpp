#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
char _map[55][55];
bool vis[55][55];
int n,m;
struct Data{
	int x,y;
	Data(){}
	Data(int _x,int _y){
		x=_x;
		y=_y;
	}
};
int dx[]={1,1,-1,-1},
	dy[]={1,-1,1,-1};
bool ok(int x,int y){
	if(x>=0 && x<n && y>=0 && y<=m && vis[x][y]==0 && _map[x][y]=='#'){
		return true;
	}
	return false;
}
void gao(){
	int ret=0;
	memset(vis,0,sizeof(vis));
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(_map[i][j]=='#' && vis[i][j]==0){
				++ret;
				queue<Data> q;
				q.push(Data(i,j));
				vis[i][j]=1;
				while(!q.empty()){
					Data now=q.front();
					q.pop();
					for(int k=0;k<4;++k){
						int tmpx=now.x+dx[k],
							tmpy=now.y+dy[k];
						if(ok(tmpx,tmpy)){
							//cout<<tmpx<<' '<<tmpy<<endl;
							q.push(Data(tmpx,tmpy));
							vis[tmpx][tmpy]=1;
						}
					}
				}
			}
		}
	}
	cout<<ret<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i){
		scanf("%s",_map[i]);
	}
	gao();
	}
	return 0;
}
