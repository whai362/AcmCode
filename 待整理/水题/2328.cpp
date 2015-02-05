#include<stdio.h>
int main(){
	int max,min,n;
	char a[10],b[10];
	while(1){
		max=11,min=0;
		while(1){
			scanf("%d",&n);
			if(!n) return 0;
			scanf("%s%s",a,b);
			if(b[0]=='h'){ if(n<max) max=n; }
			else if(b[0]=='l'){ if(n>min) min=n; }
			else break;
		}
		if(n>min&&n<max) printf("Stan may be honest\n");
		else printf("Stan is dishonest\n");
	}
	return 0;
}
