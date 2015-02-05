#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
using namespace std;
const double pi=acos(-1.0);
int main(){
	double a,b,s,m,n,arfa,v;
	while(scanf("%lf%lf%lf%lf%lf",&a,&b,&s,&m,&n) && (a||b||s||m||n)){
		arfa=atan((n*b)/(m*a));
		v=double(m*a/s/cos(arfa));
		cout<<fixed<<setprecision(2);
		cout<<arfa*180.0/pi<<' '<<v<<endl;
	}
	return 0;
}
