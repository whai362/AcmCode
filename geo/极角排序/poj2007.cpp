#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=55;
struct Pt{
	double x,y;
	double operator * (const Pt b) const{
		return x*b.y-y*b.x;
	}
}p[N];
bool cmp(Pt a,Pt b){
	return a*b>0;
}
int main(){
	int cnt=0;
	while(scanf("%lf%lf",&p[cnt].x,&p[cnt].y)!=EOF){
		++cnt;
	}
	sort(p+1,p+cnt,cmp);
	for(int i=0;i<cnt;++i){
		printf("(%0.f,%0.f)\n",p[i].x,p[i].y);
	}
	return 0;
}
