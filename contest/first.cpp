#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1e5+5;
int fa[N],r[N];

int get_fa(int x){
	if(x!=fa[x]){
		int fa_x=fa[x];
		fa[x]=get_fa(fa[x]);
		r[x]=r[fa_x]^r[x];
		return fa[x];
	}
	return x;
}
bool my_union(int u,int v){
	int fu=get_fa(u);
	int fv=get_fa(v);
	if(fu==fv){
		if(r[u]!=r[v]) return true;
		else return false;
	}
	fa[fv]=fu;
	r[fv]=(r[u]^r[v])^1;
	return true;
}
int cnt[N][2];
void init(int n){
	for(int i=1;i<=n;++i){
		fa[i]=i;
		r[i]=0;
	}
	memset(cnt,0,sizeof(cnt));
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		init(n);
		int flag=1;
		for(int i=0;i<m;++i){
			int u,v;
			scanf("%d%d",&u,&v);
			if(!my_union(u,v)){
				flag=0;
			}
		}
		if(flag==0){
			puts("Poor wyh");
			continue;
		}
		for(int i=1;i<=n;++i){
			int fx=get_fa(i);
			++cnt[fx][r[i]];
		}
		int ans=0;
		for(int i=1;i<=n;++i){
			ans+=max(cnt[i][0],cnt[i][1]);
		}
		if(n<=1){
			puts("Poor wyh");
			continue;
		}
		if(m==0) --ans;
		printf("%d %d\n",ans,n-ans);
	}
	return 0;
}
