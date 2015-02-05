#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int T;
	long long n;
	scanf("%d",&T);
	while(T--){
	scanf("%lld",&n);
	if(n%3==0) printf("%lld\n",n/3);
	else printf("%lld\n",n);
	}
	return 0;
}
