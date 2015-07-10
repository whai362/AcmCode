#include<queue>
#include<stack>
#include<cstring>
#include<iostream>
using namespace std;
const int INF=0x3f3f3f3f;
int n,m;
struct Data{
	int x,y;
	Data(){}
	Data(int _x,int _y){
		x=_x;
		y=_y;
	}
};

const int N=1005;
char mp[N][N];

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

int step[N][N];
bool vis[N][N];

bool ok(int x,int y){
	//cout<<x<<' '<<y<<' '<<mp[x][y]<<endl;
	if(x>=0 && x<n && y>=0 && y<m && mp[x][y]!='#' && vis[x][y]==0) return true;
	return false;
}

void bfs(int sx,int sy,int tx,int ty){
	queue<Data> que;
	memset(vis,0,sizeof(vis));
	memset(step,0x3f,sizeof(step));

	Data tmp=Data(sx,sy);
	que.push(tmp);
	step[tmp.x][tmp.y]=0;
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
				tmp=Data(tmpx,tmpy);
				//if(tmpx==tx && tmpy==ty){
				//	return step[now.x][now.y]+1;
				//}
				que.push(tmp);
				step[tmp.x][tmp.y]=step[now.x][now.y]+1;
				vis[tmp.x][tmp.y]=1;
			}
		}
	}
}

bool in_map(int x,int y){
	if(x>=0 && x<n && y>=0 && y<m)
		return true;
	return false;
}

void find_path(int sx,int sy,int tx,int ty){
	stack<Data> s;
	s.push(Data(tx,ty));
	int prex,prey;
	while(1){
		Data now=s.top();
		if(step[now.x][now.y]==0) break;
		for(int i=0;i<4;++i){
			int tmpx=now.x+dx[i];
			int tmpy=now.y+dy[i];
			if(!in_map(tmpx,tmpy)) continue;
			if(step[tmpx][tmpy]==step[now.x][now.y]-1)
				s.push(Data(tmpx,tmpy));
		}
	}
	while(!s.empty()){
		cout<<s.top().x<<' '<<s.top().y<<endl;
		s.pop();
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
	bfs(sx,sy,tx,ty);
	find_path(sx,sy,tx,ty);
	//for(int i=0;i<n;++i){
	//	for(int j=0;j<m;++j){
	//		if(step[i][j]==INF) cout<<"#"<<" ";
	//		else cout<<step[i][j]<<' ';
	//	}
	//	cout<<endl;
	//}

	return 0;
}
