#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;
struct node{
	double x,y;
}a[100010];
bool cmp(node n1,node n2){
	return n1.x<n2.x;
}
double dis(double k,int i){
	return sqrt((a[i].y*a[i].y)+(fabs(a[i].x-k)*fabs(a[i].x-k)));
}
int main(){
	int n,cnt=0,t;
	int i,j,k;
	double l,r,_l,_r,ans_l,ans_r;
	scanf("%d",&t);
	while(t--){
		cnt++;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		  scanf("%lf%lf",&a[i].x,&a[i].y);
		sort(a+1,a+n+1,cmp);
		l=a[1].x;
		r=a[n].x;
		while(fabs(r-l)>=1e-7){
			_l=l+(r-l)/3;
			_r=r-(r-l)/3;
			ans_l=0;
			for (i=1;i<=n;i++)
				ans_l+=dis(_l,i);
			ans_r=0;
			for (i=1;i<=n;i++)
				ans_r+=dis(_r,i);
			if (ans_l<=ans_r)
				r=_r;
			else
				l=_l;
		}
		cout<<"Case "<<cnt<<": "<<fixed<<setprecision(6)<<l<<endl;
	}
	return 0;
}

