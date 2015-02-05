#include<stdio.h>
#include<string.h>
int main(){
	char p1[50],p2[50],c[5];
	int sum=0,cost;
	while(scanf("%s",p1)&&(strlen(p1)!=1||p1[0]!='#')){
		if(strlen(p1)==1&&p1[0]=='0'){
			printf("%d\n",sum);
			sum=0;
			continue;
		}
		else{
			scanf("%s%d%s",p2,&cost,c);
			if(c[0]=='F') sum=sum+cost*2;
			else if(c[0]=='B') sum=sum+int(cost*3.0/2.0+0.5);
			else if(cost<500) sum=sum+500;
			else sum=sum+cost;
		}
	}
	return 0;
}
