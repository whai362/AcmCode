#include<cstdio>
#include<iostream>
using namespace std;
char s[5][5];
int n,t,m[5][5];
void deal(int x,int y){
	int i;
	m[x][y]=1;
	for(i=x+1;i<n;++i){
		if(s[i][y]=='X') break;
		else m[i][y]=1;
	}
	for(i=x-1;i>=0;--i){
		if(s[i][y]=='X') break;
		else m[i][y]=1;
	}
	for(i=y+1;i<n;++i){
		if(s[x][i]=='X') break;
		else m[x][i]=1;
	}
	for(i=y-1;i>=0;--i){
		if(s[x][i]=='X') break;
		else m[x][i]=1;
	}
}
void clear(){
	int i,j;
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			if(s[i][j]=='.') m[i][j]=0;
			else m[i][j]=1;
		}
	}
	return ;
}
int main(){
	int ans,cnt,i,j,tmp,x,y;
	while(scanf("%d",&n) && n){
		ans=0;
		t=n*n;
		for(i=0;i<n;++i){
			scanf("%s",s[i]);
		}
		for(i=0;i<=(1<<t);++i){
			tmp=i;
			cnt=0;
			clear();
			for(j=0;j<t;++j){
				if(tmp&1){
					x=j/n;
					y=j%n;
					if(!m[x][y]) deal(x,y);
					else break;
					++cnt;
				}
				tmp=tmp>>1;
			}
			ans=max(ans,cnt);
		}
		printf("%d\n",ans);
	}
	return 0;
}
