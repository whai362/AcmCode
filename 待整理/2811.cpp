#include<cstdio>
using namespace std;
int _map[50][50];
const int x0=25,y0=25;
struct domi{
	int a,b,x,y,d;
}d[15];
bool ok(int x,int y){
	if(x>=0 && x<50 && y>=0 && y<50 && _map[x][y]==0)
		return 1;
	return 0;
}
bool fill(int i,int x,int y,int d){
	if(ok(x,y)) _map[x][y]=d[i].a;
	if(d==0 && ok(x-1,y)){
		_map[x-1][y]=d[i].b;
		return 1;
	}
	else if(d==1 && ok(x,y-1)){
		_map[x][y-1]=d[i].b;
		return 1;
	}
	else if(d==2 && ok(x+1,y)){
		_map[x+1][y]=d[i].b;
		return 1;
	}
	else if(d==3 && ok(x,y+1)){
		_map[x][y+1]=d[i].b;
		return 1;
	}
	return 0;
}
void erase(int x,int y,int d){
	_map[x][y]=0;
	if(d==0){
		_map[x-1][y]=0;
	}
	else if(d==1){
		_map[x][y-1]=0;
	}
	else if(d==2){
		_map[x+1][y]=0;
	}
	else if(d==3){
		_map[x][y+1]=0;
	}
}
bool dfs(int k){
	for(i=0;i<50;++i){
		for(j=0;j<50;++j){
			if(_map[i][j]==d[k].a){
				
			}
		}
	}
}
int main(){
	int k,w,h;
	for(i=0;i<=k;++i){
		for(j=0;j<=k;++j){
			d[i].a=i+1;
			d[i].b=j+1;
			d[i].d=0;
		}
	}
	d[0].x=d[0].y=x0;
	dfs();
}
