#include<stdio.h>
#include<algorithm>
using namespace std;
short dp[1002][1002];
bool hash[10002];
void lcs(int a[],int n1,int b[],int n2){
	int i,j;
	dp[0][0]=0;
	for(i=1;i<=n1;++i) dp[i][0]=0;
	for(i=1;i<=n2;++i) dp[0][i]=0;
	for(i=1;i<=n1;++i)
	  for(j=1;j<=n2;++j){
		  if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+1;
		  else if(dp[i-1][j]>dp[i][j-1]) dp[i][j]=dp[i-1][j];
		  else dp[i][j]=dp[i][j-1];
	  }
}
int main(){
	int i,n1,n2,a[1002],b[1002];
	scanf("%d",&n1);
	n2=0;
	for(i=0;i<n1;++i){
		scanf("%d",&a[i]);
		if(!hash[a[i]]) b[n2++]=a[i],hash[a[i]]=1;
	}
	sort(b,b+n2);
	lcs(a,n1,b,n2);
	printf("%d\n",dp[n1][n2]);
	return 0;
}
