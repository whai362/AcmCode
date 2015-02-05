#include<stdio.h>
#include<string.h>
int a[150];
int main(){
	int count,d,i,n,t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		d=1,count=0;
		memset(a,0,sizeof(a));
		while(d<=n){
			for(i=1;i<=n;++i){
				if(!a[i]&&i%d==0) a[i]=1,++count;
				else if(a[i]&&i%d==0)  a[i]=0,--count;
			}
			++d;
		}
		printf("%d\n",count);
	}
	return 0;
}
