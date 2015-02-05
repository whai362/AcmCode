#include<stdio.h>
int atoi(char bnum[]){
	int i,num=0;
	for(i=0;i<8;++i){
		num=num*2+bnum[i]-48;
	}
	return num;
}
int main(){
	int t;
	char ip[40];
	scanf("%d",&t);
	while(t--){
		scanf("%s",ip);
		printf("%d.%d.%d.%d\n",atoi(ip),atoi(ip+8),atoi(ip+16),atoi(ip+24));
	}
	return 0;
}
