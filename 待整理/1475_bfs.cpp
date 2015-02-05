#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int N=25,
		  INF=0x3f3f3f3f;
struct Data{
	int bx,by,px,py;
	string path;
	Data(){};
	Data(int _px,int _py,int _bx,int _by,string _path){
		px=_px;
		py=_py;
		bx=_bx;
		by=_by;
		path=_path;
	}
};
int r,c,sx,sy,tx,ty,bx,by;
int dx[]={1,-1,0,0},
	dy[]={0,0,1,-1};
string pm[]={"s","n","e","w"},
	   bm[]={"S","N","E","W"};
bool bvis[N][N],pvis[N][N];
char _map[N][N];
bool ok(int x,int y){
	if(x>=0 && x<r && y>=0 && y<c && _map[x][y]!='#')
		return true;
	return false;
}
Data bfs(Data d){
	queue<Data> q;
	q.push(d);
	pvis[d.px][d.py]=true;
	while(!q.empty()){
		Data now=q.front();
		q.pop();
		if(now.px==now.bx && now.py==now.by)
			return now;
		for(int i=0;i<4;++i){
			int tmpx=now.px+dx[i],
				tmpy=now.py+dy[i];
			if(ok(tmpx,tmpy) && !pvis[tmpx][tmpy]){
				q.push(Data(tmpx,tmpy,now.bx,now.by,now.path+pm[i]));
				pvis[tmpx][tmpy]=true;
			}
		}
	}
	return Data(0,0,0,0,"-1");
}
Data gao(){
	queue<Data> q;
	memset(bvis,0,sizeof(bvis));
	q.push(Data(sx,sy,bx,by,""));
	bvis[bx][by]=true;
	while(!q.empty()){
		Data now=q.front();
		q.pop();
		if(now.bx==tx && now.by==ty)
			return now;
		for(int i=0;i<4;++i){
			int qx=now.bx+dx[i],
				qy=now.by+dy[i],
				hx=now.bx-dx[i],
				hy=now.by-dy[i];
			if(ok(qx,qy) && !bvis[qx][qy] && ok(hx,hy)){
				memset(pvis,0,sizeof(pvis));
				pvis[now.bx][now.by]=true;
				Data pmove=bfs(Data(now.px,now.py,hx,hy,""));
				if(pmove.path!="-1"){
					q.push(Data(now.bx,now.by,qx,qy,now.path+pmove.path+bm[i]));
					bvis[qx][qy]=true;
				}
			}
		}
	}
	return Data(0,0,0,0,"-1");
}
int main(){
	int cas=0;
	while(scanf("%d%d",&r,&c) && (r || c)){
	for(int i=0;i<r;++i){
		scanf("%s",_map[i]);
	}
	for(int i=0;i<r;++i){
		for(int j=0;j<c;++j){
			if(_map[i][j]=='S'){
				sx=i;
				sy=j;
			}
			if(_map[i][j]=='T'){
				tx=i;
				ty=j;
			}
			if(_map[i][j]=='B'){
				bx=i;
				by=j;
			}
		}
	}
	string ans=gao().path;
	printf("Maze #%d\n",++cas);
	if(ans=="-1") puts("Impossible.");
	else cout<<ans<<endl;
	puts("");
	}
	return 0;
}
