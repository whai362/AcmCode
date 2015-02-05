#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
#define N 160005
long long a[N],dp[N];
int pre[N];
int main(){
	int n,l,r;
	int i,j;
	while(scanf("%d%d%d",&n,&l,&r)!=EOF){
	for(i=0;i<=n;++i){
		cin>>a[i];
		//scanf("%d",&a[i]);
	}
	dp[0]=a[0];
	for(i=1;i<=n;++i){
		dp[i]=-100*160005*1000;
	}
	memset(pre,0,sizeof(pre));
	for(i=0;i<=n;++i){
		for(j=i+l;j<=i+r && j<=n;++j){
			if(dp[j]<dp[i]+a[j]){
				dp[j]=dp[i]+a[j];
				pre[j]=i;
			}
		}
	}
	long long _max=-100*160005*1000;
	int end;
	for(i=n-(r-l+1)+1;i<=n;++i){
		if(dp[i]>_max) _max=dp[i],end=i;
	}
	printf("%d\n",dp[end]);
	int cnt=0,ans[N];
	ans[cnt++]=end;
	int tmp=pre[end];
	while(tmp){
		ans[cnt++]=tmp;
		tmp=pre[tmp];
	}
	printf("0 ");
	for(i=cnt-1;i>=0;--i){
		printf("%d ",ans[i]);
	}
	printf("-1\n");
	}
	return 0;
}
