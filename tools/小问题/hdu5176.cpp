/*hdu 5176 The Experience of Love
  题目：
  一个叫Gorwin的女孩和一个叫Vivin的男孩是一对情侣。他们来到一个叫爱情的国家，这个国家由N个城市组成而且只有N-1条小道(像一棵树)，每条小道有一个值表示两个城市间的距离。他们选择两个城市住下，Gorwin在一个城市Vivin在另外一个，第一次约会，Gorwin去找Vivin，她会写下路径上最长的一条小道(maxValue)，第二次约会，Vivin去找Gorwin，他会写下路径上最短的一条小道(minValue)，然后计算maxValue减去minValue的结果作为爱情经验值，再然后重新选择两个城市居住而且计算新的爱情经验值，重复一次又一次。
  当他们选择过所有的情况后，请帮助他们计算一下爱情经验值的总和。
  限制：
  1 < N <= 150000; 1 <= a,b <= N; 1 <= c <= 1e9
  思路：
  1. 按边考虑，看一条边被算作最大值多少次，算作最小值多少次。
  2. 以最大值为例：先把边从小到大排序，从小到大往图里加边，每次加边(u,v,w)前，看与u相连的有多少个点(设有t1个点)，与v相连的有多少个点(设有t2个点)(这里可以用并查集来实现)，t1*t2就是这条边被算作最大值多少次了。
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
using namespace std;
#define LL __int64
#define ULL unsigned __int64
const int N=150005;
struct Edge{
	int fr,to,w;
	Edge(){}
	Edge(int _fr,int _to,int _w){
		fr=_fr;
		to=_to;
		w=_w;
	}
}e[N];
bool cmp1(Edge a,Edge b){
	return a.w<b.w;
}
bool cmp2(Edge a,Edge b){
	return a.w>b.w;
}
int fa[N],cnt[N];
int stk[3*N],top;
int getFa(int x){
	top=-1;
	while(x!=fa[x]){ stk[++top]=x; x=fa[x]; }
	int now=x;
	while(top>=0){ now=stk[top--]; fa[now]=x; }
	return fa[now];
}
void init(int n){
	for(int i=0;i<=n;++i){
		fa[i]=i;
		cnt[i]=1;
	}
}
void gao(int n){
	ULL ans=0;
	init(n);
	sort(e,e+n-1,cmp1);
	for(int i=0;i<n-1;++i){
		int fx=getFa(e[i].fr);
		int fy=getFa(e[i].to);
		ans+=(ULL)cnt[fx]*cnt[fy]*e[i].w;
		cnt[fx]+=cnt[fy];
		fa[fy]=fx;
	}
	init(n);
	sort(e,e+n-1,cmp2);
	for(int i=0;i<n-1;++i){
		int fx=getFa(e[i].fr);
		int fy=getFa(e[i].to);
		ans-=(ULL)cnt[fx]*cnt[fy]*e[i].w;
		cnt[fx]+=cnt[fy];
		fa[fy]=fx;
	}
	printf("%I64u\n",ans);
}
int main(){
	int n;
	int cas=0;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n-1;++i)
			scanf("%d%d%d",&e[i].fr,&e[i].to,&e[i].w);
		printf("Case #%d: ",++cas);
		gao(n);
	}
	return 0;
}
