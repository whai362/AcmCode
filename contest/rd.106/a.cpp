#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#include<vector>
using namespace std;
#define N 10005
#define INF 0x3f3f3f3f
int n;
int d[N],dis[N],vis[N],w[N];
vector<int> _map[N];
int main(){
	int i,j;
	while(scanf("%d",&n)!=EOF){
		memset(d,0,sizeof(d));
		memset(dis,0,sizeof(dis));
		memset(vis,0,sizeof(vis));
		for(i=1;i<=n;++i){
			int v;
			scanf("%d%d",&w[i],&d[i]);
			for(j=0;j<d[i];++j){
				scanf("%d",&v);
				_map[v].push_back(i);
			}
		}
		stack<int> s;
		for(i=1;i<=n;++i){
			if(!d[i]){
				vis[i]=1;
				s.push(i);
			}
		}
		while(!s.empty()){
			int u=s.top();
			s.pop();
			int sz=_map[u].size();
			for(i=0;i<sz;++i){
				int next=_map[u][i];
				--d[next];
				dis[next]=max(dis[next],dis[u]+w[u]);
				if(!vis[next] && !d[next]){
					vis[next]=1;
					s.push(next);
				}
			}
		}
		int ans=0;
		for(i=1;i<=n;++i){
			if(_map[i].size()==0){
				ans=max(ans,dis[i]+w[i]);
				//end=i;
				//break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

