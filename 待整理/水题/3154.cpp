#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	int i,j,n,m;
	double d1,d2,_min,sum,tmp;
	while(~scanf("%d%d",&n,&m)){
		d1=360.0/n;
		d2=360.0/m;
		sum=0.0;
		for(i=1;i<n;++i){
			_min=1e9;
			for(j=1;j<n+m;++j){
				tmp=fabs(double(i)/double(n)-double(j)/double(n+m));
				if(tmp<_min) _min=tmp;
			}
			sum+=_min;
		}
		cout<<fixed<<setprecision(4)<<sum*10000.0<<endl;
	}
	return 0;
}
