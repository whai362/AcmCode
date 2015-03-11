#include<iostream>
#include<cstdio>
using namespace std;
int dp[100][100];
int main(){
	dp[1][0]=1;
	for(int i=2;i<10;++i){
		int sum=0;
		for(int j=0;j<=i;++j){
			sum+=dp[i-1][j];
			dp[i][j]=sum;
		}
	}
	for(int i=1;i<10;++i){
		for(int j=0;j<i;++j){
			cout<<dp[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}
