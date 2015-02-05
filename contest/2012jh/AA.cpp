#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
#define LL __int64
const int N=100005,
	  INF=1e30;
struct Data{
	LL a,b;
}d[N];
bool cmp(Data x,Data y){
	return x.a * y.b < x.b * y.a;
}
int main(){
	int n;
	while(~scanf("%d",&n) , n){
		for(int i=1;i<=n;i++){
			scanf("%I64d%I64d",&d[i].a,&d[i].b);
		}
		sort(d+1,d+n+1,cmp);
		LL ans=0;
		for(int i=0;i<n;++i){
			ans+=ans*d[i].b+d[i].a;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
