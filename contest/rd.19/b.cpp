#include<cstdio>
#include<cmath>
using namespace std;
struct point{
	double x,y,r,R;
}p[2];
double dis(point a,point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main(){
	int count=0;
	double tmp;
	scanf("%lf%lf%lf%lf",&p[0].x,&p[0].y,&p[0].r,&p[0].R);
	scanf("%lf%lf%lf%lf",&p[1].x,&p[1].y,&p[1].r,&p[1].R);
	tmp=dis(p[0],p[1]);
	if(tmp+p[0].R<=p[1].r) count=4;
	else if(tmp+p[0].r<=p[1].r){
		if(tmp+p[0].R<=p[1].R) count=2;
		else count=1;
	}
	else{
		if(tmp+p[0].R<=p[1].R) count=1;
		else if(tmp-p[0].r>p[1].r){
			if(tmp+p[0].R<=p[1].R) count=1;
			else 
		}
	}
	printf("%d\n",count);
	return 0;
}
