#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		int a;
		int ans=0;
		for(int i=0;i<n;++i){
			scanf("%d",&a);
			if(a>6000) ++ans;
		}
		printf("%d\n",ans);
	}
	return 0;
}
