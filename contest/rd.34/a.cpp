#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	double x1,y1,x2,y2,x3,y3;
	scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);
	if((x1-x2)*(y1-y3)==(x1-x3)*(y1-y2)) printf("TOWARDS\n");
	else if((x2-x1)*(y3-y1)>(x3-x1)*(y2-y1)) printf("LEFT\n");
	else printf("RIGHT\n");
	return 0;
}
