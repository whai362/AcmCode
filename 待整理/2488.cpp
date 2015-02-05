#include<cstdio>
#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
struct point{
	int x,y;
	point(){}
	point(int x,int y){
		this->x=x;
		this->y=y;
	}
};
int p,q;
bool vis[26][26];
stack<point> s;
bool ok(int x,int y){
	if(x>=0 && x<p && y>=0 && y<q && !vis[x][y]){
		return true;
	}
	return false;
}
int dirx[]={-1,1,-2,2,-2,2,-1,1},
	diry[]={-2,-2,-1,-1,1,1,2,2};
bool dfs(int x,int y,int step){
	int tmpx,tmpy;
	if(step==p*q){
		s.push(point(x,y));
		return true;
	}
	for(int i=0;i<8;++i){
		tmpx=x+dirx[i],tmpy=y+diry[i];
		if(ok(tmpx,tmpy)){
			vis[tmpx][tmpy]=true;
			if(dfs(tmpx,tmpy,step+1)){
				s.push(point(x,y));
				return true;
			}
			else{
				vis[tmpx][tmpy]=false;
			}
		}
	}
	return false;
}
int main(){
	int T,f,flag;
	int i,j,k;
	scanf("%d",&T);
	for(i=0;i<T;++i){
		flag=0;
		scanf("%d%d",&p,&q);
		for(j=0;j<p;++j){
			for(k=0;k<q;++k){
				memset(vis,0,sizeof(vis));
				vis[j][k]=true;
				if(dfs(j,k,1)){
					flag=1;
					break;
				}
			}
			if(flag==1){
				break;
			}
		}
		printf("Scenario #%d:\n",i+1);
		if(flag==1){
			while(!s.empty()){
				printf("%c%d",s.top().y+'A',s.top().x+1);
				s.pop();
			}
			printf("\n\n");
		}
		else{
			printf("impossible\n\n");
		}
	}
	return 0;
}
