#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int INF=2*1e9+100;
void gao(int x){
	int lim=sqrt(x);
	int ans=INF;
	for(int i=1;i<=lim;++i){
		if(x%i==0){
			ans=min(ans,2*i+2*x/i);
		}
	}
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		gao(n);
	}
	return 0;
}
