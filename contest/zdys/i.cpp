#include<cstdio>
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
const double eps=10e-10,
	  inf=1e30;
double R,r;
double f(int y){
	return R*y*y*y+(r*R-2*R*R)*y*y+2*R*R*r*r;
}
double getAns(double l,double r){
	double mid; 
	while(fabs(l-r)>eps){
		mid=(l+r)/2;
		if(f(mid)>0-eps){
			r=mid;
		}
		else{
			l=mid;
		}
	}
	return l;
}
double getAns1(double l,double r){
	double mid; 
	while(fabs(l-r)>eps){
		mid=(l+r)/2;
		if(f(mid)>0-eps){
			l=mid;
		}
		else{
			r=mid;
		}
	}
	return l;
}
int main(){
	double R,r,y;
	double t1,t2,t3,t4,t5,t6,t52;
	while(scanf("%lf%lf",&r,&R)!=EOF){
		if(r>=R){
			cout<<"NO Solution!"<<endl;
			continue;
		}
		t1=(4*R-2*r)/3;
		t2=f(0);
		t3=f(t1);
		if(t2<0+eps && t3<0+eps){
			y=getAns(t1-eps,inf);
			t4=R*r/y;
			t52=4*(R*R-t4*t4);
			t5=sqrt(t52);
			t6=2*sqrt(t52-(y+r)*(y+r));
			cout<<fixed<<setprecision(9)<<t5<<' '<<t5<<' '<<t6<<endl;
		}
		else{
			if(t2>0-eps && t3<0+eps){
				y=getAns1(0-eps,t1+eps);
				t4=R*r/y;
				t52=4*(R*R-t4*t4);
				t5=sqrt(t5);
				t6=2*sqrt(t52-(y+r)*(y+r));
				cout<<fixed<<setprecision(9)<<t5<<' '<<t5<<' '<<t6<<endl;
			}
			else{
				y=getAns1(0-eps,inf);
				t4=R*r/y;
				t52=4*(R*R-t4*t4);
				t5=sqrt(t5);
				t6=2*sqrt(t52-(y+r)*(y+r));
				cout<<fixed<<setprecision(9)<<t5<<' '<<t5<<' '<<t6<<endl;
			}
		}
	}
	return  0;
}
