#include<iostream>
#include<cstdio>
using namespace std;
const double eps=1e-9;
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
			double s=(Y+1-eps)/X;
			double sum=1;
			ans=x-1;
			for(int i=1;i<=x;++i){
				double _max=s*i;
				int tmp=(int)(_max-sum);
				sum+=tmp;
				ans+=tmp;
				sum=sum*(i+1)/i;
			}

			cout<<ans<<endl;
		}
	}
	return 0;
}
