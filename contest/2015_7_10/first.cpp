#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=1e4+5;
struct Dt{
	double t,x;
}d[N];
bool cmp(Dt a,Dt b){
	return a.t<b.t;
}
int main(){
	int T;
	int n;
	//cin>>T;
	scanf("%d",&T);
	int cas=0;
	while(T--){
		//cin>>n;
		scanf("%d",&n);
		for(int i=0;i<n;++i){
			//cin>>d[i].t>>d[i].x;
			scanf("%lf%lf",&d[i].t,&d[i].x);
		}
		sort(d,d+n,cmp);
		double ans=0;
		for(int i=1;i<n;++i){
			if(d[i].t==d[i-1].t) continue;
			ans=max(ans,fabs(d[i].x-d[i-1].x)/(d[i].t-d[i-1].t));
		}
		printf("Case #%d: %.2f\n",++cas,ans);
	}
	return 0;
}
