#include<iostream>
#include<cstdio>
using namespace std;
#define LL __int64
int main(){
	LL v,v0;
	while(scanf("%I64d%I64d",&v,&v0)!=EOF){
		LL tmp=v0-v;
		printf("%I64d\n",v-tmp);
	}
	return 0;
}
