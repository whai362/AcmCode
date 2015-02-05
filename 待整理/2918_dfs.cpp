#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct Data{
	int r,c;
	Data(){}
	Data(int _r,int _c){
		r=_r;
		c=_c;
	}
};
bool r[10][10],
	 c[10][10],
	 cell[10][10];
char str[10][10],
	 _map[10][10];
void preDeal(){
	for(int i=0;i<9;++i){
		for(int j=0;j<9;++j){
			if(str[i][j]!=0){
				_map[i][j]=str[i][j];
				int num=str[i][j]-'0';
				r[i][num]=true;
				c[j][num]=true;
				cell[i/3*3+j/3][num]=true;
			}
		}
	}
}
bool ok(Data d,int num){
	if(d.r>=0 && d.r<9 && d.c>=0 && d.c<9 &&
	   !r[d.r][num] && !c[d.c][num] && !cell[d.r/3*3+d.c/3][num])
		return true;
	return false;
}
void fill(Data d,int num){
	_map[d.r][d.c]=num+'0';
	r[d.r][num]=true;
	c[d.c][num]=true;
	cell[d.r/3*3+d.c/3][num]=true;
}
void unfill(Data d,int num){
	r[d.r][num]=false;
	c[d.c][num]=false;
	cell[d.r/3*3+d.c/3][num]=false;
}
bool dfs(Data d){
	if(d.c>=9){
		if(dfs(Data(d.r+1,0))) return true;
		else return false;
	}
	if(d.r>=9) return true;
	if(str[d.r][d.c]=='0'){
		for(int i=1;i<10;++i){
			if(ok(d,i)){
				fill(d,i);
				if(dfs(Data(d.r,d.c+1))) return true;
				unfill(d,i);
			}
		}
		return false;
	}
	else{
		if(dfs(Data(d.r,d.c+1))) return true;
		return false;
	}
}
int main(){
	int cas=0,T;
	scanf("%d",&T);
	while(T--){
		memset(_map,0,sizeof(_map));
		memset(r,0,sizeof(r));
		memset(c,0,sizeof(c));
		memset(cell,0,sizeof(cell));
		for(int i=0;i<9;++i){
			scanf("%s",str[i]);
		}
		preDeal();
		dfs(Data(0,0));
		printf("Scenario #%d:\n",++cas);
		for(int i=0;i<9;++i){
			puts(_map[i]);
		}
		puts("");
	}
	return 0;
}

