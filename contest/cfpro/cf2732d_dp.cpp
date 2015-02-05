#include<iostream>
#include<cstdio>
#include<cstring>
//#include<ctime>
using namespace std;
#define LL __int64
const int N=200005,
	  MOD=1e9+7;
LL dp[20][N];
LL QM(LL x){
	if(x>=MOD) return x-MOD;
	else return x;
}
int r,g;
void gao(){
	int n=r+g;
	if(r>0) dp[1][0]=1;
	if(g>0) dp[1][1]=1;
	int i,sum=1;
	for(i=2;;++i){
		sum+=i;
		if(sum>n) break;
		for(int j=max(0,min(sum-r,i));j<=min(sum,g);++j){
			if(sum-j<=r) dp[i%2][j]=QM(dp[i%2][j]+dp[(i-1)%2][j]);
			if(j-i>=0) dp[i%2][j]=QM(dp[i%2][j]+dp[(i-1)%2][j-i]);
		}
		memset(dp[(i-1)%2],0,sizeof(dp[(i-1)%2]));
	}
	LL ans=0;
	--i;
	//cout<<"!"<<i<<endl;
	for(int j=0;j<=n;++j){
		ans=QM(ans+dp[i%2][j]);
	}
	printf("%I64d\n",ans);
}
int main(){
	//double st=clock(),en;
	scanf("%d%d",&r,&g);
	gao();
	//en=clock();
	//cerr<<(double)(en-st)/CLOCKS_PER_SEC<<endl;
	return 0;
}
