#include<cstdio>
#include<cmath>
using namespace std;
int k,m,n;
double a,b,x,y,z;
int main(){
	double i,tmp;
	scanf("%d",&n);
	x=0.0;
	while(n--){
		scanf("%lf",&tmp);
		if(tmp>x) x=tmp;
	}
	scanf("%d",&m);
	y=0.0;
	while(m--){
		scanf("%lf",&tmp);
		if(tmp>y) y=tmp;
	}
	scanf("%d",&k);
	z=1e9;
	while(k--){
		scanf("%lf",&tmp);
		if(tmp<z) z=tmp;
	}
	scanf("%lf%lf",&a,&b);
	printf("%lf\n",sqrt((x*x*y)/(a*z/b+y)));
	return 0;
}
