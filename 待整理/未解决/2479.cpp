#include<stdio.h>
int a[10010];
int main(){
	int i,t,n,tmp,max;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=0;i<n;++i) scanf("%d",&a[i]);
		tmp=max=a[0];
		for(i=1;i<n;++i){
			tmp=tmp+a[i];
			if(tmp<a[i]){
				tmp=a[i];
			}
			if(tmp>max) max=tmp;
		}
		printf("%d\n",max);
		if(t) printf("\n");
	}
	return 0;
}
// 5 -1 5 -4 4 0

