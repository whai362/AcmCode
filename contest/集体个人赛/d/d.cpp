#include<stdio.h>
#include<string.h>
int a[510][510],s[510],e[510];
int main(){
	int i,t,n,m,start,end,count=0;
	scanf("%d",&t);
	while(t--){
		count=0;
		memset(a,0,sizeof(a));
		scanf("%d%d",&n,&m);
		for(i=1;i<=m;++i){
			scanf("%d",&s[i]);
		}
		for(i=1;i<=m;++i){
			scanf("%d",&e[i]);
		}
		for(i=1;i<=m;++i){
			if(s[i]>e[i]) start=e[i],end=s[i];
			else start=s[i],end=e[i];
			if(!a[start][end]){
				a[start][end]=1;
				++count;
			}
		}
		printf("%.3f\n",(count+0.0)/n);
	}
	return 0;
}
