//f(n,m+1)=(n-2)f(n,m)+(n-1)f(n,m-1)
#include<cstdio>
#include<iostream>
using namespace std;
const int M=10000;
int dp[10005][10];
int main(){
	dp[3][1]=3;
	dp[3][2]=6;
	for(int i=3;i<=10;++i)
		for(int j=3;j<10005;++j){
			dp[i][j]=(((i-2)*dp[i][j-1])+((i-2)*dp[i][j-2]))%M;
		}
	int T;
	scanf("%d",&T);
	int n,m;
	while(T--){
		scanf("%d%d",&n,&m);
		printf("%d\n",dp[m][n]);
	}
	return 0;
}
