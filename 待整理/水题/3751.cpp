#include<stdio.h>
int main(){
	int y,mon,d,h,min,s,t;
	char c,str[5];
	scanf("%d",&t);
	while(t--){
	scanf("%d%c%d%c%d%c%d%c%d%c%d",&y,&c,&mon,&c,&d,&c,&h,&c,&min,&c,&s);
	str[1]='m',str[2]=0;
	if(mon>=10) printf("%d/",mon);
	else printf("0%d/",mon);
	if(d>=10) printf("%d/",d);
	else printf("0%d/",d);
	if(y>=1000) printf("%d-",y);
	else if(y>=100) printf("0%d-",y);
	else if(y>=10) printf("00%d-",y);
	else printf("000%d-",y);
	if(h<12) str[0]='a';
	else str[0]='p';
	h=h%12;
	if(h==0) h=12;
	if(h>=10) printf("%d:",h);
	else printf("0%d:",h);
	if(min>=10) printf("%d:",min);
	else printf("0%d:",min);
	if(s>=10) printf("%d",s);
	else printf("0%d",s);
	printf("%s\n",str);
	}
	return 0;
}
