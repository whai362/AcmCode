#include<stdio.h>
int main(){
	int i,a,h=-1;
	for(i=0;i<3;++i){ scanf("%d",&a); if(h<0&&a<168) h=a; }
	if(h>=0) printf("CRASH %d\n",h);
	else printf("NO CRASH\n");
	return 0;
}
