#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define Maxn 200500
int fa[Maxn],rela[Maxn];
int cnt[Maxn][2];
int getfather(int x){
	if (x!=fa[x]){
		int y=fa[x];
		fa[x]=getfather(fa[x]);
		rela[x]=(rela[x]+rela[y])%2;
	}
	return fa[x];
}
int main(){
	int cases,n,m,u,v;
	scanf("%d",&cases);
	for (int cas=1;cas<=cases;cas++){
		scanf("%d%d",&n,&m);
		for (int i=0;i<=n;i++) fa[i]=i,rela[i]=0;

		bool flag=true;
		for (int i=1;i<=m;i++){
			scanf("%d%d",&u,&v);
			int uu=getfather(u),vv=getfather(v);
			if (uu==vv){
				flag=false;
				continue;
			}
			fa[uu]=vv;
			rela[uu]=(rela[v]+1-rela[u]+2)%2;
		}
		if (n<=1){
			puts("Poor wyh");
			continue;
		}

		memset(cnt,0,sizeof(cnt));
		for (int i=1;i<=n;i++){
			cnt[getfather(i)][rela[i]]++;
		}
		int ans=0;
		for (int i=1;i<=n;i++){
			int Max=0;
			if (fa[i]==i){
				Max=max(cnt[i][0],cnt[i][1]);
			}
			ans+=Max;
		}
	
		if (flag) printf("%d %d\n",ans,n-ans);
		else puts("Poor wyh");
	}
	return 0;
}
