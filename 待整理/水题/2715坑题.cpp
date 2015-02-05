#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
#define EPS 1e-5
int main(){
	int cnt;
	double ans,b,w,c,c1,c2;
	while(scanf("%lf%lf%lf",&b,&w,&c) && (b || w || c)){
		c=c/16;
		c1=1,c2=0,cnt=0;
		ans=b/w;
		while(fabs(c1/(1-c1)-ans)>EPS || fabs(c2/(1-c2)-ans)>EPS){
			c2=(w*c2+c*c1)/(w+c);
			c1=((b-c)*c1+c*c2)/b;
			++cnt;
		}
		//cout<<c1<<' '<<c2<<endl;
		printf("%d\n",cnt);
	}
	return 0;
}
