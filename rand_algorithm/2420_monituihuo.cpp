#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
const double INF=1e10;
const double PI=acos(-1.0);
const int RP=4;	//初始时随机选择一些点，不用太多
const int SHIFT=60;	//但是方向一定要多
const int N=2005;
struct Point{
	double x,y;
	void goto_rand_dir(double key){
		double d=2*PI*(double)rand()/RAND_MAX;
		x+=key*sin(d);
		y+=key*cos(d);
	}
	void get_rand_point(int a,int b){
		x=rand()%a+1;
		y=rand()%b+1;
	}
}p[N],randp[RP];
double dis(Point a,Point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double d[RP];
int main(){
	srand(1123);
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;++i)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		int x=10000,y=10000;
		double tmp;
		for(int i=0;i<RP;++i){
			d[i]=INF;
			randp[i].get_rand_point(x,y);
			tmp=0;
			for(int j=0;j<n;++j)
				tmp+=dis(randp[i],p[j]);
			d[i]=min(d[i],tmp);	//取最值的地方，可修改
		}
		double key=sqrt(double(x*x+y*y));	//初始的步长，要保证初始点从该点出发肯定能包括整个区域
		while(key>=0.01){
			for(int i=0;i<RP;++i)
				for(int j=0;j<SHIFT;++j){
					Point rp=randp[i];
					rp.goto_rand_dir(key);
					if(rp.x<0 || rp.y<0 || rp.x>x || rp.y>y) continue;
					tmp=0;
					for(int k=0;k<n;++k)
						tmp+=dis(rp,p[k]);
					if(tmp<d[i]){	//取最值的地方，可修改
						d[i]=tmp;
						randp[i]=rp;
					}
				}
			key=key*0.6;	//可灵活调整
		}
		int k=0;
		for(int i=0;i<RP;++i)
			if(d[i]<d[k])
				k=i;
		printf("%.0lf\n",d[k]);
	}
	return 0;
}
