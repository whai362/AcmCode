#include<iostream>
#include<cstdio>
using namespace std;
const int N=1005;
int a[N];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		int sum1=0,sum2=0;
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			if(i & 1) sum2+=a[i];
			else sum1+=a[i];
		}
		int flag=1;
		for(int i=1;i<=n;++i){
			if(a[i]!=a[n+1-i]){ flag=0; break; }
		}
		if(!flag && sum1==sum2) puts("Yes");
		else puts("No");
	}
	return 0;
}
