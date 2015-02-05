#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1005;
int a[N];
int main(){
	for(int i=3;i<N;++i){
		for(int j=2;j<i;++j){
			if(__gcd(i,j)>1) a[i]=1;
		}
	}
	int n;
	while(scanf("%d",&n)!=EOF){
		int ans=0,t;
		for(int i=0;i<n;++i){
			scanf("%d",&t);
			if(!a[t]) ans+=t;
		}
		printf("%d\n",ans);
	}
	return 0;
}
