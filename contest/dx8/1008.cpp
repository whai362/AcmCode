#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
#define LL __int64
LL b[150005];
int top=0;
LL min(LL a,LL b){
	if (a>b) a=b;
	return a;
}
int main(){
	int cas=0;
	LL x,k,a;
	while (~scanf("%I64d%I64d",&x,&k)){
		LL y=x;
		top=0;
		if (x==0&&k==0) break;
		for (int i=1;i<=min(150000,k);i++){
			a=y%i;
			if (a==0) continue;
			y+=(i-a);
			b[++top]=i-a;
		}
		y+=b[top]*(k-min(150000,k));
		printf("Case #%d: %I64d\n",++cas,y);
	}
	return 0;
}
