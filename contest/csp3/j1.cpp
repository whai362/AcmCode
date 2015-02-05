#include<cstdio>
#include<iostream>
using namespace std;
#define M 1000000009
long long a[100005];
int main(){
	a[1]=0;
	a[2]=1;
	for(int i=3;i<100005;++i){
		a[i]=(((a[i-1]+a[i-2])%M)*(i-1))%M;
	}
	int n;
	while(scanf("%d",&n)!=EOF){
		printf("%lld\n",a[n]);
	}
	return 0;
}
