#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
	int i,max,n,t,tmp,r[1010];
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=0;i<n;++i) scanf("%d",&r[i]);
		sort(r,r+n);
		max=0;
		for(i=0;i<n;++i){
			tmp=r[i]*(n-i);
			if(tmp>max) max=tmp;
		}
		printf("%d\n",max);
	}
	return 0;
}
