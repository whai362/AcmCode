#include<iostream>
#include<cstdio>
using namespace std;
struct jewelry{
	int w,d;
}jew[3500];
int dp[13000];
int main(){
	int bound,i,j,n,m,sum;
	scanf("%d%d",&n,&m);
	sum=0;
	for(i=0;i<n;++i){
		scanf("%d%d",&jew[i].w,&jew[i].d);
		sum+=jew[i].w;
	}
	for(i=0;i<n;++i){
		bound=max(m-sum,jew[i].w);
		for(j=m;j>=bound;--j){
			dp[j]=max(dp[j],dp[j-jew[i].w]+jew[i].d);
		}
		sum-=jew[i].w;
	}
	printf("%d\n",dp[m]);
	return 0;
}
