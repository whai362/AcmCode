#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define LL long long
#define PB push_back
const int N=1e5+5;
int a[N];
vector<int> E[N];
LL deal(int fa,int rt){
	LL ret=0;
	for(int i=0;i<E[rt].size();++i){
		int ch=E[rt][i];
		if(ch==fa) continue;
		ret+=deal(rt,ch);
	}
	ret+=a[rt];
	return ret;

}
void gao(int s){
	LL ans=0;
	for(int i=0;i<E[s].size();++i){
		ans=max(ans,deal(s,E[s][i]));
	}
	printf("%lld\n",ans);
}
void init(int n){
	for(int i=0;i<=n;++i){
		E[i].clear();
	}
}
int main(){
	int T;
	int n;
	int cas=0;
	scanf("%d",&T);
	while(T--){
		int n,s;
		scanf("%d%d",&n,&s);
		init(n);
		for(int i=0;i<n-1;++i){
			int u,v;
			scanf("%d%d",&u,&v);
			E[u].PB(v);
			E[v].PB(u);
		}
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
		}
		printf("Case #%d: ",++cas);
		gao(s);
	}
	return 0;
}
