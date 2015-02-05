#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct Data{
	int x,y,t;
}mi[55*55];
int n,m,f,k;
int p;
char st[2][55][55];
bool cmp(Data d1,Data d2){
	return d1.t<d2.t;
}
int dx[]={-1,1,0,0,-1,1,-1,1},
	dy[]={0,0,-1,1,-1,1,1,-1};
bool in(int x,int y){
	if(x>=0 && x<n && y>=0 && y<m)
		return true;
	return false;
}
int getS(int t,int x,int y){
	int ret=0,tmpx,tmpy;
	for(int i=0;i<8;++i){
		tmpx=x+dx[i];
		tmpy=y+dy[i];
		if(in(tmpx,tmpy) && st[(t+1)%2][tmpx][tmpy]=='1'){
			++ret;
		}
	}
	return ret;
}
void gao(int t){
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(st[(t+1)%2][i][j]=='X'){
				st[t%2][i][j]='X';
				continue;
			}
			int sum=getS(t,i,j);
			if(sum<2) st[t%2][i][j]='0';
			else if(sum>3){
				st[t%2][i][j]='0';
			}
			else if(sum==3){
				st[t%2][i][j]='1';
			}
		}
	}
	for(;p<k;++p){
		if(mi[p].t==t){
			st[t%2][mi[p].x-1][mi[p].y-1]='X';
		}
		else break;
	}
}
int main(){
	scanf("%d %d %d %d",&n,&m,&f,&k);
	p=0;
	for(int i=0;i<n;++i){
		scanf("%s",st[0][i]);
	}
	int x,y,t;
	for(int i=0;i<k;++i){
		scanf("%d %d %d",&mi[i].t,&mi[i].x,&mi[i].y);
	}
	sort(mi,mi+k,cmp);
	for(int i=1;i<=f;++i){
		gao(i);
		for(int j=0;j<n;++j){
			printf("%s\n",st[i%2][j]);
		}
	}
	for(int i=0;i<n;++i){
		printf("%s\n",st[f%2][i]);
	}
	return 0;
}
