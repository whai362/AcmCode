#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5+5;
#define LL __int64
LL a[N],b[N];
bool cmp(LL a,LL b){
	return a>b;
}
void gao(int n,int m){
	sort(a,a+n,cmp);
	sort(b,b+m);
	LL ans=0;
	for(int i=0;i<min(n,m);++i){
		if(a[i]-b[i]>=0){
			ans+=a[i]-b[i];
		}
	}
	printf("%I64d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;++i){
			scanf("%I64d",&a[i]);
		}
		for(int i=0;i<m;++i){
			scanf("%I64d",&b[i]);
		}
		gao(n,m);
	}
	return 0;
}
