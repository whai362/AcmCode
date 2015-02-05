#include<stdio.h>
int main(){
	int r,y;
	double m;
	scanf("%d%lf%d",&r,&m,&y);
	while(y--) m=m*(100+r)/100;
	printf("%d\n",(int)m);
	return 0;
}
