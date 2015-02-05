#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
bool map[105][105];
int n,k,p[105];
int dp(int root,int step){
	int ans=0,i,tmp,tmp_p;
	tmp_p=p[root];
	p[root]=0;
	if(!step){
		p[root]=tmp_p;
		return p[root];
	}
	for(i=1;i<=n;++i){
		if(map[root][i]){
			tmp=dp(i,step-1);
			if(tmp>ans) ans=tmp;
		}
	}
	p[root]=tmp_p;
	return p[root]+ans;
}
int main(){
	int i,u,v;
	while(scanf("%d%d",&n,&k)!=EOF){
		memset(map,0,sizeof(map));
		for(i=1;i<=n;++i)
		  scanf("%d",&p[i]);
		for(i=1;i<n;++i){
			scanf("%d%d",&u,&v);
			map[u][v]=map[v][u]=1;
		}
		printf("%d\n",dp(1,k));
	}
	return 0;
}
//或许用生成树可以做
