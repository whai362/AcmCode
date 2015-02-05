#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
#define pb push_back
const int N=20005,
	  INF=0x3f3f3f3f;
vector<int> _map[N];
int n,
	sum[N],_max[N];
int dfs(int u,int fa){
	sum[u]=1;
	_max[u]=0;
	for(int i=0;i<_map[u].size();++i){
		int to=_map[u][i];
		if(to!=fa){
			int tmp=dfs(to,u);
			sum[u]+=tmp;
			_max[u]=max(_max[u],tmp);
		}
	}
	return sum[u];
}
void gao(){
	dfs(1,0);
	int ans=INF,rt;
	for(int i=1;i<=n;++i){
		_max[i]=max(_max[i],n-sum[i]);
		//cout<<'!'<<i<<' '<<_max[i]<<endl;
		if(ans>_max[i]){
			rt=i;
			ans=_max[i];
		}
	}
	printf("%d %d\n",rt,ans);
}
int main(){
	int u,v,T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<=n;++i){
			_map[i].clear();
		}
		for(int i=0;i<n-1;++i){
			scanf("%d%d",&u,&v);
			_map[u].pb(v);
			_map[v].pb(u);
		}
		gao();
	}
	return 0;
}
