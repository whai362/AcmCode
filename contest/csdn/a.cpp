#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MOD=1000000007;
#define LL __int64
int gcd(int a,int b){
	if(a==0) return b;
	return gcd(b%a,a);
}
LL dp[109][109][109];
LL gao(int n,int m){
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;++i){
		dp[0][i][i]=1;
	}
	for(int i=1;i<m;++i){
		for(int j=1;j<=n;++j){
			for(int k=1;k<=n;++k){
				for(int l=1;l<=n;++l){
					if(dp[i-1][k][l]==0) continue;
					if(l+j>n) break;
					dp[i][gcd(j,k)][l+j]=(dp[i][gcd(j,k)][l+j]+dp[i-1][k][l])%MOD;
					//cout<<i<<' '<<__gcd(j,k)<<' '<<l+j<<' '<<dp[i][__gcd(j,k)][l+j]<<endl;
				}
			}
		}
	}
	return dp[m-1][1][n];
}
LL sl(int n,int m){
	return dp[m-1][1][n];
}
int main(){
	//cout<<gcd(15,20)<<endl;
	gao(105,105);
	int n,m;
	while(cin>>n>>m){
		cout<<sl(n,m)<<endl;
	}
	//for(int i=1;i<=108;++i){
	//	for(int j=1;j<=108;++j){
	//		cout<<sl(i,j)<<',';
	//		//cerr<<i<<' '<<j<<endl;
	//	}
	//	cout<<endl;
	//}
	return 0;
}
