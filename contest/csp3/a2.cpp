#include<stdio.h>
#include<string.h>
#define N 205
#define inf 0x3f3f3f3f
int ans,n,a[N][N],dis[N];
bool vis[N];
bool prim(){
	int i,j,k,tmp;
	memset(vis,0,sizeof(vis));
	for(i=1;i<=n;++i) dis[i]=inf;
	ans=0,dis[1]=0;
	for(i=1;i<=n;++i){
		k=0,tmp=inf;
		for(j=1;j<=n;++j){
			if(!vis[j]&&dis[j]<tmp){
				tmp=dis[j];
				k=j;
			}
		}
		if(tmp==inf) return 0;
		ans=ans+tmp;
		vis[k]=1;
		for(j=1;j<=n;++j)
		  if(!vis[j]&&dis[j]>a[k][j]) dis[j]=a[k][j];
	}
	return 0;
}
int main(){
	int i,m,u,v,c;
	while(scanf("%d",&n)!=EOF){
		memset(a,inf,sizeof(a));
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				scanf("%d",&a[i][j]);
			}
		}
		prim();
		printf("%d\n",ans);
	}
	return 0;
}

