#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
#define M 100010
#define N 65
int a[N],b[N],chk[M],hash[N],map[M][N],match[M];
int n,res;
int dfs(int p){
	int i,t;
	for(i=a[p];i<=b[p];++i){
		if(map[i][p]&&!chk[i]){
			chk[i]=1;
			t=match[i];
			match[i]=p;
			if(t==0||dfs(t)) return 1;
			match[i]=t;
		}
	}
	return 0;
}
void pro(){
	int i;
	res=0;
	for(i=n;i>=1;--i){
		memset(chk,0,sizeof(chk));
		res=res+dfs(i);
	}
}
int main(){
	int i,j,t,flag;
	scanf("%d",&t);
	while(t--){
		memset(hash,0,sizeof(hash));
		memset(match,0,sizeof(match));
		scanf("%d",&n);
		for(i=1;i<=n;++i){
			scanf("%d%d",&a[i],&b[i]);
			for(j=a[i];j<=b[i];++j) map[j][i]=1;
		}
		pro();
		printf("%d\n",res);
		for(i=1;i<M;++i) if(match[i]) hash[match[i]]=1;
		flag=0;
		for(i=1;i<N;++i){
			if(hash[i]){
				if(flag) printf(" ");
				flag=1;
				printf("%d",i);
			}
		}
		printf("\n");
	}
	return 0;
}
