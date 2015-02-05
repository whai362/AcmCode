#include<cstdio>
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<cmath>
using namespace std;
#define eps 1e-8
#define pi 3.1415926
#define INF 1e18
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
	for(p1=p2=p[0],i=1;i<n;p2.x+=p[i].x,p2.y+=p[i].y,i++)
	if(p1.y-p[i].y>eps||(zero(p1.y-p[i].y)&&p1.x>p[i].x))
	p1=p[k=i];
	p2.x/=n,p2.y/=n;
	p[k]=p[0],p[0]=p1;
	qsort(p+1,n-1,sizeof(point),graham_cp);
	for(ch[0]=p[0],ch[1]=p[1],ch[2]=p[2],s=i=3;i<n;ch[s++]=p[i++])
	for(;s>2&&xmult(ch[s-2],p[i],ch[s-1])<-eps;s--);
}

int graham(int n,point* p,point* convex,int maxsize=1,int dir=1){
	point* temp=new point[n];
	int s,i;
	_graham(n,p,s,temp);
	for(convex[0]=temp[0],n=1,i=(dir?1:(s-1));dir?(i<s):i;i+=(dir?1:-1))
	if(maxsize||!zero(xmult(temp[i-1],temp[i],temp[(i+1)%s])))
	convex[n++]=temp[i];
	delete []temp;
	return n;
}
point p[50005],convex[50005];
int main(){
	int i,j,n,m;
	double r,len;
	while(scanf("%d",&n) && n!=-1){
	for(i=0;i<n;++i) scanf("%lf%lf",&p[i].x,&p[i].y);
	n=graham(n,p,convex);
	int p1,p2;
	double _max=INF,tmp1,tmp2;
	for(i=2;i<n;++i){
		tmp1=fabs(xmult(convex[0],convex[1],convex[i]));
		if(tmp1>_max) _max=tmp1,p1=i;
	}
	for(i=0;i<n-1;++i){
		tmp1=fabs(xmult(convex[i],convex[i+1],convex[p1]));
		tmp2=fabs(xmult(convex[i],convex[i+1],convex[(p1+1)%n]));
		while(tmp1<tmp2){
			++p1;
			p1=p1%n;
			tmp1=tmp2;
			tmp2=fabs(xmult(convex[i],convex[i+1],convex[(p1+1)%n]));
		}
		p2=p1;
		for(j=i+1;j<n;++j){
				tmp1=fabs(xmult(convex[i],convex[j],convex[p2]));
				tmp2=fabs(xmult(convex[i],convex[j],convex[(p2+1)%n]));
				while(tmp1>tmp2){
					++p2;
					p2=p2%n;
					tmp1=tmp2;
					tmp2=fabs(xmult(convex[i],convex[j],convex[(p2+1)%n]));
				}
				if(tmp1>_max) _max=tmp1;
		}
	}
	cout<<fixed<<setprecision(2)<<_max/2<<endl;
	}
	return 0;
}

