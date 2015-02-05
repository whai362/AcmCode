/*题意：求割点，并求出去掉每个割点图会被分成几个连通分支。
分析：求割点除了tarjan算法，还有一种O(n^2)的算法，就是分别把每个点作为根，进行dfs，看根有几个子结点，如果大于一个则为割点否则不是割点。本题就是观察每个点为根时有几个子结点，去掉该点后的连通分支数等于其子结点数。*/

#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
const int N=1005;
int tot;
int dfn[N],low[N],sub[N];
vector<int> _map[N];
void dfs(int rt,int fa){
	low[rt]=dfn[rt]=++tot;
	int sz=_map[rt].size();
	for(int i=0;i<sz;++i){
		int v=_map[rt][i];
		if(v!=fa){
			if(!dfn[v]){
				dfs(v,rt);
				low[rt]=min(low[rt],low[v]);
				if(low[v]>=dfn[rt]){
					++sub[rt];
				}
			}
			else{
				low[rt]=min(low[rt],dfn[v]);
			}
		}
	}
}
int main(){
	int n,cas=1,u,v;
	while(scanf("%d",&u) && u){
		n=tot=0;
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		memset(sub,0,sizeof(sub));
		for(int i=0;i<N;++i){
			_map[i].clear();
		}
		scanf("%d",&v);
		_map[u].push_back(v);
		_map[v].push_back(u);
		n=max(n,max(u,v));
		while(scanf("%d",&u) && u){
			scanf("%d",&v);
			_map[u].push_back(v);
			_map[v].push_back(u);
			n=max(n,max(u,v));
		}
		dfs(1,-1);
		printf("Network #%d\n", cas++);
		--sub[1];
		bool flag=0;
		for(int i=1;i<=n;++i){
			if(sub[i]>=1){
				printf("  SPF node %d leaves %d subnets\n", i, sub[i]+1);
                flag = 1;
			}
		}
		if(!flag){
			printf("  No SPF nodes\n");
		}
		printf("\n");
	}
	return 0;
}
