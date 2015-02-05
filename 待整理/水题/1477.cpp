#include<stdio.h>
int main(){
	int i,n,min,arv,count=0,h[55];
	while(scanf("%d",&n)&&n){
	arv=0,min=0;
	for(i=0;i<n;++i){
		scanf("%d",&h[i]);
		arv=arv+h[i];
	}
	arv=arv/n;
	for(i=0;i<n;++i) if(h[i]>arv) min=min+h[i]-arv;
	printf("Set #%d\nThe minimum number of moves is %d.\n\n",++count,min);
	}
	return 0;
}
