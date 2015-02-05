#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main(){
	int n,x;
	while (~scanf("%d",&n),n){
		int ans=0;
		for (int i=1;i<=n;i++){
			scanf("%d",&x);
			ans+=x*x;
		}
		printf("%d\n",ans);
	}
	return 0;
}
