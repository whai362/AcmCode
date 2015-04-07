#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
struct Dt{
	int v,w;
	Dt(){};
	Dt(int _v,int _w){
		v=_v;
		w=_w;
	}
};
vector<Dt> G[100005];
int ys;
int ans=0;
int _max=0;
int a[100005];
int gao(int u){
	if(u>=ys){
		return a[u-2];
	}
	int l=gao(G[u][0].v);
	int r=gao(G[u][1].v);
	if(l<r) swap(l,r);
	ans+=l-r;
	return l+a[u-2];
}
int main(){
	int n;
	scanf("%d",&n);
	int m=((1<<(n+1))-2);
	int V=((1<<(n+1))-1);
	ys=(1<<n);
	for(int i=0;i<m;++i){
		scanf("%d",&a[i]);
		int u=(i+2)/2,v=i+2;
		G[u].push_back(Dt(v,a[i]));
	}
	gao(1);
	printf("%d\n",ans);

	return 0;
}
