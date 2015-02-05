#include<stdio.h>
#include<string.h>
char letter[]=" ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int time[1010];
int main(){
	int a,b,i,j,max,min,n,t;
	char c[5];
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		max=0,min=1010;
		memset(time,0,sizeof(time));
		for(i=0;i<n;++i){
			scanf("%s%d%d",c,&a,&b);
			for(j=a;j<b;++j) ++time[j];
			if(a<min) min=a;
			if(b>max) max=b;
		}
		for(i=min;i<=max;++i){
			if(time[i]) printf("%c",letter[time[i]]);
		}
		printf("\n");
	}
	return 0;
}
