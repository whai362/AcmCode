#include<iostream>
#include<cstdio>
#include<map>
#include<queue>
using namespace std;
const int INF=0x3f3f3f3f;
#define LL __int64
struct Dt{
	int t,l;
	LL v;
}a[35];
struct Nd{
	int t,st;
	LL w;
	Nd(){}
	Nd(LL _w,int _t,int _st){
		w=_w; t=_t; st=_st;
	}
};
const int N=1e5+5;
queue<Nd> q;
map<int,int> mp;
void init(){
	mp.clear();
}
int main(){
	int n;
	LL w;
	while(scanf("%d%I64d",&n,&w)!=EOF){
		init();
		int ans=INF;
		for(int i=0;i<n;++i){
			scanf("%d%I64d%d",&a[i].t,&a[i].v,&a[i].l);
			int t=max(a[i].t,a[i].l);
			if(a[i].v>=w) ans=min(ans,t);
			else{
				mp[(1<<i)]=t;
				q.push(Nd(a[i].v,t,(1<<i)));
			}
		}

		if(w==0){ puts("0"); continue; }
		while(!q.empty()){
			Nd now=q.front();
			q.pop();
			for(int i=0;i<n;++i){
				if(((1<<i) & now.st)!=0) continue;
				int t=max(now.t+a[i].t,a[i].l);
				if(now.w+a[i].v>=w) ans=min(ans,t);
				else{
					int st=now.st|(1<<i);
					int tmp=mp[st];
					if(tmp==0 || tmp>t){
						mp[st]=t;
						q.push(Nd(now.w+a[i].v,t,st));
					}
				}
			}
		}
		if(ans==INF) puts("zhx is naive!");
		else printf("%d\n",ans);
	}
	return 0;
}
