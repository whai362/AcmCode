#include<cstdio>
#include<iostream>
using namespace std;
#define N 100005
#define MOD 1000000007
long long a[N],f[N];
int main(){
	int i,j,l,r,n,m,t;
	scanf("%d",&t);
	while(t--){
	scanf("%d%d",&n,&m);
	for(i=0;i<n;++i){
		scanf("%I64d",&a[i]);
	}
	for(i=0;i<m;++i){
		scanf("%d%d",&l,&r);
		f[l-1]=a[l-1];
		if(l<n) f[l]=a[l];
		for(j=l+1;j<r;++j){
			f[j]=(f[j-1]+(f[j-2]*a[j])%MOD)%MOD;
		}
		printf("%I64d\n",f[r-1]);
	}
	}
	return 0;
}
