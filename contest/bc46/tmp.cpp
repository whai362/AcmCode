#include<queue>
#include<cstring>
#include<iostream>
using namespace std;
int n,m;
struct Data{
	int x,y,s;
	Data(){}
	Data(int _x,int _y,int _s){
		x=_x;
		y=_y;
		s=_s;
	}
};
char mp[10][10];

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

const int N=105;
bool vis[N][N];


int ok(int x,int y){
	//cout<<x<<' '<<y<<' '<<mp[x][y]<<endl;
	if(x>=0 && x<n && y>=0 && y<m && mp[x][y]!='#' && vis[x][y]==0) return true;
	return false;
}


int bfs(int sx,int sy,int tx,int ty){
	queue<Data> que;
	memset(vis,0,sizeof(vis));

	Data tmp=Data(sx,sy,0);
	que.push(tmp);
	vis[tmp.x][tmp.y]=1;

	while(!que.empty()){
		Data now = que.front();
		//cout<<now.x<<' '<<now.y<<endl;
		que.pop();
		for(int i=0;i<4;++i){
			int tmpx=now.x+dx[i];
			int tmpy=now.y+dy[i];
			if(ok(tmpx,tmpy)){
				//cout<<tmpx<<' '<<tmpy<<endl;
				tmp=Data(tmpx,tmpy,now.s+1);
				if(tmpx==tx && tmpy==ty){
					return tmp.s;
				}
				que.push(tmp);
				vis[tmp.x][tmp.y]=1;
			}
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i=0;i<n;++i)
		cin>>mp[i];
	int sx,sy,tx,ty;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(mp[i][j]=='S'){
				sx=i;
				sy=j;
			}
			if(mp[i][j]=='T'){
				tx=i;
				ty=j;
			}
		}
	}
	//cout<<sx<<' '<<sy<<' '<<tx<<' '<<ty<<endl;

	cout<<bfs(sx,sy,tx,ty)<<endl;

	return 0;
}
