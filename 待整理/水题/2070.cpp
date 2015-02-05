#include<stdio.h>
int main(){
	int f;
	double a,b,c;
	while(scanf("%lf%lf%lf",&a,&b,&c)&&(a!=0||b!=0||c!=0)){
		f=1;
		if(a<=4.5&&b>=150&&c>=200) f=0,printf("Wide Receiver ");
		if(a<=6.0&&b>=300&&c>=500) f=0,printf("Lineman ");
		if(a<=5.0&&b>=200&&c>=300) f=0,printf("Quarterback ");
		if(f) printf("No positions");
		printf("\n");
	}
	return 0;
}
