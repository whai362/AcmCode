#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
#define _max 20001
int p[_max];
int dp[_max],use[_max],pre[_max];
void gao(int half,int sum,int n)
{
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	use[0]=0;
	for(int i=1;i<=n;++i){
		if(p[i]==0) continue;
		for(int j=half;j>=0;--j){
			if(dp[j]==0 && j>=p[i] && dp[j-p[i]]){
				dp[j]=1;
				use[j]=i;
				pre[j]=j-p[i];
				//if(j==9975) cout<<j<<' '<<j-p[i]<<endl;
			}
		}
	}
	int po=half;
	while(dp[po]==0) --po;
	//cout<<po<<endl;
	while(po){
		printf("%d ",use[po]);
		po=pre[po];
		//cout<<po<<endl;
	}
	puts("");
}
int main()
{
	int n;
	double num[105];
	while(scanf("%d", &n), n)
	{
		double sum = 0;
		for(int i = 1;i <= n;i++)
		{
			scanf("%lf", &num[i]);
			sum += num[i];
		}
		double k = (_max-1)/sum;
		int _sum=0,_half;
		for(int i = 1;i <= n;i++){
			p[i] = k * num[i];
			_sum = _sum + p[i];
		}
		_half = _sum / 2;
		gao(_half,_sum,n);
	}
	return 0;
}
