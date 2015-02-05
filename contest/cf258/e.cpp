#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[5],dp[100],cnt[100];
int main(){
	int n,s;
	scanf("%d%d",&n,&s);
	for(int i=0;i<n;++i){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	max=a[n-1];
	for(int i=0;i<n;++i){
		memset(cnt,0,sizeof(cnt));
		for(int j=1;j<=max;++j){
			if(dp[j]>dp[j-1]+1 && cnt[j-1]+1<a[i]){
				dp[j]=dp[j-1]+1;
				cnt[j]=cnt[j-1]+1;
			}
		}
	}
}
