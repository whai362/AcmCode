#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
#define N 100005
const long long INF=(long long)1e18;
bool vis[N];
int du[N];
long long ans,tot;
long long st[N],sum[N];
vector<int> tree[N];
long long pt(int rt){
	vis[rt]=true;
	int sz=tree[rt].size();
	sum[rt]=st[rt];
	for(int i=0;i<sz;++i){
		if(!vis[tree[rt][i]]){
			//cout<<tree[rt][i]<<endl;
			sum[rt]+=pt(tree[rt][i]);
		}
	}
	return sum[rt];
}
void dfs(int rt){
	vis[rt]=true;
	int sz=tree[rt].size();
	long long tmp=tot-2*sum[rt];
	if(tmp<0) tmp=-tmp;
	ans=min(ans,tmp);
	for(int i=0;i<sz;++i){
		if(!vis[tree[rt][i]])
			dfs(tree[rt][i]);
	}
}
int main(){
	int cas=0,n,m,rt;
	int i;
	while(scanf("%d%d",&n,&m) && (n || m)){
	ans=INF,tot=0;
	for(i=1;i<=n;++i){
		scanf("%lld",&st[i]);
		tot+=st[i];
	}
	for(i=1;i<=n;++i)
		tree[i].clear();
	memset(du,0,sizeof(du));
	memset(sum,0,sizeof(sum));
	for(i=0;i<m;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		tree[u].push_back(v);
		tree[v].push_back(u);
		++du[u];
		++du[v];
	}
	for(i=1;i<=n;++i){
		if(du[i]==1){
			rt=i;
			break;
		}
	}
	memset(vis,0,sizeof(vis));
	pt(rt);
	/*for(i=1;i<=n;++i){
		cout<<'!'<<i<<' '<<sum[i]<<endl;
	}*/
	memset(vis,0,sizeof(vis));
	dfs(rt);
	printf("Case %d: %lld\n",++cas,ans);
	}
	return 0;
}
