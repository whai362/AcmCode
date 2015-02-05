#include<cstdio>
#include<iostream>
using namespace std;
__int64 n,m,k;
__int64 gao(__int64 x){
	__int64 res=0;
	for(__int64 i=1;i<=n;++i){
		__int64 tmp=x/i;
		if(i*tmp!=x) ++tmp;
		if(tmp-1<m){
			if(tmp-1>=0) res+=tmp-1;
		}
		else res+=m;
	}
	return res+1;
}
int main(){
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	__int64 l=1,r=n*m,mid=(l+r)>>1,tmp=gao(mid);
	while(tmp!=k){
		if(tmp>k) r=mid-1;
		else l=mid+1;
		mid=(l+r)>>1;
		tmp=gao(mid);
	}
	while(tmp==k){
		--mid;
		tmp=gao(mid);
	}
	printf("%I64d\n",mid+1);
	return 0;
}
