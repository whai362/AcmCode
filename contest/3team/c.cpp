#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
struct Data{
	int x,y;
	Data(){}
	Data(int _x,int _y){
		x=_x;
		y=_y;
	}
};
int n,m;
int _map[205][205],
	vis[205][205],
	hash[205*205];
int biao[][4]={
	0,0,0,0,
	0,0,0,1,
	0,0,1,0,
	0,0,1,1,
	0,1,0,0,
	0,1,0,1,
	0,1,1,0,
	0,1,1,1,
	1,0,0,0,
	1,0,0,1,
	1,0,1,0,
	1,0,1,1,
	1,1,0,0,
	1,1,0,1,
	1,1,1,0,
	1,1,1,1
};
void read(int r,int &p,char c){
	if(c>='0' && c<='9'){
		int id=c-'0';
		for(int i=0;i<4;++i){
			_map[r][p+i]=biao[id][i];
		}
		p+=4;
	}
	else{
		int id=c-'a'+10;
		for(int i=0;i<4;++i){
			_map[r][p+i]=biao[id][i];
		}
		p+=4;
	}
}
int cnt0,
	dx[]={1,-1,0,0},
	dy[]={0,0,1,-1};
bool ok(int x,int y){
	if(x>=0 && x<n && y>=0 && y<m && _map[x][y]==0 && !vis[x][y])
		return true;
	return false;
}
bool ok_cnt(int x,int y){
	if(x>=0 && x<n && y>=0 && y<m && _map[x][y]==0 && !hash[vis[x][y]])
		return true;
	return false;
}
bool ok_gao(int x,int y){
	if(x>=0 && x<n && y>=0 && y<m && _map[x][y]==1 && !vis[x][y])
		return true;
	return false;
}
void bfs(Data d){
	queue<Data> q;
	if(!vis[d.x][d.y] && _map[d.x][d.y]==0){
		++cnt0;
		q.push(d);
		vis[d.x][d.y]=cnt0;
		while(!q.empty()){
			Data now=q.front();
			q.pop();
			for(int i=0;i<4;++i){
				int tmpx=now.x+dx[i],
					tmpy=now.y+dy[i];
				if(ok(tmpx,tmpy)){
					q.push(Data(tmpx,tmpy));
					vis[tmpx][tmpy]=cnt0;
				}
			}
		}
	}
}
int gao(Data d){
	int ret=0;
	queue<Data> q;
	memset(hash,0,sizeof(hash));
	if(!vis[d.x][d.y] && _map[d.x][d.y]==1){
		++cnt0;
		q.push(d);
		vis[d.x][d.y]=cnt0;
		while(!q.empty()){
			Data now=q.front();
			q.pop();
			for(int i=0;i<4;++i){
				int tmpx=now.x+dx[i],
					tmpy=now.y+dy[i];
				if(ok_cnt(tmpx,tmpy)){
					++ret;
					hash[vis[tmpx][tmpy]]=1;
				}
				if(ok_gao(tmpx,tmpy)){
					q.push(Data(tmpx,tmpy));
					vis[tmpx][tmpy]=cnt0;
				}
			}
		}
		return ret;
	}
	return -1;
}
char cc=0,ans[205*205];
char aa[][2]={
	"W","A","K","J","S","D"
};
int main(){
	int cas=0,p;
	char str[205];
	while(scanf("%d%d",&n,&m) && (n || m)){
	memset(vis,0,sizeof(vis));
	memset(_map,0,sizeof(_map));
	gets(str);
	for(int i=0;i<n;++i){
		gets(str);
		p=1;
		for(int j=0;j<m;++j){
			read(i,p,str[j]);
		}
	}
	m=p+1;
	cc=cnt0=0;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(vis[i][j]==0)
				bfs(Data(i,j));
		}
	}
	memset(ans,0,sizeof(ans));
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(vis[i][j]==0){
				int tt=gao(Data(i,j));
				if(tt!=-1){
					ans[cc++]=aa[tt-1][0];
				}
			}
		}
	}
	sort(ans,ans+cc);
	printf("Case %d: ",++cas);
	puts(ans);
	}
	return 0;
}
