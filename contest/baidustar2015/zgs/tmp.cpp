#include<iostream>
#include<cstdio>
using namespace std;
#define LL __int64
const int N=1e6+5;
const int MOD=1000000007;
//a(n)=a(n-1)+(n-1)*a(n-2)
LL a[N];
void predo(){
    a[0]=1;
    a[1]=1;
    for(int i=2;i<N;++i){
        a[i]=(a[i-1]+a[i-2]*(i-1)%MOD)%MOD;
    }
}
int main(){
    int T;
    int n;
    scanf("%d",&T);
    predo();
	int cas=0;
    while(T--){
        scanf("%d",&n);
        printf("Case #%d:\n%I64d\n",++cas,a[n]);
    }
    return 0;
}
