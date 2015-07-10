#include<iostream>
#include<cstdio>
using namespace std;
const int N=105;
int a[N];
void gao(int n){
	int xor_sum=0;
	for(int i=0;i<n;++i){
		xor_sum^=a[i];
	}
	int ans=0;
	for(int i=0;i<n;++i){
		int tmp=xor_sum^a[i];
		if(tmp<a[i]) ++ans;
	}
	printf("%d\n",ans);
}
int main(){
	int n;
	while(scanf("%d",&n) && n){
		for(int i=0;i<n;++i)
			scanf("%d",&a[i]);
		gao(n);
	}
	return 0;
}
