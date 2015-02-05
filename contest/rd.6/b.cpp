#include<cstdio>
int main(){
	int count,i,n,max,min,p[1005];
	scanf("%d",&n);
	for(i=0;i<n;++i) scanf("%d",&p[i]);
	count=0,max=p[0],min=p[0];
	for(i=1;i<n;++i){
		if(p[i]>max) max=p[i],++count;
		if(p[i]<min) min=p[i],++count;
	}
	printf("%d\n",count);
	return 0;
}
