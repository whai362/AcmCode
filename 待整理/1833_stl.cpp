#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
	int i,n,k,t,a[1050];
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(i=0;i<n;++i) scanf("%d",&a[i]);
		while(k--) next_permutation(a,a+n);
		for(i=0;i<n;++i) printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}

