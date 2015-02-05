//asin135与45相同，所以不要用
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const double pi=acos(-1.0);
const double eps = 1.0e-8;
struct point{
	double x,y;
}p[3];
double dis(point p1,point p2){
	return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}
int main(){
	int i,j,r,flag,t;
	double arfa,a,b,c,xm,tmp;
	point p0;
	p0.x=p0.y=0;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%lf%lf%lf%lf%lf%lf",&r,&p[0].x,&p[0].y,&p[1].x,&p[1].y,&p[2].x,&p[2].y);
		flag=0;
		for(i=0;i<2;++i)
		  for(j=i+1;j<3;++j){
			  a=dis(p[i],p0);
			  b=dis(p[j],p0);
			  c=dis(p[i],p[j]);
			  if(a && b) tmp=(a+b-c)/(2*sqrt(a*b));
			  else continue;
			  if(tmp>1.0) tmp-=eps;
			  else if(tmp<-1.0) tmp+=eps;
			  arfa=acos(tmp)/pi*180.0;
			  if(arfa>=120.0) flag=1;
		  }
		for(i=0;i<2;++i)
		  for(j=i+1;j<3;++j){
			  if(p[i].x*p[j].y==p[i].y*p[j].x && (p[i].x*p[j].x>=0 && p[i].y*p[j].y>=0))
				flag=0;
		  }
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
