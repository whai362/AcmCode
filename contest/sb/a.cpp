#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int T,h,n,cas=0;
	scanf("%d",&T);
	while(T--){
		int _max=0;
		scanf("%d",&n);
		for(int i=0;i<n;++i){
			scanf("%d",&h);
			_max=max(_max,h);
		}
		printf("Case #%d: %d\n",++cas,_max);
	}
	return 0;
}
