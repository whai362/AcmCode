#include<iostream>
#include<cstdio>
using namespace std;
#define LL __int64
const int N=1e5+5;
int mu[N];
//O(nlog(n))
void getMu(){
	for(int i=1;i<N;++i){
		int target=i==1?1:0;
		int delta=target-mu[i];
		mu[i]=delta;
		for(int j=2*i;j<N;j+=i)
			mu[j]+=delta;
	}
}

int main(){
	int T,cas=0;
	int a,b,c,d,k;
	getMu();
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		printf("Case %d: ",++cas);
		if(k==0){
			puts("0");
			continue;
		}
		b/=k;
		d/=k;
		if(b>d) swap(b,d);
		LL ans1=0;
		for(int i=1;i<=b;++i)
			ans1+=(LL)mu[i]*(b/i)*(d/i);
		LL ans2=0;
		for(int i=1;i<=b;++i)
			ans2+=(LL)mu[i]*(b/i)*(b/i);
		ans1-=ans2/2;
		printf("%I64d\n",ans1);
	}
	return 0;
}
