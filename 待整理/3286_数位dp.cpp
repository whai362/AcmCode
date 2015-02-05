#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
#define LL long long
LL dp[15][10],
   ansn[10],ansm[10],
   tab[]={0,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000LL,10000000000LL};
void init(){
	memset(dp,0,sizeof(dp));
	for(LL i=0;i<10;++i)
		dp[1][i]=1;
	for(LL i=2;i<11;++i){
		LL sum=0,tmp;
		for(LL j=1;j<i;++j){
			tmp=tab[j]-tab[j-1];
			sum+=tmp;
			dp[i][0]+=9*(i-1-j)*tmp;
		}
		for(LL j=0;j<10;++j){
			for(LL k=1;k<i;++k){
				dp[i][j]+=9*dp[k][j];
			}
		}
		for(LL j=1;j<10;++j){
			dp[i][j]+=sum;
		}
	}
	for(LL i=2;i<11;++i){
		for(LL j=0;j<10;++j){
			dp[i][j]+=dp[i-1][j];
		}
	}
}
void gao(LL n,LL *ans){
	LL bit[15],len=0,tmp=n;
	if(n<0) return ;
	if(n==0) len=1,bit[0]=0;
	while(tmp){
		bit[len++]=tmp%10;
		tmp/=10;
	}
	tmp=n;
	//cout<<len<<endl;
	for(LL i=len-1;i>=0;--i){
		if(i){
			for(LL j=(i==len-1?1:0);j<bit[i];++j)
				ans[j]+=tab[i];
			tmp=tmp-bit[i]*tab[i];
			ans[bit[i]]+=tmp+1;
			if(i==len-1)
				ans[0]=dp[i][0]+(bit[i]-1)*dp[i][1];
			else
				ans[0]+=bit[i]*dp[i][1];
			for(LL j=1;j<10;++j){
				ans[j]+=bit[i]*dp[i][j];
			}
		}
		else{
			for(LL j=0;j<=bit[i];++j)
				++ans[j];
		}
	}
}
int main(){
	LL n,m;
	init();
	/*for(LL i=1;i<11;++i){
		for(LL j=0;j<10;++j){
			cout<<dp[i][j]<<' ';
		}
		cout<<endl;
	}*/
	while(scanf("%lld%lld",&n,&m) && (n!=-1 || m!=-1)){
		memset(ansn,0,sizeof(ansn));
		memset(ansm,0,sizeof(ansm));
		if(n>m) swap(n,m);
		gao(n-1,ansn);
		gao(m,ansm);
		//cout<<n<<' '<<m<<endl;
		printf("%lld",ansm[0]-ansn[0]);
		puts("");
	}
	return 0;
}

