#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define LL __int64
const int INF=0x3f3f3f3f;
const int N=35;
const int M=40000;
struct Dt{
	int t,l;
	LL v;
}a[N];
struct Nd{
	LL v;
	int t;
	Nd(){}
	Nd(LL _v,int _t){
		v=_v;
		t=_t;
	}
}b[M];
bool cmp1(Dt a,Dt b){
	if(a.l-a.t==b.l-b.t) return a.l<b.l;
	return a.l-a.t<b.l-b.t;
}
bool cmp2(Nd a,Nd b){
	return a.v<b.v;
}
int t1[35];
int cnt=0;
//bool cmp3(int i,int j){
//	return a[i].l<a[j].l;
//}
Nd deal(int st,int n){
	cnt=0;
	for(int i=0;i<n;++i){
		if(((1<<i) & st)!=0) t1[cnt++]=i;
	}
	//sort(t1,t1+cnt,cmp3);
	Nd ret;
	ret.v=0,ret.t=0;
	for(int i=0;i<cnt;++i){
		ret.v+=a[t1[i]].v;
		ret.t+=a[t1[i]].t;
		ret.t=max(ret.t,a[t1[i]].l);
	}
	return ret;
}
int gao(int st,int n,LL w,int len){
	st=(st<<(n/2));
	LL fd=0;
	cnt=0;
	for(int i=0;i<n;++i){
		if(((1<<i) & st)!=0) t1[cnt++]=i;
	}
	//sort(t1,t1+cnt,cmp3);
	for(int i=0;i<cnt;++i)
		fd+=a[t1[i]].v;
	fd=w-fd;
	int p=lower_bound(b,b+len,Nd(fd,0),cmp2)-b;
	if(p>=len) return INF;
	int ret=b[p].t;
	for(int i=0;i<cnt;++i){
		ret=ret+a[t1[i]].t;
		ret=max(ret,a[t1[i]].l);
	}
	return ret;
}
int main(){
	int n;
	LL w;
	while(scanf("%d%I64d",&n,&w)!=EOF){
		for(int i=0;i<n;++i)
			scanf("%d%I64d%d",&a[i].t,&a[i].v,&a[i].l);
		sort(a,a+n,cmp1);
		//for(int i=0;i<n;++i)
		//	cout<<a[i].t<<' '<<a[i].v<<' '<<a[i].l<<endl;
		int lim=(1<<(n/2));
		for(int i=0;i<lim;++i){
			b[i]=deal(i,n);
		}
		sort(b,b+lim,cmp2);
		//for(int i=0;i<lim;++i){
		//	cout<<b[i].v<<' '<<b[i].t<<endl;
		//}
		int _min=INF;
		for(int i=lim-1;i>=0;--i){
			_min=min(_min,b[i].t);
			b[i].t=_min;
		}
		int lim1=(1<<(n-n/2));
		int ans=INF;
		for(int i=0;i<lim1;++i){
			ans=min(ans,gao(i,n,w,lim));
		}
		if(ans==INF) puts("zhx is naive!");
		else printf("%d\n",ans);
	}
}
