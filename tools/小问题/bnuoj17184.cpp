/*bnuoj 17184
  题意：
  现有N个未知数A[1],A[2],…A[N]，以及M个方程，每个方程都是形如A[s]+A[s+1]+A[s+2]+…A[t-1]+A[t]=c。现在求解这个方程组。
  限制：
  1 <= n,m <= 1e5; 1 <= s,t <= N; 0 <= c < 1e9
  思路：
  带权并查集。
 */
#include<iostream>
#include<cstdio>
using namespace std;
#define LL long long
const int N=1e5+5;
int fa[N];
LL rk[N];
int getFa(int x){
	if(x!=fa[x]){
		int old=fa[x];
		fa[x]=getFa(fa[x]);
		rk[x]+=rk[old];
		return fa[x];
	}
	return x;
}
bool istrue(int x,int y,LL c){
	int fx=getFa(x);
	int	fy=getFa(y);
	if(fx!=fy) return true;
	else{
		if(rk[y]+c==rk[x]) return true;
		return false;
	}
}
void Union(int x,int y,LL c){
	int fx=getFa(x);
	int	fy=getFa(y);
	if(fx==fy) return ;
	else if(fx>fy){
		fa[fx]=fy;
		rk[fx]=c+rk[y]-rk[x];
	}
	else{
		fa[fy]=fx;
		rk[fy]=rk[x]-c-rk[y];
	}
}
void isknown(int x){
	int y=x+1;
	int fx=getFa(x);
	int fy=getFa(y);
	if(fx!=fy) puts("Unknown!");
	else printf("%lld\n",rk[x]-rk[y]);
}
void init(int n){
	for(int i=1;i<=n;++i){ fa[i]=i; rk[i]=0; }
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	init(n);
	for(int i=0;i<m;++i){
		int s,t;
		LL c;
		scanf("%d%d%lld",&s,&t,&c);
		++t;
		if(istrue(s,t,c)){
			Union(s,t,c);
			puts("Accepted!");
		}
		else puts("Error!");
	}
	for(int i=1;i<=n;++i){
		isknown(i);
	}
	return 0;
}
