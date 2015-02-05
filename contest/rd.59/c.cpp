#include<iostream>
#include<iomanip>
#include<cmath>
const long double pi=acos(-1.0);
using namespace std;
int main(){
	long double w,h,a,x,tmp;
	cin>>w>>h>>a;
	if(a!=90 && a!=0 && a!=180){
		if(a>90) a=180-a;
		a=a*pi/180.0;
		x=(w/sin(a)+w/tan(a)-h)/(-tan(a)+1.0/sin(a)+1.0/(sin(a)*cos(a))+1.0/tan(a)+1.0/sin(a));
		cout<<x<<endl;
		tmp=x*x*tan(a)+(w-x-x/cos(a))*(w-x-x/cos(a))/tan(a);
		cout<<x*x*tan(a)<<endl;
		cout<<(w-x-x/cos(a))*(w-x-x/cos(a))/tan(a)<<endl;
		tmp=w*h-tmp;
		cout<<fixed<<setprecision(100)<<tmp<<endl;
	}
	else if(a==90){
		cout<<fixed<<setprecision(100)<<min(w,h)*min(w,h)<<endl;
	}
	else{
		cout<<fixed<<setprecision(100)<<w*h<<endl;
	}
	return 0;
}
