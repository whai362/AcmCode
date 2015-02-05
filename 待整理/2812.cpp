#include<cstdio>
#include<cmath>
using namespace std;
const int N=10000;
const double eps=1e-8,inf=1e50;
struct point{
    double x,y;
}p[N];
double xmult(point p1,point p2){
    return p1.x*p2.y-p2.x*p1.y;
}
int main(){
    int i,n;
	double s,v;
    while(scanf("%d",&n) && n>=3){
		s=0;
        for(i=0;i<n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        double v;
        scanf("%lf",&v);
		p[n]=p[0];
		for(i=0;i<n;i++)
        s+=xmult(p[i],p[i+1]);
        printf("BAR LENGTH: %.2f\n",2*v/fabs(s));
    }
    return 0;
}

