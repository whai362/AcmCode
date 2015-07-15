#include<iostream>
#include<cstdio>
using namespace std;
const int N=1005;
#define LL __int64
const LL INF=100000000000LL;
LL a[N];

LL deal(int n){
	LL tmp=a[0],ret=a[0];
	for(int i=1;i<n;++i){
		tmp=tmp+a[i];
		if(tmp<a[i]){
			tmp=a[i];
		}
		ret=max(ret,tmp);
	}
	return ret;
}

void gao(int n,LL P){
	LL ans=-INF;
	for(int i=0;i<n;++i){
		LL tmp=a[i];
		a[i]=P;
		ans=max(ans,deal(n));
		a[i]=tmp;
	}
	printf("%I64d\n",ans);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		LL P;
		scanf("%d%I64d",&n,&P);
		for(int i=0;i<n;++i){
			scanf("%I64d",&a[i]);
		}
		gao(n,P);
	}
	return 0;
}
