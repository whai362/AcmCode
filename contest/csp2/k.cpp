#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
char _map[35][35][35];
int vis[35][35][35];
struct Data{
	int x,y,z,s;
	Data(){};
	Data(int _z,int _x,int _y,int _s){
		x=_x;
		y=_y;
		z=_z;
		s=_s;
	}
};
int l,r,c;
bool ok(int z,int x,int y){
	if(z>=0 && z<l && x>=0 && x<r && y>=0 && y<c && _map[z][x][y]!='#' && vis[z][x][y]==0)
		return true;
	return false;
}
int dz[]={0,0,0,0,-1,1},
	dx[]={0,0,1,-1,0,0},
	dy[]={1,-1,0,0,0,0};
int main(){
	while(scanf("%d%d%d",&l,&r,&c) && (l || r || c)){
	for(int i=0;i<l;++i){
		for(int j=0;j<r;++j){
			scanf("%s",_map[i][j]);
		}
	}
	Data s,t;
	for(int i=0;i<l;++i){
		for(int j=0;j<r;++j){
			for(int k=0;k<c;++k){
				if(_map[i][j][k]=='S'){
					s=Data(i,j,k,0);
				}
				if(_map[i][j][k]=='E'){
					t=Data(i,j,k,-1);
				}
			}
		}
	}
	memset(vis,0,sizeof(vis));
	queue<Data> q;
	q.push(s);
	vis[s.z][s.x][s.y]=1;
	int ans=-1;
	while(!q.empty()){
		Data now=q.front();
		q.pop();
		for(int i=0;i<6;++i){
			int tmpz=now.z+dz[i],
				tmpx=now.x+dx[i],
				tmpy=now.y+dy[i];
			if(ok(tmpz,tmpx,tmpy)){
				if(tmpz==t.z && tmpx==t.x && tmpy==t.y){
					ans=now.s+1;
					break;
				}
				q.push(Data(tmpz,tmpx,tmpy,now.s+1));
				vis[tmpz][tmpx][tmpy]=1;
			}
		}
	}
	if(ans!=-1){
		if(ans==1)
			printf("Escaped in %d minute.\n",ans);
		else
			printf("Escaped in %d minutes.\n",ans);
	}
	else puts("No zuo no die!");
	}
	return 0;

}
