#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
#define eps 1e-8
#define pi 3.1415926
#define zero(x) (((x)>0?(x):-(x))<eps)
struct point{double x,y;};
double xmult(point p1,point p2,point p0){	
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
point p1,p2;
int graham_cp(const void* a,const void* b){
	double ret=xmult(*((point*)a),*((point*)b),p1);
	return zero(ret)?(xmult(*((point*)a),*((point*)b),p2)>0?1:-1):(ret>0?1:-1);
}
void _graham(int n,point* p,int& s,point* ch){
	int i,k=0;
	for (p1=p2=p[0],i=1;i<n;p2.x+=p[i].x,p2.y+=p[i].y,i++)
	if (p1.y-p[i].y>eps||(zero(p1.y-p[i].y)&&p1.x>p[i].x))
	p1=p[k=i];
	p2.x/=n,p2.y/=n;
	p[k]=p[0],p[0]=p1;
	qsort(p+1,n-1,sizeof(point),graham_cp);
	for (ch[0]=p[0],ch[1]=p[1],ch[2]=p[2],s=i=3;i<n;ch[s++]=p[i++])
	for (;s>2&&xmult(ch[s-2],p[i],ch[s-1])<-eps;s--);
}

int graham(int n,point* p,point* convex,int maxsize=1,int dir=1){
	point* temp=new point[n];
	int s,i;
	_graham(n,p,s,temp);
	for (convex[0]=temp[0],n=1,i=(dir?1:(s-1));dir?(i<s):i;i+=(dir?1:-1))
	if (maxsize||!zero(xmult(temp[i-1],temp[i],temp[(i+1)%s])))
	convex[n++]=temp[i];
	delete []temp;
	return n;
}
point p[1010],convex[1010];
double jisuan(int x1,int x2,int x3){
	double a=sqrt((convex[x1].x-convex[x2].x)*(convex[x1].x-convex[x2].x)+(convex[x1].y-convex[x2].y)*(convex[x1].y-convex[x2].y));
    double b=sqrt((convex[x2].x-convex[x3].x)*(convex[x2].x-convex[x3].x)+(convex[x2].y-convex[x3].y)*(convex[x2].y-convex[x3].y));
    double c=sqrt((convex[x1].x-convex[x3].x)*(convex[x1].x-convex[x3].x)+(convex[x1].y-convex[x3].y)*(convex[x1].y-convex[x3].y));
    double p=1.0/2*(a+b+c);
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
int main(){
	int i,n,m;
	double r,len;
	while(scanf("%d%lf",&n,&r)!=EOF){
	for(i=0;i<n;++i) scanf("%lf%lf",&p[i].x,&p[i].y);
	n=graham(n,p,convex);
	len=sqrt((convex[0].x-convex[n-1].x)*(convex[0].x-convex[n-1].x)+(convex[0].y-convex[n-1].y)*(convex[0].y-convex[n-1].y));
	for(i=0;i<n-1;++i){
		len=len+sqrt((convex[i].x-convex[i+1].x)*(convex[i].x-convex[i+1].x)+(convex[i].y-convex[i+1].y)*(convex[i].y-convex[i+1].y));
	}
	double area=0;
	for(int i=1;i<n-1;i++) area+=jisuan(0,i,i+1);
	printf("%.0lf %.3lf\n",2*area,len+2*pi*r);
	}
	return 0;
}

