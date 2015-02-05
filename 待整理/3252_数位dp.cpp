#include<cstdio>
#include<iostream>
using namespace std;
long long dp[32][32];
void init(){
	for(int i=0;i<32;++i){
		dp[i][0]=dp[i][i]=1;
		for(int j=1;j<i;++j){
			dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
		}
	}
}
long long gao(int n){
    int len=0,bit[32];
	long long res=0;
    while(n){
		bit[len++]=n%2;
		n/=2;
	}
	for(int i=1;i<len-1;++i){
		for(int j=(i+2)/2;j<=i;++j){
			res+=dp[i][j];
		}
	}
	int one=1,zero=0;
	for(int i=len-2;i>=0;--i){
		if(bit[i]){
			 //如果这位是1，则如果是0，枚举低位，肯定比原数小
			++zero;
			for(int j=max(0,(len+1)/2-zero);j<=i;++j){
				res+=dp[i][j];
			}
			//统计结束后，要恢复
			--zero;
			++one;
		}
		else ++zero;
	}
	return res;
}
int main(){
	int n,m,len;
	init();
	scanf("%d%d",&n,&m);
	//cout<<gao(n)<<endl;
	cout<<gao(m+1)-gao(n)<<endl;
	return 0;
}
