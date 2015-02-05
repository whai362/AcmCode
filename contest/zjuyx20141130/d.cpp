//a=2*(x2-x1);
//b=2*(y2-y1);
//c=x2*x2+y2*y2-x1*x1-y1*y1;
//d=2*(x3-x2);
//e=2*(y3-y2);
//f=x3*x3+y3*y3-x2*x2-y2*y2;
//x=(b*f-e*c)/(b*d-e*a);
//y=(d*c-a*f)/(b*d-e*a);
//r=sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
struct Point{
	double x,y;
}p1[205],p2[205];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i){
		scanf("%lf%lf",&p1[i].x,&p1[i].y);
	}
	for(int i=0;i<m;++i){
		scanf("%lf%lf",&p2[i].x,&p2[i].y);
	}
	double _minr=INF;
	for(int i=0;i<lim*3/4
}
