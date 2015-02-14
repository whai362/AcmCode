#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
#define LL __int64
LL fac[2*100005],tot,ans[2*100005],cnt;
int main(){
	LL n;
	int cas=0;
	while(scanf("%I64d",&n)!=EOF){
		tot=0;
		LL lim=sqrt(n);
		for(int i=1;i<=lim;++i){
			if(n%i==0){
				fac[tot++]=i;
				if(n/i!=i) fac[tot++]=n/i;
			}
		}
		cnt=0;
		for(int i=0;i<tot;++i){
			LL tmp=n-fac[i];
			if(tmp==0) continue;
			if((n^tmp)==__gcd(n,tmp)) ans[cnt++]=tmp;
		}
		sort(ans,ans+cnt);
		printf("Case #%d:\n%I64d\n",++cas,cnt);
		if(cnt) printf("%I64d",ans[0]);
		for(int i=1;i<cnt;++i){
			printf(" %I64d",ans[i]);
		}
		puts("");
	}
	return 0;
}
