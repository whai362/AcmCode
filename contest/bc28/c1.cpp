/*hdu 5168 Legal path
  题意：
  一个有向图，给定起点终点，每条边上有权值。
  一条合法的路径定义为相邻边的权值之差不小于K的路径，即路径上每条边的权值至少要比上一条边的权值大K，如果上一条边存在。合法路径的长度定义为路径上的边权值总和。
  求从起点到终点的合法路径的最短长度。
  限制：
  有多组数据，第一行为数据组数T（T≤10）。
  对于每组数据，第一行为三个整数n,m,K，n,m分别表示这组数据的有向图的点数，边数，起点为1号点，终点为n号点。
  在接下来有m行，每行有三个整数x,y,z，表示从x到y有一条权值为z的边。
  2 <= n <= 100,000
  0 <= m <= 200,000
  1 <= K,z <= 1,000,000,000
  1 <= x,y <= n
  思路：
  先把所有边按权值从小到大排序，因为权值大的边是不可能连到权值小的边上。
  然后按边更新dp数组
  
  dp[i]是一个vector，里面保存着：(原点到点i的最后一条边的权值c , 原点到点i的距离s)
  ps：这个信息应该要存在一个关系，如vector里面的信息为：
  (c1,s1),(c2,s2),...,(ci,si),...,(cj,sj)
  对于任意i<j，应该有ci<cj && si>sj，这是个关键点。

  每到一条边我们都可以知道这条边的出发点fr，到达点to，和边权c。
  然后按照边权c-k在dp[fr]中二分查找合适的信息，然后用来更新dp[to]。
  跑完m条边就能得到答案，复杂度为O(mlog(m))。
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define LL __int64
#define MP make_pair
#define PB push_back
const int N=100005;
const LL INF=(LL)0x3f3f3f3f*0x3f3f3f3f;
struct Edge{
	int fr,to;
	LL c;
	Edge(){};
	Edge(int _fr,int _to,LL _c){
		fr=_fr;
		to=_to;
		c=_c;
	}
}E[2*N];
bool cmp1(Edge a,Edge b){
	return a.c<b.c;
}
struct Dt{
	LL c,s;
	Dt(){}
	Dt(LL _c,LL _s){
		c=_c;
		s=_s;
	}
};
bool cmp2(Dt a,Dt b){
	if(a.c==b.c) return a.s>b.s;
	return a.c<b.c;
}
vector<Dt> dp[N];
int n,m,k;
void init(){
	for(int i=1;i<=n;++i)
		dp[i].clear();
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		init();
		for(int i=0;i<m;++i){
			scanf("%d%d%I64d",&E[i].fr,&E[i].to,&E[i].c);
		}
		sort(E,E+m,cmp1);
		for(int i=0;i<m;++i){
			int fr=E[i].fr,to=E[i].to;
			LL c=E[i].c;
			if(fr==1){
				if(dp[to].size()==0)
					dp[to].PB(Dt(E[i].c,E[i].c));
				else if(dp[to][dp[to].size()-1].s>E[i].c)
					dp[to].PB(Dt(E[i].c,E[i].c));
			}
			else{
				if(dp[fr].size()==0) continue;
				int p=upper_bound(dp[fr].begin(),dp[fr].end(),Dt(E[i].c-k,-INF),cmp2)-dp[fr].begin();
				if(p==0) continue;
				else if(p>0 && p<dp[fr].size()) --p;
				else if(dp[fr][dp[fr].size()-1].c<=E[i].c-k) p=dp[fr].size()-1;
				else continue;
				if(dp[to].size()==0)
					dp[to].PB(Dt(E[i].c,dp[fr][p].s+E[i].c));
				else if(dp[to][dp[to].size()-1].s>dp[fr][p].s+E[i].c)
					dp[to].PB(Dt(E[i].c,dp[fr][p].s+E[i].c));
			}
		}
		if(dp[n].size()==0) puts("-1");
		else printf("%I64d\n",dp[n][dp[n].size()-1].s);
	}
	return 0;
}
