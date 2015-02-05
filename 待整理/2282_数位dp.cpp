#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
#define LL long long
LL dp[15][10],
   ansn[10],ansm[10],
   tab[]={0,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
void init(){
	memset(dp,0,sizeof(dp));
	for(int i=0;i<10;++i)
		dp[1][i]=1;
	for(int i=2;i<10;++i){
		LL sum=0,tmp;
		for(int j=1;j<i;++j){
			tmp=tab[j]-tab[j-1];
			sum+=tmp;
			dp[i][0]+=9*(i-1-j)*tmp;
		}
		for(int j=0;j<10;++j){
			for(int k=1;k<i;++k){
				dp[i][j]+=9*dp[k][j];
			}
		}
		for(int j=1;j<10;++j){
			dp[i][j]+=sum;
		}
	}
	for(int i=2;i<10;++i){
		for(int j=0;j<10;++j){
			dp[i][j]+=dp[i-1][j];
		}
	}
}
LL gao(int n,LL *ans){
	int bit[15],len=0,tmp=n;
	if(n==0) len=1,bit[0]=0;
	while(tmp){
		bit[len++]=tmp%10;
		tmp/=10;
	}
	tmp=n;
	for(int i=len-1;i>=0;--i){
		if(i){
			for(int j=(i==len-1?1:0);j<bit[i];++j)
				ans[j]+=tab[i];
			tmp=tmp-bit[i]*tab[i];
			ans[bit[i]]+=tmp+1;
			if(i==len-1)
				ans[0]=dp[i][0]+(bit[i]-1)*dp[i][1];
			else
				ans[0]+=bit[i]*dp[i][1];
			for(int j=1;j<10;++j){
				ans[j]+=bit[i]*dp[i][j];
			}
		}
		else{
			for(int j=0;j<=bit[i];++j)
				++ans[j];
		}
	}
}
int main(){
	int n,m;
	init();
	while(scanf("%d%d",&n,&m) &&(n || m)){
		memset(ansn,0,sizeof(ansn));
		memset(ansm,0,sizeof(ansm));
		if(n>m) swap(n,m);
		gao(n-1,ansn);
		gao(m,ansm);
		printf("%lld",ansm[0]-ansn[0]);
		for(int i=1;i<10;++i){
			printf(" %lld",ansm[i]-ansn[i]);
		}
		puts("");
	}
	return 0;
}
