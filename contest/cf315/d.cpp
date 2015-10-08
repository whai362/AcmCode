#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

#define LL __int64

const int MOD = 1000000007;

LL T[105],B[105];
void get_bell(int n,int mod){
    B[0]=1;
    B[1]=1;
    T[0]=1;
    for(int i=2;i<=n;++i){
        T[i-1]=B[i-1];
        for(int j=i-2;j>=0;--j)
            T[j]=(T[j]+T[j+1])%mod;
        B[i]=T[0];
    }
}
//求B[n]%mod
//要先预处理前50项Bell数，当然可以更多
//vis每次调用前都要清空
map<int,LL> vis;
LL bell_mod(int n,int mod){
	vis.clear();
	LL ret=vis[n];
	if(ret) return ret;
	if(n<=50) return B[n];	//改
	LL k=0;
	LL P=1;
	while(P<n){
		P=P*mod;
		++k;
	}
	P/=mod;
	--k;
	return vis[n]=(k*bell_mod(n-P,mod)+bell_mod(n-P+1,mod))%mod;
}

int main() {
	get_bell(55, MOD);
	int n;
	cin>>n;
	LL a = bell_mod(n + 1, MOD);
	LL b = bell_mod(n, MOD);
	cout<<(a - b + MOD) % MOD<<endl;
	return 0;
}
