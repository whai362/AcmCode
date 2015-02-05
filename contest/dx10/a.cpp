#include<cstdio>
#include<iostream>
using namespace std;
#define LL __int64
int main(){
	int cas=0,n,T;
	LL a,s,_max;
	scanf("%d",&T);
	while(T--){
	scanf("%d",&n);
	s=0,_max=0;
	for(int i=0;i<n;++i){
		scanf("%I64d",&a);
		s+=a;
		_max=max(_max,a);
	}
	printf("Case #%d: %I64d\n",++cas,max((s+1)/2,_max));
	}
	return 0;

}
