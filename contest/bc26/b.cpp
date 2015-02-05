#include<iostream>
#include<cstdio>
#include<iomanip>
using namespace std;
const double eps=1e-8;
int main(){
	int T;
	int m;
	double n;
	scanf("%d",&T);
	double ans;
	double tmp;
	double div;
	int cas=0;
	while(T--){
		ans=0;
		tmp=1;
		div=1;
		scanf("%lf%d",&n,&m);
		for(int i=0;i<m;++i){
			ans+=(n-1)*ans+tmp*(1+n)*n/2;
			tmp*=(n-1);
			div*=n;
		}
		//cout<<ans<<' '<<div<<endl;
		//cout<<fixed<<setprecision(3)<<ans/div<<endl;
		printf("Case #%d: %.3f\n",++cas,ans/div+eps);
	}
	return 0;
}
