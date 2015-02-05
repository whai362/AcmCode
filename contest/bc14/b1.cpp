#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<queue>
using namespace std;
int _map[105][105],id[105][105],d[12][12],n,m,dp[1<<12][12],
	vis[105][105];
const int inf=1<<30;
int dx[]={1,-1,0,0},
	dy[]={0,0,1,-1};
struct Data{
	int x,y,s;
	Data(){}
	Data(int _x,int _y,int _s){
		x=_x;
		y=_y;
		s=_s;
	}
};
bool ok(int x,int y){
	if(x>=0 && x<n && y>=0 && y<m && vis[x][y]==0)
		return true;
	return false;
}
void bfs(int x,int y){
	int from=id[x][y]-1;
	queue<Data> q;
	memset(vis,0,sizeof(vis));
	q.push(Data(x,y,0));
	vis[x][y]=1;
	while(!q.empty()){
		Data now=q.front();
		q.pop();
		for(int i=0;i<4;++i){
			int tmpx=now.x+dx[i],
				tmpy=now.y+dy[i];
			if(ok(tmpx,tmpy)){
				q.push(Data(tmpx,tmpy,now.s+1));
				if(_map[tmpx][tmpy]){
					int to=id[tmpx][tmpy]-1;
					d[from][to]=now.s+1;
				}
				vis[tmpx][tmpy]=1;
			}
		}
	}
}
void deal(){
	int cnt=1;
	memset(d,0,sizeof(d));
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(_map[i][j]) id[i][j]=cnt++;
			else id[i][j]=0;
		}
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(_map[i][j]){
				bfs(i,j);
			}
		}
	}
	n=cnt-2;
}
int DP(){
	if(n==0) return 0;
	memset(dp,0,sizeof(dp));
	int ans=inf;
	for(int i=0;i<(1<<n);i++)
		for(int j=1;j<n+1;j++)
			if(i==(1<<(j-1)))
				dp[i][j]=d[0][j];
			else if(i&(1<<(j-1))){		
				dp[i][j]=inf;
				for(int k=1;k<n+1;k++)
					if(k!=j&&(i&(1<<(k-1))))
						dp[i][j]=min(dp[i^(1<<(j-1))][k]+d[k][j],dp[i][j]);
			}
	for(int i=1;i<n+1;i++){
		ans=min(ans,dp[(1<<n)-1][i]+d[i][0]);
	}
	return ans;
}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++){
				scanf("%d",&_map[i][j]);
			}
		_map[0][0]=1;
		deal();
		printf("%d\n",DP());
	}
	return 0;
}
