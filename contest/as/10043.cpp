#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>
#include <iomanip>
#define INF 0x3f3f3f3f
#define LL __int64
#define Maxm 3000
#define Maxn 60
#define mod 1000000007
using namespace std;
struct Edge {
	int to, next;
} edge[Maxm * 2];
int en, head[Maxn];
int rid[Maxn];
inline void add_edge(int u, int v) {
	edge[en].to = v, edge[en].next = head[u], head[u] = en++;
}
double dp[10500][60];
int main(){
	int cases;
	int n,m,d;
	int u,v;
	scanf("%d",&cases);
	while (cases--){
		scanf("%d%d%d",&n,&m,&d);
		memset(head,-1,sizeof(head));
		en=0;
		memset(rid,0,sizeof(rid));
		for (int i=1;i<=m;i++){
			scanf("%d%d",&u,&v);
			add_edge(u,v);
			add_edge(v,u);
			rid[u]++;
			rid[v]++;
		}
		for (int k=1;k<=n;k++){
			memset(dp,0,sizeof(dp));
			double ans=0;
			for (int i=1;i<=n;i++){
				dp[0][i]=1.0/n;
			}
			for (int i=0;i<=d;i++){
				ans+=dp[i][k];
				dp[i][k]=0;
				for (int j=1;j<=n;j++){
					for (int p=head[j];p!=-1;p=edge[p].next){
						int to=edge[p].to;
						dp[i+1][to]+=dp[i][j]/rid[j];
					}
				}
			}
			printf("%.10lf\n",fabs(1.0-ans));
		}
	}
	return 0;
}

