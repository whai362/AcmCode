#include<stdio.h>
#include<string.h>
int main(){
	int b,cas=0,i,len,n,sum,t;
	scanf("%d",&t);
	while(t--){
		char id[20];
		scanf("%s",id);
		sum=0,len=strlen(id)-1;
		for(i=0;i<strlen(id);++i){
			if(id[len-i]>='0'&&id[len-i]<='9'){
				if(i%3==0) sum=sum+(id[len-i]-48)*9;
				else if(i%3==1) sum=sum+(id[len-i]-48)*3;
				else sum=sum+(id[len-i]-48)*7;
			}
			else{
				b=len-i;
				if(i%3==0) n=9;
				else if(i%3==1) n=3;
				else n=7;
			}
		}
		for(i=0;i<10;++i){
			if((sum+i*n)%10==0){ id[b]=i+48; break; }
		}
		printf("Scenario #%d:\n%s\n\n",++cas,id);
	}
	return 0;
}
