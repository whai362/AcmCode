#include<iostream>
#include<cstdio>
using namespace std;
#define LL long long
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
	LL n,m,k,x,tmp;
	scanf("%lld%lld%lld",&m,&n,&k);
	if(k>=m) puts("infinite");
	else{
		x=(n-1)*m/(m-k);
		//cout<<x<<endl;
		while((k*x)/m+n>x){
			++x;
		}
		printf("%d\n",x);
	}
	}
	return 0;
}
