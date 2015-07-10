#include<iostream>
#include<cstdio>
using namespace std;
const double eps=1e-8;
int main(){
	int x,y;
	int ans;
	double X,Y;
	while(cin>>x>>y){
		X=x;
		Y=y;
		if(x>y)
			puts("-1");
		else{
			ans=x-1;
			double l=Y/X;
			double r=(Y+1)/X-eps;
			ans+=l-1;
			int flag=0;
			double tmp=(int)l;
			if(tmp>=l && tmp<=r)
				flag=1;
			for(int i=2;i<=x;++i){
				double res=1.0/i;
				while(res+tmp<r){
					++ans;
					tmp=res+tmp;
					if(tmp>=l && tmp<r){
						flag=1;
						break;
					}
				}
				if(flag) break;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
