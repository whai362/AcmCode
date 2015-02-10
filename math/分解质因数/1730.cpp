#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
#define LL __int64
int cnt[105],tot;
void gao(LL n){
	//if(n==1){ puts("1"); return ; }
	int flag=0;
	if(n<0) flag=1,n=-n;
	int lim=sqrt(n);
	tot=-1;
	memset(cnt,0,sizeof(cnt));
	for(int i=2;i<=lim;++i){
		if(n%i==0) ++tot;
		while(n%i==0) n/=i,++cnt[tot];
	}
	if(n!=1) cnt[++tot]=1;
	int ans=cnt[0];
	for(int i=0;i<=tot;++i)
		ans=__gcd(ans,cnt[i]);
	while(flag && ans%2==0) ans/=2;	//n可能是负数
	printf("%d\n",ans);
}
int main(){
	LL a;
	while(scanf("%I64d",&a) && a){
		gao(a);
	}
	return 0;
}
