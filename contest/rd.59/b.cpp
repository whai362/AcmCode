#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
	int a,b,i,m,n,t;
	double x,y,tmp,_min=1e9;
	cin>>x>>y>>n;
	for(i=1;i<=n;++i){
		tmp=x*i/y;
		t=int(tmp+0.4999999);
		if(fabs(x/y-double(t)/double(i))<_min){
		    _min=fabs(x/y-double(t)/double(i));
			a=t/__gcd(t,i);
			b=i/__gcd(t,i);
		}
	}
	cout<<a<<'/'<<b<<endl;
	return 0;
}
