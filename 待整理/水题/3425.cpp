#include<stdio.h>
#include<string.h>
#define N 1000010
int que[N];
int main(){
	int a,cost,i,n,q,x;
	while(scanf("%d",&n)!=EOF){
		cost=0;
		memset(que,0,sizeof(que));
		for(i=0;i<n;++i){
			scanf("%d%d%d",&q,&a,&x);
			if(a==0) cost=cost+10;
			else if(a==1&&x==0) cost=cost+20+que[q]*10,++que[q];
			else if(a==1&&x==1) cost=cost+40+que[q]*10,++que[q];
		}
		printf("%d\n",cost);
	}
	return 0;
}
