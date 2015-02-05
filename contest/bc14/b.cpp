#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int vis[105][105];
int _map[105][105],id[105][105];
struct Data{
	int x,y;
	int st,step;
	Data(){}
	Data(int _x,int _y,int _st,int _step){
		x=_x;
		y=_y;
		st=_st;
		step=_step;
	}
};
int n,m,goal,cnt;
bool ok(int x,int y,int st){
	if(x>=0 && x<n && y>=0 && y<m && vis[x][y]==st)
		return true;
	return false;
}
int deal(int x,int y,int st){
	if(_map[x][y]==0) return st;
	else{
		
		return ((1<<(id[x][y]-1)) | st);
	}
}
int dx[]={1,-1,0,0},
	dy[]={0,0,1,-1};
int gao(){
	memset(vis,0,sizeof(vis));
	queue<Data> q;
	goal=(1<<(cnt-1))-1;
	//cout<<goal<<endl;
	q.push(Data(0,0,0,0));
	while(!q.empty()){
		Data now=q.front();
		//cout<<now.x<<' '<<now.y<<' '<<now.st<<endl;
		q.pop();
		if(now.x==0 && now.y==0 && now.st==goal) return now.step;
		for(int i=0;i<4;++i){
			int tmpx=now.x+dx[i],
				tmpy=now.y+dy[i];
			if(ok(tmpx,tmpy,now.st)){
				int st=deal(tmpx,tmpy,now.st);
				if(tmpx==0 && tmpy==0 && st==goal) return now.step+1;
				q.push(Data(tmpx,tmpy,st,now.step+1));
				vis[tmpx][tmpy]=st;
			}
		}
	}
	return -1;
}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		cnt=1;
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				scanf("%d",&_map[i][j]);
				if(_map[i][j]) id[i][j]=cnt++;
				else id[i][j]=0;
			}
		}
		printf("%d\n",gao());
	}
	return 0;
}
