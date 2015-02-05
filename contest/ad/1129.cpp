#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
const double eps=1e-8,
			 INF=1e30;
double s[N],b[N];
int main(){
	int n,flag;
	double ans,f,vm;
	while(scanf("%d",&n)!=EOF){
	scanf("%lf%lf",&f,&vm);
	for(int i=0;i<n;++i){
		scanf("%lf%lf",&s[i],&b[i]);
	}
	double l,r,mid;
	l=0,r=vm;
	ans=INF;
	flag=0;
	while(r-l>=eps){
		mid=(l+r)/2;
		double cost=0,t=0;
		for(int i=0;i<n;++i){
			cost+=max(0.0,0.5*mid+b[i])*s[i];
			if(0.5*mid+b[i]<eps){
				t+=s[i]/min(vm,-b[i]*2);
			}
			else t+=s[i]/mid;
		}
		if(cost<=f){
			flag=1;
			ans=min(ans,t);
			l=mid;
		}
		else r=mid;
	}
	if(flag)
		printf("%.3lf\n",ans);
	else
		puts("Bad Luck!");
	}
	return 0;
}
