#include<stdio.h>
int main(){
	char i,n,isbn[15];
	int tmp;
	scanf("%s",isbn);
	tmp=0;
	for(i=0;i<10;++i){
		if(isbn[i]>='0'&&isbn[i]<='9') tmp=tmp+(isbn[i]-48)*(10-i);
		else if(isbn[i]=='X') tmp=tmp+10*(10-i);
		else if(isbn[i]=='?') n=10-i;
	}
	if(n>1){
		for(i=0;i<10;++i){
			if((tmp+i*n)%11==0){
				printf("%d\n",i);
				break;
			}
		}
		if(i==10) printf("-1\n");
	}
	else{
		for(i=0;i<=10;++i){
			if((tmp+i*n)%11==0){
				if(i<10) printf("%d\n",i);
				else printf("X\n");
				break;
			}
		}
		if(i>10) printf("-1\n");
	}
	return 0;
}
