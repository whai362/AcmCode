#include<iostream>
#include<cstdio>
using namespace std;
#define LL long long
void gao(LL n){
	while(n>18){
		if(n%18==0)
			n/=18;
		else
			n=n/18+1;
	}
	if(n<=9) puts("Stan wins.");
	else puts("Ollie wins.");
}
int main(){
	LL n;
	while(scanf("%lld",&n)!=EOF){
		gao(n);
	}
	return 0;
}
