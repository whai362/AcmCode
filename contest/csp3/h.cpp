#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	long long n,y;
	while(scanf("%lld%lld",&n,&y)!=EOF){
		n=n>>(y-1);
		if(n & 1LL){
			puts("Yes");
		}
		else{
			puts("No");
		}
	}
	return 0;
}
