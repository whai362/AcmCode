#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=5005,
	  INF=0x3f3f3f3f;
struct Data{
	int a,b;
}d[N];
int dp[N][2];
bool cmp(Data d1,Data d2){
	if(d1.a!=d2.a) return d1.a<d2.a;
	else return d1.b<d2.b;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d%d",&d[i].a,&d[i].b);
	}
	sort(d,d+n,cmp);
	dp[0][0]=d[0].a;
	dp[0][1]=d[0].b;
	for(int i=1;i<n;++i){
		int _min=min(dp[i-1][0],dp[i-1][1]);
		if(d[i].a>=_min) dp[i][0]=d[i].a;
		else dp[i][0]=INF;
		if(d[i].b>=_min) dp[i][1]=d[i].b;
		else dp[i][1]=INF;
	}
	int ans=min(dp[n-1][0],dp[n-1][1]);
	printf("%d\n",ans);
	return 0;
}
