#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
#define LL long long
#define PB push_back
const int N=1e5+5;
int a[N];
LL s[N];
vector<int> G[N];
LL _abs(LL x){
	if(x<0) return -x;
	return x;
}
LL dfs(int fa, int rt){
	for(int i=0;i<G[rt].size();++i){
		int ch=G[rt][i];
		if(ch==fa) continue;
		s[rt]+=dfs(rt, ch);
	}
	s[rt]+=a[rt];
	return s[rt];
}
void gao(int n){
	dfs(0, 1);
	LL sum=0;
	for(int i=1;i<=n;++i){
		sum+=a[i];
	}
	LL ans=_abs(sum-s[1]-s[1]);
	for(int i=2;i<=n;++i){
		ans=min(ans, _abs(sum-s[i]-s[i]));
	}
	printf("%lld\n", ans);
}
void init(int n){
	for(int i=0;i<=n;++i)
		G[i].clear();
	memset(s, 0, sizeof(s));
}
int main(){
	int n, m, Cas = 1;
	while(scanf("%d%d", &n, &m)&& (n||m)){
		printf("Case %d: ", Cas ++);
		init(n);
		for(int i=1;i<=n;++i)
			scanf("%d", &a[i]);
		int u, v;
		for(int i=0;i<m;++i){
			scanf("%d%d", &u, &v);
			G[u].PB(v);
			G[v].PB(u);
		}
		gao(n);
	}
	return 0;
}
