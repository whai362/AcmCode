#include <cstdio>
using namespace std;
#define MOD 1000000000
long long dp[1000005];
int main(){
	dp[0]=0;
	dp[1]=1;
	for(int i=2;i<=1000000;i++){
		if(i%2==0){
			dp[i]=dp[i/2]+dp[i-1];
			dp[i]%=MOD;
		}
		else{
			dp[i]=dp[(i-1)/2]+dp[i-2];
			dp[i]%=MOD;
		}
	}
	int n;
	while(scanf("%d",&n)!=EOF){
		printf("%d\n",dp[n]);
	}
	return 0;
}
