#include<cstdio>
#include<iostream>
using namespace std;
struct Cmd{
	int a,b;
	char dir[5];
}c[105];
int n,m,cnt;
int _map[105][105],
	dx[]={-1,0,1,0},
	dy[]={0,1,0,-1};
int getDir(char dir){
	switch(dir){
		case 'U': return 0;
		case 'R': return 1;
		case 'D': return 2;
		case 'L': return 3;
	}
}
bool ok(int x,int y){
	if(x>=0 && x<n && y>=0 && y<m && _map[x][y]==0)
		return true;
	return false;
}
bool dfs(int x,int y,int step){
	if(step>=cnt)
		return true;
	int dir=getDir(c[step].dir[0]);
	for(int i=0;i<=c[step].b;++i){
		int toX=x+i*dx[dir],
			toY=y+i*dy[dir];
		if(ok(toX,toY)){
			if(i>=c[step].a){
				if(dfs(toX,toY,step+1))
					return true;
			}
		}
		else break;
	}
	return false;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				scanf("%d",&_map[i][j]);
			}
		}
		int a,b;
		cnt=0;
		while(scanf("%d%d",&a,&b) && (a || b)){
			c[cnt].a=a;
			c[cnt].b=b;
			scanf("%s",c[cnt++].dir);
		}
		int ans=0;
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				if(ok(i,j) && dfs(i,j,0)) ++ans;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
