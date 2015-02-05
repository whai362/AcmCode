#include<iostream>
#include<cstdio>
using namespace std;
char _map[15][15];
int _id[15][15];
bool vis;
int n,cnt;
struct Point{
	int x,y;
	Point(){}
	Point(int _x,int _y){
		x=_x;
		y=_y;
	}
};
bool in(int x,int y){
	if(x>=0 && x<n && y>=0 && y<n)
		return true;
	return false;
}
void bfs(int x,int y){
	
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%s",_map[i]);
	}
	memset(_id,0,sizeof(_id));
	
}
