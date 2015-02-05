#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1005;
int a[N];
int main(){
	int T;
	int n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;++i){
			scanf("%d",&a[i]);
		}
		if(n%2) a[n++]=0;
		sort(a,a+n);
		int ans=0;
		for(int i=1;i<n;i+=2){
			ans^=(a[i]-a[i-1]-1);
		}
		if(ans) puts("Georgia will win");
		else puts("Bob will win");
	}
	return 0;
}
