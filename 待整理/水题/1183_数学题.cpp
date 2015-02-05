#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
using namespace std;
#define eps 1e-10
int main(){
	int i,b;
	double ans,a,c1,c2,tmp;
	scanf("%lf",&a);
	tmp=1.0/tan(atan(1/a)/2);
	if(fabs(tmp-(int)tmp)<eps) ans=2*tmp;
	else{
		b=(int)tmp;
		for(i=0;;++i){
			c1=1/tan(atan(1/a)-atan(1.0/double(b-i)));
			c2=1/tan(atan(1/a)-atan(1.0/double(b+i)));
			if(fabs(c1-(int)c1)<eps && fabs(c2-(int)c2)<eps){
				ans=min(c1+b-i,c2+b+i);
				break;
			}
			else if(fabs(c1-(int)c1)<eps && fabs(c2-(int)c2)>=eps){
				ans=c1+b-i;
				break;
			}
			else if(fabs(c1-(int)c1)>=eps && fabs(c2-(int)c2)<eps){
				ans=c2+b+i;
				break;
			}
		}
	}
	cout<<fixed<<setprecision(0)<<ans<<endl;
	return 0;
}
