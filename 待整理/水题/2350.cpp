#include<stdio.h>
int main(){
	char c;
	int count,i,n,t,a[1005];
	double ave,p;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		count=0,ave=0.0;
		for(i=0;i<n;++i) scanf("%d",&a[i]),ave=ave+a[i];
		ave=ave/n;
		for(i=0;i<n;++i) if(a[i]>ave) ++count;
		printf("%.3f%%\n",(count+0.0)*100/n);
	}
	return 0;
}
