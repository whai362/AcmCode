#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
#define C 210005
#define MOD 1000000007
int cnt[C],b[15];
long long a[15],dp[5][C];
int main(){
	int n,c;
	int i,j;
	scanf("%d%d",&n,&c);
	memset(dp,0,sizeof(dp));
	for(i=0;i<n;++i){
		scanf("%lld%d",&a[i],&b[i]);
	}
	for(i=0;i<n;++i){
		dp[i][0]=1;
	}
	for(i=0;i<n;++i){
		//cout<<"!"<<endl;
		memset(cnt,0,sizeof(cnt));
		for(j=0;j<=c;++j){
			if(i>0)
				dp[i][j]=dp[i-1][j];
			if(j>=a[i] && cnt[j-a[i]]<b[i]){
				dp[i][j]=(dp[i][j]+dp[i][j-a[i]])%MOD;
				cnt[j]=cnt[j-a[i]]+1;
			}
		}
		for(j=0;j<=10;++j){
			cout<<dp[i][j]<<' ';
		}
		cout<<endl;
	}
	//printf("%lld\n",dp[1][10]);
	return 0;
}
