#include<stdio.h>
#include<string.h>
int main(){
	char num[15];
	int i,flag,t;
	scanf("%d",&t);
	while(t--){
		scanf("%s",num);
		if(strlen(num)==1) printf("%s\n",num);
		else{
			flag=0;
			for(i=strlen(num)-1;i>=0;--i){
				num[i]=num[i]+flag;
				if(num[i]>='5') flag=1;
				else flag=0;
				if(i||i==0&&num[i]>'9') num[i]='0';
			}
			if(flag&&num[0]=='0') printf("%d",flag);
			printf("%s\n",num);
		}
	}
	return 0;
}
