//正弦定理，余弦定理
#include<cstdio>
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
const double pi=acos(-1.0);
const double eps=1e-4;
double dis(double x0,double y0,double x1,double y1){
	return (x0-x1)*(x0-x1)+(y0-y1)*(y0-y1);
}
bool isInt(double n){
	//cout<<n<<endl;
	if(fabs(n-int(n+0.5))<=eps) return true;
	return false;
}
int main(){
	double x0,y0,x1,y1,x2,y2,r;
	double a,b,c;
	cin>>x0>>y0>>x1>>y1>>x2>>y2;
	double d1,d2,d3;
	d1=dis(x0,y0,x1,y1);
	d2=dis(x1,y1,x2,y2);
	d3=dis(x0,y0,x2,y2);
	a=(d2+d3-d1)/(2*sqrt(d2)*sqrt(d3));
	a=sqrt(1-a*a);
	r=sqrt(d1)/a/2;
	b=acos((2*r*r-d1)/(2*r*r))*180.0/pi;
	c=acos((2*r*r-d2)/(2*r*r))*180.0/pi;
	//cout<<b<<' '<<c<<endl;
	int ans=-1;
	for(int i=3;i<=100;++i){
		if(isInt(b*i/360.0) && isInt(c*i/360.0)){
			ans=i;
			a=360.0/i;
			break;
		}
	}
	cout<<fixed<<setprecision(8)<<ans*r*r*sin(a*pi/180)/2<<endl;
	return 0;
}
