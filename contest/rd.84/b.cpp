#include<cstdio>
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
struct point{
	double x,y;
}p[305];
double xmult(point p1,point p2,point p0){
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
int main(){
	int i,j,k,n;
	double ans=0,max1=0,max2=0,tmp;
	scanf("%d",&n);
	for(i=0;i<n;++i)
	  cin>>p[i].x>>p[i].y;
	for(i=0;i<n-1;++i){
		for(j=i+1;j<n;++j){
			max1=max2=0;
			for(k=0;k<n;++k){
				if(k!=i && k!=j){
					tmp=xmult(p[i],p[j],p[k])/2;
					if(tmp>=0) max1=max(max1,tmp);
					else max2=max(max2,fabs(tmp));
				}
			}
			if(max1!=0 && max2!=0){
				ans=max(ans,max1+max2);
			}
		}
	}
	cout<<fixed<<setprecision(9)<<ans<<endl;
	return 0;
}
