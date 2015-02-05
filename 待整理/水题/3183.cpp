#include<stdio.h>
int h[50010];
int main(){
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;++i) scanf("%d",&h[i]);
	for(i=0;i<n;++i){
		if(i==0&&h[i]>=h[i+1]) printf("%d\n",i+1);
		else if(h[i]>=h[i-1]&&h[i]>=h[i+1]) printf("%d\n",i+1);
		else if(i==n-1&&h[i]>=h[i-1]) printf("%d\n",i+1);
	}
	return 0;
}
