#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int N=105,
	  INF=0x3f3f3f3f;
int ans,n,m;
char _map[N][N];
bool vis[N][N];
int ti[N][N][30],
	dx[]={1,-1,0,0},
	dy[]={0,0,1,-1};
bool ok(int x,int y){
	if(x>=0 && x<n && y>=0 && y<m && !vis[x][y] &&
			_map[x][y]!='*' && _map[x][y]!='#'){
		bool flag=true;
		for(char i='A';i<='Z';++i){
			if(_map[x][y]==i){
				flag=false;
			}
		}
		return flag;
	}
	return false;
}
void dfs(int t,int z,int x,int y){
	//printf("%d %d %d %d\n",t,z,x,y);
	if(t>=ans) return ;
	if(t<ti[x][y][z]){
		ti[x][y][z]=t;
	}
	else return ;
	if(_map[x][y]=='$'){
		ans=min(ans,t);
		return ;
	}
	vis[x][y]=true;
	for(int i=0;i<4;++i){
		int tmpx=x+dx[i],
			tmpy=y+dy[i];
		if(ok(tmpx,tmpy)){
			if(_map[tmpx][tmpy]=='.'){
				dfs(t,z,tmpx,tmpy);
			}
			else if(_map[tmpx][tmpy]=='$'){
				dfs(t,z,tmpx,tmpy);
			}
			else{ 
				if(z>0) dfs(t,z-1,tmpx,tmpy);
				dfs(t+_map[tmpx][tmpy]-'0',z,tmpx,tmpy);
			}
		}
	}
	vis[x][y]=false;
}
int main(){
	int cnt;
	while(1){
		cnt=0;
		scanf("%s",_map[cnt++]);
		if(_map[0][0]=='-')
			break;
		getchar();
		while(cin.getline(_map[cnt],sizeof(_map[cnt])) &&
				_map[cnt++][0]!=0);
		n=cnt-1;
		m=strlen(_map[0]);
		ans=INF;
		memset(vis,0,sizeof(vis));
		memset(ti,0x3f,sizeof(ti));
		for(int i=0;i<m;++i){
			if(_map[0][i]=='#'){
				dfs(0,0,0,i);
			}
			else if(_map[0][i]!='*'){
				dfs(0,_map[0][i]+1-'A',0,i);
			}
			//cout<<_map[cnt-1][i]<<endl;
			if(_map[n-1][i]=='#'){
				dfs(0,0,n-1,i);
			}
			else if(_map[n-1][i]!='*'){
				dfs(0,_map[n-1][i]+1-'A',n-1,i);
			}
		}
		for(int i=0;i<n;++i){
			if(_map[i][0]=='#'){
				dfs(0,0,i,0);
			}
			else if(_map[i][0]!='*'){
				dfs(0,_map[i][0]+1-'A',i,0);
			}
			if(_map[i][m-1]=='#'){
				dfs(0,0,i,m-1);
			}
			else if(_map[i][m-1]!='*'){
				//cout<<i<<' '<<m-1<<endl;
				dfs(0,_map[i][m-1]+1-'A',i,m-1);
			}
		}
		if(ans!=INF) printf("%d\n",ans);
		else printf("IMPOSSIBLE\n");
	}
	return 0;
}
