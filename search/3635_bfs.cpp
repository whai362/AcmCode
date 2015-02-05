#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int INF=0x3f3f3f3f;
int p[1005],
	dp[1005][105];
bool vis[1005][105];
struct Data{
	int v,d;
	Data(){}
	Data(int _v,int _d){
		v=_v;
		d=_d;
	}
};
struct Qnode{
	int u,d,c;
	Qnode(){}
	Qnode(int _u,int _d,int _c){
		u=_u;
		d=_d;
		c=_c;
	}
	bool operator < (const Qnode &a) const{
		return a.c<c;
	}
};
vector<Data> _map[1005];
int c,s,t;
void gao(){
	memset(dp,0x3f,sizeof(dp));
	memset(vis,0,sizeof(vis));
	priority_queue<Qnode> q;
	dp[s][0]=0;
	q.push(Qnode(s,0,0));
	while(!q.empty()){
		Qnode now=q.top();
		q.pop();
		vis[now.u][now.d]=true;
		if(now.u==t){
			printf("%d\n",now.c);
			return ;
		}
		if(now.d+1<=c && !vis[now.u][now.d+1] && dp[now.u][now.d+1]>dp[now.u][now.d]+p[now.u]){
			dp[now.u][now.d+1]=dp[now.u][now.d]+p[now.u];
			q.push(Qnode(now.u,now.d+1,dp[now.u][now.d+1]));
		}
		for(int i=0;i<_map[now.u].size();++i){
			Data ch=_map[now.u][i];
			if(now.d>=ch.d && !vis[ch.v][now.d-ch.d] && dp[ch.v][now.d-ch.d]>now.c){
				dp[ch.v][now.d-ch.d]=now.c;
				q.push(Qnode(ch.v,now.d-ch.d,now.c));
			}
		}
	}
	puts("impossible");
	return ;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i){
		scanf("%d",&p[i]);
	}
	int u,v,d;
	for(int i=0;i<m;++i){
		scanf("%d%d%d",&u,&v,&d);
		_map[u].push_back(Data(v,d));
		_map[v].push_back(Data(u,d));
	}
	int q;
	scanf("%d",&q);
	while(q--){
		scanf("%d%d%d",&c,&s,&t);
		gao();
	}
	return 0;
}
