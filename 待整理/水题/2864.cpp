#include<stdio.h>
int main(){
	int i,n,d,a,imf[110];
	while(scanf("%d%d",&n,&d)&&(n||d)){
	for(i=0;i<n;++i) imf[i]=1;
	while(d--){
		for(i=0;i<n;++i){
			scanf("%d",&a);
			imf[i]=imf[i]&a;
		}
	}
	for(i=0;i<n;++i) if(imf[i]){ printf("yes\n"); break; }
	if(i==n) printf("no\n");
	}
	return 0;
}
