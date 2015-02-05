#include<stdio.h>
#define M 2147483648ll
int main(){
	int a,i,m,n;
	long long ans;
	while(scanf("%d%d",&n,&m)&&(n||m)){
		ans=1;
		m=(n-m<m? n-m:m);
		for(i=0;i<m;++i) ans=ans%M*(n-i);
		for(i=2;i<=m;++i) ans=ans/i;
		printf("%lld\n",ans);
	}
	return 0;
}
