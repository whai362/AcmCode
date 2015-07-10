#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1005;
bool dp[N];
int n,m;
bool win(int x){
	for(int i=1;i<=m;++i){
		int tmpx=x-i;
		if(tmpx>=0 && dp[tmpx]==0) return true;
	}
	return false;
}
bool fail(int x){
	for(int i=1;i<=m;++i){
		int tmpx=x-i;
		if(tmpx<0) continue;
		if(dp[tmpx]!=1) return false;
	}
	return true;
}
void gao(int n,int m){
	memset(dp,0,sizeof(dp));
	dp[0]=0;
	for(int i=1;i<=n;++i){
		if(win(i)) dp[i]=1;
		else if(fail(i)) dp[i]=0;
	}
	if(dp[n]) puts("first");
	else puts("second");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		gao(n,m);
	}
	return 0;
}
