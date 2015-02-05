#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;
#define eps 1e-8
#define pi 3.1415926
#define zero(x) (((x)>0?(x):-(x))<eps)
struct point{double x,y;};
double xmult(point p1,point p2,point p0){	
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
double toAngle(double x,double y){
	double angle;
	if(y>0){
		if(x==0) return pi/2;
		else if(x>0) return atan(y/x);
		else return pi+atan(y/x);
	}
	else if(y==0){
		if(x>=0) return 0;
		else return pi;
	}
	else{
		if(x==0) return 3*pi/2;
		else if(x<0) return pi+atan(y/x);
		else return 2*pi+atan(y/x);
	}
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

bool cmp(point a,point b){
	return toAngle(a.x,a.y)<toAngle(b.x,b.y);
}
double dis(point a,point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)); 
}
int main(){
	int i,j,n;
	double d,s,_max;
	point p[505],convex[505];
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;++i) scanf("%lf%lf",&p[i].x,&p[i].y);
		_max=0;
		sort(p,p+n,cmp);
		d=dis(p[0],p[n-1]);
		//for(i=0;i<n;++i){
		//	cout<<"!"<<p[i].x<<' '<<p[i].y<<endl;
		//}
		for(i=0;i<n;++i){
			if(i==0 || i==n-1) continue;
			s=fabs(xmult(p[0],p[n-1],p[i]));
			_max=max(_max,s/d);
		}
		for(i=0;i<n-1;++i){
			d=dis(p[i],p[i+1]);
			for(j=0;j<n;++j){
				if(j==i || j==i+1) continue;
				s=fabs(xmult(p[i],p[i+1],p[j]));
				_max=max(_max,s/d);	
			}
		}
		n=graham(n,p,convex);
		d=dis(convex[0],convex[n-1]);
		//for(i=0;i<n;++i){
		//	cout<<"!"<<convex[i].x<<' '<<convex[i].y<<endl;
		//}
		for(i=0;i<n;++i){
			if(i==0 || i==n-1) continue;
			s=fabs(xmult(convex[0],convex[n-1],convex[i]));
			_max=max(_max,s/d);
		}
		for(i=0;i<n-1;++i){
			d=dis(convex[i],convex[i+1]);
			for(j=0;j<n;++j){
				if(j==i || j==i+1) continue;
				s=fabs(xmult(convex[i],convex[i+1],convex[j]));
				_max=max(_max,s/d);	
			}
		}
		cout<<fixed<<setprecision(5)<<_max<<endl;
	}
	return 0;
}

