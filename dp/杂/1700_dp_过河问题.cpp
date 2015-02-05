//第一种：过河时间最少的人来回接送其他人
//第二种：过河时间最少和次少的人来回接送其他人,如第1个人接第i-1个和第i个人，然后让第i-1个和第i个人一块过河，第2个人再接送第1个人
#include<stdio.h>
#include<algorithm>
using namespace std;
int a[1010],dp[1010];
int main(){
	int i,min1,min2,n,t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=0;i<n;++i) scanf("%d",&a[i]);
		sort(a,a+n);
		dp[0]=a[0];
		dp[1]=a[1];
		for(i=2;i<n;++i){
			min1=dp[i-1]+a[0]+a[i];
			min2=dp[i-2]+a[0]+a[i]+2*a[1];
			dp[i]=(min1<min2? min1:min2);
		}
		printf("%d\n",dp[n-1]);
	}
	return 0;
}
