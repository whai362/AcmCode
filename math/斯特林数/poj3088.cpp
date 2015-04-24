#include<iostream>
#include<cstdio>
using namespace std;
#define LL long long
const int N=15;
LL sti[N][N];
LL fac[N];
void predo(){
	fac[0]=1;
	for(int i=1;i<N;++i)
		fac[i]=fac[i-1]*(LL)i;
	for(int i=1;i<N;++i){
		sti[i][0]=0;
		sti[i][i]=1;
	}
	for(int i=2;i<N;++i){
		for(int j=1;j<i;++j){
			sti[i][j]=(LL)j*sti[i-1][j]+sti[i-1][j-1];
		}
	}
}
LL C(int n,int k){
	return fac[n]/fac[k]/fac[n-k];
}
void gao(int n){
	LL ans=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=i;++j){
			ans+=C(n,i)*sti[i][j]*fac[j];
		}
	}
	printf(" %d %lld\n",n,ans);
}
int main(){
	predo();
	int T;
	scanf("%d",&T);
	int cas=0;
	while(T--){
		int n;
		scanf("%d",&n);
		printf("%d",++cas);
		gao(n);
	}
	return 0;
}
