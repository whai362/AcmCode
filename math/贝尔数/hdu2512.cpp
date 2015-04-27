#include<iostream>
#include<cstdio>
using namespace std;
#define LL __int64
const int N=2005;
LL B[N],T[N];
void Bell(int n,int MOD){
    B[0]=1;
    B[1]=1;
    T[0]=1;
    for(int i=2;i<=n;++i){
        T[i-1]=B[i-1];
        for(int j=i-2;j>=0;--j){
            T[j]=(T[j]+T[j+1])%MOD;
		}
        B[i]=T[0];
    }
}
int main(){
	Bell(2000,1000);
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		printf("%I64d\n",B[n]);
	}
	return 0;
}
