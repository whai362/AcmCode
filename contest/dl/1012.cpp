#include<cstdio>
#include<cmath>
#include<iostream>
#include<iomanip>
using namespace std;
double a[1005][15];
int main(){
	int i,j,k,n,m;
	double ans,tmp;
	while(scanf("%d%d",&n,&m)!=EOF){
		ans=0.0;
		for(i=0;i<m;++i)
		for(j=0;j<n;++j) scanf("%lf",&a[i][j]);
		for(i=0;i<m-1;++i)
		  for(j=i+1;j<m;++j){
			  tmp=0.0;
			  for(k=0;k<n;++k) tmp+=fabs(a[i][k]-a[j][k]);
			  if(tmp>ans) ans=tmp;
		  }
		cout<<fixed<<setprecision(3)<<ans<<endl;
	}
	return 0;
}
