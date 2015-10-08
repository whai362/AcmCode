#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

#define LL __int64

const int MOD = 1000000007;

LL T[4005],B[4005];
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

int main() {
	get_bell(4001, MOD);
	int n;
	cin>>n;
	LL a = B[n + 1];
	LL b = B[n];
	cout<<(a - b + MOD) % MOD<<endl;
	return 0;
}
