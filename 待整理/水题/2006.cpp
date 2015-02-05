#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	double k,ce,m,n,a,b,c;
	while(scanf("%lf%lf%lf%lf",&k,&ce,&m,&n) && (k||ce||m||n)){
		a=ce/(n*m),b=-1.0/(n*m),c=-1.0/k;
		cout<<fixed<<setprecision(3)<<-log(m/((-b+sqrt(b*b-4.0*a*c))/(2.0*a)))/log(10.0)<<endl;
	}
	return 0;
}
