#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define LL __int64
const int N=100005;
const LL MOD=365*24*60*60;
struct Data{
	LL a,b;
	double c;
}d[N];
bool cmp(Data a,Data b){
	return a.a*(b.b-1)<b.a*(a.b-1);
}
int main(){
	int n;
	while(scanf("%d",&n) && n){
		for(int i=0;i<n;++i){
			scanf("%I64d%I64d",&d[i].a,&d[i].b);
		}
		sort(d,d+n,cmp);
		LL ans=0;
		for(int i=0;i<n;++i){
			ans=(ans+ans*d[i].b%MOD+d[i].a%MOD)%MOD;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
