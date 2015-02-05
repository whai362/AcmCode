#include<iostream>
#include<cstdio>
using namespace std;
#define LL __int64
const int N=447005,
	  MOD=1000000007;
LL a;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
	int n;
	scanf("%d",&n);
	LL ans=0;
	for(int i=0;i<n;++i){
		scanf("%I64d",&a);
		ans=(ans+a*(n-i)*(i+1))%MOD;
	}
	printf("%I64d\n",ans);
	}
	return 0;
}
