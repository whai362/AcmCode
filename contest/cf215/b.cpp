#include<cstdio>
using namespace std;
#define N 100005
bool hash[N];
int a[N],l[N],dp[N];
int main(){
	int i,n,m;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)
	  scanf("%d",&a[i]);
	dp[n]=1;
	hash[a[n]]=1;
	for(i=n-1;i>0;--i){
		if(!hash[a[i]]){
			dp[i]=dp[i+1]+1;
			hash[a[i]]=1;
		}
		else dp[i]=dp[i+1];
	}
	for(i=0;i<m;++i)
	  scanf("%d",&l[i]);
	for(i=0;i<m;++i)
	  printf("%d\n",dp[l[i]]);
	return 0;
}
