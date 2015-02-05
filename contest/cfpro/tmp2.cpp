#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<vector>
#include<queue>
#include<string>
#include<sstream>
#define eps 0.000001
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define MOD 1000000007
using namespace std;
typedef long long LL;
int i,j,k,n,m,x,y,T,ans,big,cas,dp[2][200005],h,a,b,num[900],u,v;
bool flag;
int main()
{
	scanf("%d%d",&a,&b);
	//h=(int)((sqrt(1+8*(a+b))-1)/2+eps)
	for (h=0;(h+1)*(h+2)/2<=a+b;h++);
	if (a>0) dp[0][1]=1; else dp[0][1]=0;
	if (b>0) dp[0][0]=1; else dp[0][0]=0;
	
	
	for (i=2,num[1]=1;i<=h;i++) num[i]+=num[i-1]+i; 
	for (i=2;i<=h;i++)
	{
		u=(i+1)%2;v=u^1;
		for (j=max(num[i]-b,0);j<=min(a,num[i]);j++)
		{
			dp[u][j]=dp[v][j];
			if (j>=i) dp[u][j]=(dp[u][j]+dp[v][j-i])%MOD;
		}
	}
	
	ans=0;u=(h+1)%2;
	for (i=max(num[h]-b,0);i<=min(a,num[h]);i++)
	{
		ans=(ans+dp[u][i])%MOD;
	}
	cout<<ans<<endl;
	//cout<<maxj<<endl;
	return 0;
}
