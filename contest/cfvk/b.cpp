#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define LL __int64
#define PB push_back
const LL INF=0x3f3f3f3fLL*0x3f3f3f3fLL;
const int N=2*1e5+5;
vector<int> G[N];
int rt=1;
LL dp[N][2];
LL a[N];
LL ans=0;
void gao(int rt){
	dp[rt][0]=0;
	dp[rt][1]=-INF;
	LL t0=0,t1=-INF;
	for(int i=0;i<G[rt].size();++i){
		int ch=G[rt][i];
		gao(ch);
		LL tmp0=t0,tmp1=t1;
		t0=max(tmp0+dp[ch][0],tmp1+dp[ch][1]);
		t1=max(tmp0+dp[ch][1],tmp1+dp[ch][0]);
	}
	dp[rt][0]=t0;
	dp[rt][1]=max(t1,t0+a[rt]);
	//cout<<rt<<' '<<dp[rt][0]<<' '<<dp[rt][1]<<endl;
}
int main(){
	int n;
	scanf("%d",&n);
	int p;
	for(int i=1;i<=n;++i){
		scanf("%d%I64d",&p,&a[i]);
		if(p==-1) rt=i;
		else{
			G[p].PB(i);
		}
	}
	gao(rt);
	printf("%I64d\n",max(dp[rt][0],dp[rt][1]));
	return 0;
}
