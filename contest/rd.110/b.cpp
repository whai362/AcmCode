#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
#define M 2049
#define N 1025
int n,top_x,lim;
char _map[N][M];
void draw(int h){
	top_x=lim-h;
	//cout<<top_x<<endl;
	if(h==2){
		_map[top_x+1][1]='/';
		_map[top_x+1][2]='\\';
		_map[top_x+2][0]='/';
		_map[top_x+2][1]=_map[top_x+2][2]='_';
		_map[top_x+2][3]='\\';
	}
	else{
		int tmp1=top_x+h/2,tmp2=h,y1=h,x2=h/2,y2=h/2;
		for(int i=tmp1+1;i<=lim;++i){
			for(int j=0;j<tmp2;++j){
				_map[i-x2][j+y2]=_map[i][j+y1]=_map[i][j];
			}
		}
	}
	/*for(int i=1;i<=lim;++i){
		cout<<_map[i]<<endl;
	}*/
}
void gao(){
	int h=2;
	lim=top_x=pow(2,n);
	memset(_map,0,sizeof(_map));
	for(int i=1;i<=lim;++i)
		for(int j=0;j<lim*2;++j)
			_map[i][j]=' ';
	while(top_x>0){
		draw(h);
		h*=2;
		//cout<<top_x<<endl;
	}
}
int main(){
	int i,j;
	while(scanf("%d",&n) && n){
	gao();
	//cout<<lim<<endl;
	for(i=1;i<=lim;++i){
		puts(_map[i]);
	}
	putchar('\n');
	}
	return 0;
}

